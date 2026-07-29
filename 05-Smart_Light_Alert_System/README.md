# 05 - Smart Light and Alert System

A tiered ambient-light monitoring system using 3 LEDs as a visual light-level indicator, with a buzzer alert triggered only in very dark/low-visibility conditions.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| LDR (Light Dependent Resistor) | 1 |
| 10kΩ resistor (LDR voltage divider) | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| 220Ω resistors (LEDs) | 3 |
| Buzzer | 1 |
| Breadboard + jumper wires | — |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### LDR (voltage divider)
| Leg | Connects to |
|---|---|
| Leg 1 | 5V |
| Leg 2 | A0 + 10kΩ resistor → GND |

### LEDs
| LED | Connects to |
|---|---|
| LED 1 (Red) | D2 (via 220Ω resistor) |
| LED 2 (Yellow) | D3 (via 220Ω resistor) |
| LED 3 (Green) | D4 (via 220Ω resistor) |
| All cathodes | GND |

### Buzzer
| Pin | Connects to |
|---|---|
| + | D5 |
| − | GND |

## How It Works
1. **LDR** continuously measures ambient light level via `analogRead(A0)`.
2. **Tiered response logic:**
   - **Very dark** (`lightValue < 200`) → all 3 LEDs ON + buzzer sounds — low-light alert.
   - **Medium light** (`200–500`) → LED 1 and LED 2 ON, LED 3 and buzzer OFF — partial indication.
   - **Bright** (`> 500`) → all LEDs and buzzer OFF — no alert needed.
3. Light readings are logged to Serial Monitor every 500ms.

## Applications
- Ambient light-level indicator for rooms, hallways, or storage areas
- Low-visibility safety alert (e.g. stairwells, parking garages)
- Simple day/dusk/night status indicator for smart lighting demos
- Educational demo for tiered threshold-based sensor logic
- Base circuit for expanding into full automatic lighting control

## Code
See [`05-Smart_Light_Alert_System.ino`](./05-Smart_Light_Alert_System.ino)
