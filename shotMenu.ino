void resetShotsConfirm()
{
    lcd.clear();
    lcd.home();
    lcd.print(F("Reset shots?"));
    globalMenu = confirmReset;
    menuLength = 2;
    menu();
}

void resetShots()
{
    resetRemainingShots();
    toIdle();
}
