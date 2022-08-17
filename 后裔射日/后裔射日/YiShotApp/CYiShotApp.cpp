#include"CYiShotApp.h"
#include"../GameConfig/CGameConfig.h"
//TODO 1 �����ļ� ���� ����
CREAT_OBJECT(CYiShotApp);
WND_PARAM(100, 20, 800, 620, L"��������");
//TODO 2 APP��ʼ��
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
//TODO 3 ��ʼ��������
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
//TODO 4 ��������Ҫ�Ķ��󴴽���ʱ��
void CYiShotApp::SetTimer()
{
	//������ʱ�ƶ�
	::SetTimer(m_hwnd, TIMER_BK_ONE_MOVE_ID, TIMER_BK_ONE_MOVE_INTERVAL, nullptr);
	//���ĳ����㶨ʱ�ƶ�
	::SetTimer(m_hwnd, TIMER_TAR_MOVE_ID, TIMER_TAR_MOVE_INTERVAL, nullptr);
	//���Ķ�ʱ�ƶ�
	::SetTimer(m_hwnd, TIMER_ARR_MOVE_ID, TIMER_ARR_MOVE_INTERVAL, nullptr);
	//̫���Ķ�ʱ����
	::SetTimer(m_hwnd, TIMER_SUN_CREAT_ID, TIMER_SUN_CREAT_INTERVAL, nullptr);
	//̫������ʧ
	::SetTimer(m_hwnd, TIMER_SUN_HURT_ID, TIMER_SUN_HURT_INTERVAL, nullptr);
	//��ʱ������Ϸ
	::SetTimer(m_hwnd, TIMER_GAMEOVER_ID, TIMER_GAMEOVER_INTERVAL, nullptr);
	//�ж��Ƿ����ռ�
	::SetTimer(m_hwnd, TIMER_DEARROW_ID, TIMER_DEARROW_INTERVAL, nullptr);
}
//TODO 5 �������������
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
//TODO 6 �ƶ�ʱ������
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
					delete (*iteArr);//���չ���
					(*iteArr) = nullptr;
					iteArr = m_arrbox.m_isarrow.erase(iteArr);//���չ����ڵ�

					(*iteSun)->m_blood -= SUN_HURT;
					if ((*iteSun)->m_blood <= 0)//̫��Ѫ������
					{
						m_score += SUN_BLOOD;//�ӷ�
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
					m_deNum += SUN_HURT;//��¼�����յļ��������Ҽ�¼�۳��ķ���
					//m_score -= SUN_HURT;//��¼�۳�����
					delete (*iteArr);//���չ���
					(*iteArr) = nullptr;
					iteArr = m_arrbox.m_isarrow.erase(iteArr);//���չ����ڵ�
					continue;
				}iteArr++;
			}


			isDestory ? (isDestory = false) : (iteShe++, true);
		}
	}break;
	}
}
//TODO 7 �����ĵ���
void CYiShotApp::On_WM_CHAR(WPARAM w)
{
	switch (w)
	{
	case PEO_ATTACK_J:
	{
		CArrow* pArr = m_peo.Archery(m_target);//����һ������
		m_arrbox.m_isarrow.push_back(pArr);//����������������
	}break;
	}
	
}
//TODO 8 ��Ϸ����������ʱ��
void CYiShotApp::GameOver()
{
	//������ʱ�ƶ�
	::KillTimer(m_hwnd, TIMER_BK_ONE_MOVE_ID);
	//���ĳ����㶨ʱ�ƶ�
	::KillTimer(m_hwnd, TIMER_TAR_MOVE_ID);
	//���Ķ�ʱ�ƶ�
	::KillTimer(m_hwnd, TIMER_ARR_MOVE_ID);
	//̫���Ķ�ʱ����
	::KillTimer(m_hwnd, TIMER_SUN_CREAT_ID);
	//̫������ʧ
	::KillTimer(m_hwnd, TIMER_SUN_HURT_ID);
	//��ʱ������Ϸ
	::KillTimer(m_hwnd, TIMER_GAMEOVER_ID);
	//�ж��Ƿ����ռ�
	::KillTimer(m_hwnd, TIMER_DEARROW_ID);
	::MessageBox(m_hwnd, L"GameOver", L"��ʾ", MB_OK);//����һ����ʾ��
	::PostMessage(m_hwnd, WM_CLOSE, 0, 0);//�ֶ�����һ���ر���Ϣ
}
//TODO 9 չʾ��������
void CYiShotApp::ShowScore()
{
	::putimage(0, 0, &m_finalscore);//��ʾ����

	wstring strNum = L"��ɱ̫����Ϊ: ";
	wstring strScore = L"�ܷ���Ϊ: ";
	wstring strTime = L"����ʣ: ";
	wstring strNum_She = L"�����յļ���: ";

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

	strTime += L" ��";
	strNum_She += L" ��";
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

//TODO 10 ��Ϸ��ʼʱ����Ϣ���ӣ������������Ӹ��ģ�
void CYiShotApp::StarMessage()
{
	::MessageBox(m_hwnd, L"�����˺�Ϊ1\n̫��Ѫ��Ϊ5\n���ƿ������ռ�������1��\n��ģʽΪ�޾�ģʽ�����õ����ߵķְ�!", L"��ʾ", MB_OK);//����һ����ʾ��
} 
//TODO 11 �����������ڵֵ���
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