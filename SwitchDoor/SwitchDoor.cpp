#include "SwitchDoor.h"

SwitchDoor::SwitchDoor(uint8_t relayId, uint8_t pinRelay) : Sensor(relayId)
{
	_switch = relayId;
}

void SwitchDoor::init()
{
	send(MyMessage(_switch, V_STATUS).set(1));
}

void SwitchDoor::loop()
{
}

void SwitchDoor::receive(const MyMessage &message)
{
	if (message.sensor == _switch && message.type == V_STATUS) {
		send(MyMessage(message.sensor, message.type).set(0));
		_relay.turnOn();
		delay(500);
		_relay.turnOff();
	}
}
