void toWhenSprayMenu() {
    globalMenu = whenSprayMenu;
    menuLength = 2;
    menu();
}

void selectSprayAtEnter() {
    // TODO: enter spray config
    toTimingMenu();
}

void selectSprayAtExit() {
    // TODO: exit spray config
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