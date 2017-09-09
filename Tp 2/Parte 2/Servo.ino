#include <Servo.h>
const int trigPin = 11;
const int echoPin = 11;
Servo servoMotor;
void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  servoMotor.attach(13);
}

void loop()
{
  long duration, inches, cm;

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  servoMotor.write(inches);
  delay(100);
}

long microsecondsToInches(long microseconds)
{

  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{

  return microseconds / 29 / 2;
}