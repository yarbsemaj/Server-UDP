#pragma once
#include "Observer.h"
class WebPoster
{
public:
	static void start(std::vector<Aircraft>& aircrafts);
	WebPoster();
	~WebPoster();
};

