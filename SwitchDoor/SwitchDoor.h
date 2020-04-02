#ifndef _sensor_switch_door_h
#define _sensor_switch_door_h

#include "Arduino.h"
// #include "XMySensors.h"
#include "Sensor.h"
#include "Relay.h"

class SwitchDoor : public Sensor
{
    protected:
        uint8_t _switch;
        Relay _relay;

    public:
        SwitchDoor(uint8_t relayId, uint8_t pinRelay);
        void init();
        void loop();
        void receive(const MyMessage &message);
};

#endif
