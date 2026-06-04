const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial) { ; }  // wait for USB on some boards
  Serial.println(F("Zelbytes Arduino Foundations — Day 1"));
  Serial.println(F("Board: check Tools > Board matches hardware"));
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
Pin inventory helper (serial only)
cpp
Copy
// Prints reserved pins — run once, read Serial Monitor
void setup() {
  Serial.begin(9600);
  Serial.println(F("Analog pins A0-A5 map to digital 14-19"));
  Serial.println(F("Avoid pins 0/1 when using USB Serial"));
}
void loop() {}
