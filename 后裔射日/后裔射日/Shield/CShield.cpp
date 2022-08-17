#include"CShield.h"
#include"../GameConfig/CGameConfig.h"

CShield::CShield()
{
	m_x = 0;
	m_y = 0;
}

CShield::~CShield()
{

}

void CShield::InitShield(int x, int y)
{
	m_x = x;
	m_y = y;
	::loadimage(&m_she, L"./settings/fangyu.jpg");
	::loadimage(&m_shemask, L"./settings/fangyumask.jpg");
}

void CShield::ShowShield()
{
	::putimage(m_x, m_y, &m_shemask, SRCPAINT);
	::putimage(m_x, m_y, &m_she,SRCAND);
}

//void CShield::MoveShield(int step)
//{
//
//}

bool CShield::isHitArrow(CArrow* pArr)
{
	int x = pArr->m_x + (IMG_ARR_WIDTH >> 1);
	int y = pArr->m_y + (IMG_ARR_HEIGHT >> 1);
	if (m_x <= x && x <= m_x + IMG_SHE_WIDTH && m_y <= y && y <= m_y + IMG_SHE_HEIGHT)return true;
	return false;
}