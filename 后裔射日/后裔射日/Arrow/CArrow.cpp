#include"CArrow.h"
#include"../GameConfig/CGameConfig.h"

CArrow::CArrow()
{
	m_x = 0;
	m_y = 0;
}

CArrow::~CArrow()
{

}


void CArrow::InitArrow(int x, int y)
{
	m_x = x;
	m_y = y;
	::loadimage(&m_arrowmask, L"./settings/jianmask.jpg");
	::loadimage(&m_arrow, L"./settings/jian.jpg");
}

void CArrow::ShowArrow()
{
	::putimage(m_x, m_y, &m_arrowmask, SRCPAINT);
	::putimage(m_x, m_y, &m_arrow, SRCAND);
}

void CArrow::MoveArrow(int step)
{
	m_x += (step/2);
	m_y -= (step/3);
}

bool CArrow::isHitSun(CSun* pSun)
{
	int x = m_x + (IMG_ARR_WIDTH >> 1);
	int y = m_y + (IMG_ARR_HEIGHT >> 1);
	if (pSun->m_x <= x && x <= (pSun->m_x + IMG_SUN_WIDTH) && pSun->m_y <= y && y <= (pSun->m_y + IMG_SUN_HEIGHT))
	{
		return true;
	}return false;
}