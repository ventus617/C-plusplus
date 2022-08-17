#include"FoePlaneSmall.h"
#include"../GameConfig/GameConfig.h"
#include"../PlaneApp/PlaneApp.h"

CFoePlaneSmall::CFoePlaneSmall()
{

}
CFoePlaneSmall::~CFoePlaneSmall()
{

}

void CFoePlaneSmall::InitFoe()
{
	::loadimage(&m_foe, L"./res/foeplanesma.jpg");
	m_x = CPlaneApp::m_randNum% (IMG_BACKGROUND_WIDTH - IMG_FOESMALL_WIDTH) + 1;
	m_y = -IMG_FOESMALL_HEIGHT;
	m_blood = FOE_SMALL_BLOOD(中等);
	m_showid = 2;
	m_points = FOE_SMALL_BLOOD(中等);
}

void CFoePlaneSmall::ShowFoe()
{
	::putimage(m_x, m_y,
		IMG_FOESMALL_WIDTH, IMG_FOESMALL_HEIGHT,
		&m_foe,
		IMG_FOESMALL_WIDTH, (2 - m_showid) * IMG_FOESMALL_HEIGHT, //开始的位置，高度是根据情况改变的
		SRCPAINT);
	::putimage(m_x, m_y,
		IMG_FOESMALL_WIDTH, IMG_FOESMALL_HEIGHT,
		&m_foe,
		0, (2 - m_showid) * IMG_FOESMALL_HEIGHT,//开始的位置，高度是根据情况改变的
		SRCAND);
}

bool CFoePlaneSmall::IsHitPlayer(CPlayerPlane& player)
{
	int x1 = player.m_x + IMG_PLAYER_WIDTH / 2;
	//点和图片是否重合 顶点
	if (m_x <= x1 && x1 <= m_x + IMG_FOESMALL_WIDTH &&
		m_y <= player.m_y && player.m_y <= m_y + IMG_FOESMALL_HEIGHT)
	{
		return true;
	}
	//左边点
	int y1 = player.m_y + IMG_PLAYER_HEIGHT / 2;
	if (m_x <= player.m_x && player.m_x <= m_x + IMG_FOESMALL_WIDTH &&
		m_y <= y1 && y1 <= m_y + IMG_FOESMALL_HEIGHT)
	{
		return true;
	}
	//右边点
	int x2 = player.m_x + IMG_PLAYER_WIDTH;
	if (m_x <= x2 && x2 <= m_x + IMG_FOESMALL_WIDTH &&
		m_y <= y1 && y1 <= m_y + IMG_FOESMALL_HEIGHT)
	{
		return true;
	}
	return false;
}

bool CFoePlaneSmall::IsHitGunner(CGunner* pGun)
{
	//点和图片坐标是否重合
	int x = pGun->m_x + IMG_GUNNER_WIDTH / 2;
	if (m_x <= x && x <= m_x + IMG_FOESMALL_WIDTH &&
		m_y <= pGun->m_y && pGun->m_y <= m_y + IMG_FOESMALL_HEIGHT)
	{
		return true;
	}
	return false;
}
