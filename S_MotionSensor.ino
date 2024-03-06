int sensorPin = A1;
byte hasMoved = 0;


int getMotion() {
  return hasMoved;
}

void updateMoveIt() {
  if(digitalRead(sensorPin)) hasMoved = 1;
}
