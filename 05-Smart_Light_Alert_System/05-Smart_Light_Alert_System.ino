/*
05 - Smart Light and Alert System
Sensor: LDR (Light Dependent Resistor)
Actuators: 3x LED (Red, Yellow, Green) + Buzzer
*/

const int ldrPin = A0;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int buzzer = 5;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.print("Light Value: ");
  Serial.println(lightValue);

  if (lightValue < 200) {
    // Very dark
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else if (lightValue < 500) {
    // Medium light
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, LOW);
  }
  else {
    // Bright
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
