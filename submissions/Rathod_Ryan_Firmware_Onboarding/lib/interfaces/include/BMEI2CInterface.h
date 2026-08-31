#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;
    bool initializeSensor();
    float readTemp();
    
private:
    Adafruit_BME280 sensor1; // I2C

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;