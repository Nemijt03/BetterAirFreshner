void toWhenSprayMenu() {
    globalMenu = whenSprayMenu;
    menuLength = 2;
    menu();
}
int oldLight = 0; //moet geen nul zijn maar de oude light

void checkSpray(){
    int getL = getLight();
    Serial.print("min:");
    Serial.println(whenSX);
    Serial.print("max:");
    Serial.println(whenSY);
    if((abs(getL - oldLight) > 100) && getL > whenSX && getL < whenSY){
        Serial.println("spray");
        spray(); 
    }
    oldLight = getL;
}


void selectSprayAtEnter() {
    // TODO: enter spray config
    whenSX = 500;
    whenSY = 1023;
    toTimingMenu();
}

void selectSprayAtExit() {
    // TODO: exit spray config
    whenSX = 0;
    whenSY = 500;
    toTimingMenu();
}

void toTimingMenu() {
    globalMenu = timingMenu;
    menuLength = 10;
    menu();
}

void selectTiming() {
    String strNum;  
    for(int i = 0; i < 10; i++) {
        if (timingMenu[i].selected) strNum = timingMenu[i].name;
    }
    int timing = strNum.substring(0,2).toInt();

    // TODO: write the timing as the global timing

    toIdle();
}