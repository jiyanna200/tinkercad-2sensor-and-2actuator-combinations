# 01 - Smart Security and Night Alert System

A night-time intrusion alert system that combines ambient light sensing with motion detection to trigger an alarm only when it's dark **and** motion is detected — avoiding false alarms during the day.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| LDR (Light Dependent Resistor) | 1 |
| 10kΩ resistor (LDR voltage divider) | 1 |
| PIR Motion Sensor | 1 |
| LED | 1 |
| 220Ω resistor (LED) | 1 |
| Buzzer | 1 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### LDR (voltage divider)
| Leg | Connects to |
|---|---|
| Leg 1 | 5V |
| Leg 2 | A0 + 10kΩ resistor → GND |

### PIR Motion Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT (signal) | D2 |

### LED
| Leg | Connects to |
|---|---|
| Anode (+) | D8 (via 220Ω resistor) |
| Cathode (−) | GND |

### Buzzer
| Pin | Connects to |
|---|---|
| + | D9 |
| − | GND |

## How It Works
1. **LDR** continuously measures ambient light via `analogRead(A0)`.
2. **PIR sensor** detects motion via `digitalRead(pirPin)` — HIGH when motion is present.
3. **Logic:**
   - If it's dark (`ldrValue < 300`) **and** motion is detected (`motion == HIGH`) → LED turns ON and buzzer sounds — "Motion Detected in Dark".
   - Otherwise → LED and buzzer stay OFF — "Safe".
4. Readings are printed to Serial Monitor every 500ms for debugging/monitoring.

## Applications
- Home/office night security alarm
- Intrusion detection for storage rooms, warehouses, or garages
- Low-cost perimeter security for small properties
- Smart doorway/entry alert system
- Base circuit for a full IoT security system (extendable with SMS/notification modules)

## Code
See [`01-Smart_Security_Night_Alert_System.ino`](./01-Smart_Security_Night_Alert_System.ino)
