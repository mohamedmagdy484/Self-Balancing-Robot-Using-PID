# 🤖 Two-Wheeled Self-Balancing Robot (ESP32 + Custom PCB)

![ESP32](https://img.shields.io/badge/Microcontroller-ESP32-blue?style=for-the-badge&logo=expressif)
![Altium Designer](https://img.shields.io/badge/PCB%20Design-Altium%20Designer-gold?style=for-the-badge&logo=altiumdesigner)
![Control System](https://img.shields.io/badge/Control-PID%20Algorithm-red?style=for-the-badge)
![Status](https://img.shields.io/badge/Phase%201-Completed-success?style=for-the-badge)

An end-to-end mechatronics and control systems project featuring an inverted pendulum **Self-Balancing Robot**. The system utilizes a custom-designed **100x70 mm 2-Layer PCB**, high-speed **ESP32 control loop**, **MPU6050 6-axis IMU**, and dual stepper motor drivers to maintain real-time dynamic balance via PID feedback control.

---

## 📸 Final Hardware Overview

<p align="center">
<img width="1200" height="1600" alt="Final_Product" src="https://github.com/user-attachments/assets/92a40ba5-4718-414d-9753-377bbd1bab9a" />
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
<img width="1200" height="1600" alt="Bread_Board" src="https://github.com/user-attachments/assets/4d6182e0-e4d4-4ac3-9324-3c2cd893c264" />
  <br>
  <i><b>Figure 2:</b> Initial proof-of-concept setup testing power distribution and sensor reading.</i>
</p>

---

### 2. Altium PCB Design & 3D Modeling
To eliminate jumper wire resistance, loose contacts, and signal noise, a dedicated 100x70 mm PCB was designed in **Altium Designer**.

<p align="center">
<img width="683" height="637" alt="3D_ISO" src="https://github.com/user-attachments/assets/e57b9a8c-a904-43f9-8bdd-b169c0932725" />
<img width="826" height="600" alt="Screenshot 2026-08-07 010718" src="https://github.com/user-attachments/assets/27841f33-8b95-4ea6-b379-f4678af586d5" />
</p>
<p align="center">
  <i><b>Figure 3 & 4:</b> 3D Isometric View and 3D Top Render in Altium Designer.</i>
</p>

#### Custom Silk & Routing Layout
<p align="center">
<img width="1147" height="727" alt="3D_BACK" src="https://github.com/user-attachments/assets/6ad0b2ac-857d-4736-a41a-1d179b7b03ed" />
<img width="1240" height="721" alt="All_Layers" src="https://github.com/user-attachments/assets/de09e98b-c719-479e-ba5c-454de4500179" />
="686" alt="Top_Layer" src="https://github.com/user-attachments/assets/e039e3d2-e3bd-46b2-b22a-b3e5c1d8f7d8" />
  <img width="1240" height<img width="1237" height="677" alt="Bottom_Layer" src="https://github.com/user-attachments/assets/46cdb7e1-74c5-493b-a336-b9de7e799e73" />

</p>
<p align="center">
  <i><b>Figure 5, 6 & 7:</b> Bottom Silkscreen with team signatures (Left), 2D Top Layer Routing (Center), Composite Layer View with dimensions (Right).</i>
</p>

<p align="center">
<img width="807" height="562" alt="No_3d" src="https://github.com/user-attachments/assets/a13d5d39-71d0-4a3f-8356-29071a9bdae7" />
  <br>
  <i><b>Figure 8:</b> 2D Board Footprint and Component Alignment.</i>
</p>

---

### 3. Fabrication & Assembly
The fabricated bare board was thoroughly tested for trace continuity before soldering the through-hole and SMD components.

<p align="center">
<img width="1200" height="1600" alt="984420ef-7dd9-46e1-91b4-36250dbad386" src="https://github.com/user-attachments/assets/a7daa777-cecb-4244-be90-077449e1e2cb" />
  <img width="1360" height="1600" alt="No_3d FABRICATION" src="https://github.com/user-attachments/assets/062d0b7c-1037-4f44-8334-7de30b68eda9" />
<img width="900" height="1600" alt="ap" src="https://github.com/user-attachments/assets/f4fc81c4-d1f5-4db8-98ea-a3543320a125" />
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
