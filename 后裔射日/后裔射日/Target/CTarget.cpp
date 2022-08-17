#include"CTarget.h"
#include"../GameConfig/CGameConfig.h"

CTarget::CTarget()
{
	m_x = 0;
	m_y = 0;
	f = 1;
}
CTarget::~CTarget()
{

}

void CTarget::InitTarget()
{
	m_x = 0;
	m_y = IMG_BK_ONE_HEIGHT-IMG_PEO_HEIGHT-2*IMG_TAR_HEIGHT;
	::loadimage(&m_tarmask, L"./settings/targetmask.jpg");
	::loadimage(&m_tar, L"./settings/target.jpg");
}

void CTarget::ShowTarget()
{
	::putimage(m_x, m_y, &m_tarmask, SRCPAINT);
	::putimage(m_x, m_y, &m_tar, SRCAND);
}

void CTarget::MoveTarget(int step)
{
	if (f & 1)m_x += step, m_y += step;
	else m_x -= step, m_y -= step;
	if (m_x >= IMG_PEO_WIDTH + 2*IMG_TAR_WIDTH)
	{
		f++;
	}
	else if (m_x <= -IMG_TAR_WIDTH)f--;
}