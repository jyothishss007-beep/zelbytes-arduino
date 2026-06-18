# System Architecture

## Overview

The Automated Grow-Bench Prototype monitors soil moisture using an ESP32 and automatically controls a water pump through a relay.

The system sends telemetry data to the Zelbytes IoT Lab cloud and displays real-time information on a Streamlit dashboard.

---

## Hardware Components

- ESP32 Dev Module
- Soil Moisture Sensor
- Relay Module
- Push Button
- LED Indicator
- Water Pump (simulated through relay)

---

## Software Components

### ESP32 Firmware

Functions:

- Read soil moisture sensor
- Automatic irrigation based on threshold
- Manual override button
- Serial commands:
  - STATUS
  - FORCE_ON
  - FORCE_OFF
- Send telemetry to Zelbytes API
- Host web server for relay control

### Dashboard

Functions:

- Display latest soil moisture value
- Show moisture condition
- Relay ON/OFF control
- Relay status monitoring
- Historical data table
- Soil moisture trend chart

---

## Data Flow

Soil Sensor
↓
ESP32
↓
Zelbytes IoT API
↓
Streamlit Dashboard

Dashboard
↓
ESP32 Web Server
↓
Relay Control

---

## Operating Modes

### Auto Mode

Pump turns ON when soil moisture falls below threshold.

Pump turns OFF when soil moisture is sufficient.

### Manual Mode

User can control relay using:

- Push button
- Dashboard controls
- Serial commands
