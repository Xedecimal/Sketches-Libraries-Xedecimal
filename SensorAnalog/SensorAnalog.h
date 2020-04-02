#ifndef _sensor_analog_h
#define _sensor_analog_h

#include "Arduino.h"

class SensorAnalog
{
  public:
    SensorAnalog(int pin);
    uint16_t getState();
  private:
    int _pin;
};

#endif
