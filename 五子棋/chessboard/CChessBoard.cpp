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
	//����ͼƬ,·��������ڹ����ļ����ڵ�·��
	::loadimage(&m_ChessBoard, L"./res/����.jpg");// ./ͬ����Ŀ¼
	m_x = 0;
	m_y = 0;
}
void CChessBoard::ShowBack()
{
	::putimage(m_x, m_y, &m_ChessBoard); //��ͼ
}

