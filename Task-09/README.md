# Firmware v1.0 – Auto Irrigation System

## Objective
Develop firmware v1.0 for an automatic irrigation system that controls watering based on soil moisture threshold and supports manual override.

---

## Features
✔ Auto irrigation based on soil moisture  
✔ Manual override button control  
✔ Serial monitor commands support  
✔ Real-time system status display  
✔ Git version tagging (`v1.0-capstone`)

---

## Hardware Required
- ESP32
- Soil Moisture Sensor
- Relay Module
- Water Pump / Valve
- Push Button (Manual Override)
- Jumper Wires
- USB Cable

---

## System Working

### Auto Mode
- Reads soil moisture continuously.
- If soil value is below threshold → Pump turns ON.
- If threshold is reached → Pump turns OFF.

### Manual Override
- Press the button to manually toggle irrigation.
- Manual mode has higher priority than auto mode.

---

## Serial Commands

| Command | Function |
|----------|----------|
| `STATUS` | Display current system state |
| `FORCE_ON` | Turn irrigation ON manually |
| `FORCE_OFF` | Turn irrigation OFF manually |

Example:

```
STATUS
FORCE_ON
FORCE_OFF
```

---

## Pin Configuration

| Component | ESP32 Pin |
|-----------|----------|
| Soil Sensor | GPIO 34 |
| Relay | GPIO 26 |
| Manual Button | GPIO 14 |

*(Modify pins if your wiring is different.)*

---

## Threshold Configuration

```cpp
const int SOIL_THRESHOLD = 2000;
```

Adjust threshold after calibration.

---

## Program Flow

1. Start system
2. Initialize sensors
3. Read soil moisture
4. Compare with threshold
5. Auto control irrigation
6. Check manual override
7. Accept serial commands
8. Repeat

---

## Build & Upload

### Arduino IDE
1. Open project folder
2. Select **ESP32 Board**
3. Select COM Port
4. Upload sketch

---

## Testing

### Test 1 – Auto Irrigation
- Dry soil → Pump ON
- Wet soil → Pump OFF

### Test 2 – Manual Override
- Press button
- Verify pump toggles

### Test 3 – Serial Commands
Open Serial Monitor:

```
STATUS
FORCE_ON
FORCE_OFF
```

---

## Git Tag

Create release tag:

```bash
git tag v1.0-capstone
git push origin v1.0-capstone
```

Verify:

```bash
git tag
```

---

## Submission

Submit:

- Firmware source code
- Demo video (2–3 min) OR mentor checklist
- Git tag link

Example:

```
https://github.com/your-username/project/releases/tag/v1.0-capstone
```

---

## Author
Your Name
