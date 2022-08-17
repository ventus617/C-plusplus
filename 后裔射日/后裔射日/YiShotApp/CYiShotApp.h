#pragma once 

#include"../GameFrame/GameFrame.h"
#include"../BackGround/CBackGround.h"
#include"../People/CPeople.h"
#include"../Arrow/CArrowBox.h"
#include"../Target/CTarget.h"
#include"../Sun/CSunBox.h"
#include"../Shield/CShieldBox.h"
class CYiShotApp :public CGameFrame
{
public:
	IMAGE		m_finalscore;
	CBackGround m_back;
	CPeople		m_peo;
	CArrowBox	m_arrbox;
	CTarget		m_target;
	CSunBox		m_sunbox;
	CShieldBox	m_shieldbox;
	//clock_t start;
	int			m_time;
	int			m_score;
	int			m_deNum;
public:
	CYiShotApp();

	~CYiShotApp();
public:

	virtual void On_Init();

	virtual void On_Paint();

	virtual void On_Close();

	virtual void On_WM_CHAR(WPARAM w);

	virtual void On_WM_TIMER(WPARAM w, LPARAM l);

	void SetTimer();

	void GameOver();

	void ShowScore();
	
	void StarMessage();

	void GreatShield(int num, int step_x,int step_y);
};



