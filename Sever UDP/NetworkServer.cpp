#include "NetworkServer.h"
#include<winsock2.h>
#include <iostream>
#include<stdio.h>
#include"NetworkData.h"
#include "Observer.h"
#include "FileWriter.h";
#include "UI.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data



NetworkServer::NetworkServer()
{

}

void NetworkServer::start(std::vector<Aircraft> &aircrafts) {
	std::vector<Observer*> observers;
	observers.push_back(new FileWriter());
	observers.push_back(new UI());

	Packet packet;
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[BUFLEN];
	WSADATA wsa;


	slen = sizeof(si_other);

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	//Bind
	if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	puts("Bind done");

	//keep listening for data
	while (1)
	{
		fflush(stdout);

		memset(buf, '\0', BUFLEN);
		recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen);

		packet.deserialize(buf);
		bool newAircraft = true;
		
		for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it)
			(*it)->update(aircrafts);

		for (int y = 0; y < aircrafts.size(); y++)
		{
			if (std::strcmp(aircrafts[y].registration, packet.regNum)==0) {
				newAircraft = false;
				aircrafts[y].update(packet.regNum, packet.presure, packet.longitude, packet.latitude, packet.speed, packet.altitude);
			}
		}
		if (newAircraft) {
			Aircraft arircraft = Aircraft();
			arircraft.update(packet.regNum, packet.presure, packet.longitude, packet.latitude, packet.speed, packet.altitude);
			aircrafts.push_back(arircraft);
		}		

	}

	closesocket(s);
	WSACleanup();

}


NetworkServer::~NetworkServer()
{
}
