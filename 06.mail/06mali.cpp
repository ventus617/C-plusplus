//利用class函数的封装思想
#include<conio.h>
#include<iostream>
#include<easyx.h>
using namespace std;

//1.
#define DEF_DIRECT_UP 72
#define DEF_DIRECT_DOWN 80
#define DEF_DIRECT_LEFT 75
#define DEF_DIRECT_RIGHT 77
#define DEF_KEY_ESC 27

class Cmali
{
public:
	int m_x;//坐标
	int m_y;

	int m_direction;//方向

	int m_step;//每次移动的距离

	//定义图片变量
	IMAGE m_imagUp;
	IMAGE m_imagDown;
	IMAGE m_imagLeft;
	IMAGE m_imagRight;
public:
	Cmali()
	{
		/*
		::作用域运算符
		这里表示全局作用域
		
		*/
		::initgraph(600,600,0);//设置窗口大小
		::setbkcolor(RGB(255,255,255));//设置窗口背景颜色
		::cleardevice();//目的是让设置的背景色立即生效
		 //窗口约定 600*600

		 //------------图片资源与IMAGE变量绑定-----------------
		::loadimage(&m_imagUp, "./res/mali-up.bmp");//使用多字节字符集
		::loadimage(&m_imagDown, "./res/mali-down.bmp");
		::loadimage(&m_imagLeft, "./res/mali-left.bmp");
		::loadimage(&m_imagRight, "./res/mali-right.bmp");
		//------------------------------------------------------
		 m_x=300;//坐标 图片左上角的坐标
		 m_y=300;
		 m_direction=DEF_DIRECT_RIGHT;//方向
		 ::putimage(m_x, m_y, &m_imagRight);

		 m_step=2;//每次移动的距离

		

		
	}
	~Cmali()
	{
		//4.
		::closegraph();//关闭窗口
	}

public:

	//2.
	void showmali()
	{
		::BeginBatchDraw();//开始批量绘图
		::cleardevice();//清屏


		switch (m_direction)
		{
		case DEF_DIRECT_UP:
		
			::putimage(m_x, m_y, &m_imagUp);
			break;
		case DEF_DIRECT_DOWN:
			
			::putimage(m_x, m_y, &m_imagDown);
			break;
		case DEF_DIRECT_LEFT:
			
			::putimage(m_x, m_y, &m_imagLeft);
			break;
		case DEF_DIRECT_RIGHT:
		
			::putimage(m_x, m_y, &m_imagRight);
			break;
		}


		::EndBatchDraw();//结束批量绘图
	}

	void Movemali(int direction)
	{

		switch (direction)
		{
		case DEF_DIRECT_UP:
			if ((m_y - m_step) >= 0)m_y -= m_step;
			else m_y = 2;
			m_direction = direction;//传播方向
			break;
		case DEF_DIRECT_DOWN:
			if ((m_y + m_step) <= 540)m_y += m_step;//540=600-图片高度
			else m_y = 538;
			m_direction = direction;//传播方向
			break;
		case DEF_DIRECT_LEFT:
			if ((m_x - m_step) >= 0)m_x -= m_step;
			else m_x = 2;
			m_direction = direction;//传播方向
			break;
		case DEF_DIRECT_RIGHT:
			if ((m_x - m_step) <= 540)m_x += m_step;//540=600-图片宽度
			else m_x = 540;
			m_direction = direction;//传播方向
			break;
		}
	}
	//---------------------------------------------
	//3.
	void runMail()
	{
		while (1)
		{
			int key=_getch();
			if (key == DEF_KEY_ESC)
			{
				::MessageBox(NULL, "程序退出", "提示", MB_OK);//弹出框，提示结束游戏
				break;
			}

			Movemali(key);//移动
			//m_direction = key;//传播方向 放在这里会闪屏 
			//因为其不是双缓冲，仅在是键值的时候才会双缓冲
			//key值是刷新的，方向值是不固定的，因为功能键的问题会导致值是不固定的，一旦不是键值，就会直接进行清屏，导致闪屏
			showmali();//刷新



			Sleep(10);//睡眠时间10，有了就不用系统暂停了
		}

	}
};


int main()
{
	Cmali mali;
	mali.runMail();
	//system("pause");//暂停

	return 0;
}