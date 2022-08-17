#include"PlaneApp.h"
#include"../GameConfig/GameConfig.h"
#include<time.h>
#include"../FoePlaneBox/FoePlaneBig.h"
#include"../FoePlaneBox/FoePlaneMiddle.h"
#include"../FoePlaneBox/FoePlaneSmall.h"
#include<string>


CREATE_OBJECT(CPlaneApp)
WND_PARAM(100, 20, (600+16), (800+39), L"�ɻ���ս");//����ͱ߿�ռ��һ���Ĵ�С
size_t CPlaneApp::m_randNum = 0; //unsigned int = size_t
CPlaneApp::CPlaneApp()
{
	m_total_score = 0;
	
}
CPlaneApp::~CPlaneApp()
{

}

void CPlaneApp::On_init()
{
	//�������ͬһ���߳����� ���Ҳ��Ϻ�
	srand((unsigned int)time(0));//�趨�����������
	//�����ĳ�ʼ��
	m_back.InitBack();
	//��ҷɻ��ĳ�ʼ��
	m_player.InitPlayer();

	//��ʾ������
	
	::loadimage(&m_scoreBoard, L"./res/cardboard.png",140,50);

	//�趨���еĶ�ʱ��
	SetTimer();
}
void CPlaneApp::SetTimer()
{
	//���ھ������ʶ��ʱ�����͸��ĸ�����,��ʱ����ID��������೤ʱ�䣨���룩����һ�Σ�,��ʱ���Ļص�����

	::SetTimer(m_hwnd, TIMER_BACK_MOVE_ID, TIMER_BACK_MOVE_INTERVAL, nullptr); //�ö�ʱ��������Ϣ ��Ϣ���������ON_WM_TIMER����

	//��ʱ����Ƿ�Ӧ���ƶ�
	::SetTimer(m_hwnd, TIMER_PLAYER_MOVE_ID, TIMER_PLAYER_MOVE_INTERVAL, nullptr);

	//�����ڵ���ʱ�ƶ�
	::SetTimer(m_hwnd, TIMER_GUNNER_MOVE_ID, TIMER_GUNNER_MOVE_INTERVAL, nullptr);

	//��ʱ�����ڵ�
	::SetTimer(m_hwnd, TIMER_SEND_GUNNER_ID, TIMER_SEND_GUNNER_INTERVAL, nullptr);

	//��ʱ�������˷ɻ�
	::SetTimer(m_hwnd, TIMER_FOEBIG_MOVE_ID, TIMER_FOEBIG_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hwnd, TIMER_FOEMIDDLE_MOVE_ID, TIMER_FOEMIDDLE_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hwnd, TIMER_FOESMALL_MOVE_ID, TIMER_FOESMALL_MOVE_INTERVAL, nullptr);

	//��ʱ�ƶ����˷ɻ�
	::SetTimer(m_hwnd, TIMER_FOE_MOVE_ID, TIMER_FOE_MOVE_INTERVAL, nullptr);
	//��ʱ�����ײ
	::SetTimer(m_hwnd, TIMER_HIT_ONE_ID, TIMER_HIT_ONE_INTERVAL, nullptr);

	//��ʱ�л���ը��ͼƬ
	::SetTimer(m_hwnd, TIMER_CHANGE_PIG_ID, TIMER_CHANGE_PIG_INTERVAL, nullptr);

}
void CPlaneApp::On_Paint()
{
	CPlaneApp::m_randNum = rand();//ÿ���ػ涼����һ�������

	m_back.ShowBack();//��ʾ����

	m_player.ShowPlayer();//��ʾ���

	m_gunBox.ShowAllGunner();//��ʾ�����ڵ�
	
	m_foeBox.ShowAllFoe();//��ʾ�����������˷ɻ�
	
	m_foeBox.ShowAllBoomFoe();//��ʾ���б�ը�ɻ�
	
	ShowScore();
}

void CPlaneApp::On_Close()
{
	GameOver();
}

//���յ�TIMER���͵���Ϣ TIMER�ĵڶ����������ǽ��յ���wo 
void CPlaneApp::ON_WM_TIMER(WPARAM wo, LPARAM lo)
{
	
	switch (wo)//Ҫ�ж��ĸ���ʱ��,ʹ��WPARAM�������,���ݵ�ֵ���Ƕ�ʱ����ID
	{
	case TIMER_BACK_MOVE_ID:
	{
		m_back.MoveBack(TIMER_BACK_MOVE_STEP);
	}
	break;
	case TIMER_PLAYER_MOVE_ID:
	{
		//������if���Խ��б�ߵķ���,�����Դ���������� һ��ִ��,�����else if ��ֻ��ִ�е���
		if (::GetAsyncKeyState(VK_UP))
		{
			//GetAsyncKeyState��ȡ����ĳ��������״̬���Ƿ��£�
			m_player.MovePlayer(VK_UP, TIMER_PLAYER_MOVE_STEP);
		}
		if (::GetAsyncKeyState(VK_LEFT))
		{
			m_player.MovePlayer(VK_LEFT, TIMER_PLAYER_MOVE_STEP);
		}
		if (::GetAsyncKeyState(VK_RIGHT))
		{
			m_player.MovePlayer(VK_RIGHT, TIMER_PLAYER_MOVE_STEP);
		}
		if (::GetAsyncKeyState(VK_DOWN))
		{
			m_player.MovePlayer(VK_DOWN, TIMER_PLAYER_MOVE_STEP);
		}
	}
	break;
	case TIMER_GUNNER_MOVE_ID:
	{
		m_gunBox.MoveAllGunner(TIMER_GUNNER_MOVE_STEP);
	}
	break;
	case TIMER_SEND_GUNNER_ID:
	{
		CGunner* pGun = m_player.SendGunner();//��pGun���շ����ȥ��һ���ڵ��ĵ�ַ
		m_gunBox.m_listGun.push_back(pGun);//�ŵ��ڵ�����������
	}
	break;
	case TIMER_FOEBIG_MOVE_ID:
	{
		CFoePlane* pFoe = new CFoePlaneBig;//�������˷ɻ�
		pFoe->InitFoe();
		m_foeBox.m_listFoe.push_back(pFoe);//��ӵ��˷ɻ�
	}
	break;
	case TIMER_FOEMIDDLE_MOVE_ID:
	{
		CFoePlane* pFoe = new CFoePlaneMiddle;//�������˷ɻ�
		pFoe->InitFoe();
		m_foeBox.m_listFoe.push_back(pFoe);//��ӵ��˷ɻ�
	}
	break;
	case TIMER_FOESMALL_MOVE_ID:
	{
		CFoePlane* pFoe = new CFoePlaneSmall;//�������˷ɻ�
		pFoe->InitFoe();
		m_foeBox.m_listFoe.push_back(pFoe);//��ӵ��˷ɻ�
	}
	break;
	case TIMER_FOE_MOVE_ID:
	{
		m_foeBox.MoveAllFoe();
	}
	break;
	case TIMER_HIT_ONE_ID:
	{
		list<CFoePlane*>::iterator iteFoe = m_foeBox.m_listFoe.begin();
		bool isBoom = false;
		while (iteFoe != m_foeBox.m_listFoe.end())
		{
		
			//�ӵл��ӽǿ�
			
			//�ڵ�ײ��
			list<CGunner*>::iterator iteGun = m_gunBox.m_listGun.begin();
			while (iteGun != m_gunBox.m_listGun.end())
			{
				if ((*iteFoe)->IsHitGunner(*iteGun))
				{
					//ײ�����ڵ�
					delete(*iteGun);
					(*iteGun) = nullptr;

					iteGun=m_gunBox.m_listGun.erase(iteGun);//�����ڵ��ڵ�
					
					(*iteFoe)->m_blood -= GUNNER_DAMAGE(�е�); //��Ѫ
					if ((*iteFoe)->m_blood <= 0)
					{
						//�ȼӷ�
						m_total_score += (*iteFoe)->m_points;
						//���˷ɻ���ը
						m_foeBox.m_listBoomFoe.push_back(*iteFoe);//��ӵ���ը����,��ʾ�걬ըЧ����delete
						iteFoe = m_foeBox.m_listFoe.erase(iteFoe);//ɾ�������ĵ��˷ɻ��ڵ�
						isBoom = true;
						break;//���˾Ͳ���ȥ�ж��Ƿ�ײ����

					}

					continue;
				}


				iteGun++;
			}

			//��ҷɻ�ײ��
			if (iteFoe != m_foeBox.m_listFoe.end() &&(*iteFoe)->IsHitPlayer(m_player))
			{
				CloseGame();
				return;
			}



			//�жϵ������Ƿ�++
			if (isBoom )
			{ 
				isBoom = false;
			}
			else
			{
				iteFoe++;//�������εĻ� ����÷ɻ������һ�ܷɻ� ���������ָ�� ��ʹ�ÿ�ָ��ȥִ��while�ͻᱨ��

			}
		/*	isBoom ? isBoom = false: (iteFoe++, true);
			*/
		}
	}
	break;
	case TIMER_CHANGE_PIG_ID:
	{

		list<CFoePlane*>::iterator iteBoom = m_foeBox.m_listBoomFoe.begin();
		while (iteBoom != m_foeBox.m_listBoomFoe.end())
		{
			if ((*iteBoom))
			{
				(*iteBoom)->m_showid--;
				if ((*iteBoom)->m_showid < 0)
				{
					delete(*iteBoom);//���շɻ�
					(*iteBoom) = nullptr;
					iteBoom=m_foeBox.m_listBoomFoe.erase(iteBoom);//���սڵ�
					continue;
				}
			}
			iteBoom++;
		}

	}
	break;
	}
}

void  CPlaneApp::ON_WM_KEYDOWN(WPARAM wo)
{
	//switch (wo)
	//{
	//case VK_UP:
	//{
	//	m_player.MovePlayer(VK_UP, TIMER_PLAYER_MOVE_STEP);
	//}
	//break;
	//case VK_DOWN:
	//{
	//	m_player.MovePlayer(VK_DOWN, TIMER_PLAYER_MOVE_STEP);
	//}
	//break;
	//case VK_LEFT :
	//{
	//	m_player.MovePlayer(VK_LEFT, TIMER_PLAYER_MOVE_STEP);
	//}
	//break;
	//case VK_RIGHT:
	//{
	//	m_player.MovePlayer(VK_RIGHT, TIMER_PLAYER_MOVE_STEP);
	//}
	//break;
	//}

	m_player.MovePlayer(wo, TIMER_PLAYER_MOVE_STEP);
}

void CPlaneApp::GameOver()
{
	//-----------------------------�رն�ʱ��-----------------------------
	//���ھ������ʶ��ʱ�����͸��ĸ�����,��ʱ����ID��������೤ʱ�䣨���룩����һ�Σ�,��ʱ���Ļص�����

	::KillTimer(m_hwnd, TIMER_BACK_MOVE_ID); //�ö�ʱ��������Ϣ ��Ϣ���������ON_WM_TIMER����

	//��ʱ����Ƿ�Ӧ���ƶ�
	::KillTimer(m_hwnd, TIMER_PLAYER_MOVE_ID);

	//�����ڵ���ʱ�ƶ�
	::KillTimer(m_hwnd, TIMER_GUNNER_MOVE_ID);

	//��ʱ�����ڵ�
	::KillTimer(m_hwnd, TIMER_SEND_GUNNER_ID);

	//��ʱ�������˷ɻ�
	::KillTimer(m_hwnd, TIMER_FOEBIG_MOVE_ID);
	::KillTimer(m_hwnd, TIMER_FOEMIDDLE_MOVE_ID);
	::KillTimer(m_hwnd, TIMER_FOESMALL_MOVE_ID);

	//��ʱ�ƶ����˷ɻ�
	::KillTimer(m_hwnd, TIMER_FOE_MOVE_ID);
	//��ʱ�����ײ
	::KillTimer(m_hwnd, TIMER_HIT_ONE_ID);
	::KillTimer(m_hwnd, TIMER_CHANGE_PIG_ID);

	::MessageBox(m_hwnd, L"��Ϸ����", L"��ʾ", MB_OK);//����һ����ʾ�� MB_OK��ʾֻ��һ��ȷ����ť

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //�ֶ�����һ���ر���Ϣ

}

void CPlaneApp::ShowScore()
{
	

	putimage(0, 0, &m_scoreBoard);//��ʾ������

	//����drawtext�����������
	//��ʾ����

	wstring strScore = L"Score:";

	//����itow����������� w_char*   ----- TCHAR���Դ����κ����͵�char
	TCHAR arr[8] = { 0 };//�洢����
	//itoa();
	_itow_s(m_total_score, arr, 10);
	strScore += arr;
	//char* ,wchar_t*
	settextcolor(RGB(255, 0, 0));

	RECT rect = {0,15,150,80 };//Rect�ṹͨ�����ε����ϽǺ����½ǵ����궨����Ρ�

	::drawtext(strScore.c_str(),&rect ,DT_CENTER );
	//string��ֵchar����ͨ��str.c_str()ת��
	// c_str() ���ַ���������ת��Ϊ�� null ��β�� char ���͵��ַ�����
	//c_str() �������Խ� const string* ���� ת��Ϊ cons char* ����
	//LPCTSTR Ҳ��const WCHAR*���͵� �൱��Ҳ��CHAR*���͵�
}

