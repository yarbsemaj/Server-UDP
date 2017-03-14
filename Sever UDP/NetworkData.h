#pragma once
#include <string>

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {
	INIT_CONNECTION = 0,
	DATA_EVENT = 1,
};


struct Packet {

	unsigned int packet_type;
	double speed;
	float longitude;
	float latitude;
	float altitude;
	float presure;
	char regNum[7];



	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};