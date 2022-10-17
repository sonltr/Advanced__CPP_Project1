
#ifndef GENERAL_H_
#define GENERAL_H_

#include "Setting.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "commonInfo.h"

using namespace std;
extern vector<CommonInfo> timezoneList;
extern vector<CommonInfo> languageList;

class General
{
public:
	General();
	~General();
	void PrintInformationGeneral();
	// get, set general information
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
private:
	string timeZone;
	string language;
};
#endif //GENERAL_H_
