#include "Sound.h"

Sound::Sound()
{
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}

Sound::~Sound() {}

void Sound::InputSound() {
	cout << "media level: ";
	cin >> media_level;
	cout << "call level: ";
	cin >> call_level;
	cout << "navi level: ";
	cin >> navi_level;
	cout << "notification level: ";
	cin >> notification_level;
}

void Sound::PrintInformationSound() {
	cout << setw(10) << left << media_level << setw(10) << left << call_level << setw(10) << left << navi_level << setw(10) << left << notification_level << endl;
}

int Sound::get_media_level() {
	return media_level;
}

int Sound::get_call_level() {
	return call_level;
}

int Sound::get_navi_level() {
	return navi_level;
}

int Sound::get_notification_level() {
	return notification_level;
}

void Sound::set_media_level(int data) {
	media_level = data;
}

void Sound::set_call_level(int data) {
	call_level = data;
}

void Sound::set_navi_level(int data) {
	navi_level = data;
}

void Sound::set_notification_level(int data) {
	notification_level = data;
}

