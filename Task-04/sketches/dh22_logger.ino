dht 
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);

unsigned long lastReadTime = 0;
const unsigned long READ_INTERVAL = 2000; // 2 seconds

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("DHT22 Temperature and Humidity Monitor");
  Serial.println("Time(ms),Temperature(C),Humidity(%)");
}

void loop() {
  if (millis() - lastReadTime < READ_INTERVAL) {
    return;
  }

  lastReadTime = millis();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  unsigned long seconds = millis() / 1000;

Serial.print("[");
Serial.print(seconds);
Serial.print(" s] ");
Serial.print("Temperature: ");
Serial.print(temperature, 1);
Serial.print(" C, Humidity: ");
Serial.print(humidity, 1);
Serial.println(" %");
}
