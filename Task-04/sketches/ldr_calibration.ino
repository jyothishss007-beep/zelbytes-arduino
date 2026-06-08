const uint8_t LDR_PIN = A0;
const float VREF = 5.0;

// Adjust after calibration
const int DARK_THRESHOLD = 300;
const int BRIGHT_THRESHOLD = 700;

int readAveraged(uint8_t pin, uint8_t samples = 8) {
  long sum = 0;

  for (uint8_t i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(2);
  }

  return sum / samples;
}

void setup() {
  Serial.begin(9600);
  Serial.println(F("raw,voltage,light_level"));
}

void loop() {

  int raw = readAveraged(LDR_PIN);

  float voltage = raw * (VREF / 1023.0);

  String level;

  if (raw < DARK_THRESHOLD) {
    level = "DARK";
  }
  else if (raw > BRIGHT_THRESHOLD) {
    level = "BRIGHT";
  }
  else {
    level = "AMBIENT";
  }

  Serial.print(raw);
  Serial.print(",");

  Serial.print(voltage, 3);
  Serial.print(",");

  Serial.println(level);

  delay(1000);
}
