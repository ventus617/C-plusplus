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
	m_x = (IMG_BACKGROUND_WIDTH - IMG_PLAYER_WIDTH) / 2; //������
	m_y = IMG_BACKGROUND_HEIGHT - IMG_PLAYER_HEIGHT;//��ȥ���ͼƬ����ײ�����߲����Ǵ�0,0��ʼ��
}

void CPlayerPlane::ShowPlayer()
{

	//SRCPAINT SRCAND ���ڵ�ǰλ�õ�ͼ�����λ�� λ�����
	
	//������ͼ�ͱ���ͼ��λ����� ��ɫ0000��õ�����ͼ���� ������һ���Ľ���ͷɻ�ͼ��λ����� ��ɫ1111��õ��ɻ�����
	::putimage(m_x, m_y,&m_playerMask, SRCPAINT);//Դͼ������ͼ���� Ŀ��ͼ������ͼ�� ��һ��λ�����
	::putimage(m_x, m_y, &m_player, SRCAND);//ԭͼ�����ɻ�ͼ�� ����һ���Ľ�� ��һ��λ�����
}

void CPlayerPlane::MovePlayer(WPARAM direct, int step)
{
	if (direct == VK_UP)
	{//�����ƶ�
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
	{//�����ƶ�
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
	{//�����ƶ�
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
	{//�����ƶ�
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

	return pGun;//����������ͳ�ȥ���ڵ�ָ���ַ
}