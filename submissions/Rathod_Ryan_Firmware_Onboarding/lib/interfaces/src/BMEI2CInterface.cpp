#include "BMEConstants.h"
#include "BMEI2CInterface.h"
#include <Adafruit_BME280.h>

bool BMEI2CInterface::initializeSensor() {
    return sensor1.begin(0x77, &Wire);
};

float BMEI2CInterface::readTemp() {
    return sensor1.readTemperature();
};