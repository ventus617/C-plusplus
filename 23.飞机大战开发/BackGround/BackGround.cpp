#include"BackGround.h"
#include"../GameConfig/GameConfig.h"
CBackGround::CBackGround()
{
	m_x = 0;
	m_y = 0;
}
CBackGround::~CBackGround()
{

}
void CBackGround::InitBack()
{
	//����ͼƬ,·��������ڹ����ļ����ڵ�·��
	::loadimage(&m_back, L"./res/����.jpg");// ./ͬ����Ŀ¼
	m_x = 0;
	m_y = -IMG_BACKGROUND_HEIGHT;//�Ž�ȥ��ʱ���� ����ͼ��һ�� ���Ա���ͼ���ϰ벿���Ǹ���ֵ
}
void CBackGround::ShowBack()
{
	::putimage(m_x, m_y, &m_back); //��ͼ
}
void CBackGround::MoveBack(int step)
{
	m_y += step;
	if (m_y >= 0) //����Ϊ0��ʱ�� �Ѿ�������һ��ȫ����ӡ������ �����ֵ����������漴ͼƬ���ʼ
	{
		m_y = -IMG_BACKGROUND_HEIGHT;
	}
}