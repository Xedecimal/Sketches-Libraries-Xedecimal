#include "SensorAnalog.h"

SensorAnalog::SensorAnalog(int pin)
{
    pinMode(pin, INPUT);
    _pin = pin;
}

uint16_t SensorAnalog::getState()
{
    return analogRead(_pin);
}
