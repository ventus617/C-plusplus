#include"FoePlaneBig.h"
#include"../GameConfig/GameConfig.h"
#include"../PlaneApp/PlaneApp.h"

CFoePlaneBig::CFoePlaneBig()
{

}
CFoePlaneBig::~CFoePlaneBig()
{

}

void CFoePlaneBig::InitFoe()
{
	::loadimage(&m_foe, L"./res/foeplanebig.jpg");
	m_x= CPlaneApp::m_randNum %(IMG_BACKGROUND_WIDTH-IMG_FOEBIG_WIDTH)+1;
	m_y=-IMG_FOEBIG_HEIGHT;
	m_blood=FOE_BIG_BLOOD(中等);
	m_showid=4;
	m_points= FOE_BIG_BLOOD(中等);
}

void CFoePlaneBig::ShowFoe()
{
	::putimage(m_x, m_y, 
		IMG_FOEBIG_WIDTH,IMG_FOEBIG_HEIGHT, 
		&m_foe,
		IMG_FOEBIG_WIDTH, (4 - m_showid) * IMG_FOEBIG_HEIGHT, //开始的位置，高度是根据情况改变的
		SRCPAINT);
	::putimage(m_x, m_y,
		IMG_FOEBIG_WIDTH, IMG_FOEBIG_HEIGHT,
		&m_foe,
		0, (4 - m_showid) * IMG_FOEBIG_HEIGHT,//开始的位置，高度是根据情况改变的
		SRCAND);
}

bool CFoePlaneBig::IsHitPlayer(CPlayerPlane& player)
{
	int x1=player.m_x + IMG_PLAYER_WIDTH / 2;
	//点和坐标是否重合
	if (m_x <= x1 && x1 <= m_x + IMG_FOEBIG_WIDTH &&
		m_y <= player.m_y && player.m_y <= m_y + IMG_FOEBIG_HEIGHT)
	{
		return true;
	}
	int y1 = player.m_y + IMG_PLAYER_HEIGHT / 2;
	if (m_x <= player.m_x && player.m_x <= m_x + IMG_FOEBIG_WIDTH &&
		m_y <= y1 && y1 <= m_y + IMG_FOEBIG_HEIGHT)
	{
		return true;
	}
	int x2 = player.m_x + IMG_PLAYER_WIDTH;
	if (m_x <= x2 && x2 <= m_x + IMG_FOEBIG_WIDTH &&
		m_y <= y1 && y1 <= m_y + IMG_FOEBIG_HEIGHT)
	{
		return true;
	}

	return false;
}

bool CFoePlaneBig::IsHitGunner(CGunner* pGun)
{

	int x = pGun->m_x + IMG_GUNNER_WIDTH / 2;
	if (m_x <= x && x <= m_x + IMG_FOEBIG_WIDTH &&
		m_y <= pGun->m_y && pGun->m_y <= m_y + IMG_FOEBIG_HEIGHT)
	{
		return true;
	}
	return false;
}
