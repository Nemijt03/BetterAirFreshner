#include <LiquidCrystal.h>

void displaySetup() {
  lcd.begin(16, 2);
}

void display(String message) {
  lcd.setCursor(0, 1);
  lcd.print(message);
}

void display(float temperature, float distance, int motion) {
  lcd.setCursor(0, 0);
  lcd.print(motion);
  lcd.print(" ");
  lcd.print(distance);
  lcd.setCursor(0,1);
  String message = "Temp: " + String(temperature);
  lcd.print(message);
}

void displayMotion(int motion) {
  lcd.setCursor(0,0);
  lcd.print(motion);
}

void displayDistance(float distance) {
  lcd.setCursor(2,0);
  lcd.print(distance);
}

void displayTemperature(float temperature) {
  lcd.setCursor(0,1);
  String message = "Temp: " + String(temperature);
  lcd.print(message);
}
