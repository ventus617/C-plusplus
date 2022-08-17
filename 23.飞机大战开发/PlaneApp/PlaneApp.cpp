#include"PlaneApp.h"
#include"../GameConfig/GameConfig.h"
#include<time.h>
#include"../FoePlaneBox/FoePlaneBig.h"
#include"../FoePlaneBox/FoePlaneMiddle.h"
#include"../FoePlaneBox/FoePlaneSmall.h"
#include<string>


CREATE_OBJECT(CPlaneApp)
WND_PARAM(100, 20, (600+16), (800+39), L"飞机大战");//标题和边框占据一定的大小
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
	//如果不在同一个线程里面 则会挂不上号
	srand((unsigned int)time(0));//设定随机数的种子
	//背景的初始化
	m_back.InitBack();
	//玩家飞机的初始化
	m_player.InitPlayer();

	//显示背景板
	
	::loadimage(&m_scoreBoard, L"./res/cardboard.png",140,50);

	//设定所有的定时器
	SetTimer();
}
void CPlaneApp::SetTimer()
{
	//窗口句柄：标识定时器发送给哪个窗口,定时器的ID，间隔（多长时间（毫秒）触发一次）,定时器的回调函数

	::SetTimer(m_hwnd, TIMER_BACK_MOVE_ID, TIMER_BACK_MOVE_INTERVAL, nullptr); //该定时器发送消息 消息会由下面的ON_WM_TIMER接收

	//定时检测是否应该移动
	::SetTimer(m_hwnd, TIMER_PLAYER_MOVE_ID, TIMER_PLAYER_MOVE_INTERVAL, nullptr);

	//所有炮弹定时移动
	::SetTimer(m_hwnd, TIMER_GUNNER_MOVE_ID, TIMER_GUNNER_MOVE_INTERVAL, nullptr);

	//定时发射炮弹
	::SetTimer(m_hwnd, TIMER_SEND_GUNNER_ID, TIMER_SEND_GUNNER_INTERVAL, nullptr);

	//定时创建敌人飞机
	::SetTimer(m_hwnd, TIMER_FOEBIG_MOVE_ID, TIMER_FOEBIG_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hwnd, TIMER_FOEMIDDLE_MOVE_ID, TIMER_FOEMIDDLE_MOVE_INTERVAL, nullptr);
	::SetTimer(m_hwnd, TIMER_FOESMALL_MOVE_ID, TIMER_FOESMALL_MOVE_INTERVAL, nullptr);

	//定时移动敌人飞机
	::SetTimer(m_hwnd, TIMER_FOE_MOVE_ID, TIMER_FOE_MOVE_INTERVAL, nullptr);
	//定时检测碰撞
	::SetTimer(m_hwnd, TIMER_HIT_ONE_ID, TIMER_HIT_ONE_INTERVAL, nullptr);

	//定时切换爆炸的图片
	::SetTimer(m_hwnd, TIMER_CHANGE_PIG_ID, TIMER_CHANGE_PIG_INTERVAL, nullptr);

}
void CPlaneApp::On_Paint()
{
	CPlaneApp::m_randNum = rand();//每次重绘都会获得一个随机数

	m_back.ShowBack();//显示背景

	m_player.ShowPlayer();//显示玩家

	m_gunBox.ShowAllGunner();//显示所有炮弹
	
	m_foeBox.ShowAllFoe();//显示所有正常敌人飞机
	
	m_foeBox.ShowAllBoomFoe();//显示所有爆炸飞机
	
	ShowScore();
}

void CPlaneApp::On_Close()
{
	GameOver();
}

//接收到TIMER发送的消息 TIMER的第二个参数就是接收到的wo 
void CPlaneApp::ON_WM_TIMER(WPARAM wo, LPARAM lo)
{
	
	switch (wo)//要判断哪个定时器,使用WPARAM这个参数,传递的值就是定时器的ID
	{
	case TIMER_BACK_MOVE_ID:
	{
		m_back.MoveBack(TIMER_BACK_MOVE_STEP);
	}
	break;
	case TIMER_PLAYER_MOVE_ID:
	{
		//这里用if可以解决斜走的方法,即可以触发两种情况 一起执行,如果是else if 则只能执行单个
		if (::GetAsyncKeyState(VK_UP))
		{
			//GetAsyncKeyState获取键盘某个按键的状态（是否按下）
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
		CGunner* pGun = m_player.SendGunner();//用pGun接收发射出去的一个炮弹的地址
		m_gunBox.m_listGun.push_back(pGun);//放到炮弹盒子链表中
	}
	break;
	case TIMER_FOEBIG_MOVE_ID:
	{
		CFoePlane* pFoe = new CFoePlaneBig;//创建敌人飞机
		pFoe->InitFoe();
		m_foeBox.m_listFoe.push_back(pFoe);//添加敌人飞机
	}
	break;
	case TIMER_FOEMIDDLE_MOVE_ID:
	{
		CFoePlane* pFoe = new CFoePlaneMiddle;//创建敌人飞机
		pFoe->InitFoe();
		m_foeBox.m_listFoe.push_back(pFoe);//添加敌人飞机
	}
	break;
	case TIMER_FOESMALL_MOVE_ID:
	{
		CFoePlane* pFoe = new CFoePlaneSmall;//创建敌人飞机
		pFoe->InitFoe();
		m_foeBox.m_listFoe.push_back(pFoe);//添加敌人飞机
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
		
			//从敌机视角看
			
			//炮弹撞击
			list<CGunner*>::iterator iteGun = m_gunBox.m_listGun.begin();
			while (iteGun != m_gunBox.m_listGun.end())
			{
				if ((*iteFoe)->IsHitGunner(*iteGun))
				{
					//撞击到炮弹
					delete(*iteGun);
					(*iteGun) = nullptr;

					iteGun=m_gunBox.m_listGun.erase(iteGun);//回收炮弹节点
					
					(*iteFoe)->m_blood -= GUNNER_DAMAGE(中等); //掉血
					if ((*iteFoe)->m_blood <= 0)
					{
						//先加分
						m_total_score += (*iteFoe)->m_points;
						//敌人飞机爆炸
						m_foeBox.m_listBoomFoe.push_back(*iteFoe);//添加到爆炸链表,显示完爆炸效果再delete
						iteFoe = m_foeBox.m_listFoe.erase(iteFoe);//删除正常的敌人飞机节点
						isBoom = true;
						break;//打爆了就不用去判断是否撞击了

					}

					continue;
				}


				iteGun++;
			}

			//玩家飞机撞击
			if (iteFoe != m_foeBox.m_listFoe.end() &&(*iteFoe)->IsHitPlayer(m_player))
			{
				CloseGame();
				return;
			}



			//判断迭代器是否++
			if (isBoom )
			{ 
				isBoom = false;
			}
			else
			{
				iteFoe++;//加了两次的话 如果该飞机是最后一架飞机 则会跳到空指针 再使用空指针去执行while就会报错

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
					delete(*iteBoom);//回收飞机
					(*iteBoom) = nullptr;
					iteBoom=m_foeBox.m_listBoomFoe.erase(iteBoom);//回收节点
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
	//-----------------------------关闭定时器-----------------------------
	//窗口句柄：标识定时器发送给哪个窗口,定时器的ID，间隔（多长时间（毫秒）触发一次）,定时器的回调函数

	::KillTimer(m_hwnd, TIMER_BACK_MOVE_ID); //该定时器发送消息 消息会由下面的ON_WM_TIMER接收

	//定时检测是否应该移动
	::KillTimer(m_hwnd, TIMER_PLAYER_MOVE_ID);

	//所有炮弹定时移动
	::KillTimer(m_hwnd, TIMER_GUNNER_MOVE_ID);

	//定时发射炮弹
	::KillTimer(m_hwnd, TIMER_SEND_GUNNER_ID);

	//定时创建敌人飞机
	::KillTimer(m_hwnd, TIMER_FOEBIG_MOVE_ID);
	::KillTimer(m_hwnd, TIMER_FOEMIDDLE_MOVE_ID);
	::KillTimer(m_hwnd, TIMER_FOESMALL_MOVE_ID);

	//定时移动敌人飞机
	::KillTimer(m_hwnd, TIMER_FOE_MOVE_ID);
	//定时检测碰撞
	::KillTimer(m_hwnd, TIMER_HIT_ONE_ID);
	::KillTimer(m_hwnd, TIMER_CHANGE_PIG_ID);

	::MessageBox(m_hwnd, L"游戏结束", L"提示", MB_OK);//弹出一个提示框 MB_OK表示只有一个确定按钮

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //手动发送一个关闭消息

}

void CPlaneApp::ShowScore()
{
	

	putimage(0, 0, &m_scoreBoard);//显示分数板

	//根据drawtext所需参数类型
	//显示分数

	wstring strScore = L"Score:";

	//根据itow所需参数类型 w_char*   ----- TCHAR可以代表任何类型的char
	TCHAR arr[8] = { 0 };//存储分数
	//itoa();
	_itow_s(m_total_score, arr, 10);
	strScore += arr;
	//char* ,wchar_t*
	settextcolor(RGB(255, 0, 0));

	RECT rect = {0,15,150,80 };//Rect结构通过矩形的左上角和右下角的坐标定义矩形。

	::drawtext(strScore.c_str(),&rect ,DT_CENTER );
	//string赋值char必需通过str.c_str()转换
	// c_str() 将字符串的内容转换为以 null 结尾的 char 类型的字符串。
	//c_str() 函数可以将 const string* 类型 转化为 cons char* 类型
	//LPCTSTR 也是const WCHAR*类型的 相当于也是CHAR*类型的
}

