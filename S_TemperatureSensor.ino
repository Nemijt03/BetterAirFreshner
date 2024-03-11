#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float getTemperature()
{
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

void updateTemperature()
{
  if (globalMenu[0].name == "To settings" && state != TRIGGERED)
  {
    lcd.home();
    lcd.print(getTemperature());
  }
}
