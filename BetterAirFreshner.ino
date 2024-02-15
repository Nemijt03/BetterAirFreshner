void setup() {
  displaySetup();
}

void loop() {
  delay(1000);

  display(getTemperature(), getDistance(), getMotion());
}
