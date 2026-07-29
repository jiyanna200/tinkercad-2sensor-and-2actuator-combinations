/*
08 - Smart Garage Door Control System
Sensors: HC-SR04 Ultrasonic Sensor + LDR
Actuators: Servo (garage door) + LED
*/

#include <Servo.h>
Servo gateServo;

const int trigPin = 9;
const int echoPin = 10;
const int ldrPin = A0;
const int ledPin = 8;

long duration;
int distance;

void setup()
{
  gateServo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read LDR
  int ldrValue = analogRead(ldrPin);

  // Measure Distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm  ");
  Serial.print("LDR: ");
  Serial.println(ldrValue);

  if (distance < 15 && ldrValue > 500)
  {
    gateServo.write(90);
    digitalWrite(ledPin, HIGH);
    Serial.println("Garage Open");
  }
  else
  {
    gateServo.write(0);
    digitalWrite(ledPin, LOW);
    Serial.println("Garage Closed");
  }

  delay(500);
}
