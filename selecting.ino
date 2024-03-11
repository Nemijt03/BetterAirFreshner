
void selectNext()
{
    for (int i = 0; i < menuLength; i++)
    {
        if (!globalMenu[i].selected)
            continue;

        globalMenu[i].selected = false;
        int newSelection = i + 1;

        if (i == (menuLength - 1))
        {
            newSelection = 0;
        }

        globalMenu[newSelection].selected = true;
        break;
    }
}

void selectItem()
{
    getSelected().func();
}

struct MenuItem getSelected()
{
    for (int i = 0; i < menuLength; i++)
    {
        if (globalMenu[i].selected)
            return globalMenu[i];
    }
}