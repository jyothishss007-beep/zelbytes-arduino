#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>

#define SOIL_PIN 34
#define RELAY_PIN 26
#define BUTTON_PIN 27
#define LED_PIN 2

const int DRY_THRESHOLD = 2000;

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

const char* apiKey = "YOUR_API_KEY";
const char* serverURL = "https://careers.zelbytes.com/api/iot-lab/v1/telemetry";

bool pumpState = false;
bool manualMode = false;

WebServer webServer(80);

void connectWiFi() {

  WiFi.begin(ssid, password);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
}

void relayON() {

  manualMode = true;
  pumpState = true;

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, HIGH);

  webServer.send(200, "text/plain", "Relay ON");
}

void relayOFF() {

  manualMode = true;
  pumpState = false;

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN, LOW);

  webServer.send(200, "text/plain", "Relay OFF");
}

void relaySTATUS() {

  String statusText = pumpState ? "ON" : "OFF";

  webServer.send(200, "text/plain", statusText);
}

void sendTelemetry(int soilPercent) {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    http.begin(serverURL);

    http.addHeader("Content-Type", "application/json");
    http.addHeader("X-Iot-Lab-Key", apiKey);

    String payload =
      "{\"soil_moisture_pct\":" +
      String(soilPercent) +
      "}";

    int code = http.POST(payload);

    Serial.print("POST Code: ");
    Serial.println(code);

    http.end();
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN, LOW);

  connectWiFi();

  webServer.on("/on", relayON);
  webServer.on("/off", relayOFF);
  webServer.on("/status", relaySTATUS);

  webServer.begin();

  Serial.println("Web Server Started");
}

void loop() {

  webServer.handleClient();

  int rawSoil = analogRead(SOIL_PIN);

  int soilPercent = map(rawSoil, 4095, 0, 0, 100);
  soilPercent = constrain(soilPercent, 0, 100);

  if (digitalRead(BUTTON_PIN) == LOW) {

    manualMode = !manualMode;
    pumpState = !pumpState;

    delay(300);
  }

  if (!manualMode) {

    if (rawSoil > DRY_THRESHOLD)
      pumpState = true;
    else
      pumpState = false;
  }

  digitalWrite(RELAY_PIN, pumpState ? LOW : HIGH);
  digitalWrite(LED_PIN, pumpState);

  if (Serial.available()) {

    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "STATUS") {

      Serial.println("=== STATUS ===");

      Serial.print("Soil Moisture %: ");
      Serial.println(soilPercent);

      Serial.print("Pump: ");
      Serial.println(pumpState ? "ON" : "OFF");

      Serial.print("Mode: ");
      Serial.println(manualMode ? "MANUAL" : "AUTO");
    }

    else if (cmd == "FORCE_ON") {

      manualMode = true;
      pumpState = true;
    }

    else if (cmd == "FORCE_OFF") {

      manualMode = true;
      pumpState = false;
    }
  }

  sendTelemetry(soilPercent);

  delay(3000);
}
