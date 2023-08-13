#include <dht.h>        // Include library
#define outPin 3       // Defines pin number to which the sensor is connected

dht DHT;                // Creates a DHT object

int buzzerPin = 8;

void setup() {
	pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

	int readData = DHT.read11(outPin);

	float t = DHT.temperature;        // Read temperature
	float h = DHT.humidity;           // Read humidity

	Serial.print("Temperature = ");
	Serial.print(t);
	Serial.print("°C | ");

	Serial.print("Humidity = ");
	Serial.print(h);

	Serial.println("% ");
	Serial.println("");
  if(h>88)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
  }
	delay(2000); // wait two seconds
}