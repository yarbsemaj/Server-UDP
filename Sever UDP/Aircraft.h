#pragma once
#include<string>
#include"Sensor.h"
class Aircraft
{
public:
	Aircraft();
	~Aircraft();

	void update(char registration[7], float presure, float longitude, float latitude, float speed, float altitude);

	void incrementNotiStat();

	int timeComp();

	char registration [7];
	Sensor presure;
	Sensor longitude;
	Sensor latitude;
	Sensor speed;
	Sensor altitude;
	int time;
	int notiState;

};

