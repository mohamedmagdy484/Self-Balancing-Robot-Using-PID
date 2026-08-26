/*
  ================================================================
  ESP32 Self-Balancing Robot - PURE BALANCE EDITION
  ================================================================
  - YABR Balancing Math (PROVEN)
  - Bluetooth Live Tuning & Debug
  - No OLED, No I2C bottleneck
  ================================================================
*/

#include <Wire.h>
#include <FastAccelStepper.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// ============== PIN DEFINITIONS ==============
#define STEP_PIN1 26
#define DIR_PIN1  25
#define STEP_PIN2 27
#define DIR_PIN2  14

#define M0_PIN    19
#define M1_PIN    18
#define M2_PIN    5
#define MPU_ADDR  0x68

#define PWR_MGMT_1   0x6B
#define ACCEL_XOUT_H 0x3B

// ============== SENSOR & FILTER ==============
volatile float angle = 0.0;
float angleAcc = 0.0;
float gyroRate = 0.0;
unsigned long lastTime = 0;

const float ALPHA = 0.9996f; // High trust in Gyro during active motion

float gyroPitchOffset = 0.0;
float accelAngleOffset = 0.0;

// ============== BALANCED PID VALUES ==============
float Kp = 16.5f;
float Ki = 0.44f;
float Kd = 3.1f;

float selfBalanceSetpoint = 0.0;
float pidError = 0.0;
float pidOutput = 0.0;
float integral = 0.0;
float lastPidError = 0.0;

bool invertMotorDir = false;

volatile bool startBalancing = false;
volatile bool hasFallen = false;
const float FALL_ANGLE = 28.0;

// ============== STEPPER ENGINE ==============
FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper1 = NULL;
FastAccelStepper *stepper2 = NULL;

TaskHandle_t BalanceTaskHandle;

unsigned long lastBTPrint = 0;
const unsigned long BT_PRINT_INTERVAL = 300;

// ============== FUNCTION DECLARATIONS ==============
void calibrateSensor();
void updateAngle();
void readRawData(int16_t &ax, int16_t &ay, int16_t &az, int16_t &gx, int16_t &gy, int16_t &gz);
void setMotors(float output);
void handleBluetoothCommands();

// ================================================================
// CORE 0: 250Hz (4ms) HIGH PRIORITY BALANCING LOOP
// ================================================================
void balanceTask(void * pvParameters) {
  TickType_t xLastWakeTime = xTaskGetTickCount();
  const TickType_t xFrequency = pdMS_TO_TICKS(4);

  for (;;) {
    vTaskDelayUntil(&xLastWakeTime, xFrequency);

    updateAngle();

    // 1. START BALANCING DETECT
    if (!startBalancing) {
      if (angleAcc > (selfBalanceSetpoint - 0.4f) && angleAcc < (selfBalanceSetpoint + 0.4f)) {
        angle = angleAcc;
        startBalancing = true;
        integral = 0.0f;
        lastPidError = 0.0f;
        pidOutput = 0.0f;
        SerialBT.println("\n>>> BALANCING STARTED <<<\n");
      }
      setMotors(0);
      continue;
    }

    // 2. SAFETY TRIPPED (FALLEN)
    if (fabs(angle - selfBalanceSetpoint) > FALL_ANGLE) {
      startBalancing = false;
      hasFallen = true;
      pidOutput = 0.0f;
      integral = 0.0f;
      setMotors(0);
      SerialBT.println("\n!!! ROBOT FALLEN !!!\n");
      continue;
    }
    hasFallen = false;

    // ============================================================
    // 3. CLEAN PID COMPUTATION
    // ============================================================
    pidError = angle - selfBalanceSetpoint;

    // Dynamic anti-runaway braking
    if (pidOutput > 10.0f || pidOutput < -10.0f) {
      pidError += pidOutput * 0.045f;/*i changed the value here*/
    }

    // Integral with strict clamp
    integral += Ki * pidError;
    integral = constrain(integral, -300.0f, 300.0f);

    // D-Term without the dt division scaling bug
    float dTerm = Kd * (pidError - lastPidError);
    lastPidError = pidError;

    // Total Control Speed Output
    pidOutput = (Kp * (angle - selfBalanceSetpoint)) + integral + dTerm;
    pidOutput = constrain(pidOutput, -400.0f, 400.0f);

    // Motor deadband
    if (pidOutput > -4.0f && pidOutput < 4.0f) {
      pidOutput = 0.0f;
    }

    // Send pulses to stepper driver
    setMotors(pidOutput);

    // Auto-adjust center of gravity
    if (pidOutput > 0) selfBalanceSetpoint += 0.0025f;
    if (pidOutput < 0) selfBalanceSetpoint -= 0.0025f;

    // Live Telemetry via Bluetooth
    unsigned long now = millis();
    if (now - lastBTPrint > BT_PRINT_INTERVAL) {
      lastBTPrint = now;
      SerialBT.print("Ang: "); SerialBT.print(angle, 2);
      SerialBT.print("° | SetP: "); SerialBT.print(selfBalanceSetpoint, 2);
      SerialBT.print(" | Out: "); SerialBT.print(pidOutput, 1);
      SerialBT.print(" | Kp:"); SerialBT.print(Kp, 1);
      SerialBT.print(" Ki:"); SerialBT.print(Ki, 2);
      SerialBT.print(" Kd:"); SerialBT.println(Kd, 1);
    }
  }
}

// ================================================================
// STEPPER DRIVER FREQUENCY GENERATION
// ================================================================
void setMotors(float output) {
  if (fabs(output) < 4.0f) {
    if (stepper1) stepper1->setSpeedInHz(0);
    if (stepper2) stepper2->setSpeedInHz(0);
    return;
  }

  uint32_t speedHz = (uint32_t)(fabs(output) * 11.0f);
  speedHz = constrain(speedHz, 80, 4500);

  bool dirForward = (output > 0);
  if (invertMotorDir) dirForward = !dirForward;

  if (stepper1) {
    stepper1->setSpeedInHz(speedHz);
    if (dirForward) stepper1->runForward();
    else            stepper1->runBackward();
  }

  if (stepper2) {
    stepper2->setSpeedInHz(speedHz);
    if (dirForward) stepper2->runBackward();
    else            stepper2->runForward();
  }
}

// ================================================================
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_ROBOT");
  delay(1000);

  Wire.begin(21, 22);
  Wire.setClock(400000);

  // Awake and set MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission(true);
  delay(100);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1B);
  Wire.write(0x00); // Gyro +/- 250dps
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1C);
  Wire.write(0x08); // Accel +/- 4g
  Wire.endTransmission(true);

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x1A);
  Wire.write(0x03); // Low Pass Filter ~43Hz
  Wire.endTransmission(true);

  pinMode(M0_PIN, OUTPUT);
  pinMode(M1_PIN, OUTPUT);
  pinMode(M2_PIN, OUTPUT);

  // Enable Microstepping (1/4 Step)
  digitalWrite(M0_PIN, LOW);
  digitalWrite(M1_PIN, HIGH);
  digitalWrite(M2_PIN, LOW);

  engine.init();

  stepper1 = engine.stepperConnectToPin(STEP_PIN1);
  if (stepper1) {
    stepper1->setDirectionPin(DIR_PIN1);
    stepper1->setAcceleration(120000); // ⚡ Instant responsiveness, no lag
  }

  stepper2 = engine.stepperConnectToPin(STEP_PIN2);
  if (stepper2) {
    stepper2->setDirectionPin(DIR_PIN2);
    stepper2->setAcceleration(120000);
  }

  calibrateSensor();
  lastTime = micros();

  // Fire up Core 0 Balance Task
  xTaskCreatePinnedToCore(
    balanceTask,
    "BalanceTask",
    4096,
    NULL,
    3, // Highest priority
    &BalanceTaskHandle,
    0
  );

  SerialBT.println("=== PURE BALANCE SYSTEM ONLINE ===");
  SerialBT.println("Commands:");
  SerialBT.println("  DIR    - Invert motor direction");
  SerialBT.println("  KP+/-  - Adjust Kp");
  SerialBT.println("  KI+/-  - Adjust Ki");
  SerialBT.println("  KD+/-  - Adjust Kd");
  SerialBT.println("  STATUS - Show current PID");
}

// ================================================================
// CORE 1: BLUETOOTH COMMANDS
// ================================================================
void loop() {
  handleBluetoothCommands();
  vTaskDelay(pdMS_TO_TICKS(20));
}

// ================================================================
// SENSOR READING & FILTERING
// ================================================================
void updateAngle() {
  int16_t ax, ay, az, gx, gy, gz;
  readRawData(ax, ay, az, gx, gy, gz);

  float rawAccelAngle = atan2((float)ax, (float)az) * 180.0f / PI;
  angleAcc = rawAccelAngle;

  gyroRate = (gy / 131.0f) - gyroPitchOffset;

  unsigned long now = micros();
  float dt = (now - lastTime) / 1000000.0f;
  lastTime = now;

  angle += gyroRate * dt;
  angle = angle * ALPHA + angleAcc * (1.0f - ALPHA);
}

void readRawData(int16_t &ax, int16_t &ay, int16_t &az,
                 int16_t &gx, int16_t &gy, int16_t &gz) {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  ax = (Wire.read() << 8) | Wire.read();
  ay = (Wire.read() << 8) | Wire.read();
  az = (Wire.read() << 8) | Wire.read();
  Wire.read(); Wire.read();
  gx = (Wire.read() << 8) | Wire.read();
  gy = (Wire.read() << 8) | Wire.read();
  gz = (Wire.read() << 8) | Wire.read();
}

void calibrateSensor() {
  const int samples = 500;
  float gyroPitchSum = 0.0f;
  float accelSum = 0.0f;

  SerialBT.println("=== CALIBRATING SENSOR (KEEP STILL) ===");
  delay(1500);

  for (int i = 0; i < samples; i++) {
    int16_t ax, ay, az, gx, gy, gz;
    readRawData(ax, ay, az, gx, gy, gz);

    gyroPitchSum += (gy / 131.0f);
    accelSum += (atan2((float)ax, (float)az) * 180.0f / PI);
    delay(4);
  }

  gyroPitchOffset = gyroPitchSum / samples;
  accelAngleOffset = accelSum / samples;

  angle = accelAngleOffset;
  selfBalanceSetpoint = accelAngleOffset;
  lastTime = micros();

  SerialBT.print("Calibration Succeeded: Setpoint is ");
  SerialBT.println(selfBalanceSetpoint, 2);
}

// ================================================================
// BLUETOOTH CONFIG COMMAND INTERFACE
// ================================================================
void handleBluetoothCommands() {
  if (SerialBT.available()) {
    String cmd = SerialBT.readStringUntil('\n');
    cmd.toUpperCase();
    cmd.trim();

    if (cmd == "DIR") {
      invertMotorDir = !invertMotorDir;
      SerialBT.print("Motor Direction Flipped: ");
      SerialBT.println(invertMotorDir ? "TRUE" : "FALSE");
    }
    else if (cmd == "KP+") {
      Kp += 0.5f;
      SerialBT.print("Kp = "); SerialBT.println(Kp, 1);
    }
    else if (cmd == "KP-") {
      Kp = max(1.0f, Kp - 0.5f);
      SerialBT.print("Kp = "); SerialBT.println(Kp, 1);
    }
    else if (cmd == "KD+") {
      Kd += 0.5f;
      SerialBT.print("Kd = "); SerialBT.println(Kd, 1);
    }
    else if (cmd == "KD-") {
      Kd = max(0.0f, Kd - 0.5f);
      SerialBT.print("Kd = "); SerialBT.println(Kd, 1);
    }
    else if (cmd == "KI+") {
      Ki += 0.05f;
      SerialBT.print("Ki = "); SerialBT.println(Ki, 2);
    }
    else if (cmd == "KI-") {
      Ki = max(0.0f, Ki - 0.05f);
      SerialBT.print("Ki = "); SerialBT.println(Ki, 2);
    }
    else if (cmd == "STATUS") {
      SerialBT.println("\n=== CURRENT TUNING ===");
      SerialBT.print("Kp = "); SerialBT.println(Kp, 2);
      SerialBT.print("Ki = "); SerialBT.println(Ki, 2);
      SerialBT.print("Kd = "); SerialBT.println(Kd, 2);
      SerialBT.print("Balance Point = "); SerialBT.println(selfBalanceSetpoint, 3);
      SerialBT.print("Motors Inverted = "); SerialBT.println(invertMotorDir ? "YES" : "NO");
      SerialBT.println("======================\n");
    }
  }
}