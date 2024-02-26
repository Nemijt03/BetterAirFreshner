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
    lcd.write(byte(126)); // '->'
    lcd.print(F(" for menu"));
}

void updateIdle() {
    lcd.home();
    lcd.print(getTemperature());
}

void toIdleMenu() {
    globalMenu = &idleMenu;
    toIdle();
}

void menu(struct MenuItem items[], int length) {
    lcd.clear();
    lcd.home();
    if ((length == 2) && (items[0].name.length() + items[1].name.length() <= 13)) // beside each other
    {
        lcd.setCursor(0,1);
        if (items[0].selected) {
            lcd.write(126);
            lcd.print(F(" "));
            lcd.print(items[0].name);
            lcd.print(F(" "));
            lcd.print(items[1].name);
        }
        else {
            lcd.print(items[0].name);
            lcd.print(F(" "));
            lcd.write(126);
            lcd.print(F(" "));
            lcd.print(items[1].name);
        }
        return;
    }
    int selected = 0;
    int displayed = 0;
    for (int i = 0; i < length; i++)
    {
        if (!items[i].selected) continue;

        selected = i;
        if (i + 1 != length) displayed = i + 1;
        break;
    }

    Serial.print("Selected: ");
    Serial.println(items[selected].name);
    Serial.print("Displayed: ");
    Serial.println(items[displayed].name);
    lcd.write(126);
    lcd.print(F(" "));
    lcd.print(items[selected].name);
    lcd.setCursor(0,1);
    lcd.print(items[displayed].name);
    }

void printMenu() {

}

void toDelayConfig() {
    
}

void toWhenToSpray() { // two choises

}