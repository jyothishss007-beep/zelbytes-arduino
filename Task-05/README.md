## Test Log – One Full Irrigation Cycle

### Test Conditions
- Soil Threshold = 400
- Irrigation Time = 5 seconds
- Cooldown Time = 10 seconds
- DHT11 Sensor working normally

### Serial Monitor Output

```text
System Started
STATE -> IDLE

Soil Moisture: 512
Dry Soil Detected
STATE -> IRRIGATING

Soil Moisture: 505
Soil Moisture: 498
Soil Moisture: 492

Watering Complete
STATE -> COOLDOWN

Soil Moisture: 380
Soil Moisture: 375

Cooldown Complete
STATE -> IDLE
```

### State Transitions

```text
IDLE
  ↓
IRRIGATING
  ↓
COOLDOWN
  ↓
IDLE
```

### Result

PASS

- Dry soil condition (512 > 400) triggered irrigation.
- Relay activated and valve opened.
- Irrigation ran for 5 seconds.
- System entered COOLDOWN state.
- Cooldown completed after 10 seconds.
- System returned to IDLE state.
- One complete irrigation cycle executed successfully.
