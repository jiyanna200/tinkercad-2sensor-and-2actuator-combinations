# 10 - Smart Water Tank Monitoring System

A water tank level monitor that uses ultrasonic distance sensing (mounted at the top of the tank) to detect low water levels, with a manual pushbutton to force-trigger the alert for testing.

## Components
| Component | Qty |
|---|---|
| Arduino UNO | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Pushbutton | 1 |
| LED | 1 |
| 220Ω resistor (LED) | 1 |
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
| + | D7 |
| − | GND |

## How It Works
1. **HC-SR04** is mounted at the top of the tank, measuring the distance down to the water surface.
2. As water level drops, the measured distance increases.
3. **Alert logic:** LED and buzzer turn ON if **either** condition is true — distance exceeds 15 cm (indicating low water) **or** the pushbutton is manually pressed (test/override) — "LOW WATER LEVEL".
4. If the tank is sufficiently full and the button isn't pressed → LED and buzzer stay OFF — "Water Level Normal".
5. Distance readings are logged to Serial Monitor every 500ms.

## Applications
- Residential/rooftop water tank low-level alert system
- Overhead tank monitoring for homes, hostels, or apartment complexes
- Agricultural water storage tank monitoring
- Industrial tank/reservoir level alarm with manual test capability
- Base circuit for extending into a full automatic water pump refill system

## Code
See [`10-Smart_Water_Tank_Monitoring_System.ino`](./10-Smart_Water_Tank_Monitoring_System.ino)
