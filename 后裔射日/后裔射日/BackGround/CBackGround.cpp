#include"CBackGround.h"
#include"../GameConfig/CGameConfig.h"
CBackGround::CBackGround()
{
	m_x = m_y = 0;
	
}

CBackGround::~CBackGround()
{

}

void CBackGround::InitBack(int tot)
{
	if (tot == 1)
	{
		m_x=IMG_BK_ONE_WIDTH; 
		m_y=0;
		::loadimage(&m_back, L"./settings/bk1.png");
	}
	else if(tot==2)
	{
		::loadimage(&m_back, L"./settings/bk2.png");
	}
}

void CBackGround::ShowBack()
{
	::putimage(m_x, m_y, &m_back);
}

void CBackGround::MoveBack(int step)
{
	m_x += step;
	if (m_x >= 0)m_x = -IMG_BK_ONE_WIDTH;
}