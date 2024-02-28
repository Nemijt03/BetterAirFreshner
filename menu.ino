#include <Arduino.h>

void toIdle() {
    globalMenu = idleMenu;
    menuLength = 1;

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

void toSelectorMenu() {
    globalMenu = selectorMenu;
    menuLength = 3;
    menu();
}

void menu() {
    lcd.home();
    if (globalMenu[0].name == "To settings") {
        lcd.clear();
        toIdle();
        return;
    }
    if ((menuLength == 2) && (globalMenu[0].name.length() + globalMenu[1].name.length() <= 13)) // beside each other
    {
        lcd.setCursor(0,1);
        if (globalMenu[0].selected) {
            lcd.write(126);
            lcd.print(F(" "));
            lcd.print(globalMenu[0].name);
            lcd.print(F(" "));
            lcd.print(globalMenu[1].name);
        }
        else {
            lcd.print(globalMenu[0].name);
            lcd.print(F(" "));
            lcd.write(126);
            lcd.print(F(" "));
            lcd.print(globalMenu[1].name);
        }
        return;
    }
    lcd.clear();
    int selected = 0;
    int displayed = 0;
    for (int i = 0; i < menuLength; i++)
    {
        if (!globalMenu[i].selected) continue;

        selected = i;
        if (i + 1 != menuLength) displayed = i + 1;
        break;
    }

    Serial.print("Selected: ");
    Serial.println(globalMenu[selected].name);
    Serial.print("Displayed: ");
    Serial.println(globalMenu[displayed].name);
    lcd.write(126);
    lcd.print(F(" "));
    lcd.print(globalMenu[selected].name);
    lcd.setCursor(0,1);
    lcd.print(globalMenu[displayed].name);
    }

void printMenu() {

}

void toDelayConfig() {
    
}

void toWhenToSpray() { // two choises

}