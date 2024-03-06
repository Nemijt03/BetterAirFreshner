#include <LiquidCrystal.h>

void displaySetup() {
  lcd.begin(16, 2);
}

void display(String message) {
  lcd.setCursor(0, 1);
  lcd.print(message);
}

void toIdle() {
    globalMenu = idleMenu;
    menuLength = 1;
    changeState(NOTINUSE);

    lcd.createChar(0, degree);
    lcd.setCursor(0,0);
    lcd.print(getTemperature());
    lcd.write(byte(0));
    lcd.print(F("C  S: "));
    lcd.print(getRemainingShots());
    lcd.setCursor(0,1);
    lcd.print(F("Press "));
    lcd.write(byte(126)); // '->'
    lcd.print(F(" for menu"));
}

void updateRemainingShots() {
    if (globalMenu[0].name == "To settings") {
        lcd.setCursor(12,0);
        lcd.print(getRemainingShots());
    }
}