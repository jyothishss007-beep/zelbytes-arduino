Project Title
Analog Sensor Calibration Suite

Development Board
Parameter	Specification
Board	Arduino Uno
Operating Voltage	5V
Serial Baud Rate	9600
Components Used
Component	Quantity
Arduino Uno	1
LDR (Light Dependent Resistor)	1
10kΩ Resistor	1
DHT22 Temperature & Humidity Sensor	1
HC-SR04 Ultrasonic Sensor	1
Capacitive Soil Moisture Sensor v1.2	1
Breadboard	1
Jumper Wires	As Required
Pin Configuration
Sensor	Arduino Pin
LDR	A0
DHT22 Data	D4
HC-SR04 TRIG	D9
HC-SR04 ECHO	D10
Soil Moisture AOUT	A1
Soil Moisture Power	D7
Sensor Descriptions
LDR (Light Dependent Resistor)
Purpose: Measure ambient light intensity.

Calibration Parameters

Parameter	Value
DARK_THRESHOLD	300
BRIGHT_THRESHOLD	700
DHT22 Temperature & Humidity Sensor
Purpose: Measure temperature and humidity.

Parameter	Value
Data Pin	D4
Read Interval	2000 ms
HC-SR04 Ultrasonic Sensor
Purpose: Measure distance using ultrasonic pulses.

Parameter	Value
TRIG Pin	D9
ECHO Pin	D10
Timeout	30000 µs
Capacitive Soil Moisture Sensor v1.2
Purpose: Measure relative soil moisture.

Parameter	Value
Analog Pin	A1
Power Pin	D7
DRY_ADC	820
WET_ADC	380
Operating Conditions
Parameter	Value
Supply Voltage	5V
Controller	Arduino Uno
Communication	USB Serial
Baud Rate	9600
Summary
The system consists of:

LDR for ambient light measurement
DHT22 for temperature and humidity monitoring
HC-SR04 for distance measurement
Capacitive Soil Moisture Sensor for soil moisture detection
All sensors were tested individually and later integrated into a unified logging module producing CSV-style serial output for calibration and analysis.
