#pragma once
#include"../GameFrame/GameFrame.h" // ../上层目录
#include"../BackGround/BackGround.h"
#include"../PlayerPlane/PlayerPlane.h"
#include"../GunnerBox/GunnerBox.h"
#include"../FoePlaneBox/FoePlaneBox.h"

class CPlaneApp :public CGameFrame
{
public:
	CBackGround m_back;
	CPlayerPlane m_player;
	CGunnerBox m_gunBox;
	CFoePlaneBox m_foeBox;
	int m_total_score;
	static size_t m_randNum;
	IMAGE m_scoreBoard;
public:
	CPlaneApp();
	~CPlaneApp();
public:

	virtual void On_init() ;
	virtual void On_Paint() ;
	virtual void On_Close() ;
	virtual void ON_WM_TIMER(WPARAM wo, LPARAM lo) override; //override:要求当前修饰的虚函数一定是要重写的虚函数;
	virtual void ON_WM_KEYDOWN(WPARAM wo);
	void SetTimer();
	void GameOver();
	void ShowScore();
};