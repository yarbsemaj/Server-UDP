#pragma once
#include <vector>
#include "Aircraft.h"
class Observer
{
public:
	virtual ~Observer() = 0;
	virtual void update(std::vector<Aircraft> &aircrafts)=0;
};

