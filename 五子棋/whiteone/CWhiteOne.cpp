#include"CWhiteOne.h"
#include"../GameConfig/GameConfig.h"

CWhiteOne::CWhiteOne()
{
	//负的就行 只要初始化的一个棋子不在棋盘上存在
	m_x = -50;
	m_y = -50;
}
CWhiteOne::~CWhiteOne()
{

}
void CWhiteOne::PlayerClick(POINT po)
{
	m_x = po.x - CHESS_BOARD_OUTSIDE;//偏移量 和棋框外的额外部分有关
	m_y = po.y - CHESS_BOARD_OUTSIDE;//偏移量
	m_whiterow[(m_x) / CHESS_BOARD_SPACING] = m_x / CHESS_BOARD_SPACING;
	m_whiteline[(m_y) / CHESS_BOARD_SPACING] = m_y / CHESS_BOARD_SPACING;
	
}

void CWhiteOne::InitPlayer(int x,int y)
{
	//加载图片,路径是相对于工程文件所在的路径
	::loadimage(&m_whiteone, L"./res/白1.png");// ./同级的目录
	::loadimage(&m_whiteoneMask, L"./res/白1副.png");
	m_x = x-18;
	m_y = y-18;

}
void CWhiteOne::ShowPlayer()
{
	//由于背景图不是全是棋盘 有边框 所以设置贴图条件
	if (0 <= m_whiterow[m_x / CHESS_BOARD_SPACING]
		&& m_whiterow[m_x / CHESS_BOARD_SPACING] < CHESS_BOARD_PIECES_NUMBER
		&& 0 <= m_whiteline[m_y / CHESS_BOARD_SPACING]
		&& m_whiteline[m_y / CHESS_BOARD_SPACING] < CHESS_BOARD_PIECES_NUMBER
		)
	{
		::putimage(
			m_x,m_y,
			&m_whiteoneMask,SRCPAINT); //贴图
		::putimage(
			m_x,m_y,
			&m_whiteone,SRCAND); //贴图
		
	}

}

CWhiteOne* CWhiteOne::ChessPiece(POINT po)
{
	CWhiteOne* pOne = new CWhiteOne;
	int x = ((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	int y = ((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) * CHESS_BOARD_SPACING + 22;
	pOne->InitPlayer(x, y);
	return pOne;//返回棋子的地址
}
