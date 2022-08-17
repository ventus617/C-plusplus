#include"GameFrame.h"
#include<iostream>
#include<windowsx.h>



using namespace std;
CGameFrame* Game = nullptr;
//3.����ص�����,hwnd ���ھ�����ĸ����ڣ�,uMsg���ĸ���Ϣ����ϢЬ���Ĳ�����wParam,lParam
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	//if (uMsg == WM_LBUTTONDOWN)
	//{
	//	POINT po = { 0 };
	//	po.x = GET_X_LPARAM(lParam); //��lParam�����л�ȡ�����
	//	po.y = GET_Y_LPARAM(lParam);
	//	Game->ON_WM_LBUTTONDOWN(po);
	//}

	//if (uMsg == WM_CLOSE)//����Ǵ��ڹرյ���Ϣ
	//{
	//	
	//	Game->CloseGame();

	//}
	if (Game->m_MsgMap.count(uMsg))//count��ͳ�������� ����ID��Ψһ�� ����Ҫô0 Ҫô1 �൱��Ҫôfalse Ҫôtrue
	{
		
		switch (Game->m_MsgMap[uMsg].MSG_TYPE)//������Ϣ��ID-m_MsgMap[uMsg],�͵õ���Ϣ����� MSG_TYPE
		{
		case EM_MOUSE:
		{
			POINT po = { 0 };
			po.x = GET_X_LPARAM(lParam);
			po.y = GET_Y_LPARAM(lParam);
			(Game->*(Game->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_MOUSE))(po);//,�ɴ�ִ����صĺ���
			break;//����break��һֱִ����ȥ �����Ƿ����caseֵ
		}
		case EM_KEY:
		{
			(Game->*(Game->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_KEY))(wParam);
			break;
		}
		case EM_CHAR: //���ܼ��������ַ�
		{
			(Game->*(Game->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_CHAR))(wParam);
			break;

		}
		case EM_WINDOW:
		{
			(Game->*(Game->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_WINDOW))(wParam,lParam);
			break;
		}

		}


		//����Ϣ �Ҵ�������Ϣ�� ���»�ͼ
		Game->PaintGame();
	}


	if (uMsg == WM_CLOSE)//����Ǵ��ڹرյ���Ϣ
	{
		Game->CloseGame();
	}

	
	return::DefWindowProc(hwnd, uMsg, wParam, lParam); //windows��Ĭ�ϵĴ�����
}

//����ص�����


CGameFrame* CreateObject();//��������

//������ֵ
extern int WND_POS_X;
extern int WND_POS_Y;
extern int WND_POS_WIDTH;
extern int WND_POS_HEIGHT;
extern const TCHAR* WND_POS_TITLE;

int main()
{
	Game = CreateObject();
	Game->InitWindows(WND_POS_X, WND_POS_Y, WND_POS_WIDTH, WND_POS_HEIGHT,WND_POS_TITLE);

	//Game.RunGame();
	while (!Game->GetQuit())
	{
		Sleep(500);
	}

	delete Game;
	Game = nullptr;
	//system("pause");

	return 0;
}