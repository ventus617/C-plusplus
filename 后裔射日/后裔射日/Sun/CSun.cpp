#include"CSun.h"
#include"../GameConfig/CGameConfig.h"
#include<time.h>

CSun::CSun()
{
	m_x = 0;
	m_y = 0;
	m_blood = 0;
}

CSun::~CSun()
{

}


void CSun::InitSun()
{
	//srand((unsigned)time(nullptr));
	m_x = (rand()%(4*IMG_SUN_WIDTH))+IMG_BK_ONE_WIDTH - 5*IMG_SUN_WIDTH;
	m_y = rand()%(3*IMG_SUN_HEIGHT);
	m_blood = SUN_BLOOD;
	::loadimage(&m_sunmask, L"./settings/sunmask.jpg");
	::loadimage(&m_sun, L"./settings/sun.jpg");
}

void CSun::ShowSun()
{
	::putimage(m_x, m_y, &m_sunmask, SRCPAINT);
	::putimage(m_x, m_y, &m_sun, SRCAND);
}