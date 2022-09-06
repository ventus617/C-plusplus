#include"CFiveinarow.h"
#include"../GameFrame/GameFrame.h"
#include<mmsystem.h>
#include<string>
#pragma comment(lib,"Winmm.lib")

CREATE_OBJECT(CFiveinarowApp)
WND_PARAM(600, 200, (535 + 16), (535 + 39), L"五子棋");


CFiveinarowApp::CFiveinarowApp()
{
	::MessageBox(m_hwnd, L"开始,黑棋先下子", L"提示", MB_OK);
	flag = 1;
	tag_block[CHESS_BOARD_LENGTH][CHESS_BOARD_HEIGHT] = { 0 };//初始化时棋盘所有位置为空
	tag_win[CHESS_BOARD_LENGTH][CHESS_BOARD_HEIGHT] = { 0 };
	m_remaintime = 60;
}

CFiveinarowApp::~CFiveinarowApp()
{

}

void CFiveinarowApp::On_init()
{
	//背景初始化
	m_Board.InitBack();
	::loadimage(&m_TimeBoard, L"./res/计时器11.png",100,30);
	::loadimage(&m_TimeBoardMask, L"./res/计时器11副.png", 100, 30);
	mciSendString(_T("open 阳光下的海滩.mp3 alias bkmusic"), NULL, 0, NULL);
	/*mciSendString(_T("open 康加鼓敲击鼓一枪.mp3 alias mymusic"), NULL, 0, NULL);*/
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
	SetTimer();
}

void CFiveinarowApp::SetTimer()
{
	::SetTimer(m_hwnd, TIMER_CLICK_ID, TIMER_CLICK_INTERVAL, nullptr);
}

void CFiveinarowApp::ON_WM_TIMER(WPARAM wo, LPARAM lo)
{
	switch (wo)
	{
	//计时
	case TIMER_CLICK_ID:
	{
		m_remaintime--;
		if (m_remaintime == 0)
		{
			if (flag == 1)
			{
				flag = 0;
				::MessageBox(m_hwnd, L"超时,白棋下子", L"提示", MB_OK);
				
			}
			else if (flag == 0)
			{
				flag = 1;
				::MessageBox(m_hwnd, L"超时,黑棋下子", L"提示", MB_OK);
				
			}
			m_remaintime = 60;
		}
	}
	break;
	//平局检测
	case TIMER_CHECK_ID:
	{
		int total = 0;
		for (int i = 0;i < CHESS_BOARD_PIECES_NUMBER; i++)
		{
			for (int j = 0; j < CHESS_BOARD_PIECES_NUMBER; j++)
			{
				if (tag_win[i][j] == 0)break;
				else if (tag_win[i][j] != 0)total++;
				if (total == CHESS_BOARD_HEIGHT * CHESS_BOARD_LENGTH)
					Gameover_draw();

			}
		}
	}
	break;
	}
}

void CFiveinarowApp::ON_WM_LBUTTONDOWN(POINT po)
{

		
		mciSendString(_T("play 落子.mp3"), NULL, 0, NULL);
		if (flag == 1&& tag_block
			[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
		[(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
		== 0)
		{
			
			m_Black.PlayerClick(po);
			CBlackOne* pBone = m_Black.ChessPiece(po);
			m_BlackBox.m_listBlack.push_back(pBone);
			flag = 0;//交换位 1为黑子行 0为白子行
			m_remaintime = 60;
			tag_block[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 1;//放置棋子之后 该位置标记为非空
			tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 1;//黑子是1
			if (Winner(po))
			{
				Gameover_black();
			}
		}
		else if (flag == 0&& tag_block
			[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
		[(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
		== 0)
		{
			
			m_White.PlayerClick(po);
			CWhiteOne* pOne = m_White.ChessPiece(po);
			m_WhiteBox.m_listWhite.push_back(pOne);
			flag = 1;
			m_remaintime = 60;
			tag_block[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 1;
			tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 2;//白子是2
			if (Winner(po))
			{
				Gameover_white();
			}
		}
	

	
}

void CFiveinarowApp::On_Paint()
{
	//显示背景
	m_Board.ShowBack();
	m_BlackBox.ShowAllBlack();
	m_WhiteBox.ShowAllWhite();
	Showlefttime();
	
}

void CFiveinarowApp::On_Close()
{
	
}
void CFiveinarowApp::Gameover_black()
{
	::MessageBox(m_hwnd, L"游戏结束,黑棋赢", L"提示", MB_OK);//弹出一个提示框 MB_OK表示只有一个确定按钮

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //手动发送一个关闭消息
}

void CFiveinarowApp::Gameover_white()
{
	::MessageBox(m_hwnd, L"游戏结束,白棋赢", L"提示", MB_OK);//弹出一个提示框 MB_OK表示只有一个确定按钮

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //手动发送一个关闭消息
}
void CFiveinarowApp::Gameover_draw()
{
	::MessageBox(m_hwnd, L"游戏结束,平局", L"提示", MB_OK);//弹出一个提示框 MB_OK表示只有一个确定按钮

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //手动发送一个关闭消息
}
bool CFiveinarowApp::Winner(POINT po)
{
	int total_black = 0;
	int total_white = 0;
	int black_win = 1;
	int white_win = 1;
	//先判断是黑子还是白子
	if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] == 1)
	{
		//--------------------------------------------------------------------------------------------------------
			//判断左右是不是一共有五个
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING +i] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING +i] != 0
					)
				{
					total_black += 1;
				}
			}
			//如果该下棋的左右4个位置中共有五个及以上黑子 判断是否相连
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//从左往右开始,若当前数和下一个相同
					if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j]==1&&
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] ==
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1])
					{
						black_win += 1;
						if (black_win == 5)return true;
					}
					else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] !=
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1]
						&& black_win < 5)
					{
						black_win = 1;
					}
				}
			}
			total_black = 0;
			black_win = 1;

			//--------------------------------------------------------------------------------------------------------
			//判断上下是不是共有五个
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ] != 0
					)
				{
					total_black += 1;
				}
			}
			//如果该下棋的上下4个位置中共有五个及以上黑子 判断是否相连
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//从上往下开始,若当前数和下一个相同
					if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] == 1 &&
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] ==
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+j+1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING])
					{
						black_win += 1;
						if (black_win == 5)return true;
					}
					else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ] !=
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ]
						&& black_win < 5)
					{
						black_win = 1;
					}
				}
			}
			total_black = 0;
			black_win = 1;


			//--------------------------------------------------------------------------------------------------------
			//判断左斜是不是共有五个
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
					)
				{
					total_black += 1;
				}
			}
			//如果该下棋的左斜4个位置中共有五个及以上黑子 判断是否相连
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//从左上往右下开始,若当前数和下一个相同
					if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] == 1 &&
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] ==
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1])
					{
						black_win += 1;
						if (black_win == 5)return true;
					}
					else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] !=
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1]
						&& black_win < 5)
					{
						black_win = 1;
					}
				}
			}
			total_black = 0;
			black_win = 1;
			

			//--------------------------------------------------------------------------------------------------------
			//判断右斜是不是共有五个
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
					)
				{
					total_black += 1;
				}
			}
			//如果该下棋的左斜4个位置中共有五个及以上黑子 判断是否相连
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//从左上往右下开始,若当前数和下一个相同
					if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] == 1 &&
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] ==
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j - 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1])
					{
						black_win += 1;
						if (black_win == 5)return true;
					}
					else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] !=
						tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j - 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1]
						&& black_win < 5)
					{
						black_win = 1;
					}
				}
			}
			return false;
	}




	//--------------------------------------------------------------------------------------------------------
	//判断是不是白子
	else if ((tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] == 2))
	{
		//--------------------------------------------------------------------------------------------------------
			//判断左右是不是一共有五个
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
				)
			{
				total_white += 1;
			}
		}
		//如果该下棋的左右4个位置中共有五个及以上黑子 判断是否相连
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//从左往右开始,若当前数和下一个相同
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] == 2 &&
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] ==
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1])
				{
					white_win += 1;
					if (white_win == 5)return true;
				}
				else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] !=
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1]
					&& white_win < 5)
				{
					white_win = 1;
				}
			}
		}
		total_white = 0;
		white_win = 1;

		//--------------------------------------------------------------------------------------------------------
		//判断上下是不是共有五个
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] != 0
				)
			{
				total_white += 1;
			}
		}
		//如果该下棋的上下4个位置中共有五个及以上黑子 判断是否相连
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//从上往下开始,若当前数和下一个相同
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] == 2 &&
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] ==
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING])
				{
					white_win += 1;
					if (white_win == 5)return true;
				}
				else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] !=
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
					&& white_win < 5)
				{
					white_win = 1;
				}
			}
		}
		total_white = 0;
		white_win = 1;


		//--------------------------------------------------------------------------------------------------------
		//判断左斜是不是共有五个
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
				)
			{
				total_white += 1;
			}
		}
		//如果该下棋的左斜4个位置中共有五个及以上黑子 判断是否相连
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//从左上往右下开始,若当前数和下一个相同
				if (tag_win[((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) + j][((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING )+ j] == 2 &&
					tag_win[((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING)+ j][((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING )+ j] ==
					tag_win[((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) + j + 1][((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) + j + 1])
				{
					white_win += 1;
					if (white_win == 5)return true;
				}
				else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] !=
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1]
					&& white_win < 5)
				{
					white_win = 1;
				}
			}
		}
		total_white = 0;
		white_win = 1;


		//--------------------------------------------------------------------------------------------------------
		//判断右斜是不是共有五个
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
				)
			{
				total_white += 1;
			}
		}
		//如果该下棋的左斜4个位置中共有五个及以上黑子 判断是否相连
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//从左上往右下开始,若当前数和下一个相同
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] == 2 &&
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] ==
					tag_win[((po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) - j - 1][((po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING) + j + 1])
				{
					white_win += 1;
					if (white_win == 5)return true;
				}
				else if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j] !=
					tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - j - 1][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + j + 1]
					&& white_win < 5)
				{
					white_win = 1;
				}
			}
		}
		return false;
	}
}

void CFiveinarowApp::Showlefttime()
{
	putimage(0, 0, &m_TimeBoardMask,SRCPAINT);
	putimage(0, 0, &m_TimeBoard, SRCAND);
	wstring strTime = L"剩余时间:";
	TCHAR arr[8] = { 0 };//存储剩余时间
	_itow_s(m_remaintime, arr, 10);
	strTime += arr;
	settextcolor(RGB(255,153,18));

	RECT rect = { 0,5,100,95 };
	::setbkmode(TRANSPARENT);//设置文字背景透明
	::drawtext(strTime.c_str(), &rect, DT_CENTER);//DT_CENTER居中显示

}