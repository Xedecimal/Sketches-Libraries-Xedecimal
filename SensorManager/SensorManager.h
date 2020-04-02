#ifndef _sensor_manager_h
#define _sensor_manager_h

#include <Sensor.h>

#ifndef SENSOR_COUNT
    #define SENSOR_COUNT 1
#endif

class SensorManager
{
    protected:
        Sensor* _sensors[SENSOR_COUNT];

    public:
        SensorManager(Sensor *sensors[SENSOR_COUNT]);
        bool init();
        bool loop();
        bool receive(const MyMessage &message);
};

#endif
