#pragma once
#include<easyx.h>
#include<map>
#include<iostream>
using namespace std;
//声明一个回调函数
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

#define INIT_MSG_MAP(MSG_ID,MSG_T)\
m_MsgMap[MSG_ID].MSG_TYPE = MSG_T;\
m_MsgMap[MSG_ID].MSG_FUN.p_fun_##MSG_T = &CGameFrame::On_##MSG_ID;

class CGameFrame
{
	//WindowProc 是 CGameFrame 的朋友可以直接使用私有成员
	friend LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);
protected:
	HWND m_hwnd;//窗口句柄
private:
	bool m_isQuit;//退出标识，false不退出，true退出
	//#define EM_MOUSE	1
	//#define EM_KEY	2
	//#define EM_CHAR	4
	//#define EM_WINDOW	8
	typedef void(CGameFrame::*P_FUN_EM_MOUSE)(POINT);//鼠标类型的消息处理函数
	typedef void(CGameFrame::* P_FUN_EM_KEY)(WPARAM);//键盘类型的消息处理函数
	typedef void(CGameFrame::* P_FUN_EM_CHAR)(WPARAM);//字符类型的消息处理函数
	typedef void(CGameFrame::* P_FUN_EM_WINDOW)(WPARAM,LPARAM);//窗口类型的消息处理函数
	struct MSG_TYPE_FUN
	{
		size_t MSG_TYPE;
		union FUN 
		{
			P_FUN_EM_MOUSE p_fun_EM_MOUSE;//鼠标类别
			P_FUN_EM_KEY p_fun_EM_KEY;//键盘类别
			P_FUN_EM_CHAR p_fun_EM_CHAR;//字符类别
			P_FUN_EM_WINDOW p_fun_EM_WINDOW;//窗口类别
		}MSG_FUN;
		
	};
	map<UINT, MSG_TYPE_FUN>m_MsgMap;//消息映射表
public:
	CGameFrame():m_isQuit(false)
	{

	}
	virtual ~CGameFrame()
	{

	}
	//获取退出标识
	bool GetQuit()
	{
		return m_isQuit;
	}
	void InitMsgMap()
	{
		INIT_MSG_MAP(WM_MOUSEMOVE, EM_MOUSE);
		INIT_MSG_MAP(WM_LBUTTONDOWN, EM_MOUSE);
		INIT_MSG_MAP(WM_RBUTTONDOWN, EM_MOUSE);
		INIT_MSG_MAP(WM_KEYDOWN, EM_KEY);
		INIT_MSG_MAP(WM_CHAR, EM_CHAR);
		//INIT_MSG_MAP(WM_CLOSE, EM_WINDOW);//注释掉：先处理重绘最后关闭窗口，加在这里顺序逻辑不当
		INIT_MSG_MAP(WM_TIMER, EM_WINDOW);
		
	}
public:
	//TODO 1.创建,初始化窗口
	void InitGame(int x, int y, int width, int height, const TCHAR* pTitle)
	{
		//HWND 窗口句柄，标识当前窗口
		m_hwnd = ::initgraph(width, height,0);//创建窗口


		::MoveWindow(m_hwnd/*创口句柄*/, x, y/*指定位置*/, width, height/*窗口大小*/, true);//true：窗口移动完毕，需要重新刷新
		::setbkcolor(RGB(0xff, 0xff, 0xff));//设置窗口的背景颜色	
		//设置窗口的标题
		::SetWindowText(m_hwnd, pTitle);

		
		::cleardevice();//目的是让设置的颜色立即生效

		InitMsgMap();

		//为窗口指定一个回调函数
		::SetWindowLong(m_hwnd, GWL_WNDPROC, (LONG)&WindowProc);

		//具体游戏的初始化
		On_Init();
	}

	//TODO: 2.重绘，显示窗口的函数
	void PaintGame()
	{
		::BeginBatchDraw();//开始批量绘图
		::cleardevice();//清屏

		On_Paint();//具体游戏的绘图代码


		::EndBatchDraw();//批量绘图结束
	}

	//TODO 3.游戏运行的函数
	//void RunGame()
	//{
	//	ExMessage msg;
	//	while (1)
	//	{
	//		::getmessage(&msg);//从消息队列里中获取消息,获取所有类别的消息
	//		if (msg.message == WM_LBUTTONDOWN)
	//		{
	//		//	int x=msg.x;//获取鼠标按点
	//		//	int y=msg.y;
	//			POINT po = { msg.x,msg.y };
	//			On_WM_LBUTTONDOWN(po);
	//		}
	//		if (msg.message == WM_CLOSE)//如果是窗口关闭的消息
	//		{
	//			CloseGame();
	//			break;
	//		}
	//		PaintGame();
	//	}

	//}
	//TODO 4.关闭窗口回收资源
	void CloseGame()
	{
		On_Close();
		::MessageBox(m_hwnd, L"欢迎下次继续玩耍", L"提示", MB_OK);//弹出一个提示框
		::closegraph();//关闭窗口
		m_isQuit = true;
	}

	//具体游戏必须重写定义实现的函数
	virtual void On_Init() = 0;//具体游戏的初始化
	
	virtual void On_Paint() = 0;//具体游戏的绘图代码
	virtual void On_Close() = 0;//具体游戏的回收资源

	//根据需求重写对应的处理函数
	virtual void On_WM_LBUTTONDOWN(POINT po) {}//鼠标左键按下的处理函数
	virtual void On_WM_RBUTTONDOWN(POINT po) {}//鼠标右键按下的处理函数

	virtual void On_WM_KEYDOWN(WPARAM w) {}
	virtual void On_WM_CHAR(WPARAM w) {}

	virtual void On_WM_TIMER(WPARAM w,LPARAM l) {}
	virtual void On_WM_MOUSEMOVE(POINT po) {}


}; 

#define CREAT_OBJECT(OBJECT)\
CGameFrame*CreatObject()\
{\
	return new OBJECT;\
}

#define WND_PARAM(X,Y,WIDTH,HEIGHT,TITLE)\
		int WND_POS_X=X;\
		int WND_POS_Y = Y;\
		int WND_WIDTH = WIDTH;\
		int WND_HEIGHT = HEIGHT;\
		const TCHAR* WND_TITLE = TITLE;
/*

游戏壳：包含的文件 main.cpp 和 GameFrame.h
自定义一个具体游戏类，继承CGameFrame 类，抽象类中的 On_Init(),On_Paint(),On_Close()纯虚函数在具体类中的定义实现
在 具体游戏的原文件中，使用CREAT_OBJECT WND_PARAM 宏， 传递对应的参数

对于其他的消息，如果是需要就重写对应的消息处理函数，如下
	virtual void On_WM_LBUTTONDOWN(POINT po)//鼠标左键按下的处理函数

	virtual void On_WM_RBUTTONDOWN(POINT po)//鼠标右键按下的处理函数

	virtual void On_WM_KEYDOWN(WPARAM w)

	virtual void On_WM_CHAR(WPARAM w)

	virtual void On_WM_TIMER(WPARAM w,LPARAM l)

	virtual void On_WM_MOUSEMOVE(POINT po)

	如果需要额外消息及处理函数 ，在 InitMsgMap()函数中添加（使用 INIT_MSG_MAP 宏添加)
*/