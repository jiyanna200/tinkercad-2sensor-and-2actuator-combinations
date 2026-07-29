/*
11 - Smart Brightness Control System
Sensors: LDR + Potentiometer (adjustable threshold)
Actuators: RGB LED + Buzzer
*/

const int ldrPin = A0;
const int potPin = A1;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buzzerPin = 8;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int ldrValue = analogRead(ldrPin);
  int threshold = analogRead(potPin);

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" Threshold: ");
  Serial.println(threshold);

  if (ldrValue < threshold)
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Dark - Alert");
  }
  else
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Bright - Safe");
  }

  delay(500);
}
