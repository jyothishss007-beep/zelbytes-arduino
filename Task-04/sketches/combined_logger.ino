#include <DHT.h>

// DHT22
#define DHT_PIN 4
#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

// Ultrasonic
const int trigPin = 9;
const int echoPin = 10;

// Soil Moisture
const int MOIST_PIN = A1;
const int MOIST_PWR = 7;

// Functions
int readMoistRaw() {
  digitalWrite(MOIST_PWR, HIGH);
  delay(10);

  int value = analogRead(MOIST_PIN);

  digitalWrite(MOIST_PWR, LOW);

  return value;
}

float readDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2.0;
}

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(MOIST_PWR, OUTPUT);
  digitalWrite(MOIST_PWR, LOW);

  Serial.println("millis,temp,humidity,distance_cm,soil_raw");
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  float distance = readDistance();

  int moistRaw = readMoistRaw();

  Serial.print(millis());
  Serial.print(",");

  Serial.print(temperature, 1);
  Serial.print(",");

  Serial.print(humidity, 1);
  Serial.print(",");

  Serial.print(distance, 1);
  Serial.print(",");

  Serial.println(moistRaw);

  delay(2000);
}
