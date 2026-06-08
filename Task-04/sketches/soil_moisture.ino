const uint8_t MOIST_PIN = A1;
const uint8_t MOIST_PWR = 7;

const int DRY_ADC = 820;
const int WET_ADC = 380;

int readMoistRaw() {
  digitalWrite(MOIST_PWR, HIGH);
  delay(10);
  int v = analogRead(MOIST_PIN);
  digitalWrite(MOIST_PWR, LOW);
  return v;
}

int toPercent(int raw) {
  return constrain(map(raw, DRY_ADC, WET_ADC, 0, 100), 0, 100);
}

void setup() {
  pinMode(MOIST_PWR, OUTPUT);
  digitalWrite(MOIST_PWR, LOW);

  Serial.begin(9600);
  Serial.println("Soil Moisture Sensor Test");
}

void loop() {
  int raw = readMoistRaw();
  int moisture = toPercent(raw);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("  Moisture: ");
  Serial.print(moisture);
  Serial.print("%  Condition: ");

  if (moisture < 30) {
    Serial.println("DRY");
  }
  else if (moisture < 70) {
    Serial.println("MOIST");
  }
  else {
    Serial.println("WET");
  }

  delay(1000);
}
