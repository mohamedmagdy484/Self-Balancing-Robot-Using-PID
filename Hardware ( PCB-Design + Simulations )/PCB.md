# ⚙️ Two-Wheeled Self-Balancing Robot — Mechanical Design & Hardware

![CAD Software](https://img.shields.io/badge/CAD-SolidWorks-blue?style=for-the-badge&logo=solidworks)
![Manufacturing](https://img.shields.io/badge/Fabrication-3D%20Printing%20%2F%20Laser%20Cut-orange?style=for-the-badge)
![Architecture](https://img.shields.io/badge/Chassis-Multi--Tier%20Stacked-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Mechanical%20Phase-Completed-success?style=for-the-badge)

A robust, modular, multi-tier mechanical chassis engineered specifically for an inverted pendulum **Self-Balancing Robot**. Built upon dynamic stabilization principles, the chassis utilizes a vertical stacked design to elevate the Center of Gravity (CoG), optimizing real-time PID responsiveness while delivering a stable platform for embedded control electronics.

---

## 📸 Hardware & CAD Overview

<p align="center">
  <img width="400" alt="SolidWorks 3D CAD Render" src="https://github.com/user-attachments/assets/a30a0735-8840-44b4-affa-04bdcc9a1e4e" />
  <img width="380" alt="Assembled Robot Hardware" src="https://github.com/user-attachments/assets/3741b069-9dda-4ac0-9b98-50e9efa8f887" />
  <br>
  <i><b>Figure 1:</b> SolidWorks 3D CAD Model (Left) matched against the assembled physical prototype (Right).</i>
</p>

---

## 📌 Table of Contents
1. [Mechanical Highlights](#-mechanical-highlights)
2. [Technical Specifications & BOM](#-technical-specifications--bom)
3. [Design & Assembly Evolution](#-design--assembly-evolution)
   - [Phase 1: SolidWorks CAD Modeling](#1-solidworks-cad-modeling)
   - [Phase 2: Structural Framing & Assembly](#2-structural-framing--assembly)
   - [Phase 3: Actuator & Power Integration](#3-actuator--power-integration)
4. [Mechanical Component Breakdown](#-mechanical-component-breakdown)
5. [Future Enhancements](#-future-enhancements)
6. [The Engineering Team](#-the-engineering-team)

---

## ⚡ Mechanical Highlights

* **Elevated Center of Gravity (CoG):** Battery pack intentionally mounted on the top tier to increase the moment of inertia, making balance corrections smoother for the PID loop.
* **Rigid Threaded Rod Pillars:** Utilizes continuous threaded steel rods with locking hex nuts for high structural rigidity and customizable tier spacing.
* **Direct-Drive Stepper Mounts:** Dual NEMA 17 stepper motors mounted low at the chassis base to minimize unwanted vibration and provide direct torque transmission.
* **Modular Electronics Bay:** Middle plate features pre-calculated mounting hole patterns for the custom ESP32 control board and MPU6050 IMU sensor.
* **High-Traction Drive System:** Heavy-duty rubber tires coupled with precision brass shaft adapters to eliminate rotational backlash during rapid direction flips.

---

## 🛠️ Technical Specifications & BOM

| Parameter | Specification |
| :--- | :--- |
| **CAD Tool** | SolidWorks 2024 |
| **Chassis Architecture** | 3-Tier Vertical Stacked System |
| **Plate Materials** | 3D Printed PLA (3mm Thickness) |
| **Structural Frame** | 4x M4 Threaded Steel Rods with Lock Nuts |
| **Actuators** | 2x NEMA 17 Stepper Motors (1.8° Step Angle) |
| **Wheels & Tires** | 65mm High-Grip Off-Road Rubber Tires |
| **Shaft Coupling** | 5mm-to-Hex Brass Rigid Shaft Couplers |
| **Power Mounting** | Top-tier 4x 18650 Li-ion Battery Enclosure |

---

## 🔬 Design & Assembly Evolution

### 1. SolidWorks CAD Modeling
The complete assembly was designed in **SolidWorks** to verify motor clearances, weight distribution, and sensor placement before fabrication.

<p align="center">
  <img width="380" alt="3D CAD Front View" src="https://github.com/user-attachments/assets/66ee1d01-b30d-45e3-94cd-325f9e04cd9e" />
  <img width="280" alt="3D CAD Side View" src="https://github.com/user-attachments/assets/e7f98fa6-05b5-4d00-bee6-2dfaea693a97" />
</p>
<p align="center">
  <img width="380" alt="3D CAD Isometric Perspective" src="https://github.com/user-attachments/assets/96687c58-1e85-4f20-89a2-cb7d215931ca" />
  <img width="380" alt="3D CAD Rear Perspective" src="https://github.com/user-attachments/assets/613a74a7-f68f-42a5-a344-3e3629734ffa" />
  <br>
  <i><b>Figures 2, 3, 4 & 5:</b> SolidWorks 3D models displaying front, side, and isometric perspectives.</i>
</p>

---

### 2. Structural Framing & Assembly
Assembly of the vertical skeleton using threaded steel rods, enabling easy height adjustments between the power, electronics, and drive tiers.

<p align="center">
  <img width="380" alt="Battery Mount Top Tier" src="https://github.com/user-attachments/assets/d0d589c7-3343-4f9e-96ec-bb47719a6477" />
  <img width="380" alt="Chassis Frame Assembly" src="https://github.com/user-attachments/assets/c5275308-f29f-463e-aa61-ac852e823080" />
  <br>
  <i><b>Figures 6 & 7:</b> Battery mount assembly (Left) and continuous threaded rod frame alignment (Right).</i>
</p>

---

### 3. Actuator & Power Integration
Final mounting of NEMA 17 stepper motors, brass couplers, high-traction wheels, and PCB standoffs.

<p align="center">
  <img width="380" alt="Assembled Robot Side View" src="https://github.com/user-attachments/assets/5b107583-abff-4314-bcdf-414e1efa1558" />
  <img width="380" alt="Drive Base Assembly" src="https://github.com/user-attachments/assets/7346ec8b-8199-4fea-845b-0368b9d24f91" />
  <br>
  <i><b>Figures 8 & 9:</b> Fully assembled physical robot (Left) and base drive subsystem with motors (Right).</i>
</p>

---

## 🔌 Mechanical Component Breakdown

1. **Top Tier (Power Unit):** Holds the 18650 battery holder at the maximum vertical position to optimize inverted pendulum physics.
2. **Middle Tier (Control Platform):** Houses the ESP32 main PCB, MPU6050 IMU, and OLED telemetry display.
3. **Bottom Tier (Drive Unit):** Direct structural housing for two NEMA 17 motors using M3 mounting fasteners.
4. **Threaded Rod Pillars:** Continuous steel rods acting as the central load-bearing skeleton.
5. **Wheel Assemblies:** High-grip wheels locked directly onto motor shafts via brass set-screw couplers.

---

## 🎯 Future Enhancements

- [ ] **Protective Chassis Shell:** Lightweight 3D-printed outer cover to protect electronics during fall testing.
- [ ] **Aluminum Plate Upgrade:** Replacing PLA plates with 2mm CNC aluminum for maximum durability.
- [ ] **Dampened Sensor Mount:** Adding rubber anti-vibration grommets under the MPU6050 mount to filter out high-frequency motor noise.

---

## 👥 The Engineering Team

| Name | Role & Responsibilities |
| :--- | :--- |
| **Wagdy Mohamed** | Mechanical CAD Design, Assembly & Physical Prototyping |
| **Mohamed Magdy** | PCB Engineering & Hardware Design |
| **Omar Elkady** | Control Systems & Embedded PID Logic |
| **Mohamed Assad** | Sensor Fusion & System Calibration |

---

<p align="center">
  <i>Designed & Fabricated for the Mechatronics & Control Systems Engineering Course 🚀</i>
</p>
