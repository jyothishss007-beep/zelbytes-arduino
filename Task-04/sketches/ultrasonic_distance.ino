const int trigPin = 9;
const int echoPin = 10;

long duration;
float distanceCm;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.println("HC-SR04 Ultrasonic Sensor Test");
}

void loop() {
  // Clear TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 µs pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read ECHO pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distanceCm = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(500);
}
