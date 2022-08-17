#pragma once
#include"../GameFrame/GameFrame.h" // ../�ϲ�Ŀ¼
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
	virtual void ON_WM_TIMER(WPARAM wo, LPARAM lo) override; //override:Ҫ��ǰ���ε��麯��һ����Ҫ��д���麯��;
	virtual void ON_WM_KEYDOWN(WPARAM wo);
	void SetTimer();
	void GameOver();
	void ShowScore();
};