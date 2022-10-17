#pragma once
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

class CarSetting : public Setting
{
private:
	Display* m_disp;
	Sound* m_sound;
	General* m_gen;
	
public:
	CarSetting();
	~CarSetting();
	Display* getDisplay();
	Sound* getSound();
	General* getGeneral();
	//function update information joint
	void UpdateInfomationJoint(CarSetting s);
};

