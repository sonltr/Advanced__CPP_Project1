#include "Setting.h"
#include <iomanip>
#include <regex>

Setting::Setting()
{
	car_name = "";
	personal_key = ""; 	
	email = "";			
	odo = 0;
	service_remind = 0;
}

Setting::~Setting() {}

string Setting::getCarName() {
	return car_name;
}

string Setting::getPersonalKey() {
	return personal_key;
}
string Setting::getEmail() {
	return email;
}
void Setting::setCarName(string data)
{
	this->car_name = data;
}
void Setting::setPersonalKey(string data)
{
	this->personal_key = data;
}
void Setting::setODO(int data)
{
	this->odo = data;
}
void Setting::setEmail(string data)
{
	this->email = data;
}
void Setting::setServiceRemind(int data)
{
	this->service_remind = data;
}
int Setting::getODO() {
	return odo;
}
int Setting::getServiceRemind() {
	return service_remind;
}

int Setting::checkOdoAndSRemind()
{
	int n = 0; //return
	string Input_OdoandSRemind = "";
	std::regex re_OdoAndSRemind("^[0-9]*$");

	while (1)
	{
		getline(cin, Input_OdoandSRemind);
		if (!regex_match(Input_OdoandSRemind, re_OdoAndSRemind) || Input_OdoandSRemind.empty())
		{
			cout << "Input is not valid\n";
			cout << "enter again: ";
		}
		else
		{
			n = stoi(Input_OdoandSRemind);
			break;
		}
	}
	return n;
}
void Setting::InputInformationJoint() {
	regex re_name("^[a-z A-Z]{1,50}$");    
	regex re_email("(\\w+)(\\.|_)?(\\W*)@((\\w+){3})(\\.(\\w+){3})");
	regex re_personalKey("^[0-9]{8}$");	 
	
	string s;	
	while (1) {
		cout << "Owner name: "; 
		getline(cin, s);
		cin.ignore(0);
		if (!regex_match(s, re_name) || s.empty()) {
			cout << "Input is not valid\n";
		}
		else {
			setCarName(s);
			break;
		}
	}
	while (1) {
		cout << "Email: "; 
		getline(cin, s);
		cin.ignore(0);
		if (!regex_match(s, re_email) || s.empty()) {
			cout << "Input is not valid\n";		
		}
		else {
			setEmail(s);
			break;
		}	
	}
	while (1) {
		cout << "Key number: "; 
		getline(cin, s);
		cin.ignore(0);
		if (!regex_match(s, re_personalKey) || s.empty()) {
			cout << "Input is not valid\n";	
		}
		else {
			setPersonalKey(s);
			break;
		}
	}
	cout << "ODO number: ";
	setODO(checkOdoAndSRemind());
	cout << "Remind Service: ";
	setServiceRemind(checkOdoAndSRemind());
}

void Setting::PrintInformationJoint() {
	cout << setw(20) << left << car_name << setw(20) << left << email << setw(10) << left << personal_key << setw(10) << left << odo << setw(15) << left << service_remind;
}