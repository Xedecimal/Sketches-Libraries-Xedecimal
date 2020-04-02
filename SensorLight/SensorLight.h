#ifndef _sensor_light_h
#define _sensor_light_h

#include "Arduino.h"
#include "XMySensors.h"
#include "Sensor.h"
#include "SensorDigital.h"

class SensorLight : public Sensor
{
    protected:
        SensorDigital _dr;
        uint8_t _sensor;
        int _status;

    public:
        SensorLight(uint8_t childId, uint8_t pin);
        void init();
        void loop();
        void receive(const MyMessage &message);
};

#endif
