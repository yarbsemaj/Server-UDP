#include "Aircraft.h"
#include <iostream>
#include <ctime>

Aircraft::Aircraft()
{
	//set up the aircraft
	presure = Sensor();
	longitude = Sensor();
	latitude = Sensor();
	speed = Sensor();
	altitude = Sensor();
}


Aircraft::~Aircraft()
{
}

void Aircraft::update(char registration [7] , float presure, float longitude, float latitude, float speed, float altitude)
{
	//sets its atributes
	memcpy(this->registration,registration, 7);
	this->presure.setValue(presure);
	this->longitude.setValue(longitude);
	this->latitude.setValue(latitude);
	this->speed.setValue(speed);
	this->altitude.setValue(altitude);
	this->time = std::time(0);
	this->notiState = 0;
}
void Aircraft::incrementNotiStat() {
	//increment its notification state
	this->notiState++;
}

int Aircraft::timeComp() {
	return std::time(0)- this->time;
}
