void toWhenSprayMenu() {
    globalMenu = whenSprayMenu;
    menuLength = 2;
    menu();
}

void selectSprayAtEnter() {
    // TODO: enter spray config
    //if (getLight() && old != new) spray()
    //Trigger spray when getLight changes, make a variable and if old != new en licht is uit dan spray 
    // old/new kan ook al in de getLight klasse en dat we het tijdverschil tussen de 2 checken voor hoelang iemand bezig is geweest.
    toTimingMenu();
}

void selectSprayAtExit() {
    // TODO: exit spray config
    //if (!getLight()) spray(), maar het moet maar 1x, dus zo gaat die constant als het licht uit staat sprayen. Maar hoe maar 1x??
    
    // Trigger spray when getLight changes, make a variable and if old != new en licht is uit dan spray 

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