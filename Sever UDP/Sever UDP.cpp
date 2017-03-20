#include <iostream>
#include <thread> 
#include "NetworkServer.h"
#include <vector>
#include "Alert.h"
#include "Aircraft.h"


int main()
{
	//creates the vector of aircraft
	std::vector<Aircraft> aircraft;
	//start the server and checker thread
	std::thread serverThred(&NetworkServer::start, std::ref(aircraft));
	std::thread checker(&Alert::start, std::ref(aircraft));

	serverThred.join();
}