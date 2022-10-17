#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// get, set information Languages and timezones 
class CommonInfo {
public:
	string getNumber() {
		return number;
	}
	string getName() {
		return name;
	}
	void setNumber(string data) {
		number = data;
	}
	void setName(string data) {
		name = data;
	}
private:
	string number;
	string name;
};

#endif // COMMON_H_

