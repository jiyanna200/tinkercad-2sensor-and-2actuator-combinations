# 03 - Smart Irrigation and Security Monitoring System

A dual-purpose system that automates plant irrigation based on soil dryness while simultaneously monitoring for security intrusions using motion detection — with status shown on a 7-segment display.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| PIR Motion Sensor | 1 |
| Soil Moisture Sensor | 1 |
| DC Motor (water pump) | 1 |
| 7-Segment Display (5 segments used) | 1 |
| 220Ω resistors (segments) | 5 |

## Circuit Diagram
See [`circuit_sketch.png`](./circuit_sketch.png)

## Wiring

### PIR Motion Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT (signal) | D7 |

### Soil Moisture Sensor
| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| A0 (signal) | A0 |

### DC Motor (water pump)
| Pin | Connects to |
|---|---|
| + | D8 |
| − | GND |

### 7-Segment Display (5 segments: a, d, e, f, g)
| Segment | Connects to |
|---|---|
| a | D2 (via 220Ω) |
| d | D3 (via 220Ω) |
| e | D4 (via 220Ω) |
| f | D5 (via 220Ω) |
| g | D6 (via 220Ω) |
| Common cathode | GND |

> Note: Only 5 of the 7 segments (a, d, e, f, g) are wired — enough to form an "E" (alert) shape or a blank (safe) display. Segments b and c are unused.

## How It Works
1. **Soil Moisture Sensor** continuously reads soil dryness via `analogRead(A0)`.
   - If the reading exceeds `soilDryThreshold` (500) → soil is dry → **DC Motor (pump) turns ON** to irrigate.
   - Otherwise → pump stays OFF.
2. **PIR Sensor** independently monitors for motion.
   - If motion is detected → **7-segment display shows "E"** (security alert).
   - If no motion → display stays blank (safe).
3. Both systems run in parallel and independently — irrigation status does not affect security status or vice versa.
4. All readings (motion, soil moisture, pump state, security state) are logged to Serial Monitor every 500ms.

## Applications
- Combined smart-farm irrigation + perimeter security monitoring
- Greenhouse automation with intrusion alerting
- Remote farmland plots needing both watering automation and theft/animal-intrusion detection
- Home garden automation with basic security awareness
- Low-cost dual-purpose IoT agriculture prototype

## Code
See [`03-Smart_Irrigation_Security_Monitoring_System.ino`](./03-Smart_Irrigation_Security_Monitoring_System.ino)
