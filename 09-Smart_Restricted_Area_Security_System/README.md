# 09 - Smart Restricted Area Security System

A restricted-zone monitoring system that triggers a visible barrier response (servo) and audible alarm (buzzer) when motion is detected, with a manual pushbutton for testing or manual alert activation.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| PIR Motion Sensor | 1 |
| Pushbutton | 1 |
| Servo Motor (barrier/indicator) | 1 |
| Buzzer | 1 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### PIR Motion Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT (signal) | D2 |

### Pushbutton
| Pin | Connects to |
|---|---|
| One leg | D3 |
| Other leg | GND |

> Uses `INPUT_PULLUP` mode — no external resistor needed. Button reads LOW when pressed.

### Servo (barrier)
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
1. **PIR sensor** continuously monitors the restricted area for motion.
2. **Pushbutton** acts as a manual alert trigger (wired with internal pull-up, so pressed = LOW).
3. **Alert logic:** Servo moves to 90° (barrier drops/alert position) and buzzer sounds if **either** condition is true — motion is detected **or** the button is manually pressed — "Restricted Area Alert".
4. If no motion is detected and the button isn't pressed → servo returns to 0° (normal position) and buzzer stays silent — "Area Secure".
5. Motion and button states are logged to Serial Monitor every 500ms.

## Applications
- Restricted-zone intrusion detection with automatic barrier response
- Warehouse/storage room unauthorized-access alarm
- Construction site or hazardous-area entry alert system
- Manual panic-trigger security system combined with automatic motion sensing
- Educational demo for combining automatic sensing with manual override control

## Code
See [`09-Smart_Restricted_Area_Security_System.ino`](./09-Smart_Restricted_Area_Security_System.ino)
