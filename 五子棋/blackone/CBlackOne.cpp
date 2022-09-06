#include"CBlackOne.h"
#include"../GameConfig/GameConfig.h"


CBlackOne::CBlackOne()
{
	m_x = -50;
	m_y = -50;
}
CBlackOne::~CBlackOne()
{
	
}
void CBlackOne::PlayerClick(POINT po)
{
	m_x = po.x- CHESS_BOARD_OUTSIDE;
	m_y = po.y- CHESS_BOARD_OUTSIDE;
	m_blackrow[(m_x) / CHESS_BOARD_SPACING] = m_x / CHESS_BOARD_SPACING;
	m_blackline[(m_y) / CHESS_BOARD_SPACING] = m_y / CHESS_BOARD_SPACING;
	

}

void CBlackOne::InitPlayer(int x,int y)
{
	//����ͼƬ,·��������ڹ����ļ����ڵ�·��
	::loadimage(&m_blackone, L"./res/��1.png");// ./ͬ����Ŀ¼
	::loadimage(&m_blackoneMask, L"./res/��1��.png");// ./ͬ����Ŀ¼
	m_x = x-18;
	m_y = y-18;

}
void CBlackOne::ShowPlayer()
{
	//���ڱ���ͼ����ȫ������ �б߿� ����������ͼ����
	if (0 <= m_blackrow[m_x / CHESS_BOARD_SPACING]
		&& m_blackrow[m_x / CHESS_BOARD_SPACING] < CHESS_BOARD_PIECES_NUMBER
		&& 0 <= m_blackline[m_y / CHESS_BOARD_SPACING]
		&& m_blackline[m_y / CHESS_BOARD_SPACING] < CHESS_BOARD_PIECES_NUMBER
		)
	{
		::putimage(
			m_x,m_y,
			&m_blackoneMask, SRCPAINT); //��ͼ
		::putimage(
			m_x, m_y,
			&m_blackone,SRCAND); //��ͼ
		
	}

}
CBlackOne* CBlackOne::ChessPiece(POINT po)
{
	CBlackOne* pOne = new CBlackOne;
	int x = ((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	int y = ((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	pOne->InitPlayer(x, y);
	return pOne;//�������ӵĵ�ַ
}


