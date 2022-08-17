#include"CYiShotApp.h"
#include"../GameConfig/CGameConfig.h"
//TODO 1 创建文件 标题 窗口
CREAT_OBJECT(CYiShotApp);
WND_PARAM(100, 20, 800, 620, L"后羿射日");
//TODO 2 APP初始化
CYiShotApp::CYiShotApp()
{
	m_score = 0;
	m_deNum = 0;
	m_time = PEO_ATTACKS_TIME;
	::loadimage(&m_finalscore, L"./settings/score.png");
}

CYiShotApp::~CYiShotApp()
{

}
//TODO 3 初始化各个类
void CYiShotApp::On_Init()
{
	m_back.InitBack(2);
	m_peo.InitPeo();
	m_target.InitTarget();
	//m_arr.InitArrow(IMG_PEO_WIDTH, IMG_BK_ONE_HEIGHT - IMG_PEO_HEIGHT);
	GreatShield(NUM_SHIELD, NUM_SHIELD_INTERVAL_X, NUM_SHIELD_INTERVAL_Y);
	SetTimer();
	StarMessage();
}
//TODO 4 给各个需要的对象创建定时器
void CYiShotApp::SetTimer()
{
	//背景定时移动
	::SetTimer(m_hwnd, TIMER_BK_ONE_MOVE_ID, TIMER_BK_ONE_MOVE_INTERVAL, nullptr);
	//箭的出发点定时移动
	::SetTimer(m_hwnd, TIMER_TAR_MOVE_ID, TIMER_TAR_MOVE_INTERVAL, nullptr);
	//箭的定时移动
	::SetTimer(m_hwnd, TIMER_ARR_MOVE_ID, TIMER_ARR_MOVE_INTERVAL, nullptr);
	//太阳的定时生成
	::SetTimer(m_hwnd, TIMER_SUN_CREAT_ID, TIMER_SUN_CREAT_INTERVAL, nullptr);
	//太阳的消失
	::SetTimer(m_hwnd, TIMER_SUN_HURT_ID, TIMER_SUN_HURT_INTERVAL, nullptr);
	//定时结束游戏
	::SetTimer(m_hwnd, TIMER_GAMEOVER_ID, TIMER_GAMEOVER_INTERVAL, nullptr);
	//判断是否吸收箭
	::SetTimer(m_hwnd, TIMER_DEARROW_ID, TIMER_DEARROW_INTERVAL, nullptr);
}
//TODO 5 画出各个类对象
void CYiShotApp::On_Paint()
{
	m_back.ShowBack();
	m_peo.ShowPeo();
	m_target.ShowTarget();
	m_arrbox.ShowAllArrow();
	m_sunbox.ShowAllSun();
	m_shieldbox.ShowAllShield();
	//m_arr.ShowArrow();
	ShowScore();
}

void CYiShotApp::On_Close()
{

}
//TODO 6 计定时器调用
void CYiShotApp::On_WM_TIMER(WPARAM w, LPARAM l)
{
	switch (w)
	{
	case TIMER_BK_ONE_MOVE_ID:
	{
		m_back.MoveBack(TIMER_BK_ONE_MOVE_STEP);
	}break;
	case TIMER_TAR_MOVE_ID:
	{
		m_target.MoveTarget(TIMER_TAR_MOVE_STEP);
	}break;
	case TIMER_ARR_MOVE_ID:
	{
		m_arrbox.MoveAllArrow(TIMER_ARR_MOVE_STEP);
	}break;
	case TIMER_SUN_CREAT_ID:
	{
		srand((unsigned)time(nullptr));
		CSun* pSun = new CSun;
		pSun->InitSun();
		m_sunbox.m_issun.push_back(pSun);
	}break;
	case TIMER_SUN_HURT_ID:
	{	
		list<CSun*>::iterator iteSun = m_sunbox.m_issun.begin();
		bool isDestory = false;
		while (iteSun != m_sunbox.m_issun.end())
		{
			list<CArrow*>::iterator iteArr = m_arrbox.m_isarrow.begin();
			
			while (iteArr != m_arrbox.m_isarrow.end())
			{
				if ((*iteArr)->isHitSun(*iteSun))
				{
					delete (*iteArr);//回收弓箭
					(*iteArr) = nullptr;
					iteArr = m_arrbox.m_isarrow.erase(iteArr);//回收弓箭节点

					(*iteSun)->m_blood -= SUN_HURT;
					if ((*iteSun)->m_blood <= 0)//太阳血量归零
					{
						m_score += SUN_BLOOD;//加分
						iteSun = m_sunbox.m_issun.erase(iteSun);
						isDestory = true;
						break;
					}
					continue;
				}iteArr++;
			}


			isDestory ? (isDestory = false) : (iteSun++, true);
		}
	}break;
	case TIMER_GAMEOVER_ID:
	{
		m_time -= 1;
		if (m_time < 0)
		{
			GameOver();
			return;
		}
		
	}break;
	case TIMER_DEARROW_ID:
	{
		list<CShield*>::iterator iteShe = m_shieldbox.m_isshield.begin();
		bool isDestory = false;
		while (iteShe != m_shieldbox.m_isshield.end())
		{
			list<CArrow*>::iterator iteArr = m_arrbox.m_isarrow.begin();

			while (iteArr != m_arrbox.m_isarrow.end())
			{
				if ((*iteShe)->isHitArrow(*iteArr))
				{
					m_deNum += SUN_HURT;//记录被吸收的箭的数量且记录扣除的分数
					//m_score -= SUN_HURT;//记录扣除分数
					delete (*iteArr);//回收弓箭
					(*iteArr) = nullptr;
					iteArr = m_arrbox.m_isarrow.erase(iteArr);//回收弓箭节点
					continue;
				}iteArr++;
			}


			isDestory ? (isDestory = false) : (iteShe++, true);
		}
	}break;
	}
}
//TODO 7 按键的调用
void CYiShotApp::On_WM_CHAR(WPARAM w)
{
	switch (w)
	{
	case PEO_ATTACK_J:
	{
		CArrow* pArr = m_peo.Archery(m_target);//创建一个弓箭
		m_arrbox.m_isarrow.push_back(pArr);//将弓箭放入链表里
	}break;
	}
	
}
//TODO 8 游戏结束结束定时器
void CYiShotApp::GameOver()
{
	//背景定时移动
	::KillTimer(m_hwnd, TIMER_BK_ONE_MOVE_ID);
	//箭的出发点定时移动
	::KillTimer(m_hwnd, TIMER_TAR_MOVE_ID);
	//箭的定时移动
	::KillTimer(m_hwnd, TIMER_ARR_MOVE_ID);
	//太阳的定时生成
	::KillTimer(m_hwnd, TIMER_SUN_CREAT_ID);
	//太阳的消失
	::KillTimer(m_hwnd, TIMER_SUN_HURT_ID);
	//定时结束游戏
	::KillTimer(m_hwnd, TIMER_GAMEOVER_ID);
	//判断是否吸收箭
	::KillTimer(m_hwnd, TIMER_DEARROW_ID);
	::MessageBox(m_hwnd, L"GameOver", L"提示", MB_OK);//弹出一个提示框
	::PostMessage(m_hwnd, WM_CLOSE, 0, 0);//手动发送一个关闭消息
}
//TODO 9 展示各个分数
void CYiShotApp::ShowScore()
{
	::putimage(0, 0, &m_finalscore);//显示分数

	wstring strNum = L"击杀太阳数为: ";
	wstring strScore = L"总分数为: ";
	wstring strTime = L"您还剩: ";
	wstring strNum_She = L"被吸收的箭有: ";

	TCHAR arr[5] = { 0 };
	_itow_s(m_score-m_deNum, arr, 10);
	strScore += arr;

	TCHAR arr1[5] = { 0 };
	_itow_s(m_score/5, arr1, 10);
	strNum += arr1;

	TCHAR arr2[5] = { 0 };
	_itow_s(m_time, arr2, 10);
	strTime += arr2;

	TCHAR arr3[5] = { 0 };
	_itow_s(m_deNum, arr3, 10);
	strNum_She += arr3;

	strTime += L" 秒";
	strNum_She += L" 把";
	RECT rect = { 0,0,125,25 };
	RECT rect1 = { 0,25,130,50 };
	RECT rect2 = { 0,50,125,75 };
	RECT rect3 = { 0,75,150,100 };
	::settextcolor(RGB(0, 0, 0xff));

	::drawtext(strScore.c_str(), &rect, DT_LEFT);
	::drawtext(strNum.c_str(), &rect1, DT_LEFT);
	::drawtext(strTime.c_str(), &rect2, DT_LEFT);
	::drawtext(strNum_She.c_str(), &rect3, DT_LEFT);
}

//TODO 10 游戏开始时的消息盒子（后续可以增加更改）
void CYiShotApp::StarMessage()
{
	::MessageBox(m_hwnd, L"箭的伤害为1\n太阳血量为5\n盾牌可以吸收箭被并扣1分\n该模式为无尽模式尽情拿到更高的分吧!", L"提示", MB_OK);//弹出一个提示框
} 
//TODO 11 创建盾牌用于抵挡箭
void CYiShotApp::GreatShield(int num,int step_x,int step_y)
{
	int x = IMG_BK_ONE_WIDTH - 7 * IMG_SUN_WIDTH - 2 * IMG_SHE_WIDTH;
	int y = 0;
	for (int i = 0; i < num; i++)
	{
		if (i < num / 2)
		{
			CShield* pShe = new CShield;
			pShe->InitShield(x, y);
			m_shieldbox.m_isshield.push_back(pShe);
			x += step_x;
			y += step_y;
			step_x += 12;
		}
		else
		{
			CShield* pShe = new CShield;
			pShe->InitShield(x, y);
			m_shieldbox.m_isshield.push_back(pShe);
			x += step_x;
			y += step_y;
		}
	}
}