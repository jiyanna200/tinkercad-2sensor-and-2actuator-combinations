# 08 - Smart Garage Door Control System

An automated garage door that opens only when a vehicle is detected close by **and** it's daytime/bright enough (avoiding false triggers from stray objects at night), with an LED indicating door status.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| LDR (Light Dependent Resistor) | 1 |
| 10kΩ resistor (LDR voltage divider) | 1 |
| Servo Motor (garage door) | 1 |
| LED | 1 |
| 220Ω resistor (LED) | 1 |

## Circuit Diagram
*(Add your Tinkercad circuit screenshot here as `circuit_sketch.png`)*

## Wiring

### HC-SR04 Ultrasonic Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| Trig | D9 |
| Echo | D10 |

### LDR (voltage divider)
| Leg | Connects to |
|---|---|
| Leg 1 | 5V |
| Leg 2 | A0 + 10kΩ resistor → GND |

### Servo (garage door)
| Wire | Connects to |
|---|---|
| Signal (orange/yellow) | D6 |
| VCC (red) | 5V |
| GND (brown/black) | GND |

### LED
| Leg | Connects to |
|---|---|
| Anode (+) | D8 (via 220Ω resistor) |
| Cathode (−) | GND |

## How It Works
1. **HC-SR04** measures distance to detect an approaching vehicle/object.
2. **LDR** measures ambient light to confirm it's daytime/bright conditions.
3. **Access logic:** Garage door opens (servo → 90°) and LED turns ON **only if** distance is under 15 cm **AND** light level is above 500 (bright) — "Garage Open".
4. If either condition fails, the door stays closed (servo → 0°) and LED stays off — "Garage Closed".
5. Distance and light readings are logged to Serial Monitor every 500ms.

## Applications
- Automated residential garage door opener with daylight safety check
- Vehicle proximity-based smart entry for driveways
- Combined sensor logic to reduce false triggers (e.g. animals at night)
- Smart home automation prototype for entry points
- Educational demo for combining ultrasonic + light-based conditional logic

## Code
See [`08-Smart_Garage_Door_Control_System.ino`](./08-Smart_Garage_Door_Control_System.ino)
