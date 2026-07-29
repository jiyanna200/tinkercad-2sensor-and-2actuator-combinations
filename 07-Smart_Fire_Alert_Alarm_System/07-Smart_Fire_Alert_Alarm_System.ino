/*
07 - Smart Fire Alert Alarm System
Sensors: TMP36 Temperature Sensor + Pushbutton (manual alarm trigger)
Actuators: LED + Buzzer
*/

const int tempPin = A0;
const int buttonPin = 2;
const int ledPin = 8;
const int buzzerPin = 9;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  int buttonState = digitalRead(buttonPin);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  ");
  Serial.print("Button: ");
  Serial.println(buttonState);

  if (temperature > 30 || buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Fire Alert!");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Normal");
  }

  delay(500);
}
