// 02 - Smart Temperature and Light Controlled System
// Sensors: TMP36 Temperature Sensor + LDR
// Actuators: Servo + LED

#include <Servo.h>
Servo myServo;

const int tempPin = A1;
const int ldrPin = A0;
const int ledPin = 8;

void setup()
{
  myServo.attach(9);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read temperature
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  // Read light level
  int ldrValue = analogRead(ldrPin);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  ");
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  if (temperature > 30 && ldrValue > 500)
  {
    myServo.write(90);
    digitalWrite(ledPin, HIGH);
    Serial.println("Ventilation ON");
  }
  else
  {
    myServo.write(0);
    digitalWrite(ledPin, LOW);
    Serial.println("Ventilation OFF");
  }

  delay(500);
}
