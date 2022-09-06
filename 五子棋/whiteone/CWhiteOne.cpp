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
	m_x = po.x - CHESS_BOARD_OUTSIDE;//ƫ���� �������Ķ��ⲿ���й�
	m_y = po.y - CHESS_BOARD_OUTSIDE;//ƫ����
	m_whiterow[(m_x) / CHESS_BOARD_SPACING] = m_x / CHESS_BOARD_SPACING;
	m_whiteline[(m_y) / CHESS_BOARD_SPACING] = m_y / CHESS_BOARD_SPACING;
	
}

void CWhiteOne::InitPlayer(int x,int y)
{
	//����ͼƬ,·��������ڹ����ļ����ڵ�·��
	::loadimage(&m_whiteone, L"./res/��1.png");// ./ͬ����Ŀ¼
	::loadimage(&m_whiteoneMask, L"./res/��1��.png");
	m_x = x-18;
	m_y = y-18;

}
void CWhiteOne::ShowPlayer()
{
	//���ڱ���ͼ����ȫ������ �б߿� ����������ͼ����
	if (0 <= m_whiterow[m_x / CHESS_BOARD_SPACING]
		&& m_whiterow[m_x / CHESS_BOARD_SPACING] < CHESS_BOARD_PIECES_NUMBER
		&& 0 <= m_whiteline[m_y / CHESS_BOARD_SPACING]
		&& m_whiteline[m_y / CHESS_BOARD_SPACING] < CHESS_BOARD_PIECES_NUMBER
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
	int x = ((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	int y = ((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	pOne->InitPlayer(x, y);
	return pOne;//�������ӵĵ�ַ
}
