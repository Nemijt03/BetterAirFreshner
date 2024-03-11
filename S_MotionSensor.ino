int sensorPin = 2;
byte hasMoved = 0;

void setupMotionSensor()
{
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensorPin), triggerMove, RISING);
}

int getMotion()
{
  return hasMoved;
}

void triggerMove()
{
  if (state != NOTINUSE)
    hasMoved = 1;
}

void resetMotion()
{
  hasMoved = 0;
}