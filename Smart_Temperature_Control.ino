#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin, OUTPUT);
}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Sensor Error");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  if (temp > 30) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Status : HIGH TEMPERATURE");
    Serial.println("LED : ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Status : NORMAL");
    Serial.println("LED : OFF");
  }

  Serial.println("---------------------");

  delay(2000);
}
