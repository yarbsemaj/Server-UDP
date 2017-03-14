#include <iostream>
#include <thread> 
#include "NetworkServer.h"
#include <vector>
#include "Alert.h"
#include "Aircraft.h"


int main()
{
	std::vector<Aircraft> aircraft;
	NetworkServer server = NetworkServer();
	std::thread serverThred(&NetworkServer::start, std::ref(aircraft));
	std::thread checker(&Alert::start, std::ref(aircraft));

	serverThred.join();
}