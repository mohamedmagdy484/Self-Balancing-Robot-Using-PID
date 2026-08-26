# ⚙️ Two-Wheeled Self-Balancing Robot — Mechanical Design & Hardware



A robust, modular, multi-tier mechanical chassis engineered specifically for an inverted pendulum **Self-Balancing Robot**. Built upon dynamic stabilization principles, the chassis utilizes a vertical stacked design to elevate the Center of Gravity (CoG), optimizing real-time PID responsiveness while delivering a stable platform for embedded control electronics.

---

## 📸 Hardware & CAD Overview

<p align="center">
<img width="744" height="645" alt="8" src="https://github.com/user-attachments/assets/a30a0735-8840-44b4-affa-04bdcc9a1e4e" />
<img width="720" height="1280" alt="5" src="https://github.com/user-attachments/assets/3741b069-9dda-4ac0-9b98-50e9efa8f887" />


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
| **Plate Materials** | Laser-Cut Acrylic / 3D Printed PLA (3mm Thickness) |
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
  <img src="9.jpeg" width="45%" alt="3D Front View" />
  <img src="1.jpg" width="35%" alt="3D Side View" />
</p>
<p align="center">
  <i><b>Figures 2 & 3:</b> SolidWorks 3D Front View (`9.jpeg`) and Side Elevation (`1.jpg`).</i>
</p>

---

### 2. Structural Framing & Assembly
Assembly of the vertical skeleton using threaded steel rods, enabling easy height adjustments between the power, electronics, and drive tiers.

<p align="center">
  <img src="6.jpg" width="45%" alt="Bare Structural Frame" />
  <img src="2.jpg" width="45%" alt="Top Tier Battery Mount" />
</p>
<p align="center">
  <i><b>Figures 4 & 5:</b> Initial chassis alignment frame (`6.jpg`) and top-tier battery holder mounting (`2.jpg`).</i>
</p>

---

### 3. Actuator & Power Integration
Final mounting of NEMA 17 stepper motors, brass couplers, high-traction wheels, and PCB standoffs.

<p align="center">
  <img src="7.jpeg" width="45%" alt="Drive Subsystem" />
  <img src="4.jpg" width="45%" alt="Completed Mechanical Build Side View" />
</p>
<p align="center">
  <i><b>Figures 6 & 7:</b> Base drive assembly with stepper motors (`7.jpeg`) and fully wired physical robot side view (`4.jpg`).</i>
</p>

---

## 🔌 Mechanical Component Breakdown

1. **Top Tier (Power Unit):** Holds the 18650 battery holder (`2.jpg`) at the maximum vertical position to optimize inverted pendulum physics.
2. **Middle Tier (Control Platform):** Houses the ESP32 main PCB, MPU6050 IMU, and OLED telemetry display (`5.jpg`).
3. **Bottom Tier (Drive Unit):** Direct structural housing for two NEMA 17 motors using M3 mounting fasteners (`7.jpeg`).
4. **Threaded Rod Pillars:** Continuous steel rods acting as the central load-bearing skeleton (`6.jpg`).
5. **Wheel Assemblies:** High-grip wheels locked directly onto motor shafts via brass set-screw couplers (`7.jpeg`).

---

## 🎯 Future Enhancements

- [ ] **Protective Chassis Shell:** Lightweight 3D-printed outer cover to protect electronics during fall testing.
- [ ] **Aluminum Plate Upgrade:** Replacing PLA/acrylic plates with 2mm CNC aluminum for maximum durability.
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
</p>![Uploading 8.jpeg…]()
