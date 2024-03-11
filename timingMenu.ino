void toTimingMenu()
{
    globalMenu = timingMenu;
    menuLength = 10;
    menu();
}

void selectTiming()
{
    String strNum;
    for (int i = 0; i < 10; i++)
    {
        if (timingMenu[i].selected)
            strNum = timingMenu[i].name;
    }
    int timing = strNum.substring(0, 2).toInt();
    timeToSpray = timing;
    toIdle();
}