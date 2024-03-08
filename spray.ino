int oldLight = 0; //moet geen nul zijn maar de oude light
int lightThreshold = 800;
int mosfet = A2;
int spraysRemaining = 0;

// when light on or of
void checkEnterExit(){
    int getL = getLight();
    // Serial.print(F("Light level: "));
    // Serial.println(getL);
    if(abs(getL - oldLight) > 100) {
      enterexit1();
    }
    oldLight = getL;
}

void enterexit1() {
  int getL = getLight();
  if(getL >= lightThreshold && state != TRIGGERED) {
      changeState(UNDEFINED); // blocks waiting for spray
      Serial.println("enter");
      digitalWrite(backlightPin, HIGH);
      lcd.display();
      entered = millis();
  }
  if(getL < lightThreshold) {
    exited = millis(); 
    Serial.println("exit"); 
    changeState(NOTINUSE); 
    timedSpray(); 
    digitalWrite(backlightPin, LOW); 
    lcd.noDisplay();
  } //resets van sensors
}

int timeOnToilet(){
  Serial.print("time on toilet: "); 
  int timeTook = exited - entered;

  if (timeTook < 0) timeTook = millis() - entered;
  Serial.println(timeTook);

  if((timeTook >= longEnough) && getMotion()) {return 1;}
  return 0;
}

void timedSpray() {
  if (getStateFromSensors() != 3) {
    int timing = timeToSpray - 15;
    updateSpray = Timer(timing * 1000, &howManySpray);
    changeState(TRIGGERED);
  }
  else resetAll();
}

void howManySpray() {
  byte getS = getStateFromSensors();
  updateSpray = Timer(100000, &nothing);

  spraysRemaining = getS - 1;
  mosfetToggle();
}

void spray() {

  Serial.println(F("Spraying"));
  changeState(TRIGGERED);
  spraysRemaining = 0;
  mosfetToggle();
}

byte mosfetState = LOW;

void mosfetToggle() {
  Serial.print(F("mosfetState: "));
  Serial.println(mosfetState);
  Serial.print(F("spraysRemaining: "));
  Serial.println(spraysRemaining);

  if (mosfetState == LOW) {
    mosfetState = HIGH;
    digitalWrite(mosfet, HIGH);
    Serial.println("LOW");
    builtInSprayDelay = Timer(17000, &mosfetToggle); //TODO 17000 delay
  }
  else if (mosfetState == HIGH && spraysRemaining != 0){
    writeLow();
    spraysRemaining--;
    Serial.println(F("HIGH spraysremaining != 0"));
    builtInSprayDelay = Timer(2000, &mosfetToggle);
  }
  else {
    writeLow();
    Serial.println(F("changestate aanroepen"));
    // all reset functionality
    
    resetAll();
    // changeState denk ik
    // hoeft niet meer te ticken
  }


}

void resetAll() {
  resetMotion();
  resetSit();
  resetPaper();
  resetSensors();
  enterexit1();
  toIdle();
}
void writeLow() {
  decrementRemainingShots();
  Serial.println(F("17 sec na mosfet activatie"));
  mosfetState = LOW;
  digitalWrite(mosfet, LOW);
}