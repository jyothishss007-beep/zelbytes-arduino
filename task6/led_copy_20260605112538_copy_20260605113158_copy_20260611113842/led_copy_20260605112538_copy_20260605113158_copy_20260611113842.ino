const int ledPin = 8;
const int buttonPin = 2;

bool ledState = false;

int lastReading = HIGH;
int stableState = HIGH;

unsigned long lastChange = 0;

const int debounceDelay = 50;

void setup() {

  pinMode(ledPin, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  int reading =
      digitalRead(buttonPin);

  if (reading != lastReading) {

    lastChange = millis();
  }

  if ((millis() - lastChange)
       > debounceDelay) {

    if (reading != stableState) {

      stableState = reading;

      if (stableState == LOW) {

        ledState = !ledState;

        digitalWrite(
          ledPin,
          ledState
        );

        Serial.println(
          "Button Pressed"
        );
      }
    }
  }

  lastReading = reading;
}