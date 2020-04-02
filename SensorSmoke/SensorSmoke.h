#ifndef _sensor_smoke_h
#define _sensor_smoke_h

#include "Arduino.h"
#include "XMySensors.h"
#include "Sensor.h"
#include "SensorAnalog.h"

class SensorSmoke : public Sensor
{
    protected:
        SensorAnalog _reader;
        uint8_t _sensorSmoke;
        float _statusSmoke;

    public:
        SensorSmoke(uint8_t childId, uint8_t pin);
        void init();
        void loop();
        void receive(const MyMessage &message);
};

#endif
