#pragma once

#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void flashLED(float temperature);

private:
    // What state, if any, does the controller need to remember?
};

using LEDControllerInstance = etl::singleton<LEDController>;