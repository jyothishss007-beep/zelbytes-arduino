# Testing Report

## Test Cases

| Test ID | Test Description | Expected Result | Status |
|----------|-----------------|----------------|---------|
| T1 | ESP32 connects to WiFi | IP address displayed in Serial Monitor | PASS |
| T2 | Soil moisture sensor reading | Valid moisture percentage shown | PASS |
| T3 | Auto irrigation mode | Relay turns ON when soil is dry | PASS |
| T4 | Auto irrigation mode | Relay turns OFF when moisture is sufficient | PASS |
| T5 | Manual button override | Relay state changes on button press | PASS |
| T6 | STATUS command | Current status displayed in Serial Monitor | PASS |
| T7 | FORCE_ON command | Pump turns ON | PASS |
| T8 | FORCE_OFF command | Pump turns OFF | PASS |
| T9 | Telemetry upload | POST Code 202 received | PASS |
| T10 | Dashboard data display | Latest soil moisture shown | PASS |
| T11 | Relay ON from dashboard | Relay activated successfully | PASS |
| T12 | Relay OFF from dashboard | Relay deactivated successfully | PASS |

---

## Test Evidence

### Serial Monitor

- WiFi Connected
- ESP32 IP Address displayed
- POST Code: 202

### Dashboard

- Soil moisture value displayed
- Relay controls functional
- Historical logs displayed
- Moisture trend chart displayed

---

## Result

All required Task 9 functionalities were tested successfully and produced expected results.
