#include "FileWriter.h"
#include <iostream>
#include<vector>
#include "Aircraft.h"
#include <fstream>
#include <ctime>

using namespace std;

FileWriter::FileWriter()
{
}


FileWriter::~FileWriter()
{
}

void FileWriter::update(std::vector<Aircraft> &aircrafts)
{
	ofstream out("log.txt");
	for (int y = 0; y < aircrafts.size(); y++)
	{
		const time_t rawtime = (time_t)aircrafts[y].time;
		int t = aircrafts[y].time;
		out << "Reg: " << aircrafts[y].registration << "Longitude: "
			<< aircrafts[y].latitude.getValue() << "Latitude: " << aircrafts[y].longitude.getValue()
			<< "Altitude: " << aircrafts[y].altitude.getValue() << "Presure: " << aircrafts[y].presure.getValue()
			<< "Time: "<< ctime(&rawtime);
	}

	out.close();
}

string FileWriter::timeStamp(const time_t *rawtime)
{
	return asctime(std::localtime(rawtime));
}
