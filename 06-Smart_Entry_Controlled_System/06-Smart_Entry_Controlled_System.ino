/*
06 - Smart Entry Controlled System
Sensors: HC-SR04 Ultrasonic Sensor + Pushbutton
Actuators: Servo (gate) + LED
*/

#include <Servo.h>
Servo gateServo;

const int trigPin = 9;
const int echoPin = 10;
const int buttonPin = 2;
const int ledPin = 8;

long duration;
int distance;

void setup()
{
  gateServo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Read button
  int buttonState = digitalRead(buttonPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm  ");
  Serial.print("Button: ");
  Serial.println(buttonState);

  if (distance < 15 && buttonState == LOW)
  {
    gateServo.write(90);
    digitalWrite(ledPin, HIGH);
    Serial.println("Access Granted");
  }
  else
  {
    gateServo.write(0);
    digitalWrite(ledPin, LOW);
    Serial.println("Access Denied");
  }

  delay(500);
}
