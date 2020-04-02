#ifndef SensorCover_h
#define SensorCover_h

/*
* SensorCover
*/

#include "sensors/SensorRelay.h"

class SensorCover: public Sensor {
public:
	SensorCover(int8_t pinRelayUp, int8_t pinRelayDown, uint8_t child_id = 0): Sensor(pinRelayUp) {
		_name = "COVER";
		children.allocateBlocks(1);
		new Child(this, INT, child_id, S_COVER, V_DIMMER, _name);
		_relayUp = new SensorRelay(pinRelayUp);
		//_relayUp->setSafeguard(1); // Turn off after a minute in case forgotten about.
		_relayDown = new SensorRelay(pinRelayDown);
		//_relayDown->setSafeguard(1);

		// Stop relay from triggering on boot.
		digitalWrite(pinRelayDown, HIGH);
		digitalWrite(pinRelayUp, HIGH);
	}

	void onReceive(MyMessage* message) {
		int8_t type = message->getType();
		if (type == V_UP) {
			_relayDown->setStatus(0);
			_relayUp->setStatus(1);
			children.get()->setValue(status = 100);
		} else if (type == V_DOWN) {
			_relayUp->setStatus(0);
			_relayDown->setStatus(1);
			children.get()->setValue(status = 0);
		} else { // Likely V_STOP
			_relayDown->setStatus(1);
			_relayUp->setStatus(1);
			children.get()->setValue(status);
		}
	}

protected:
	int status;
	SensorRelay *_relayUp;
	SensorRelay *_relayDown;
};

#endif
