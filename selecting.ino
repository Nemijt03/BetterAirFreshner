
void selectNext(struct MenuItem items[], int length) {
    Serial.println("selectNext");
    for (int i = 0; i < length; i++)
    {
        if (!items[i].selected) continue;

        items[i].selected = false;
        int newSelection = i + 1;

        if (i == (length - 1)) {
            newSelection = 0;
        }

        items[newSelection].selected = true;
        Serial.print("i:");
        Serial.println(i);
        Serial.print("newSelection:");
        Serial.println(newSelection);
        for (int i = 0; i < length; i++)
        {
            Serial.print("\nNaam: ");
            Serial.println(items[i].name);
            Serial.print("Selected: ");
            Serial.println(items[i].selected);
        }
        break;
        
    }
    
}

void selectItem(struct MenuItem items[], int length) {
    for(int i = 0; i < length; i++) {
        if (!items[i].selected) continue;
        
        items[i].func();
        break;
    }
}