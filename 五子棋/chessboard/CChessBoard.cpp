#include"CChessBoard.h"

CChessBoard::CChessBoard()
{
	m_x = 0;
	m_y = 0;
}
CChessBoard::~CChessBoard()
{

}
void CChessBoard::InitBack()
{
	//加载图片,路径是相对于工程文件所在的路径
	::loadimage(&m_ChessBoard, L"./res/棋盘.jpg");// ./同级的目录
	m_x = 0;
	m_y = 0;
}
void CChessBoard::ShowBack()
{
	::putimage(m_x, m_y, &m_ChessBoard); //贴图
}

