#include "BMEConstants.h"
#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : sensor2(BMEConstants::BME_CS_PIN, &SPI)
{
}

bool BMESPIInterface::initializeSensor() {
    return sensor2.begin();
};

float BMESPIInterface::readTemp() {
    return sensor2.readTemperature();
};