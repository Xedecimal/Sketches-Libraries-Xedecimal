#ifndef _sensor_door_h
#define _sensor_door_h

#include "Arduino.h"
#include "XMySensors.h"
#include "Sensor.h"
#include "SensorDigital.h"

class SensorDoor : public Sensor
{
    protected:
        SensorDigital _digitalRead;
        uint8_t _sensorDoor;
        uint8_t _statusDoor;

    public:
        SensorDoor(uint8_t sensorId, uint8_t pinSensor);
        void init();
        void loop();
        void receive(const MyMessage &message);
};

#endif
