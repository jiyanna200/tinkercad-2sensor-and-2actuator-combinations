# Arduino Sensor-Actuator Combination Projects (Tinkercad)

A collection of 11 Arduino UNO mini-projects, each combining 2 sensors and 2 actuators (or actuator sets) into a meaningful, real-world-inspired system. Built and simulated in [Tinkercad Circuits](https://www.tinkercad.com/).

## 📁 Project Index

| # | Project | Sensors | Actuators | Folder |
|---|---|---|---|---|
| 01 | Smart Security and Night Alert System | LDR, PIR | LED, Buzzer | [`01-Smart_Security_Night_Alert_System`](./01-Smart_Security_Night_Alert_System) |
| 02 | Smart Temperature and Light Controlled System | TMP36, LDR | Servo, LED | [`02-Smart_Temperature_Light_Controlled_System`](./02-Smart_Temperature_Light_Controlled_System) |
| 03 | Smart Irrigation and Security Monitoring System | PIR, Soil Moisture | DC Motor, 7-Segment Display | [`03-Smart_Irrigation_Security_Monitoring_System`](./03-Smart_Irrigation_Security_Monitoring_System) |
| 04 | Smart Gate Access and Motion Alert System | HC-SR04 Ultrasonic, PIR | Servo, Buzzer | [`04-Smart_Gate_Access_Motion_Alert_System`](./04-Smart_Gate_Access_Motion_Alert_System) |
| 05 | Smart Light and Alert System | LDR | 3× LED, Buzzer | [`05-Smart_Light_Alert_System`](./05-Smart_Light_Alert_System) |
| 06 | Smart Entry Controlled System | HC-SR04 Ultrasonic, Pushbutton | Servo, LED | [`06-Smart_Entry_Controlled_System`](./06-Smart_Entry_Controlled_System) |
| 07 | Smart Fire Alert Alarm System | TMP36, Pushbutton | LED, Buzzer | [`07-Smart_Fire_Alert_Alarm_System`](./07-Smart_Fire_Alert_Alarm_System) |
| 08 | Smart Garage Door Control System | HC-SR04 Ultrasonic, LDR | Servo, LED | [`08-Smart_Garage_Door_Control_System`](./08-Smart_Garage_Door_Control_System) |
| 09 | Smart Restricted Area Security System | PIR, Pushbutton | Servo, Buzzer | [`09-Smart_Restricted_Area_Security_System`](./09-Smart_Restricted_Area_Security_System) |
| 10 | Smart Water Tank Monitoring System | HC-SR04 Ultrasonic, Pushbutton | LED, Buzzer | [`10-Smart_Water_Tank_Monitoring_System`](./10-Smart_Water_Tank_Monitoring_System) |
| 11 | Smart Brightness Control System | LDR, Potentiometer | RGB LED, Buzzer | [`11-Smart_Brightness_Control_System`](./11-Smart_Brightness_Control_System) |

## 🧰 Tech Stack
- **Platform:** Arduino UNO (simulated in Tinkercad Circuits)
- **Language:** Arduino C/C++ (`.ino`)
- **Sensors used across projects:** LDR, PIR Motion Sensor, TMP36 Temperature Sensor, HC-SR04 Ultrasonic Sensor, Soil Moisture Sensor, Pushbutton, Potentiometer
- **Actuators used across projects:** LED (single/RGB/multi), Buzzer, Servo Motor, DC Motor, 7-Segment Display

## 📂 Folder Structure
Each project folder follows the same structure:
```
0X-Project_Name/
├── 0X-Project_Name.ino     # Arduino source code
├── circuit_sketch.png      # Tinkercad circuit diagram/screenshot
└── README.md                # Project-specific documentation (components, wiring, logic, applications)
```

## ⚙️ How to Run Any Project
1. Open [Tinkercad Circuits](https://www.tinkercad.com/) and create a new circuit.
2. Add the components listed in that project's `README.md`.
3. Wire the components according to the wiring table in the same README.
4. Open the code editor, switch to **Text mode**, and paste the contents of the project's `.ino` file.
5. Click **Start Simulation** and check the Serial Monitor for live sensor readings and system status.

## 🎯 Design Approach
Each project pairs two sensors with two actuators around a single, coherent real-world use case (security, agriculture, safety, access control, or environmental monitoring) rather than combining components arbitrarily — so every circuit demonstrates a meaningful automation or monitoring scenario, not just a component test.

## 📌 Notes
- All threshold values (distance limits, temperature thresholds, light levels) are set as adjustable variables at the top of each `.ino` file and can be tuned to match real sensor behavior.
- Common cathode configuration is assumed for all RGB LEDs and 7-segment displays unless noted otherwise in the individual project README.
- Pushbuttons use `INPUT_PULLUP` mode throughout (no external resistor required); a pressed button reads `LOW`.
