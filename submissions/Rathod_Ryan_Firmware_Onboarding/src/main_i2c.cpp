#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    BMEI2CInterfaceInstance::instance().initializeSensor();
}

void loop()
{
    float temperature = BMEI2CInterfaceInstance::instance().readTemp();
    LEDControllerInstance::instance().flashLED(temperature);
}