# 02 - Smart Temperature and Light Controlled System

An automated ventilation system that opens a vent/window (via servo) and turns on an indicator LED when it's both **hot** and **bright** — e.g. a greenhouse or room ventilation flap that only opens under actual heat + sunlight conditions.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| TMP36 Temperature Sensor | 1 |
| LDR (Light Dependent Resistor) | 1 |
| 10kΩ resistor (LDR voltage divider) | 1 |
| Servo Motor | 1 |
| LED | 1 |
| 220Ω resistor (LED) | 1 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### TMP36 Temperature Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| Signal (Vout) | A1 |

### LDR (voltage divider)
| Leg | Connects to |
|---|---|
| Leg 1 | 5V |
| Leg 2 | A0 + 10kΩ resistor → GND |

### Servo
| Wire | Connects to |
|---|---|
| Signal (orange/yellow) | D9 |
| VCC (red) | 5V |
| GND (brown/black) | GND |

### LED
| Leg | Connects to |
|---|---|
| Anode (+) | D8 (via 220Ω resistor) |
| Cathode (−) | GND |

## How It Works
1. **TMP36** reads analog voltage on A1, converted to °C using `(voltage - 0.5) * 100`.
2. **LDR** reads ambient light level on A0.
3. **Logic:**
   - If `temperature > 30°C` **and** `ldrValue > 500` (bright) → servo rotates to 90° (vent opens) and LED turns ON — "Ventilation ON".
   - Otherwise → servo returns to 0° (vent closed) and LED turns OFF — "Ventilation OFF".
4. Readings are logged to Serial Monitor every 500ms.

## Applications
- Greenhouse automated ventilation (opens vents when hot and sunny)
- Smart window/skylight flap controller
- Server room / electronics enclosure cooling trigger
- Poultry farm or livestock shed climate control
- Solar-aware HVAC assist system prototype

## Code
See [`02-Smart_Temperature_Light_Controlled_System.ino`](./02-Smart_Temperature_Light_Controlled_System.ino)
