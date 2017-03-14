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
	while (true) {
		for (int y = 0; y < aircrafts.size(); y++) {
			this_thread::sleep_for(2s);
			switch (aircrafts[y].notiState) {
			case 0:
				if (aircrafts[y].timeComp() > 4) {
					aircrafts[y].incrementNotiStat();
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
	string name = nameArray;
	string mes = name + " has been heard from for for "+ time + " secounds";
	wstring mesage;
	StringToWString(mesage, mes);

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

