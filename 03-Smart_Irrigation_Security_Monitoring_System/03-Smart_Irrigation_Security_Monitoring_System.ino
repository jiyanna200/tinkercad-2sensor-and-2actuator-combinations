/*
03 - Smart Irrigation and Security Monitoring System
Sensors: PIR Motion Sensor + Soil Moisture Sensor
Actuators: DC Motor (water pump) + 7-Segment Display
*/

#define PIR_PIN 7
#define SOIL_PIN A0
#define MOTOR_PIN 8

// 7-Segment Display pins (5 segments: a, d, e, f, g)
#define SEG_A 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 6

int soilDryThreshold = 500; // adjust based on sensor readings (lower = wetter, higher = drier)

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
}

void clearSegments() {
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
}

void displayE() {
  // Security alert -> "E"
  clearSegments();
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
}

void displaySafe() {
  clearSegments(); // blank -> all safe, no irrigation
}

void loop() {
  int motion = digitalRead(PIR_PIN);
  int soilValue = analogRead(SOIL_PIN);

  bool intrusion = (motion == HIGH);
  bool soilDry = (soilValue > soilDryThreshold);

  // Motor runs pump when soil is dry
  digitalWrite(MOTOR_PIN, soilDry ? HIGH : LOW);

  // Display shows "E" if intrusion detected, else blank
  if (intrusion) {
    displayE();
  } else {
    displaySafe();
  }

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" Soil: ");
  Serial.print(soilValue);
  Serial.print(" Pump: ");
  Serial.print(soilDry ? "ON" : "OFF");
  Serial.print(" Security: ");
  Serial.println(intrusion ? "ALERT" : "Safe");

  delay(500);
}
