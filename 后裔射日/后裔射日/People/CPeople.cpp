#include"CPeople.h"
#include"../GameConfig/CGameConfig.h"
CPeople::CPeople()
{
	m_x = 0;
	m_y = 0;
}

CPeople::~CPeople()
{
	
}

void CPeople::InitPeo()
{
	::loadimage(&m_Peomask, L"./settings/houyimask.jpg");
	::loadimage(&m_Peo, L"./settings/houyi.jpg");

	m_x = 0;
	m_y = IMG_BK_ONE_HEIGHT - IMG_PEO_HEIGHT;
}

void CPeople::ShowPeo()
{
	::putimage(m_x, m_y, &m_Peomask, SRCPAINT);
	::putimage(m_x, m_y, &m_Peo, SRCAND);
}
CArrow* CPeople::Archery(CTarget& tar)
{
	CArrow* pArr = new CArrow;
	pArr->InitArrow(tar.m_x  , tar.m_y );
	return pArr;
}