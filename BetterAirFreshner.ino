void setup() {
  displaySetup();
}

void loop() {
  delay(1000);

  float tempC = getTemp();
  String message = "Temp: " + String(tempC);
  display(message);
  lcd.setCursor(0,0);
  int ifjea = digitalRead(10);
  lcd.print(String(ifjea));
  lcd.setCursor(3,0);
  
  lcd.print(hc.dist());
}
