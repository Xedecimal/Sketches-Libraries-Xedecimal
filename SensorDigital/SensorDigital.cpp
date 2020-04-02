#include <SensorDigital.h>

SensorDigital::SensorDigital(int pin, bool pull_up)
{
    pinMode(pin, INPUT);
    _pin = pin;
    if (pull_up) {
        digitalWrite(pin,HIGH);
    }
}

int SensorDigital::getState()
{
    return digitalRead(_pin);
}
