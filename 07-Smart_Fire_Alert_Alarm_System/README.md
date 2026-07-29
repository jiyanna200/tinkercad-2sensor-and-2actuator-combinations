# 07 - Smart Fire Alert Alarm System

A fire/overheating detection system that triggers an alarm automatically when temperature exceeds a safe threshold, with a manual pushbutton override for testing or manual alarm activation.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| TMP36 Temperature Sensor | 1 |
| Pushbutton | 1 |
| LED | 1 |
| 220Ω resistor (LED) | 1 |
| Buzzer | 1 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### TMP36 Temperature Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| Signal (Vout) | A0 |

### Pushbutton
| Pin | Connects to |
|---|---|
| One leg | D2 |
| Other leg | GND |

> Uses `INPUT_PULLUP` mode — no external resistor needed. Button reads LOW when pressed.

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
1. **TMP36** reads analog voltage on A0, converted to °C using `(voltage - 0.5) * 100`.
2. **Pushbutton** acts as a manual alarm trigger (wired with internal pull-up, so pressed = LOW).
3. **Alarm logic:** LED and buzzer turn ON if **either** condition is true — temperature exceeds 30°C **or** the button is manually pressed — "Fire Alert!".
4. If temperature is normal and the button isn't pressed → LED and buzzer stay OFF — "Normal".
5. Temperature and button state are logged to Serial Monitor every 500ms.

## Applications
- Home/office fire and overheating early-warning system
- Kitchen or server room temperature safety alarm
- Manual panic-button fire alarm combined with automatic sensing
- Industrial equipment overheating alert system
- Low-cost prototype for smart fire detection with human-in-the-loop testing

## Code
See [`07-Smart_Fire_Alert_Alarm_System.ino`](./07-Smart_Fire_Alert_Alarm_System.ino)
