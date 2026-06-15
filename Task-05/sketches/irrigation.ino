#include <DHT.h>

#define SOIL_PIN   A0
#define DHTPIN     2
#define DHTTYPE    DHT11

#define RELAY_PIN  9
#define LED_PIN    13

DHT dht(DHTPIN, DHTTYPE);

enum State {
  IDLE,
  IRRIGATING,
  COOLDOWN,
  FAULT
};

State currentState = IDLE;

// Adjust after calibration
const int soilThreshold = 400;

// Timing
const unsigned long irrigationTime = 5000; // 5 sec
const unsigned long cooldownTime = 10000;  // 10 sec

unsigned long stateStartTime = 0;

int dhtFailCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Initial state
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  Serial.println("System Started");
  Serial.println("STATE -> IDLE");
}

void loop() {

  // Read soil moisture
  int soilValue = analogRead(SOIL_PIN);

  // Read DHT humidity (used for fault detection)
  float humidity = dht.readHumidity();

  Serial.print("Soil Moisture: ");
  Serial.println(soilValue);

  // Check DHT failures
  if (isnan(humidity)) {

    dhtFailCount++;

    Serial.print("DHT Error Count: ");
    Serial.println(dhtFailCount);

    if (dhtFailCount >= 3) {
      currentState = FAULT;
      Serial.println("STATE -> FAULT");
    }

  } else {
    dhtFailCount = 0;
  }

  switch (currentState) {

    // ---------------- IDLE ----------------
    case IDLE:

      digitalWrite(RELAY_PIN, LOW); // Valve closed
      digitalWrite(LED_PIN, LOW);   // LED OFF

      // Dry soil detected
      if (soilValue > soilThreshold && dhtFailCount == 0) {

        currentState = IRRIGATING;
        stateStartTime = millis();

        Serial.println("Dry Soil Detected");
        Serial.println("STATE -> IRRIGATING");

        digitalWrite(RELAY_PIN, HIGH); // Open valve
        digitalWrite(LED_PIN, HIGH);   // LED ON
      }

      break;

    // ------------- IRRIGATING -------------
    case IRRIGATING:

      digitalWrite(RELAY_PIN, HIGH); // Valve open
      digitalWrite(LED_PIN, HIGH);   // LED ON

      if (millis() - stateStartTime >= irrigationTime) {

        digitalWrite(RELAY_PIN, LOW); // Close valve
        digitalWrite(LED_PIN, LOW);

        currentState = COOLDOWN;
        stateStartTime = millis();

        Serial.println("Watering Complete");
        Serial.println("STATE -> COOLDOWN");
      }

      break;

    // ------------- COOLDOWN ---------------
    case COOLDOWN:

      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);

      if (millis() - stateStartTime >= cooldownTime) {

        currentState = IDLE;

        Serial.println("Cooldown Complete");
        Serial.println("STATE -> IDLE");
      }

      break;

    // --------------- FAULT ----------------
    case FAULT:

      digitalWrite(RELAY_PIN, LOW); // Valve closed

      // Blink LED
      digitalWrite(LED_PIN, HIGH);
      delay(250);
      digitalWrite(LED_PIN, LOW);
      delay(250);

      Serial.println("FAULT: DHT Sensor Failure");

      break;
  }

  delay(500);
}
