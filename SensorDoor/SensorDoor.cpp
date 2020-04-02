#include <SensorDoor.h>

SensorDoor::SensorDoor(uint8_t childId, uint8_t pinSensor) :
	Sensor(childId),
	_digitalRead(pinSensor, false)
{
	_sensorDoor = childId;
}

void SensorDoor::init()
{
    send(MyMessage(_sensorDoor, V_TRIPPED).set(1));
}

void SensorDoor::loop()
{
	uint8_t newState = _digitalRead.getState();
	if (newState != _statusDoor) {
		send(MyMessage(_sensorDoor, V_TRIPPED).set(_statusDoor = newState));
	}
}

void SensorDoor::receive(const MyMessage &message)
{
	if (message.sensor == _sensorDoor && message.type == V_TRIPPED) {
		send(MyMessage(message.sensor, message.type).set(_statusDoor));
	}
}

