void temperature() {
  displayTemperature(getTemperature());
}

void distance() {
    displayDistance(getDistance());
}

void motion() {
    displayMotion(getMotion());
}

void light() {
    checkSpray();
    
}

int ledStateBuildin = LOW;
void blinkBuildin() {
  if (ledStateBuildin == LOW) ledStateBuildin = HIGH;
  else ledStateBuildin = LOW;

  digitalWrite(LED_BUILTIN, ledStateBuildin);
}

int ledState7 = LOW;
void blink7() {
  if (ledState7 == LOW) ledState7 = HIGH;
  else ledState7 = LOW;

  digitalWrite(12, ledState7);
}