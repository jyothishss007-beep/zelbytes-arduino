# Threshold Configuration

## Soil Moisture Thresholds

SOIL_MIN = 25%

SOIL_TARGET = 40%

## Humidity Threshold

HUMIDITY_MAX = 85%

## Debounce Setting

LOW_COUNT_REQ = 3

## Timing Parameters

MAX_RUN_TIME = 10000 ms

COOLDOWN_TIME = 5000 ms

## Hysteresis Logic

Irrigation starts when soil moisture falls below 25%.

Irrigation stops when soil moisture reaches 40%.

Using separate ON and OFF thresholds prevents rapid relay switching near the threshold value.
