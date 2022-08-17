#include"PlayerPlane.h"
#include"../GameConfig/GameConfig.h"

CPlayerPlane::CPlayerPlane()
{
	m_x = 0;
	m_y = 0;
}
CPlayerPlane::~CPlayerPlane()
{

}
void CPlayerPlane::InitPlayer()
{
	::loadimage(&m_player, L"./res/playerplane.jpg");
	::loadimage(&m_playerMask, L"./res/playerplane-mask.jpg");
	m_x = (IMG_BACKGROUND_WIDTH - IMG_PLAYER_WIDTH) / 2; //正中心
	m_y = IMG_BACKGROUND_HEIGHT - IMG_PLAYER_HEIGHT;//减去玩家图片的最底部（最高部分是从0,0开始）
}

void CPlayerPlane::ShowPlayer()
{

	//SRCPAINT SRCAND ：在当前位置的图层进行位或 位与操作
	
	//先屏蔽图和背景图做位或操作 黑色0000则得到背景图本身 再用上一步的结果和飞机图做位与操作 白色1111则得到飞机本身
	::putimage(m_x, m_y,&m_playerMask, SRCPAINT);//源图（屏蔽图）和 目标图（背景图） 做一个位或操作
	::putimage(m_x, m_y, &m_player, SRCAND);//原图（即飞机图） 和上一步的结果 做一个位与操作
}

void CPlayerPlane::MovePlayer(WPARAM direct, int step)
{
	if (direct == VK_UP)
	{//向上移动
		if ((m_y - step) >= 0)
		{
			m_y -= step;
		}
		else
		{
			//m_y=0;
			m_y+=step;
		}
	}
	else if (direct == VK_DOWN)
	{//向下移动
		if ((m_y + step) <= IMG_BACKGROUND_HEIGHT - IMG_PLAYER_HEIGHT)
		{
			m_y += step;
		}
		else
		{
			m_y -= step;
			//m_y = IMG_BACKGROUND_HEIGHT - IMG_PLAYER_HEIGHT;
		}
	}
	else if (direct == VK_LEFT)
	{//向左移动
		if (m_x - step >= 0)
		{
			m_x -= step;
		}
		else
		{
			m_x += step;
			//m_x=0;
		}
	}
	else if (direct == VK_RIGHT)
	{//向右移动
		if (m_x + step <= IMG_BACKGROUND_WIDTH - IMG_PLAYER_WIDTH)
		{
			m_x += step;
		}
		else
		{
			m_x -= step;
			//m_x=IMG_BACKGROUND_WIDTH - IMG_PLAYER_WIDTH;
		}
	}
}


CGunner* CPlayerPlane::SendGunner()
{
	CGunner* pGun = new CGunner;
	int x = m_x + (IMG_PLAYER_WIDTH - IMG_GUNNER_WIDTH) / 2;
	int y = m_y - IMG_GUNNER_HEIGHT;
	pGun->InitGunner(x, y);

	return pGun;//返回这个发送出去的炮弹指针地址
}