#include"CFiveinarow.h"
#include"../GameFrame/GameFrame.h"
#include<mmsystem.h>
#include<string>
#pragma comment(lib,"Winmm.lib")

CREATE_OBJECT(CFiveinarowApp)
WND_PARAM(600, 200, (535 + 16), (535 + 39), L"������");


CFiveinarowApp::CFiveinarowApp()
{
	::MessageBox(m_hwnd, L"��ʼ,����������", L"��ʾ", MB_OK);
	flag = 1;
	tag_block[CHESS_BOARD_LENGTH][CHESS_BOARD_HEIGHT] = { 0 };//��ʼ��ʱ��������λ��Ϊ��
	tag_win[CHESS_BOARD_LENGTH][CHESS_BOARD_HEIGHT] = { 0 };
	m_remaintime = 60;
}

CFiveinarowApp::~CFiveinarowApp()
{

}

void CFiveinarowApp::On_init()
{
	//������ʼ��
	m_Board.InitBack();
	::loadimage(&m_TimeBoard, L"./res/��ʱ��11.png",100,30);
	::loadimage(&m_TimeBoardMask, L"./res/��ʱ��11��.png", 100, 30);
	mciSendString(_T("open �����µĺ�̲.mp3 alias bkmusic"), NULL, 0, NULL);
	/*mciSendString(_T("open ���ӹ��û���һǹ.mp3 alias mymusic"), NULL, 0, NULL);*/
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
	//��ʱ
	case TIMER_CLICK_ID:
	{
		m_remaintime--;
		if (m_remaintime == 0)
		{
			if (flag == 1)
			{
				flag = 0;
				::MessageBox(m_hwnd, L"��ʱ,��������", L"��ʾ", MB_OK);
				
			}
			else if (flag == 0)
			{
				flag = 1;
				::MessageBox(m_hwnd, L"��ʱ,��������", L"��ʾ", MB_OK);
				
			}
			m_remaintime = 60;
		}
	}
	break;
	//ƽ�ּ��
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

		
		mciSendString(_T("play ����.mp3"), NULL, 0, NULL);
		if (flag == 1&& tag_block
			[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
		[(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING]
		== 0)
		{
			
			m_Black.PlayerClick(po);
			CBlackOne* pBone = m_Black.ChessPiece(po);
			m_BlackBox.m_listBlack.push_back(pBone);
			flag = 0;//����λ 1Ϊ������ 0Ϊ������
			m_remaintime = 60;
			tag_block[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 1;//��������֮�� ��λ�ñ��Ϊ�ǿ�
			tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 1;//������1
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
			tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] = 2;//������2
			if (Winner(po))
			{
				Gameover_white();
			}
		}
	

	
}

void CFiveinarowApp::On_Paint()
{
	//��ʾ����
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
	::MessageBox(m_hwnd, L"��Ϸ����,����Ӯ", L"��ʾ", MB_OK);//����һ����ʾ�� MB_OK��ʾֻ��һ��ȷ����ť

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //�ֶ�����һ���ر���Ϣ
}

void CFiveinarowApp::Gameover_white()
{
	::MessageBox(m_hwnd, L"��Ϸ����,����Ӯ", L"��ʾ", MB_OK);//����һ����ʾ�� MB_OK��ʾֻ��һ��ȷ����ť

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //�ֶ�����һ���ر���Ϣ
}
void CFiveinarowApp::Gameover_draw()
{
	::MessageBox(m_hwnd, L"��Ϸ����,ƽ��", L"��ʾ", MB_OK);//����һ����ʾ�� MB_OK��ʾֻ��һ��ȷ����ť

	::PostMessage(m_hwnd, WM_CLOSE, 0, 0); //�ֶ�����һ���ر���Ϣ
}
bool CFiveinarowApp::Winner(POINT po)
{
	int total_black = 0;
	int total_white = 0;
	int black_win = 1;
	int white_win = 1;
	//���ж��Ǻ��ӻ��ǰ���
	if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] == 1)
	{
		//--------------------------------------------------------------------------------------------------------
			//�ж������ǲ���һ�������
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING +i] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING +i] != 0
					)
				{
					total_black += 1;
				}
			}
			//��������������4��λ���й�����������Ϻ��� �ж��Ƿ�����
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//�������ҿ�ʼ,����ǰ������һ����ͬ
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
			//�ж������ǲ��ǹ������
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING+i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING ] != 0
					)
				{
					total_black += 1;
				}
			}
			//��������������4��λ���й�����������Ϻ��� �ж��Ƿ�����
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//�������¿�ʼ,����ǰ������һ����ͬ
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
			//�ж���б�ǲ��ǹ������
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
					)
				{
					total_black += 1;
				}
			}
			//������������б4��λ���й�����������Ϻ��� �ж��Ƿ�����
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//�����������¿�ʼ,����ǰ������һ����ͬ
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
			//�ж���б�ǲ��ǹ������
			for (int i = -4; i <= 4; i++)
			{
				if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 2
					&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
					)
				{
					total_black += 1;
				}
			}
			//������������б4��λ���й�����������Ϻ��� �ж��Ƿ�����
			if (total_black >= 5)
			{
				for (int j = -4; j <= 3; j++)
				{
					//�����������¿�ʼ,����ǰ������һ����ͬ
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
	//�ж��ǲ��ǰ���
	else if ((tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] == 2))
	{
		//--------------------------------------------------------------------------------------------------------
			//�ж������ǲ���һ�������
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
				)
			{
				total_white += 1;
			}
		}
		//��������������4��λ���й�����������Ϻ��� �ж��Ƿ�����
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//�������ҿ�ʼ,����ǰ������һ����ͬ
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
		//�ж������ǲ��ǹ������
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING] != 0
				)
			{
				total_white += 1;
			}
		}
		//��������������4��λ���й�����������Ϻ��� �ж��Ƿ�����
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//�������¿�ʼ,����ǰ������һ����ͬ
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
		//�ж���б�ǲ��ǹ������
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
				)
			{
				total_white += 1;
			}
		}
		//������������б4��λ���й�����������Ϻ��� �ж��Ƿ�����
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//�����������¿�ʼ,����ǰ������һ����ͬ
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
		//�ж���б�ǲ��ǹ������
		for (int i = -4; i <= 4; i++)
		{
			if (tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 1
				&& tag_win[(po.x - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING - i][(po.y - CHESS_BOARD_OUTSIDE) / CHESS_BOARD_SPACING + i] != 0
				)
			{
				total_white += 1;
			}
		}
		//������������б4��λ���й�����������Ϻ��� �ж��Ƿ�����
		if (total_white >= 5)
		{
			for (int j = -4; j <= 3; j++)
			{
				//�����������¿�ʼ,����ǰ������һ����ͬ
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
	wstring strTime = L"ʣ��ʱ��:";
	TCHAR arr[8] = { 0 };//�洢ʣ��ʱ��
	_itow_s(m_remaintime, arr, 10);
	strTime += arr;
	settextcolor(RGB(255,153,18));

	RECT rect = { 0,5,100,95 };
	::setbkmode(TRANSPARENT);//�������ֱ���͸��
	::drawtext(strTime.c_str(), &rect, DT_CENTER);//DT_CENTER������ʾ

}