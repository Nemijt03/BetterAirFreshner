
void selectNext() {
    Serial.println("selectNext");
    for (int i = 0; i < menuLength; i++)
    {
        if (!globalMenu[i].selected) continue;

        globalMenu[i].selected = false;
        int newSelection = i + 1;

        if (i == (menuLength - 1)) {
            newSelection = 0;
        }

        globalMenu[newSelection].selected = true;
        Serial.print("i:");
        Serial.println(i);
        Serial.print("newSelection:");
        Serial.println(newSelection);
        for (int i = 0; i < menuLength; i++)
        {
            Serial.print("\nNaam: ");
            Serial.println(globalMenu[i].name);
            Serial.print("Selected: ");
            Serial.println(globalMenu[i].selected);
        }
        break;
        
    }
    
}

void selectItem() {
    for(int i = 0; i < menuLength; i++) {
        if (!globalMenu[i].selected) continue;
        
        globalMenu[i].func();
        break;
    }
}