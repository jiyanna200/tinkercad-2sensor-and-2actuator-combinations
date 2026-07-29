# 06 - Smart Entry Controlled System

A two-factor access control system that only grants entry (opens the gate) when a person is detected within range AND presses the access button — combining proximity sensing with manual confirmation.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Pushbutton | 1 |
| Servo Motor (gate) | 1 |
| LED | 1 |
| 220Ω resistor (LED) | 1 |

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

### Pushbutton
| Pin | Connects to |
|---|---|
| One leg | D2 |
| Other leg | GND |

> Uses `INPUT_PULLUP` mode — no external resistor needed. Button reads LOW when pressed.

### Servo (gate)
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
1. **HC-SR04** continuously measures distance to detect a person/object near the entry point.
2. **Pushbutton** acts as a manual confirmation/access request (wired with internal pull-up, so pressed = LOW).
3. **Access logic:** Gate opens (servo → 90°) and LED turns ON **only if** distance is under 15 cm **AND** the button is pressed — "Access Granted".
4. If either condition fails, the gate stays closed (servo → 0°) and LED stays off — "Access Denied".
5. Distance and button state are logged to Serial Monitor every 500ms.

## Applications
- Two-factor entry control (presence + manual confirmation) for gates or doors
- Secure access point requiring both proximity and deliberate action (reduces accidental triggers)
- Smart turnstile or checkpoint access system
- Delivery/visitor gate requiring buzzer-in confirmation
- Educational demo for combined sensor-and-input access logic

## Code
See [`06-Smart_Entry_Controlled_System.ino`](./06-Smart_Entry_Controlled_System.ino)
