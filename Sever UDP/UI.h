#pragma once
#include "Observer.h"
class UI :
	public Observer
{
public:
	void update(std::vector<Aircraft>& aircrafts);
	std::string timeStamp(const time_t * rawtime);
};

