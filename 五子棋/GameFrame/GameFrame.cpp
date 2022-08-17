#include"GameFrame.h"
#include<iostream>
#include<windowsx.h>



using namespace std;
CGameFrame* Game = nullptr;
//3.定义回调函数,hwnd 窗口句柄（哪个窗口）,uMsg：哪个消息，消息鞋带的参数：wParam,lParam
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	//if (uMsg == WM_LBUTTONDOWN)
	//{
	//	POINT po = { 0 };
	//	po.x = GET_X_LPARAM(lParam); //从lParam参数中获取坐标点
	//	po.y = GET_Y_LPARAM(lParam);
	//	Game->ON_WM_LBUTTONDOWN(po);
	//}

	//if (uMsg == WM_CLOSE)//如果是窗口关闭的消息
	//{
	//	
	//	Game->CloseGame();

	//}
	if (Game->m_MsgMap.count(uMsg))//count是统计数量的 由于ID是唯一的 所以要么0 要么1 相当于要么false 要么true
	{
		
		switch (Game->m_MsgMap[uMsg].MSG_TYPE)//根据消息的ID-m_MsgMap[uMsg],和得到消息的类别 MSG_TYPE
		{
		case EM_MOUSE:
		{
			POINT po = { 0 };
			po.x = GET_X_LPARAM(lParam);
			po.y = GET_Y_LPARAM(lParam);
			(Game->*(Game->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_MOUSE))(po);//,由此执行相关的函数
			break;//不加break就一直执行下去 不管是否符合case值
		}
		case EM_KEY:
		{
			(Game->*(Game->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_KEY))(wParam);
			break;
		}
		case EM_CHAR: //功能键不属于字符
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


		//有消息 且处理完消息后 重新绘图
		Game->PaintGame();
	}


	if (uMsg == WM_CLOSE)//如果是窗口关闭的消息
	{
		Game->CloseGame();
	}

	
	return::DefWindowProc(hwnd, uMsg, wParam, lParam); //windows的默认的处理函数
}

//定义回调函数


CGameFrame* CreateObject();//声明对象

//窗口数值
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