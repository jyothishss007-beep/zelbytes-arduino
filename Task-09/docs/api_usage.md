# API Usage

## Telemetry Upload

ESP32 sends soil moisture data to the Zelbytes IoT Lab API using HTTP POST.

### Endpoint

https://careers.zelbytes.com/api/iot-lab/v1/telemetry

### Headers

Content-Type: application/json

X-Iot-Lab-Key: <API_KEY>

### Example Payload

{
  "soil_moisture_pct": 89
}

### Response

HTTP Status Code: 202 Accepted

A POST Code 202 in Serial Monitor confirms successful telemetry submission.

---

## Telemetry Retrieval

The dashboard fetches the latest telemetry using:

https://careers.zelbytes.com/api/iot-lab/v1/telemetry/latest

### Method

GET

### Header

X-Iot-Lab-Key: <API_KEY>

### Dashboard Features

- Display current soil moisture
- Moisture status indicator
- Relay control buttons
- Historical logs table
- Soil moisture trend chart
