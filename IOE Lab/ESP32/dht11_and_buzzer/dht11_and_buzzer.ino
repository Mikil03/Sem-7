#include "DHT.h"
#define DHT11PIN 21

DHT dht(DHT11PIN, DHT11);
void setup()
{
  
  Serial.begin(115200);
/* Start the DHT11 Sensor */
  dht.begin();
}

void loop()
{
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);
  delay(1000);
}

// #include "DHT.h"

// #define PIN_BUZZER     8 // ESP32 pin GPIO8 connected to the buzzer
// #define DHTPIN         4  
// #define DHTTYPE        DHT11

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(115200);
//   Serial.println(F("DHTxx, and Buzzer Test"));
//   dht.begin();
//   pinMode(PIN_BUZZER, OUTPUT);
// }

// void loop() {
//   // DHT11 Temperature and Humidity Sensor
//   float h = dht.readHumidity();
//   float t = dht.readTemperature();
//   float f = dht.readTemperature(true);

//   if (isnan(h) || isnan(t) || isnan(f)) {
//     Serial.println(F("Failed to read from DHT sensor!"));
//     return;
//   }

//   // Print DHT11 Data
//   Serial.print(F("DHT Humidity: "));
//   Serial.print(h);
//   Serial.print(F("%  Temperature: "));
//   Serial.print(t);
//   Serial.print(F("°C "));
//   Serial.print(f);
//   Serial.println(F("°F"));

//   // Check Humidity and activate buzzer if above 74
//   if (h > 74) {
//     digitalWrite(PIN_BUZZER, HIGH); // Turn on the buzzer
//     Serial.println(F("High Humidity Detected! Buzzer On"));
//   } else {
//     digitalWrite(PIN_BUZZER, LOW); // Turn off the buzzer
//   }
//   delay(2000);
// }