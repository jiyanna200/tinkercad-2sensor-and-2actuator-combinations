# 04 - Smart Gate Access and Motion Alert System

An automated gate that opens when an object/vehicle approaches within range, combined with a PIR-based motion alert for security monitoring around the gate area.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| PIR Motion Sensor | 1 |
| Servo Motor (gate arm) | 1 |
| Buzzer | 1 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### HC-SR04 Ultrasonic Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| Trig | D9 |
| Echo | D10 |

### PIR Motion Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT (signal) | D2 |

### Servo (gate)
| Wire | Connects to |
|---|---|
| Signal (orange/yellow) | D6 |
| VCC (red) | 5V |
| GND (brown/black) | GND |

### Buzzer
| Pin | Connects to |
|---|---|
| + | D8 |
| − | GND |

## How It Works
1. **HC-SR04** continuously measures distance to nearby objects/vehicles.
   - If an object is closer than 15 cm → **servo rotates to 90°** (gate opens).
   - Otherwise → **servo returns to 0°** (gate closed).
2. **PIR sensor** independently monitors for motion in the surrounding area.
   - If motion is detected → **buzzer sounds** as a security alert.
   - Otherwise → buzzer stays silent.
3. Gate control and motion alert operate independently and simultaneously.
4. Distance and motion readings are logged to Serial Monitor every 500ms.

## Applications
- Automated vehicle/pedestrian gate for driveways or compounds
- Smart parking barrier with proximity-based auto-open
- Perimeter security system combining access control and intrusion alerts
- Warehouse or loading dock automated gate with motion-triggered alarm
- Campus/gated community entry automation

## Code
See [`04-Smart_Gate_Access_Motion_Alert_System.ino`](./04-Smart_Gate_Access_Motion_Alert_System.ino)
