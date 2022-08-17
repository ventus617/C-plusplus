#pragma once
#include"../chessboard/CChessBoard.h"
#include"../GameFrame/GameFrame.h"
#include"../GameConfig/GameConfig.h"
#include"../whiteone/CWhiteBox.h"
#include"../blackone/CBlackBox.h"

class CFiveinarowApp:public CGameFrame
{
	CChessBoard m_Board;
	CWhiteOne m_White;
	CBlackOne m_Black;
	CWhiteBox m_WhiteBox;
	CBlackBox m_BlackBox;
	int tag_win[CHESS_BOARD_LENGTH][CHESS_BOARD_HEIGHT];//�ڰ����ӱ��λ
	int m_remaintime;
	IMAGE m_TimeBoard;
	IMAGE m_TimeBoardMask;
	int m_x;
	int m_y;
	int flag;
	int tag_block[CHESS_BOARD_LENGTH][CHESS_BOARD_HEIGHT];//���ӱ��λ
public:
	CFiveinarowApp();
	~CFiveinarowApp();
public:
	virtual void On_init();
	virtual void On_Paint();
	virtual void On_Close();
	virtual void ON_WM_LBUTTONDOWN(POINT po);
	void Gameover_black();
	void Gameover_white();
	void Gameover_draw();
	void Showlefttime();
	bool Winner(POINT po);
	virtual void ON_WM_TIMER(WPARAM wo, LPARAM lo) override; //override:Ҫ��ǰ���ε��麯��һ����Ҫ��д���麯��;
	void SetTimer();

};