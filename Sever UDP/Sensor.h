#pragma once
class Sensor
{
public:
	Sensor();
	~Sensor();
	float getValue();
	void setValue(float value);

private:
	float value;
};

