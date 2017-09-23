#include <Servo.h>
int servo = 3;
int engineLeft = 5;
int engineRight = 6;
int engineBack = 2;
int photoRight = 1;
int photoLeft = 0;
int light = 4;
Servo servoMotor;
long duration = 180;
int inches;
int cm;
void setup()
{
  // pinMode(4, OUTPUT);
  pinMode(photoRight, INPUT);
  pinMode(photoLeft, INPUT);
  pinMode(engineLeft, OUTPUT);
  pinMode(engineRight, OUTPUT);
  pinMode(engineBack, OUTPUT);
  pinMode(light, OUTPUT);
  servoMotor.attach(servo);
}

void loop()
{

  if (analogRead(photoRight) < 512 && analogRead(photoLeft) < 512)
  {
    moveAlong();
  }
  else if (analogRead(photoRight) > 512 && analogRead(photoLeft) < 512)
  {
    moveRight();
  }
  else if (analogRead(photoRight) < 512 && analogRead(photoLeft) > 512)
  {
    moveLeft();
  }
  else if (analogRead(photoRight) > 512 && analogRead(photoLeft) > 512)
  {
    moveBack();
  }
  else
  {
    stop();
  }
  // else if (analogRead(photoRight) > 512)
  // {
  //   digitalWrite(engineRight, HIGH);
  //   digitalWrite(engineLeft, LOW);
  // }

  // inches = microsecondsToInches(duration);
  // cm = microsecondsToCentimeters(duration);
  // servoMotor.write(inches);

  // digitalWrite(4, HIGH);
  // delay(1000); // Wait for 1000 millisecond(s)
  // digitalWrite(4, LOW);
  // delay(1000); // Wait for 1000 millisecond(s)
  delay(10);
}
void moveAlong()
{
  digitalWrite(engineRight, HIGH);
  digitalWrite(engineLeft, HIGH);
  digitalWrite(engineBack, LOW);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  digitalWrite(light, LOW);
  
  servoMotor.write(90);
}
void moveRight()
{
  digitalWrite(engineRight, HIGH);
  digitalWrite(engineLeft, HIGH);
  digitalWrite(engineBack, LOW);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  digitalWrite(light, LOW);
  
  servoMotor.write(45);
}
void moveLeft()
{
  digitalWrite(engineRight, HIGH);
  digitalWrite(engineLeft, HIGH);
  digitalWrite(engineBack, LOW);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  digitalWrite(light, LOW);
  servoMotor.write(135);
}
void moveBack()
{
  digitalWrite(engineRight, LOW);
  digitalWrite(engineLeft, LOW);
  digitalWrite(engineBack, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  digitalWrite(light, HIGH);
  servoMotor.write(90);
}
void stop()
{
  digitalWrite(engineRight, LOW);
  digitalWrite(engineLeft, LOW);
}
long microsecondsToInches(long microseconds)
{

  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{

  return microseconds / 29 / 2;
}