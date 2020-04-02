#include <Arduino.h>
#include "SensorManager.h"

SensorManager::SensorManager(Sensor* sensors[SENSOR_COUNT])
{
    for (int i = 0; i < SENSOR_COUNT; i++) {
        _sensors[i] = sensors[i];
    }
}

bool SensorManager::init() {
    for (int i = 0; i < SENSOR_COUNT; i++) {
        _sensors[i]->init();
    }
}

bool SensorManager::loop()
{
    for (int i = 0; i < SENSOR_COUNT; i++) {
        _sensors[i]->loop();
    }
}

bool SensorManager::receive(const MyMessage &message)
{
    for (int i = 0; i < SENSOR_COUNT; i++) {
        _sensors[i]->receive(message);
    }
}
