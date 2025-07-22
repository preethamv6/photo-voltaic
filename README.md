# ☀️ Optimization of Floating Photovoltaic Cells with IoT and Solar Tracking

This project explores the optimization of floating photovoltaic (FPV) systems using Arduino-based control, real-time IoT monitoring, and a dual-LDR solar tracking mechanism. The system dynamically orients solar panels on water bodies to maximize solar exposure and transmits sensor data (voltage, current, temperature) to mobile/PC via Bluetooth.

> Developed as part of the Experiential Learning Program at **RV College of Engineering**, Bengaluru (2024–25)

---

## 🎯 Objectives

- Develop an Arduino-controlled floating solar system with real-time monitoring.
- Integrate IoT (via RemoteXY + Bluetooth) for mobile/PC visualization of sensor data.
- Design an LDR-based solar tracking system to orient the panel towards maximum sunlight.

---

## ⚙️ Tech Stack

| Category        | Tools/Components                                    |
|----------------|------------------------------------------------------|
| Microcontroller | Arduino UNO                                         |
| Sensors         | LDRs, Current Sensor (ACS712), DHT11 (Temp & Hum)   |
| Actuators       | Servo Motor                                         |
| Communication   | HC-05 Bluetooth Module + RemoteXY App               |
| Power           | Solar Panel, Battery                                |
| Structure       | Plastic Base, Thermocol Floatation                  |
| Languages       | Arduino C/C++                                       |

---

## 📐 Working Principle

- **Solar Tracking:** Two LDRs detect light intensity on either side of the panel. The servo motor tilts the panel toward the brighter side to optimize sun exposure.
- **Sensor Readings:** Current, voltage, and temperature are read from analog pins and displayed on the mobile/PC interface using RemoteXY via Bluetooth.
- **Data Flow:** All sensor values are continuously sent to a smartphone or computer for monitoring and analysis.

---

## 🧠 Advantages of Floating PV + Tracking

- ✅ Utilizes water surfaces, conserving land
- 🌡️ Water cooling improves solar panel efficiency
- 🪞 Albedo effect from water enhances sunlight capture
- 💧 Reduces water evaporation and algae growth
- 🔄 Solar tracking boosts energy output by 25–35%

---

## 🔋 Circuit Components

- Arduino UNO
- SG90 Servo Motor
- 2× LDRs (Light Dependent Resistors)
- DHT11 Temperature & Humidity Sensor
- ACS712 Current Sensor
- HC-05 Bluetooth Module
- Solar Panel
- Jumper Wires, Resistors, Battery, Thermocol Base

---

## 💻 Code Snippet

```cpp
int ldr1 = analogRead(A0);
int ldr2 = analogRead(A1);

int value = abs(ldr1 - ldr2);

if (value > threshold) {
  if (ldr1 > ldr2) Spoint--;
  else Spoint++;
}
servo.write(Spoint);
```

> 📲 Data from `DHT11`, `ACS712`, and LDRs are sent to the phone via **RemoteXY**

---

## 📸 Demo & Visuals

The project images:
[Solar Tracking Demo](Elec_EL.jpg)


---

## 📄 Report

View the full documentation:  
[Elec_EL.docx](Elec_EL.docx) 

---

## 🚀 Future Scope

- ML-based sun prediction for more precise panel orientation
- GSM module for remote alerts
- Battery health monitoring & water level detection
- Integration with cloud-based dashboards (e.g., Firebase/Thingspeak)

---

## 👨‍💻 Contributors

**SPARK EC Cluster – RVCE**  
- Navya Singh  
- Vijayalaxmi Patil  
- Sesha Sai Chillara  
- Preetham V  
- Chinmay Sharma  

---

## 📬 Contact

- Email: preethamv.et23@rvce.edu.in  
- GitHub: [github.com/preethamv6](https://github.com/preethamv6)

---

> “Smarter solar for a sustainable tomorrow.” 🌞
