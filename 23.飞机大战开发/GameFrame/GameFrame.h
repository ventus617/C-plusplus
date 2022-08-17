#pragma once
#include<easyx.h>//使用easyX的函数 一般加上全局作用域:: 原因：如果在项目里有重名函数 导致使用的是非easyX的函数
#include<map>
using namespace std;
//声明一个回调函数,是在windows接受消息后 将其翻译转发到回调函数中,由此可以拿来使用回调函数来匹配windows自定义的键位
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

#define INIT_MSG_MAP(WM_TYPE,EM_TYPE)\
m_MsgMap[WM_TYPE].MSG_TYPE = EM_TYPE;\
m_MsgMap[WM_TYPE].MSG_FUN.p_fun_##EM_TYPE = &CGameFrame::ON_##WM_TYPE;


class CGameFrame
{
friend LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);
//友元函数 即该函数是CGameFrame的朋友 可以直接使用CGameFrame的私有成员

protected:
	HWND m_hwnd; //窗口句柄
private:
	bool m_isQuit;//退出标识,false是不退出
	
	/*
	* 以下是创建一个map容器 根据消息的ID-uMsg,和得到消息的类别,由此执行相关的函数
	* 
	* 由于map只有key值和value值 因此key值必须是唯一的标定 所以将类别和函数构造成一个结构体 来作为一个value
	* 
	*/
	typedef void (CGameFrame::* P_FUN_EM_MOUSE)(POINT);			//鼠标类型消息处理的类函数指针
	typedef void (CGameFrame::*P_FUN_EM_KEY)(WPARAM);			//键盘类型消息处理的类函数指针
	typedef void (CGameFrame::* P_FUN_EM_CHAR)(WPARAM);			//字符类型消息处理的类函数指针
	typedef void (CGameFrame::* P_FUN_EM_WINDOW)(WPARAM,LPARAM);//窗口类型消息处理的类函数指针
	struct MSG_TYPE_FUN
	{
		size_t MSG_TYPE;//消息类别
		/*
		#define EM_MOUSE	1
		#define EM_KEY		2
		#define EM_CHAR		4
		#define EM_WINDOW	8
		*/
		union FUN	//占用同一个空间的联合用法
					//共享内存，以size最大的结构作为自己的大小
					//联合中只能有一个数据成员可以有值。当给联合中某个成员赋值之后，该联合中的其它成员就变成未定义状态了。
		{
			P_FUN_EM_MOUSE p_fun_EM_MOUSE;	//鼠标类别 
			P_FUN_EM_KEY p_fun_EM_KEY;		//键盘类别
			P_FUN_EM_CHAR p_fun_EM_CHAR;	//字符类别
			P_FUN_EM_WINDOW p_fun_EM_WINDOW;//窗口类别
		}MSG_FUN;
		

	};

	map<UINT, MSG_TYPE_FUN> m_MsgMap;//消息映射表

	//-------------------------------------------------------
public:
	CGameFrame():m_isQuit(false)
	{

	}
	virtual ~CGameFrame()
	{
		int a = 0;
	}
	bool GetQuit()
	{
		return m_isQuit;
	}
	void InitMsg_MAP()
	{
			//鼠标消息设置
			//m_MsgMap[WM_LBUTTONDOWN].MSG_TYPE = EM_MOUSE;
			//m_MsgMap[WM_LBUTTONDOWN].MSG_FUN.p_fun_mouse = &CGameFrame::ON_WM_LBUTTONDOWN;
		INIT_MSG_MAP(WM_LBUTTONDOWN, EM_MOUSE);
		INIT_MSG_MAP(WM_RBUTTONDOWN, EM_MOUSE);
		INIT_MSG_MAP(WM_MOUSEMOVE, EM_MOUSE);
			//m_MsgMap[WM_RBUTTONDOWN].MSG_TYPE = EM_MOUSE;
			//m_MsgMap[WM_RBUTTONDOWN].MSG_FUN.p_fun_mouse = &CGameFrame::ON_WM_RBUTTONDOWN;

			//按键消息设置
			//m_MsgMap[WM_KEYDOWN].MSG_TYPE = EM_KEY;
		INIT_MSG_MAP(WM_KEYDOWN, EM_KEY);
			
			//字符消息设置
		INIT_MSG_MAP(WM_CHAR, EM_CHAR);

			//窗口消息设置
	//	INIT_MSG_MAP(WM_CLOSE, EM_WINDOW); 应该先处理重绘,最后再关闭窗口,出现逻辑顺序错误,可能会出现问题
		INIT_MSG_MAP(WM_TIMER, EM_WINDOW);
			//m_MsgMap[WM_KEYDOWN].MSG_FUN.p_fun_key = &CGameFrame::ON_WM_KEYDOWN;
	}



public:
	//1.创建初始化窗口
	void InitWindows(int x, int y, int width, int height, const TCHAR* pTitle)
	{
		//::initgraph(width, height, 0);
		//窗口句柄 HWND ,标识当前窗口的
		m_hwnd = ::initgraph(width, height, 0);//设置窗口大小

		//移动窗口到指定位置
		::MoveWindow(m_hwnd,//窗口句柄
			x, y,//指定位置
			width, height,//窗口大小
			true); //true:窗口移动完毕后 是否需要重新刷新

		::setbkcolor(RGB(255, 255, 255));//设置窗口背景颜色

		//设置窗口标题
		::SetWindowText(m_hwnd, pTitle);



		::cleardevice();//目的是让设置的背景色立即生效

		//--------------------------------
		CGameFrame::InitMsg_MAP();

		//---------------------------------
		//为窗口指定一个回调函数
		::SetWindowLong(m_hwnd, GWL_WNDPROC,(LONG)&WindowProc);

		//具体游戏的初始化
		On_init();
	}



public:
	//2.重绘,显示窗口的函数
	void PaintGame()
	{
		::BeginBatchDraw();//开始批量绘图
		::cleardevice();//清屏
		//----------------------------

		//具体游戏的绘图代码
		On_Paint();


		//----------------------------
		::EndBatchDraw();//结束批量绘图
	}




	//4.关闭窗口 回收资源
	void CloseGame()
	{
		On_Close();
		//关闭窗口
		::closegraph();
		m_isQuit = true;
	}
	//------------------------------纯虚函数多态方式实现简化----------------------------------------
	//------------------------------子类强制重写的虚函数--------------------------------------------
	virtual void On_init() = 0;
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;
	
	//void On_init()//初始化具体的游戏
	//{

	//}
	//void On_Paint()//具体游戏的绘图代码
	//{

	//}
	//void On_Close()//具体游戏的回收资源
	//{

	//}
	//------------------------------子类不必强制重写的虚函数------------------------------------------
	




	
	
	virtual void ON_WM_LBUTTONDOWN(POINT po)
	{
		
	}
	virtual void ON_WM_RBUTTONDOWN(POINT po)
	{
		
	}
	virtual void ON_WM_MOUSEMOVE(POINT po)
	{
		
	}

	virtual void ON_WM_KEYDOWN(WPARAM wo)
	{
		
	}
	
	virtual void ON_WM_CHAR(WPARAM wo)
	{
		
	}

	virtual void ON_WM_TIMER(WPARAM wo, LPARAM lo)
	{
		
	}	
	
	//------------------------------根据需求重写消息对应的处理函数------------------------------------



	/*void ON_WM_CLOSE(WPARAM wo, LPARAM lo)
	{
		CGameFrame::CloseGame();
	}*/
};

//函数定义
#define CREATE_OBJECT(CLASSNAME)\
CGameFrame* CreateObject()\
{\
	return (new CLASSNAME);\
}

#define WND_PARAM(X,Y,WIDTH,HEIGHT,TITLE)\
int WND_POS_X = X;\
int WND_POS_Y = Y;\
int WND_POS_WIDTH = WIDTH;\
int WND_POS_HEIGHT = HEIGHT;\
const TCHAR* WND_POS_TITLE = TITLE;

/*
	游戏壳:包含的文件 main.cpp 和 GameFrame.h
	自定义一个具体游戏类：继承 CGameFrame 类，On_Init(),On_Paint(),On_Close() 纯虚函数在具体类中一定要定义实现的
	
	在具体游戏的源文件中,使用 CREATE_OBJECT WND_PARAM 宏,传递对应的参数

	对于其他的消息,如果是需要就重写对应的消息处理函数,如下：
	virtual void ON_WM_LBUTTONDOWN(POINT po)
	virtual void ON_WM_RBUTTONDOWN(POINT po)
	virtual void ON_WM_MOUSEMOVE(POINT po)
	virtual void ON_WM_KEYDOWN(WPARAM wo)
	virtual void ON_WM_CHAR(WPARAM wo)
	virtual void ON_WM_TIMER(WPARAM wo, LPARAM lo)

	如果需要额外消息 以及 处理函数 在InitMsgMsp（）函数中添加（使用INIT_MSG_MAP 宏添加）
*/



/*
void RunGame()
	{
		ExMessage msg;
		while (1)
		{
			::getmessage(&msg, -1); //从消息队列中获取全部类别消息

			if (msg.message == WM_LBUTTONDOWN )
			{
				//int x=msg.x; //获取鼠标点
				//int y=msg.y;

				POINT po = { msg.x,msg.y };//封装一个坐标点
				ON_WM_LBUTTONDOWN(po);
			}

			if (msg.message == WM_CLOSE)//如果是窗口关闭的消息 ,easyX接收不到WM_CLOSE
			{
				CloseGame();
				break;
			}




			//处理完消息后 重新绘图
			PaintGame();

		}


	}

*/