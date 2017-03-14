#include "UI.h"
#include "FileWriter.h"
#include <iostream>
#include<vector>
#include "Aircraft.h"
#include <ctime>

using namespace std;


void UI::update(std::vector<Aircraft> &aircrafts)
{
	system("cls");
	for (int y = 0; y < aircrafts.size(); y++)
	{
		const time_t rawtime = (time_t)aircrafts[y].time;
		int t = aircrafts[y].time;
		cout << "Reg: " << aircrafts[y].registration << " Longitude: "
			<< aircrafts[y].latitude.getValue() << " Latitude: " << aircrafts[y].longitude.getValue()
			<< " Altitude: " << aircrafts[y].altitude.getValue() << " Presure: " << aircrafts[y].presure.getValue()
			<< " Time: " << ctime(&rawtime);
	}

}

string UI::timeStamp(const time_t *rawtime)
{
	return asctime(std::localtime(rawtime));
}

