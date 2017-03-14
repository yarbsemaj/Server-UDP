#pragma once
#include <vector>
#include "Aircraft.h"
class NetworkServer
{
public:
	NetworkServer();
	~NetworkServer();
	static void start(std::vector<Aircraft> &aircrafts);
};

