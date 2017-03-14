#include "Sensor.h"



Sensor::Sensor()
{
}


Sensor::~Sensor()
{
}

float Sensor::getValue()
{
	return value;
}

void Sensor::setValue(float value)
{
	this->value=value;
}
