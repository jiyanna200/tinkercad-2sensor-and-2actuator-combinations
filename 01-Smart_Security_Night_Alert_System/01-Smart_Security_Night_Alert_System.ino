// 01 - Smart Security and Night Alert System
// Sensors: LDR + PIR Motion Sensor
// Actuators: LED + Buzzer

int ldrPin = A0;
int pirPin = 2;
int ledPin = 8;
int buzzerPin = 9;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int ldrValue = analogRead(ldrPin);
  int motion = digitalRead(pirPin);

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print("  PIR: ");
  Serial.println(motion);

  if (ldrValue < 300 && motion == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Motion Detected in Dark");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Safe");
  }

  delay(500);
}
