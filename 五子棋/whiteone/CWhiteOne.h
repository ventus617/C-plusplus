#pragma once
#include<easyx.h>
#include"../GameConfig/GameConfig.h"

class CWhiteOne
{
public:
	IMAGE m_whiteone;
	int m_x;
	int m_y;
	int m_whiterow[CHESS_BOARD_LENGTH];
	int m_whiteline[CHESS_BOARD_HEIGHT];
	IMAGE m_whiteoneMask;
public:
	CWhiteOne();
	~CWhiteOne();
public:
	void InitPlayer(int x,int y);
	void ShowPlayer();
	void PlayerClick(POINT po);
	CWhiteOne* ChessPiece(POINT po);
};