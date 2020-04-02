#include "SensorSmoke.h"

uint32_t SLEEP_TIME = 1000;

SensorSmoke::SensorSmoke(uint8_t childId, uint8_t pin) :
	Sensor(childId),
	_reader(pin)
{
	_sensorSmoke = childId;
}

void SensorSmoke::init()
{
    send(MyMessage(_sensorSmoke, V_STATUS).set(1));
}

void SensorSmoke::loop()
{
	uint16_t voMeasured = _reader.getState(); // Get DUST value
	float calcVoltage = voMeasured * (5.0 / 1024.0);
	float dustDensity = (0.17 * calcVoltage - 0.1)*1000;
  	byte newSmoke = 0;

    Serial.print("Raw Signal Value (0-1023): ");
    Serial.print(voMeasured);

    Serial.print(" - Voltage: ");
    Serial.print(calcVoltage);

    Serial.print(" - Dust Density: ");
    Serial.println(dustDensity); // unit: ug/m3

    if (ceil(dustDensity) != _statusSmoke) {
        send(MyMessage(_sensorSmoke, V_LEVEL).set((int16_t)ceil(dustDensity)));
        _statusSmoke = ceil(dustDensity);
    }
}

void SensorSmoke::receive(const MyMessage &message)
{
	if (message.sensor == _sensorSmoke && message.type == V_LEVEL) {
		send(MyMessage(message.sensor, message.type).set((int16_t)_statusSmoke));
	}
}
