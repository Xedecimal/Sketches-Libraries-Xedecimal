/*
* The MySensors Arduino library handles the wireless radio link and protocol
* between your home built sensors/actuators and HA controller of choice.
* The sensors forms a self healing radio network with optional repeaters. Each
* repeater and gateway builds a routing tables in EEPROM which keeps track of the
* network topology allowing messages to be routed to nodes.
*
* Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
* Copyright (C) 2013-2017 Sensnology AB
* Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
*
* Documentation: http://www.mysensors.org
* Support Forum: http://forum.mysensors.org
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* version 2 as published by the Free Software Foundation.
*/
#ifndef SensorDoorCat_h
#define SensorDoorCat_h

/*
* SensorDoor
*/

#include "sensors/SensorDoor.h"
#include "sensors/SensorRelay.h"

class SensorDoorCat: public SensorDoor {
public:
	SensorDoorCat(int8_t pin, SensorRelay *relay, uint8_t child_id = 0):
	SensorDoor(pin, child_id), _relay(relay) {
		_debounce = 0;
		_flipped = false;
	};

  	void onInterrupt() {
      	Child* child = children.get(1);

		// read the value of the pin
		int value = nodeManager.getLastInterruptValue();

		if (value == 0 && (millis() - _debounce) >= 4000) {
			if (!_flipped) {
				_relay->toggleStatus();
				wait(500);
				_relay->toggleStatus();
				wait(500);
				_relay->toggleStatus();
				_flipped = !_flipped;
			} else {
				_flipped = !_flipped;
			}

			_debounce = millis();
		}

        child->setValue(value);
    }

	void reset() {
		_flipped = true;
	}

protected:
	SensorRelay *_relay;
	bool _flipped;
	unsigned long _debounce;
};
#endif
