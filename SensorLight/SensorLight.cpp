#include <SensorLight.h>

SensorLight::SensorLight(uint8_t childId, uint8_t pin) :
	Sensor(pin),
	_dr(pin, false),
	_sensor(childId)
{
}

void SensorLight::init()
{
    send(MyMessage(_sensor, V_STATUS).set(1));
}

void SensorLight::loop()
{
	int newState = !_dr.getState();
	if (newState != _status) {
		send(MyMessage(_sensor, V_STATUS).set(_status = newState));
	}
}

void SensorLight::receive(const MyMessage &message)
{
	if (message.sensor == _sensor && message.type == V_STATUS) {
		send(MyMessage(message.sensor, message.type).set(_status));
	}
}
