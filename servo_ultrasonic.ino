#include <Servo.h>

Servo servo;

const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 9;

void setup() {
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.write(0);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  if (distance <= 10) {
    servo.write(90);
  } else {
    servo.write(0);
  }

  delay(100);
}