#include"FoePlaneMiddle.h"
#include"../GameConfig/GameConfig.h"
#include"../PlaneApp/PlaneApp.h"

CFoePlaneMiddle::CFoePlaneMiddle()
{

}
CFoePlaneMiddle::~CFoePlaneMiddle()
{

}

void CFoePlaneMiddle::InitFoe()
{
	::loadimage(&m_foe, L"./res/foeplanemid.jpg");
	m_x = CPlaneApp::m_randNum% (IMG_BACKGROUND_WIDTH - IMG_FOEMIDDLE_WIDTH) + 1;
	m_y = -IMG_FOEMIDDLE_HEIGHT;
	m_blood = FOE_MIDDLE_BLOOD(�е�);
	m_showid = 3;
	m_points = FOE_MIDDLE_BLOOD(�е�);
}

void CFoePlaneMiddle::ShowFoe()
{
	::putimage(m_x, m_y,
		IMG_FOEMIDDLE_WIDTH, IMG_FOEMIDDLE_HEIGHT,
		&m_foe,
		IMG_FOEMIDDLE_WIDTH, (3 - m_showid) * IMG_FOEMIDDLE_HEIGHT, //��ʼ��λ�ã��߶��Ǹ�������ı��
		SRCPAINT);
	::putimage(m_x, m_y,
		IMG_FOEMIDDLE_WIDTH, IMG_FOEMIDDLE_HEIGHT,
		&m_foe,
		0, (3 - m_showid) * IMG_FOEMIDDLE_HEIGHT,//��ʼ��λ�ã��߶��Ǹ�������ı��
		SRCAND);
}

bool CFoePlaneMiddle::IsHitPlayer(CPlayerPlane& player)
{
	int x1 = player.m_x + IMG_PLAYER_WIDTH / 2;
	//��������Ƿ��غ�
	if (m_x <= x1 && x1 <= m_x + IMG_FOEMIDDLE_WIDTH &&
		m_y <= player.m_y && player.m_y <= m_y + IMG_FOEMIDDLE_HEIGHT)
	{
		return true;
	}
	int y1 = player.m_y + IMG_PLAYER_HEIGHT / 2;
	if (m_x <= player.m_x && player.m_x <= m_x + IMG_FOEMIDDLE_WIDTH &&
		m_y <= y1 && y1 <= m_y + IMG_FOEMIDDLE_HEIGHT)
	{
		return true;
	}
	int x2 = player.m_x + IMG_PLAYER_WIDTH;
	if (m_x <= x2 && x2 <= m_x + IMG_FOEMIDDLE_WIDTH &&
		m_y <= y1 && y1 <= m_y + IMG_FOEMIDDLE_HEIGHT)
	{
		return true;
	}

	return false;
}

bool CFoePlaneMiddle::IsHitGunner(CGunner* pGun)
{
	int x = pGun->m_x + IMG_GUNNER_WIDTH / 2;
	if (m_x <= x && x <= m_x + IMG_FOEMIDDLE_WIDTH &&
		m_y <= pGun->m_y && pGun->m_y <= m_y + IMG_FOEMIDDLE_HEIGHT)
	{
		return true;
	}
	return false;
}
