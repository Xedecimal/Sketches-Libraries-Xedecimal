#ifndef _sensor_digital_h
#define _sensor_digital_h

#include "Arduino.h"

class SensorDigital
{
  public:
    SensorDigital(int pin, bool pull_up);
    int getState();
  private:
    int _pin;
};

#endif
