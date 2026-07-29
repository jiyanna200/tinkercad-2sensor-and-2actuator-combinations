/*
10 - Smart Water Tank Monitoring System
Sensors: HC-SR04 Ultrasonic Sensor + Pushbutton (manual test/override)
Actuators: LED + Buzzer
*/

const int trigPin = 9;
const int echoPin = 10;
const int buttonPin = 2;
const int ledPin = 8;
const int buzzerPin = 7;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Measure Distance (tank water level, measured from top)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int buttonState = digitalRead(buttonPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 15 || buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.println("LOW WATER LEVEL");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Water Level Normal");
  }

  delay(500);
}
