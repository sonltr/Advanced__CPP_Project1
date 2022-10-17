#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

// class information joint
class Setting {
public:
	Setting();
	virtual ~Setting();
	//input and print information joint
	void InputInformationJoint();
	void PrintInformationJoint();
	
	//funtion get, set information Joint
	string getCarName();
	string getPersonalKey();
	string getEmail();
	int getODO();
	int getServiceRemind();
	void setCarName(string data);
	void setPersonalKey(string data);
	void setEmail(string data);
	void setODO(int data);
	void setServiceRemind(int data);
	//funtion check
	int checkOdoAndSRemind();
private:
	string car_name;
	string personal_key; 	 
	string email;			 
	int odo;
	int service_remind;

};
#endif /* SETTING_H_ */

