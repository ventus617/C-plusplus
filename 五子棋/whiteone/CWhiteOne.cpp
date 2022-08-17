#include"CWhiteOne.h"
#include"../GameConfig/GameConfig.h"

CWhiteOne::CWhiteOne()
{
	//���ľ��� ֻҪ��ʼ����һ�����Ӳ��������ϴ���
	m_x = -50;
	m_y = -50;
}
CWhiteOne::~CWhiteOne()
{

}
void CWhiteOne::PlayerClick(POINT po)
{
	m_x = po.x - 25;//ƫ���� �������Ķ��ⲿ���й�
	m_y = po.y - 25;//ƫ����
	m_whiterow[(m_x) / CHESS_BOARD_SPACING] = m_x / CHESS_BOARD_SPACING;
	m_whiteline[(m_y) / CHESS_BOARD_SPACING] = m_y / CHESS_BOARD_SPACING;
	
}

void CWhiteOne::InitPlayer(int x,int y)
{
	//����ͼƬ,·��������ڹ����ļ����ڵ�·��
	::loadimage(&m_whiteone, L"./res/��1.png");// ./ͬ����Ŀ¼
	::loadimage(&m_whiteoneMask, L"./res/��1��.png");
	m_x = x;
	m_y = y;

}
void CWhiteOne::ShowPlayer()
{
	//���ڱ���ͼ����ȫ������ �б߿� ����������ͼ����
	if (0 <= m_whiterow[m_x / CHESS_BOARD_SPACING]
		&& m_whiterow[m_x / CHESS_BOARD_SPACING] < 14
		&& 0 <= m_whiteline[m_y / CHESS_BOARD_SPACING]
		&& m_whiteline[m_y / CHESS_BOARD_SPACING] < 14
		)
	{
		::putimage(
			m_x,m_y,
			&m_whiteoneMask,SRCPAINT); //��ͼ
		::putimage(
			m_x,m_y,
			&m_whiteone,SRCAND); //��ͼ
		
	}

}

CWhiteOne* CWhiteOne::ChessPiece(POINT po)
{
	CWhiteOne* pOne = new CWhiteOne;
	int x = ((po.x - 25) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	int y = ((po.y - 25) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	pOne->InitPlayer(x, y);
	return pOne;//�������ӵĵ�ַ
}
