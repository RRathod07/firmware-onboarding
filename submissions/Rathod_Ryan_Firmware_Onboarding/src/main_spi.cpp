#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    BMESPIInterfaceInstance::instance().initializeSensor();
}

void loop()
{
    float temperature = BMESPIInterfaceInstance::instance().readTemp();
    LEDControllerInstance::instance().flashLED(temperature);
}