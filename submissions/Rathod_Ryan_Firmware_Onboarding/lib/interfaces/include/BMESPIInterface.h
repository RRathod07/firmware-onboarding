#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include <Adafruit_BME280.h>

class BMESPIInterface
{
public:

    BMESPIInterface();
    bool initializeSensor();
    float readTemp();
private:
    Adafruit_BME280 sensor2; // SPI
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;