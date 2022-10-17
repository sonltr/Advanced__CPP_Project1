#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include "CarSetting.h"
#include <fstream>
#include <regex>
#include <iomanip>


using namespace std;

CarSetting* listCar = new CarSetting[100];
// count the number of cars
int countCar = 0;
//copy key of personal_key
int* copyKey = new int;

vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void InputSettingInformation();
void PrintSettingInformation();

void PrintSettingsInformationDisplay();
void PrintSettingInformationSound();
void PrintSettingsInformationGeneral();
void PrintSettingInformationAll();

void inputSettingDisplay();
void inputSettingSound();
void inputSettingGeneral();

void downloadTimeZone();
void downloadLanguage();
void showThongTinTIMEZONES();
void showThongTinLANGUAGES();

int checkKey(string key);
int checkInput(int length);
bool checkYorN();

void TangDan(int a[], int n);
void getkey();
void menu();


int main(int argc, char** argv) {
	//cout << "hi4" << endl;
	downloadLanguage();
	downloadTimeZone();
	menu();

	delete[]listCar;

	return 0;
}

void menu()
{
	int SelectMenu1 = 0;
	regex re_num("[1-3]{1}");
	cout << "-----SELECT menu 1-----" << endl;
	cout << "1. Input setting information" << endl;
	cout << "2. Print setting information" << endl;
	cout << "3. Exit" << endl;
	cout << "Your selction:  ";

	string strMenu1 = "";
	getline(cin, strMenu1);
	while (regex_match(strMenu1, re_num) == false)
	{		// check input before coming to switch
		cout << "Input 1-3: >>";
		getline(cin, strMenu1);
		cin.ignore(0);
	}
	SelectMenu1 = stoi(strMenu1);	// convert into integer
	switch (SelectMenu1)
	{
	case 1:
		system("cls");
		InputSettingInformation();
		break;
	case 2:
		system("cls");
		PrintSettingInformation();
		break;
	case 3:
		system("cls");
		cout << "---GOOD BYE---!!!";
		exit(0);
	default:
		break;
	}
}

int checkInput(int length)
{
	regex pattern("[0-9]+");
	string input;
	int numberReturn = 0;
	while (1) {
		getline(cin, input);
		if (regex_match(input, pattern) && stoi(input) < length + 1 && stoi(input) > 0) {
			numberReturn = stoi(input);
			break;
		}
	}
	return numberReturn;
}
// check whether owner key has existed or not
int checkKey(string key) {
	bool flag = false;
	int m = 0;
	for (int i = 0; i < countCar; i++) {
		if (key == listCar[i].getPersonalKey()) {
			flag = true;
			m = i;
			break;
		}
	}
	if (flag) { //true
		cout << "--->This car " << m + 1 << " already existed, data will be overitten\n";
		return m;
	}
	else {
		cout << "--->This car " << countCar + 1 << " data will be appended to your list\n";
		return countCar;
	}
}
//function to if check input is yes or no
bool checkYorN() {
	bool status = true;
	string s;
	regex no("[n|N]{1}|[no]{2}$");
	regex yes("[y|Y]{1}|[yes]{3}$");
	while (1) {
		getline(cin, s);
		cin.ignore(0);
		if (regex_match(s, yes))
		{
			return status;
		}
		if (regex_match(s, no))
		{
			status = false;
			return status;
		}
		if ((!(regex_match(s, no)) && (!regex_match(s, yes))))
		{
			cout << "y or n \n";
		}
	}
	
}
void InputSettingInformation() {

	int SelectMenu2 = 0;
	regex re_num("[0-3]{1}");
	cout << "-----SELECT menu 2-----" << endl;
	cout << "1. Input display setting  " << endl;
	cout << "2. Input sound setting  " << endl;
	cout << "3. Input general setting  " << endl;
	cout << "0. Exit" << endl;
	cout << "selction: ";

	string strMenu2 = "";
	getline(cin, strMenu2);
	while (regex_match(strMenu2, re_num) == false)
	{
		cout << "IS NOT VALUE ->INPUT 1-3:\n";
		cout << ">> ";
		getline(cin, strMenu2);
		cin.ignore(0);
	}
	// convert into integer
	SelectMenu2 = stoi(strMenu2);
	switch (SelectMenu2) {
	case 1: {
		system("cls");
		inputSettingDisplay();
		menu();
		break;
	}
	case 2: {
		system("cls");
		inputSettingSound();
		menu();
		break;
	}
	case 3: {
		system("cls");
		inputSettingGeneral();
		menu();
		break;
	}
	case 0:
		system("cls");
		menu();
		break;
	default:
	{
		break;
	}
	}
}
void inputSettingDisplay()
{
	bool continueYorN = true;
	do {
		cout << "Input Display setting----";
		if (countCar >= 100) 
		{
			cout << "100 cars limit -> can't enter more";
			break;
		}
		cout << "Car index: " << countCar + 1 << endl;
		//Input Information Joint class Setting
		listCar[countCar].InputInformationJoint();
		int n = checkKey(listCar[countCar].getPersonalKey());
		for (size_t i = 0; i < countCar; i++)
		{
			if (n == i)
			{
				listCar[n].UpdateInfomationJoint(listCar[countCar]);
				countCar--;
			}
		}
		listCar[n].getDisplay()->InputDisplay();
		// Car exitsted increase index
		countCar++;
		cout << "Will you input for car " << countCar + 1 << " ->";
		continueYorN = checkYorN();
		system("cls");
	} while (continueYorN);
}
void inputSettingSound()
{
	bool continueYorN = true;
	do {
		cout << "Input Sound setting----";
		if (countCar >= 100)
		{
			cout << "100 cars limit -> can't enter more";
			break;
		}
		cout << "Car index: " << countCar + 1 << endl;
		//Input Information Joint class Setting
		listCar[countCar].InputInformationJoint();
		int n = checkKey(listCar[countCar].getPersonalKey());
		for (size_t i = 0; i < countCar; i++)
		{
			if (n == i)
			{
				listCar[n].UpdateInfomationJoint(listCar[countCar]);
				countCar--;
			}
		}
		listCar[n].getSound()->InputSound();
		// Car exitsted increase index
		countCar++;
		cout << "Will you input for car " << countCar + 1 << " ->";
		continueYorN = checkYorN();
		system("cls");
	} while (continueYorN);
}

bool sortName(CommonInfo& a_string, CommonInfo& b_string)
{
	return (a_string.getName() < b_string.getName());
}

void showThongTinLANGUAGES()
{
	cout << "---SELECT LANGUAGE DATA---" << endl;

	sort(languageList.begin(), languageList.end(), sortName);
	for (size_t i = 0; i < languageList.size(); i++)
	{
		cout << i + 1 << ": " << languageList.at(i).getName() << endl;
	}
}
void showThongTinTIMEZONES() {
	cout << "---SELECT TIMEZONE DATA---" << endl;

	for (size_t i = 0; i < timezoneList.size(); i++)
	{
		cout << i + 1 << ": " << timezoneList.at(i).getNumber() << " " << timezoneList.at(i).getName() << endl;
	}
}
void inputSettingGeneral()
{
	int timezone_index = 0;
	int language_index = 0;
	bool continueYorN = true;
	do {
		cout << "Input General setting----";
		if (countCar >= 100)
		{
			cout << "100 cars limit -> can't enter more";
			break;
		}
		cout << "Car index: " << countCar + 1 << endl;
		//Input Information Joint class Setting
		listCar[countCar].InputInformationJoint();
		int n = checkKey(listCar[countCar].getPersonalKey());
		for (size_t i = 0; i < countCar; i++)
		{
			if (n == i)
			{
				listCar[n].UpdateInfomationJoint(listCar[n]);
				countCar--;
			}
		}
		/*
		timezone
		*/
		showThongTinTIMEZONES();
		cout << "---YOUR SELECTION -->>: ";
		timezone_index = checkInput(timezoneList.size()) - 1;
		listCar[n].getGeneral()->set_timeZone(timezoneList[timezone_index].getNumber());
		cout << endl << endl;
		/*
		language
		*/
		sort(languageList.begin(), languageList.end(), sortName);
		showThongTinLANGUAGES();
		cout << "---YOUR SELECTION -->>: ";
		language_index = checkInput(languageList.size()) - 1;
		listCar[n].getGeneral()->set_language(languageList[language_index].getName());

		// Car exitsted increase index
		countCar++;
		cout << "Will you input for car " << countCar + 1 << " ->";
		continueYorN = checkYorN();
		system("cls");
	} while (continueYorN);
}

void PrintSettingInformation() {
	int SelectMenu3 = 0;
	regex re_num("[1-5]{1}");
	cout << "---SELECT MENU 3---\n";
	cout << "1. Print Display setting information\n";
	cout << "2. print Sound setting information\n";
	cout << "3. Print General setting information\n";
	cout << "4. Print all setting information\n";
	cout << "5. Exit\n";
	cout << "Your selection: ";
	string strMenu3 = "";
	getline(cin, strMenu3);
	while (regex_match(strMenu3, re_num) == false)
	{
		cout << "IS NOT VALUE ->INPUT 1- 5:\n";
		cout << ">> ";
		getline(cin, strMenu3);
		cin.ignore(0);
	}
	// convert string into integer
	SelectMenu3 = stoi(strMenu3);
	switch (SelectMenu3) {
	case 1:
		system("cls");
		PrintSettingsInformationDisplay();
		break;
	case 2:
		system("cls");
		PrintSettingInformationSound();
		break;
	case 3:
		system("cls");
		PrintSettingsInformationGeneral();
		break;
	case 4:
		system("cls");
		PrintSettingInformationAll();
		break;
	case 5:
		system("cls");
		menu();
		break;
	default:
		break;
	}
}

const vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

void downloadLanguage() {
	ifstream file;
	file.open("languages.txt");
	if (file.good() == true)
	{
		string str;
		while (getline(file, str))
		{
			vector<string> strLine = explode(str, '/');
			if (strLine.size() >= 2)
			{
				CommonInfo info;
				info.setNumber(strLine.at(0));
				info.setName(strLine.at(1));
				languageList.push_back(info);
			}
		}

	}
	else
	{
		cout << "Can not read file!" << endl;
	}
	file.close();
}
void downloadTimeZone() {
	ifstream file;
	file.open("timezones.txt");
	if (file.good() == true)
	{
		string str;
		while (getline(file, str))
		{
			vector<string> strLine = explode(str, '/');
			if (strLine.size() >= 2)
			{
				CommonInfo info;
				info.setNumber(strLine.at(0));
				info.setName(strLine.at(1));
				timezoneList.push_back(info);
			}
		}
	}
	else
	{
		cout << "Can not read file!" << endl;
	}
	file.close();
}


void getkey()
{
	for (size_t c = 0; c < countCar; c++)
	{
		*(copyKey + c) = stoi(listCar[c].getPersonalKey());
	}
}
void TangDan(int a[], int n) {
	int tg;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				// Hoan vi 2 so a[i] va a[j]
				tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
void PrintSettingsInformationDisplay()
{
	getkey();
	TangDan(copyKey, countCar);
	cout << "---Print Display setting---\n";
	cout << setw(20) << left << "Owner name" << setw(20) << left << "Email" << setw(10) << left << "Key" << setw(10) << left << "ODO" << setw(15) << left << "service" << setw(10) << left << "Light" << setw(10) << left << "Taplo" << setw(10) << left << "Screen" << endl;
	for (int t = 0; t < countCar; t++)
	{
		for (int i = 0; i < countCar; i++)
		{
			if (copyKey[t] == stoi(listCar[i].getPersonalKey()))
			{
				listCar[i].PrintInformationJoint();
				listCar[i].getDisplay()->PrintInformationDisplay();
			}
		}
	}
	PrintSettingInformation();
}
void PrintSettingInformationSound() 
	{
		getkey();
		TangDan(copyKey, countCar);
		cout << "---Print Sound setting---\n";
		cout << setw(20) << left << "Owner name" << setw(20) << left << "Email" << setw(10) << left << "Key" << setw(10) << left << "ODO" << setw(15) << left << "service" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(10) << left << "Navi" << setw(10) << left << "Notify" << endl;
		for (int t = 0; t < countCar; t++)
		{
			for (int i = 0; i < countCar; i++)
			{
				if (copyKey[t] == stoi(listCar[i].getPersonalKey()))
				{
					listCar[i].PrintInformationJoint();
					listCar[i].getSound()->PrintInformationSound();
				}
			}
		}
		PrintSettingInformation();
	}

void PrintSettingsInformationGeneral() 
{
	getkey();
	TangDan(copyKey, countCar);
	cout << "---Print General setting---\n";
	cout << setw(20) << left << "Owner name" << setw(20) << left << "Email" << setw(10) << left << "Key" << setw(10) << left << "ODO" << setw(15) << left << "service" << setw(15) << left << "TimeZone" << setw(15) << left << "Language" << endl;
	for (int t = 0; t < countCar; t++)
	{
		for (int i = 0; i < countCar; i++)
		{
			if (copyKey[t] == stoi(listCar[i].getPersonalKey()))
			{
				listCar[i].PrintInformationJoint();
				listCar[i].getGeneral()->PrintInformationGeneral();
				cout << endl;
			}
		}
	}
	PrintSettingInformation();
}



void PrintSettingInformationAll()
{

	getkey();
	TangDan(copyKey, countCar);
	cout << "---Print All setting---\n";
	for (int t = 0; t < countCar; t++)
	{
		for (size_t i = 0; i < countCar; i++)
		{
			if (copyKey[t] == stoi(listCar[i].getPersonalKey()))
			{

				cout << "  " << t + 1 << "  "

					<< setw(20) << left << "Owner name" << setw(20) << left << "Email" << setw(10) << left << "Key" << setw(10) << left << "ODO" << setw(15) << left << "Service" << endl;
				cout << "     ";
				listCar[i].PrintInformationJoint();
				cout << endl;

				cout << "     Display:       " << setw(10) << left << "Light" << setw(10) << left << "Taplo" << setw(10) << left << "Screen" << endl;
				cout << setw(20) << left << "";
				listCar[i].getDisplay()->PrintInformationDisplay();

				cout << "     Sound:         " << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(10) << left << "Navi" << setw(10) << left << "Notify" << endl;;
				cout << setw(20) << left << "";
				listCar[i].getSound()->PrintInformationSound();

				cout << "     General:       " << setw(15) << left << "TimeZone" << setw(15) << left << "Language" << endl;
				cout << setw(20) << left << "";
				listCar[i].getGeneral()->PrintInformationGeneral();

				cout << endl << endl;
			}
		}
	}
	PrintSettingInformation();
}






