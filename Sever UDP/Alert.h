#pragma once
#include <vector>
#include "Aircraft.h"

class Alert
{
public:
	Alert();
	~Alert();
	static void start(std::vector<Aircraft> &aircrafts);
	static void popup(char * name, const char * time, int type);
	static int StringToWString(std::wstring &ws, const std::string &s);
};

