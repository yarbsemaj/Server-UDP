#include "Alert.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>

using namespace std;




Alert::Alert()
{
}


Alert::~Alert()
{
}

void Alert::start(vector<Aircraft>& aircrafts)
{
	using namespace chrono_literals;
	//run forever
	while (true) {
		//iterare over all aircrafts
		this_thread::sleep_for(2s);
		for (int y = 0; y < aircrafts.size(); y++) {
			//get the apropriate alert
			switch (aircrafts[y].notiState) {
			case 0:
				//if there has been nod data
				if (aircrafts[y].timeComp() > 4) {
					//incrament the alert lever
					aircrafts[y].incrementNotiStat();
					//display the alert
					popup(aircrafts[y].registration, "4", MB_ICONASTERISK);
				}
				break;

			case 1:
				if (aircrafts[y].timeComp() > 60) {
					aircrafts[y].incrementNotiStat();
					popup(aircrafts[y].registration, "60", MB_ICONEXCLAMATION);
				}
				break;
			case 2:
				if (aircrafts[y].timeComp() > 120) {
					aircrafts[y].incrementNotiStat();
					popup(aircrafts[y].registration, "120", MB_ICONSTOP);
				}
				break;
			}
		}
	}

}

void Alert::popup(char* nameArray, const char* time , int type) {
	//build the alert
	string name = nameArray;
	string mes = name + " has been heard from for for "+ time + " secounds";
	wstring mesage;
	//conver the string to a wstring
	StringToWString(mesage, mes);
	//disoplay the message box
	int msgboxID = MessageBox(
		NULL,
		mesage.c_str(),
		L"Keep an eye on it",
		type | MB_OK);

}

int Alert::StringToWString(std::wstring &ws, const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());
	ws = wsTmp;
	return 0;
}

