#include <Arduino.h>

void toIdle() {
    lcd.createChar(0, degree);
    lcd.setCursor(0,0);
    lcd.print(getTemperature());
    lcd.write(byte(0));
    lcd.print(F("C  S: "));
    lcd.print(remainingShots);
    lcd.setCursor(0,1);
    lcd.print(F("Press "));
    lcd.write(byte(B01111110)); // '->'
    lcd.print(F(" for menu"));
    delay(2000);
    lcd.noDisplay();
}

void updateIdle() {
    lcd.home();
    lcd.print(getTemperature());
}

void resetShots() {
    remainingShots = 2400;
    toIdle();
}

void toDelayConfig() {
    
}

void toWhenToSpray() { // two choises

}