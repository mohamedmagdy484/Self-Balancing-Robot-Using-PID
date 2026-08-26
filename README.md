# 🤖 Two-Wheeled Self-Balancing Robot (ESP32 + Custom PCB)

![ESP32](https://img.shields.io/badge/Microcontroller-ESP32-blue?style=for-the-badge&logo=expressif)
![Altium Designer](https://img.shields.io/badge/PCB%20Design-Altium%20Designer-gold?style=for-the-badge&logo=altiumdesigner)
![Control System](https://img.shields.io/badge/Control-PID%20Algorithm-red?style=for-the-badge)
![Status](https://img.shields.io/badge/Phase%201-Completed-success?style=for-the-badge)

An end-to-end mechatronics and control systems project featuring an inverted pendulum **Self-Balancing Robot**. The system utilizes a custom-designed **100x70 mm 2-Layer PCB**, high-speed **ESP32 control loop**, **MPU6050 6-axis IMU**, and dual stepper motor drivers to maintain real-time dynamic balance via PID feedback control.

---

## 📸 Final Hardware Overview

<p align="center">
  <img src="./Final_Product_2.jpg" alt="Final Assembled PCB" width="700"/>
  <br>
  <i><b>Figure 1:</b> Assembled Custom Control Board matched against the Altium Designer 3D Model.</i>
</p>

---

## 🎥 Video Demonstration

Check out Phase 1 in action (Self-Balancing Mode & Dynamic Stability Test):

* 📹 **[Watch Demonstration Video on Google Drive](https://drive.google.com/drive/folders/1tvHIlpAVQ2EQqLJnxOTqIaO8B6XP8_57?usp=sharing)**

*(Note: To display the video directly inside GitHub README, upload your `.mp4` file directly in the editor or convert a short clip into a `.gif` and embed it using `![Demo](demo.gif)`)*

---

## 📌 Table of Contents
1. [Project Highlights](#-project-highlights)
2. [Technical Specifications](#-technical-specifications)
3. [Development & Hardware Evolution](#-development--hardware-evolution)
   - [Phase 1: Breadboard Prototyping](#1-breadboard-prototyping)
   - [Phase 2: Altium PCB Design & Routing](#2-altium-pcb-design--3d-modeling)
   - [Phase 3: PCB Fabrication & Assembly](#3-fabrication--assembly)
4. [Hardware Component Breakdown](#-hardware-component-breakdown)
5. [Future Enhancements (Phase 2)](#-future-enhancements-phase-2)
6. [The Engineering Team](#-the-engineering-team)

---

## ⚡ Project Highlights

* **High-Speed Control Loop:** Powered by the dual-core **ESP32** running at 240 MHz for fast PID calculation and precise step generation.
* **Noise Isolation & Decoupling:** Heavy onboard electrolytic decoupling capacitors and ground planes to suppress high-current motor switching noise.
* **System Protection:** Integrated 5x20mm glass inline fuse holder (`BLX-A`) and reverse polarity protection logic.
* **Modular Interface:** Onboard OLED screen header for interactive UI, real-time telemetry, and status feedback.
* **Custom Silkscreen Design:** Custom signature branding engraved directly onto the bottom copper/silk layer.

---

## 🛠️ Technical Specifications

| Parameter | Specification |
| :--- | :--- |
| **Main Controller** | ESP32-WROOM-32 (30-Pin Dev Module) |
| **Sensor (IMU)** | MPU6050 (3-Axis Accelerometer + 3-Axis Gyroscope) |
| **Motor Drivers** | Dual A4988 / DRV8825 Stepper Drivers with Aluminium Heatsinks |
| **Actuators** | 2x NEMA 17 Stepper Motors |
| **Board Dimensions** | 100 mm x 70 mm (Double Layer FR4) |
| **Power Source** | 3x 18650 Li-ion Battery Pack (~11.1V - 12.6V Nominal) |
| **Display Header** | 4-Pin I2C Header for 0.96" OLED Display |
| **CAD Software** | Altium Designer v25 |

---

## 🔬 Development & Hardware Evolution

### 1. Breadboard Prototyping
Initial verification of the MPU6050 complementary/Kalman filter, ESP32 timer interrupts, and stepper driver signals was executed on a breadboard.

<p align="center">
  <img src="./Bread_Board.jpg" alt="Breadboard Prototype" width="650"/>
  <br>
  <i><b>Figure 2:</b> Initial proof-of-concept setup testing power distribution and sensor reading.</i>
</p>

---

### 2. Altium PCB Design & 3D Modeling
To eliminate jumper wire resistance, loose contacts, and signal noise, a dedicated 100x70 mm PCB was designed in **Altium Designer**.

<p align="center">
  <img src="./3D_ISO_2.png" alt="3D Isometric View" width="48%"/>
  <img src="./Screenshot%202026-08-07%20010718_2.png" alt="3D Top View" width="48%"/>
</p>
<p align="center">
  <i><b>Figure 3 & 4:</b> 3D Isometric View and 3D Top Render in Altium Designer.</i>
</p>

#### Custom Silk & Routing Layout
<p align="center">
  <img src="./3D_BACK_2.png" alt="3D Back Silkscreen" width="31%"/>
  <img src="./Top_Layer_2.png" alt="Top Layer Traces" width="31%"/>
  <img src="./All_Layers_2.png" alt="All Layers Layout" width="31%"/>
</p>
<p align="center">
  <i><b>Figure 5, 6 & 7:</b> Bottom Silkscreen with team signatures (Left), 2D Top Layer Routing (Center), Composite Layer View with dimensions (Right).</i>
</p>

<p align="center">
  <img src="./No_3d_2.png" alt="2D Board Outline" width="55%"/>
  <br>
  <i><b>Figure 8:</b> 2D Board Footprint and Component Alignment.</i>
</p>

---

### 3. Fabrication & Assembly
The fabricated bare board was thoroughly tested for trace continuity before soldering the through-hole and SMD components.

<p align="center">
  <img src="./984420ef-7dd9-46e1-91b4-36250dbad386_2.jpg" alt="Bare vs Assembled PCB" width="48%"/>
  <img src="./No_3d%20FABRICATION_2.jpg" alt="Fabricated Board Alignment" width="48%"/>
</p>
<p align="center">
  <i><b>Figure 9 & 10:</b> Bare PCB next to fully soldered PCB (Left); Fabricated board physical verification over CAD layout (Right).</i>
</p>

---

## 🔌 Hardware Component Breakdown

1. **ESP32 Development Board:** Executes high-speed control loops and calculates target stepper pulse rates.
2. **MPU6050 IMU:** Positioned near the board center to minimize angular acceleration distortion.
3. **A4988 / DRV8825 Drivers:** Equipped with individual heat sinks and decoupling capacitors (`C1`, `C2`) near power pins to suppress inductive kickback.
4. **BLX-A Fuse Protection:** Inline protection preventing overcurrent damage from motor stalls.
5. **LM7805 / Voltage Regulator:** Provides clean power step-down for logic components.

---

## 🎯 Future Enhancements (Phase 2)

- [ ] **Interactive OLED UI:** Adding dynamic status faces, battery voltage monitoring, and PID parameter tuning menus.
- [ ] **Wireless Remote Control:** Implementing ESP-NOW / Wi-Fi / Bluetooth web server control for real-time steering and motion control.
- [ ] **Adaptive PID Tuning:** Implementing online auto-tuning for varying surface friction and payload changes.

---

## 👥 The Engineering Team

| Name | Role & Responsibilities |
| :--- | :--- |
| **Mohamed Magdy** | Hardware Engineering, PCB Design (Altium) & Embedded Systems |
| **Omar Elkady** | Control Theory, PID Algorithms & Embedded Logic |
| **Mohamed Assad** | System Calibration, Sensor Fusion & Embedded Systems |
| **Wagdy Mohamed** | Mechanical CAD Design & Structure Assembly |

---

<p align="center">
  <i>Developed for the College Control Systems Course — Bridging Theory & Practical Engineering 🚀</i>
</p>
