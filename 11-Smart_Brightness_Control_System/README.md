# 11 - Smart Brightness Control System

An adjustable light-level alert system where the darkness threshold is user-tunable via a potentiometer, rather than fixed in code — combined with an RGB LED and buzzer for status/alert indication.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| LDR (Light Dependent Resistor) | 1 |
| 10kΩ resistor (LDR voltage divider) | 1 |
| Potentiometer (threshold adjustment) | 1 |
| RGB LED (common cathode) | 1 |
| 220Ω resistors (RGB LED) | 3 |
| Buzzer | 1 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

> ⚠️ Note: The uploaded circuit screenshot shows the LDR and RGB LED wired, but the potentiometer is not visible in frame. Make sure it's wired as described below for `threshold` (A1) to read correctly.

## Wiring

### LDR (voltage divider)
| Leg | Connects to |
|---|---|
| Leg 1 | 5V |
| Leg 2 | A0 + 10kΩ resistor → GND |

### Potentiometer
| Pin | Connects to |
|---|---|
| Outer leg 1 | 5V |
| Outer leg 2 | GND |
| Middle (wiper) | A1 |

### RGB LED
| Leg | Connects to |
|---|---|
| Red | D9 (via 220Ω) |
| Green | D10 (via 220Ω) |
| Blue | D11 (via 220Ω) |
| Common cathode | GND |

### Buzzer
| Pin | Connects to |
|---|---|
| + | D8 |
| − | GND |

## How It Works
1. **LDR** measures ambient light level via `analogRead(A0)`.
2. **Potentiometer** sets a user-adjustable darkness threshold via `analogRead(A1)` — turning the knob changes how dark it must get before the alert triggers.
3. **Logic:** If the LDR reading falls below the potentiometer's threshold value → RGB LED turns **red** and buzzer sounds — "Dark - Alert". Otherwise → RGB LED turns **green** and buzzer stays off — "Bright - Safe".
4. Both readings are logged to Serial Monitor every 500ms for calibration/debugging.

## Applications
- Adjustable-sensitivity night light or security alert (tune to room conditions)
- Calibratable ambient light monitor for greenhouses or photography studios
- User-configurable dusk-detection system without needing to reprogram the Arduino
- Educational demo for combining two analog sensors (fixed sensor + adjustable reference)
- Base circuit for building tunable smart lighting systems

## Code
See [`11-Smart_Brightness_Control_System.ino`](./11-Smart_Brightness_Control_System.ino)
