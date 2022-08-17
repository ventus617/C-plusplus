#include"Gunner.h"
#include"../GameConfig/GameConfig.h"

CGunner::CGunner()
{
	m_x = 0;
	m_y = 0;
}
CGunner::~CGunner()
{

}
void CGunner::InitGunner(int x, int y)
{
	::loadimage(&m_gun, L"./res/gunner.jpg");
	m_x = x;
	m_y = y;
}
void CGunner::ShowGunner()
{

	::putimage(m_x, m_y,//�ŵ���Ŀ�꣨���ڣ���λ��
		IMG_GUNNER_WIDTH, IMG_GUNNER_HEIGHT, //��Ŀ�괰����ʾ��ͼƬ�Ķ���
		&m_gun, //Դͼ
		IMG_GUNNER_WIDTH, 0,//��Դͼ���ĸ�����λ�ÿ�ʼ�� ��������ͼ��
		SRCPAINT); //���䷽ʽλ��

	::putimage(m_x, m_y,//�ŵ���Ŀ�꣨���ڣ���λ��
		IMG_GUNNER_WIDTH, IMG_GUNNER_HEIGHT, //��Ŀ�괰����ʾ��ͼƬ�Ķ���
		&m_gun, //Դͼ
		0, 0,//��Դͼ���ĸ�����λ�ÿ�ʼ�ң����ӵ�ͼ��
		SRCAND); //���䷽ʽλ��
}
void CGunner::MoveGunner(int step)
{
	m_y -= step; //���� ����
}