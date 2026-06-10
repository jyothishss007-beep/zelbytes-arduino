
# Calibration Table

## Sensor Calibration Summary

| Sensor | Calibration Parameter | Value | Method |
|----------|----------|----------|----------|
| LDR | DARK_THRESHOLD | 300 ADC | Determined from dark condition readings |
| LDR | BRIGHT_THRESHOLD | 700 ADC | Defined bright-light threshold |
| DHT22 | Read Interval | 2000 ms | Required by DHT22 specifications |
| Ultrasonic HC-SR04 | Timeout | 30000 µs | Returns -1 when no echo is received |
| Soil Moisture | DRY_ADC | 820 ADC | Firmware calibration constant |
| Soil Moisture | WET_ADC | 380 ADC | Firmware calibration constant |

---

# LDR Calibration

## Observed Values

| Condition | Raw ADC Reading |
|------------|----------------|
| Dark | 219 |
| Dark | 273 |
| Dark | 299 |
| Ambient | 399 |
| Ambient | 409 |
| Ambient | 411 |
| Ambient | 426 |
| Ambient | 442 |
| Ambient | 443 |
| Ambient | 475 |

## Thresholds Used

| Parameter | Value |
|------------|--------|
| DARK_THRESHOLD | 300 |
| BRIGHT_THRESHOLD | 700 |

## Interpretation

| ADC Range | Classification |
|------------|----------------|
| < 300 | DARK |
| 300 - 700 | AMBIENT |
| > 700 | BRIGHT |

---

# DHT22 Validation

## Sample Readings

| Temperature (°C) | Humidity (%) |
|------------------|--------------|
| 33.2 | 73.4 |
| 33.3 | 73.3 |
| 33.3 | 73.4 |
| 33.3 | 73.5 |

## Configuration

| Parameter | Value |
|------------|--------|
| Data Pin | D4 |
| Read Interval | 2000 ms |
| Output Format | CSV Serial Output |

---

# HC-SR04 Ultrasonic Validation

## Sample Measurements

| Measured Distance (cm) |
|------------------------|
| 314.6 |
| 316.1 |
| 316.9 |
| -1.0 (Timeout / No Echo) |

## Notes

- Timeout set to 30000 µs.
- Invalid measurements are reported as -1.
- Sensor range approximately 2–400 cm.

---

# Soil Moisture Calibration

## Calibration Constants

| Parameter | Value |
|------------|--------|
| DRY_ADC | 820 |
| WET_ADC | 380 |

## Sample Readings

| Raw ADC | Moisture (%) | Condition |
|----------|-------------|-----------|
| 454 | 83 | WET |
| 454 | 83 | WET |
| 452 | 83 | WET |
| 453 | 83 | WET |
| 451 | 83 | WET |
| 438 | 86 | WET |
| 425 | 89 | WET |

## Moisture Classification

| Moisture (%) | Condition |
|--------------|-----------|
| 0 - 29 | DRY |
| 30 - 69 | MOIST |
| 70 - 100 | WET |

## Moisture Mapping

```cpp
moisture = map(raw, DRY_ADC, WET_ADC, 0, 100);
425	89              	WET
Moisture Classification
Moisture (%)	Condition
0 - 29	      DRY
30 - 69     	MOIST
70 - 100	     WET
