#pragma once
#pragma once
#include<easyx.h>
#include"../GameConfig/GameConfig.h"

class CBlackOne
{
public:
	IMAGE m_blackone;
	int m_x;
	int m_y;
	int m_blackrow[CHESS_BOARD_LENGTH];
	int m_blackline[CHESS_BOARD_HEIGHT];
	IMAGE m_blackoneMask;
public:
	CBlackOne();
	~CBlackOne();
public:
	void InitPlayer(int x,int y);
	void ShowPlayer();
	void PlayerClick(POINT po);
	CBlackOne* ChessPiece(POINT po);
};