#include "UI.h"
#include "FileWriter.h"
#include <iostream>
#include<vector>
#include "Aircraft.h"
#include <ctime>

using namespace std;


void UI::update(std::vector<Aircraft> &aircrafts)
{
	//clear the screen
	system("cls");
	cout << "**James Aircraft Tracker**" << endl;
	//loop though all aircraft
	for (int y = 0; y < aircrafts.size(); y++)
	{
		//gets the time string
		const time_t rawtime = (time_t)aircrafts[y].time;
		int t = aircrafts[y].time;
		//prints out the data to the screen
		cout << "Reg: " << aircrafts[y].registration << " Longitude: "
			<< aircrafts[y].latitude.getValue() << " Latitude: " << aircrafts[y].longitude.getValue()
			<< " Altitude: " << aircrafts[y].altitude.getValue() << " feet Presure: " << aircrafts[y].presure.getValue()
			<< " atmos Time: " << ctime(&rawtime);
	}

}

string UI::timeStamp(const time_t *rawtime)
{
	return asctime(std::localtime(rawtime));
}

