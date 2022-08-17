#include"GameFrame.h"
#include<Windowsx.h>
//定义回调函数
CGameFrame *pGame=nullptr;
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	//if (uMsg == WM_LBUTTONDOWN)
	//{
	//	POINT po={0};
	//	po.x = GET_X_LPARAM(lParam);//从lparam参数中获取坐标点
	//	po.y = GET_Y_LPARAM(lParam);
	//	pGame->On_WM_LBUTTONDOWN(po);
	//}
	//if (uMsg == WM_CLOSE)//如果是关闭的消息
	//{
	//	pGame->CloseGame();
	//}
	if (pGame->m_MsgMap.count(uMsg))
	{
		switch (pGame->m_MsgMap[uMsg].MSG_TYPE)
		{
		case EM_MOUSE:
		{
			POINT po = { 0 };
			po.x = GET_X_LPARAM(lParam);//从lparam参数中获取坐标点
			po.y = GET_Y_LPARAM(lParam);
			pGame->On_WM_LBUTTONDOWN(po);
			(pGame->*(pGame->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_MOUSE))(po);
			break;
		}
		case EM_KEY:
		{
			(pGame->*(pGame->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_KEY))(wParam);
			break;
		}
		case EM_CHAR:
		{
			(pGame->*(pGame->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_CHAR))(wParam);
			break;
		}
		case  EM_WINDOW:
		{
			(pGame->*(pGame->m_MsgMap[uMsg].MSG_FUN.p_fun_EM_WINDOW))(wParam,lParam);
			break;
		}	
		}
		//处理完消息后重新绘图
		pGame->PaintGame();
	}

	if (uMsg == WM_CLOSE)//如果是关闭的消息
	{
		pGame->CloseGame();
	}

	return ::DefWindowProc(hwnd, uMsg, wParam, lParam);//windows的默认处理函数
}
//声明
	CGameFrame* CreatObject();
	extern int WND_POS_X;
	extern int WND_POS_Y;
	extern int WND_WIDTH;
	extern int WND_HEIGHT;
	extern const TCHAR* WND_TITLE;
int main()
{

	
	pGame = CreatObject();
	pGame->InitGame(WND_POS_X, WND_POS_Y, WND_WIDTH, WND_HEIGHT, WND_TITLE);
//	pGame->InitGame(100 ,20, 400, 400, L"AA");
//	pGame->RunGame();
	while (!pGame->GetQuit())
	{
		Sleep(500);
	}
	//system("pause");
	delete pGame;
	pGame = nullptr;
	return 0;
}