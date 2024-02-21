#include <Arduino.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void displaySetup() {
  // set up the LCD's number of columns and rows:
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