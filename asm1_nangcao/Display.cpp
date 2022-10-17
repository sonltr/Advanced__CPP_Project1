#include "Display.h"

Display::Display()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display() {}

int Display::get_light_level() {
	return light_level;
}

int Display::get_screen_light_level() {
	return screen_light_level;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}
void Display::set_light_level(int data) {
	light_level = data;
}

void Display::set_screen_light_level(int data) {
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
	taplo_light_level = data;
}

void Display::InputDisplay() {
	cout << "light level: ";
	cin >> light_level;
	cout << "screen light level: ";
	cin >> screen_light_level;
	cout << "taplo light level: ";
	cin >> taplo_light_level;
}

void Display::PrintInformationDisplay() {
	cout << setw(10) << left << light_level << setw(10) << left << taplo_light_level << setw(10) << left << screen_light_level << endl;
}