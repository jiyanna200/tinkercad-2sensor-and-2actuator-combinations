/*
09 - Smart Restricted Area Security System
Sensors: PIR Motion Sensor + Pushbutton (manual alert trigger)
Actuators: Servo (barrier/gate) + Buzzer
*/

#include <Servo.h>
Servo gateServo;

const int pirPin = 2;
const int buttonPin = 3;
const int buzzerPin = 8;

void setup()
{
  gateServo.attach(6);
  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  gateServo.write(0);
}

void loop()
{
  int motion = digitalRead(pirPin);
  int button = digitalRead(buttonPin);

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print("  Button: ");
  Serial.println(button);

  if (motion == HIGH || button == LOW)
  {
    gateServo.write(90);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Restricted Area Alert");
  }
  else
  {
    gateServo.write(0);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Area Secure");
  }

  delay(500);
}
