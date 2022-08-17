#pragma once
#include<easyx.h>

class CChessBoard
{
public:
	IMAGE m_ChessBoard;
	int m_x;
	int m_y;

public:
	CChessBoard();
	~CChessBoard();
public:
	void InitBack();
	void ShowBack();
};