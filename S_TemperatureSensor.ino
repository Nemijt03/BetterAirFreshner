#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 8

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

float getTemperature() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}

void updateTemperature() {
    if (globalMenu[0].name == "To settings") {
        lcd.home();
        lcd.print(getTemperature());
    }
}
