#include "CarSetting.h"

CarSetting::CarSetting()
{
	m_disp = new Display();
	m_sound = new Sound();
	m_gen = new General();
}

CarSetting::~CarSetting()
{
}

Display* CarSetting::getDisplay()
{
	return m_disp;
}

Sound* CarSetting::getSound()
{
	return m_sound;
}

General* CarSetting::getGeneral()
{
	return m_gen;
}
void CarSetting::UpdateInfomationJoint(CarSetting st)
{
	 setCarName(st.getCarName());
	 setPersonalKey(st.getPersonalKey());
	 setODO(st.getODO());
	 setEmail(st.getEmail());
	 setServiceRemind(st.getServiceRemind());
}




