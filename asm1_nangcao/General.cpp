#include "General.h"
#include "CommonInfo.h"
 
General::General()
{
	language = "English";
	timeZone = "(GMT-00:00)";
}
General::~General() {}
void General::PrintInformationGeneral() {
	
	cout << left << setw(15) << get_timeZone() << setw(15) << left << get_language();
}
string General::get_language() {
	return language;
}
string General::get_timeZone() {
	return timeZone;
}
void General::set_timeZone(string data) {
	timeZone = data;
}
void General::set_language(string data) {
	language = data;
}

