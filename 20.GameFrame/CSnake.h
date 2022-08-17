#pragma once
#include"GameFrame.h"
class CSnake :public CGameFrame
{
public:
	virtual void On_init();
	virtual void On_Paint();
	virtual void On_Close();
	virtual void ON_WM_LBUTTONDOWN(POINT po);
	CSnake();
	~CSnake();
};

