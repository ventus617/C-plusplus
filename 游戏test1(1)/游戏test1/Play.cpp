#define _CRT_SECURE_NO_WARNINGS 1
#include<easyx.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<string>
using namespace std;
//TODO: 1������������Ϣ
#define DEF_DIRECT_UP 119
#define DEF_DIRECT_DOWN 115
#define DEF_DIRECT_LEFT 97
#define DEF_DIRECT_RIGHT 100
#define DEF_KEY_ESC 27
#define DEF_DIRECT_ONE 49
#define DEF_DIRECT_TWO 50
#define DEF_DIRECT_THREE 51
//#define DEF_DIRECT_ATTACK 106
//TODO: 2 ������
//class CWars//����
//{
//public:
//	IMAGE m_wars1_up;
//	IMAGE m_wars1_left;
//	IMAGE m_wars1_down;
//	IMAGE m_wars1_right;
//	int m_x;
//	int m_y;
//	int m_dir;
//	int m_step;
//public:
//	CWars()
//	{
//
//		m_step = 1;
//		loadimage(&m_wars1_up, L"C:/Users/wenjiegg/Desktop/text/a.png");
//		loadimage(&m_wars1_right, L"C:/Users/wenjiegg/Desktop/text/b.png");
//		loadimage(&m_wars1_down, L"C:/Users/wenjiegg/Desktop/text/c.png");
//		loadimage(&m_wars1_left, L"C:/Users/wenjiegg/Desktop/text/d.png");
//		
//	}
//	~CWars()
//	{
//
//	}
//public:
//	
//
//};
//TODO: 3 ������
class CEnemy//����
{
public:
	int m_ex;
	int m_ey;
	int m_edir;
	int m_estep;
	IMAGE m_eimgup;//����ͼ�����Ϣ
	IMAGE m_eimgdown;
	IMAGE m_eimgleft;
	IMAGE m_eimgright;
public:
	CEnemy()
	{

		srand((unsigned)time(NULL));
		int num = rand() % 40000 + 1;
		loadimage(&m_eimgup, L"./settings/12.png");
		loadimage(&m_eimgleft, L"./settings/10.png");
		loadimage(&m_eimgdown, L"./settings/9.png");
		loadimage(&m_eimgright, L"./settings/11.png");
		if (num%4 == 1)
		{
			m_edir = DEF_DIRECT_UP;
			m_ex = rand() % 250, m_ey = rand() % 250;

		}
		else if (num%4 == 2)
		{
			m_edir = DEF_DIRECT_LEFT;
			m_ex = rand() % 450+300, m_ey = rand() % 250;
		}
		else if (num%4 == 3)
		{
			m_edir = DEF_DIRECT_DOWN;
			m_ex = rand() % 450 + 300, m_ey = rand() % 450 + 300;
		}
		else if (num%4 == 0)
		{
			m_edir = DEF_DIRECT_RIGHT;
			m_ex = rand() % 250, m_ey = rand() % 450 + 300;
		}
	}
	~CEnemy(){}
public:
	void ChooseHard(int key)//ѡ���Ѷȼ��ص��������Լ���������
	{
		if (key == DEF_DIRECT_ONE)
		{
			m_estep = 5;
		}
		else if (key == DEF_DIRECT_TWO)
		{
			m_estep = 6;
		}
		else if (key == DEF_DIRECT_THREE)
		{
			m_estep = 8;
		}
	}
};


//TODO: 4 ������
class CPeople//����
{
public:
	IMAGE m_imgup;//����ͼ�����Ϣ
	IMAGE m_imgdown;
	IMAGE m_imgleft;
	IMAGE m_imgright;
	int m_x;//���������
	int m_y;
	int m_dir;//���﷽��
	int m_step;//�����ƶ�����
public:
	CPeople()//��ʼ�����������Լ�����ͼ��
	{
		m_x = 350;
		m_y = 350;
		m_dir = DEF_DIRECT_RIGHT;
	}
	~CPeople()
	{

	}
public:
	void Move(int dir)//��ȡ���ﵱǰλ����Ϣ
	{
		if (dir == DEF_DIRECT_UP)
		{
			if (m_y - m_step >= 0)m_y -= m_step;
			else m_y = 0;
			m_dir = DEF_DIRECT_UP;
		}
		else if (dir == DEF_DIRECT_LEFT)
		{
			if (m_x - m_step >= 0)m_x -= m_step;
			else m_x = 0;
			m_dir = DEF_DIRECT_LEFT;
		}
		else if (dir == DEF_DIRECT_DOWN)
		{
			if (m_y + m_step <= 800-50)m_y += m_step;
			else m_y = 800-50;
			m_dir = DEF_DIRECT_DOWN;
		}
		else if (dir == DEF_DIRECT_RIGHT)
		{
			if (m_x + m_step <= 800-50)m_x += m_step;
			else m_x = 800-50;
			m_dir = DEF_DIRECT_RIGHT;
		}
	}
	void ChoosePeople(int key)//����ѡ�񣬼��ز�ͬ��ͼ����Ϣ
	{
		if (key == DEF_DIRECT_ONE)
		{
			loadimage(&m_imgup, L"./settings/4.png");
			loadimage(&m_imgleft, L"./settings/2.png");
			loadimage(&m_imgdown, L"./settings/1.png");
			loadimage(&m_imgright, L"./settings/3.png");
		}
		else
		{
			loadimage(&m_imgup, L"./settings/8.png");
			loadimage(&m_imgleft, L"./settings/6.png");
			loadimage(&m_imgdown, L"./settings/5.png");
			loadimage(&m_imgright, L"./settings/7.png");
		}
	}
	void ChooseHard(int key)//ѡ���Ѷȣ�������ɫ��ͬ������
	{
		if (key == DEF_DIRECT_ONE)
		{
			m_step = 5;
		}
		else if (key == DEF_DIRECT_TWO)
		{
			m_step = 4;
		}
		else if (key == DEF_DIRECT_THREE)
		{
			m_step = 3;
		}
	}
};
//TODO: 5 ��ͼ��
class CDraw//��ͼ��
{
public:
	int size_x;
	int size_y;
	int tot;
	CPeople pDola;
	//CWars war[5];
	CEnemy emy[5];
public:
	CDraw()//�ƶ����ڴ�С
	{
		size_x = 800;
		size_y = 800;
		initgraph(size_x, size_y);//���ƴ���
		color();//���ñ�����ɫ
		cleardevice();//����ɫ������Ч
	}
	~CDraw()
	{
		closegraph();//�رմ���
	}
public:

	void color()//������ɫ
	{
		setbkcolor(RGB(0xff, 0xff, 0xff));
	}
	void DrawPeople_and_Enemy()//�������ﵱǰ״̬
	{
		BeginBatchDraw();//��ʼ������ͼ,ֱ��EndBatchDraw��ʼ���
		cleardevice();
		if (pDola.m_dir == DEF_DIRECT_UP)putimage(pDola.m_x, pDola.m_y, &pDola.m_imgup);
		else if (pDola.m_dir == DEF_DIRECT_LEFT)putimage(pDola.m_x, pDola.m_y, &pDola.m_imgleft);
		else if (pDola.m_dir == DEF_DIRECT_DOWN)putimage(pDola.m_x, pDola.m_y, &pDola.m_imgdown);
		else if (pDola.m_dir == DEF_DIRECT_RIGHT)putimage(pDola.m_x, pDola.m_y, &pDola.m_imgright);
		for (int i = 1; i <=tot ; i++)
		{
			if (emy[i].m_edir == DEF_DIRECT_UP)putimage(emy[i].m_ex, emy[i].m_ey, &emy[i].m_eimgup);
			else if (emy[i].m_edir == DEF_DIRECT_LEFT)putimage(emy[i].m_ex, emy[i].m_ey, &emy[i].m_eimgleft);
			else if (emy[i].m_edir == DEF_DIRECT_DOWN)putimage(emy[i].m_ex, emy[i].m_ey, &emy[i].m_eimgdown);
			else if (emy[i].m_edir == DEF_DIRECT_RIGHT)putimage(emy[i].m_ex, emy[i].m_ey, &emy[i].m_eimgright);
		}EndBatchDraw();
	}
	//void DrawWars(int key)//�����ӵ��Լ����ж��켣
	//{
	//	if (key == DEF_DIRECT_ATTACK)
	//	{
	//		
	//		war[0].m_x = pDola.m_x;//��ȡ��������
	//		war[0].m_y = pDola.m_y;
	//		war[0].m_dir = pDola.m_dir;
	//		
	//		while (war[0].m_x >= 0 && war[0].m_x <= 800 - 12 && war[0].m_y >= 0 && war[0].m_y <= 800 - 5)//�����滭������cleardevice�����˷����������˾�û��
	//		{	
	//			BeginBatchDraw();
	//			cleardevice();
	//			if (war[0].m_dir == DEF_DIRECT_UP)putimage(war[0].m_x, war[0].m_y, &war[0].m_wars1_up), putimage(pDola.m_x, pDola.m_y, &pDola.m_imgup), war[0].m_y -= war[0].m_step;
	//			else if (war[0].m_dir == DEF_DIRECT_LEFT)putimage(war[0].m_x, war[0].m_y, &war[0].m_wars1_left), putimage(pDola.m_x, pDola.m_y, &pDola.m_imgleft), war[0].m_x -= war[0].m_step;
	//			else if (war[0].m_dir == DEF_DIRECT_DOWN)putimage(war[0].m_x, war[0].m_y, &war[0].m_wars1_down), putimage(pDola.m_x, pDola.m_y, &pDola.m_imgdown), war[0].m_y += war[0].m_step;
	//			else if (war[0].m_dir == DEF_DIRECT_RIGHT)putimage(war[0].m_x, war[0].m_y, &war[0].m_wars1_right), putimage(pDola.m_x, pDola.m_y, &pDola.m_imgright), war[0].m_x += war[0].m_step;
	//			if (emy.m_edir == DEF_DIRECT_UP)putimage(emy.m_ex, emy.m_ey, &emy.m_eimgup);
	//			else if (emy.m_edir == DEF_DIRECT_LEFT)putimage(emy.m_ex, emy.m_ey, &emy.m_eimgleft);
	//			else if (emy.m_edir == DEF_DIRECT_DOWN)putimage(emy.m_ex, emy.m_ey, &emy.m_eimgdown);
	//			else if (emy.m_edir == DEF_DIRECT_RIGHT)putimage(emy.m_ex, emy.m_ey, &emy.m_eimgright);
	//		//	Sleep(5);
	//			EndBatchDraw(); 
	//		}
	//	}
	//}
	void GetMovePeople(int dir)//�������λ����Ϣ�仯
	{
		pDola.Move(dir);
	}
	void GetMoveEnemy()//��õ���λ����Ϣ�仯
	{
		srand((unsigned)time(NULL));
		int num;
		
		for (int i = 1; i <= tot; i++)
		{
			num = rand() % 40000 + 1;
			if (num % 4 == 1)
			{
				emy[i].m_edir = DEF_DIRECT_UP;
			}
			else if (num % 4 == 2)
			{
				emy[i].m_edir = DEF_DIRECT_LEFT;
			}
			else if (num % 4 == 3)
			{
				emy[i].m_edir = DEF_DIRECT_DOWN;
			}
			else if (num % 4 == 0)
			{
				emy[i].m_edir = DEF_DIRECT_RIGHT;
			}
			if (emy[i].m_edir == DEF_DIRECT_UP)
			{
				if (emy[i].m_ey - emy[i].m_estep >= 0)emy[i].m_ey -= emy[i].m_estep;
				else emy[i].m_ey = 0;
			}
			else if (emy[i].m_edir == DEF_DIRECT_LEFT)
			{
				if (emy[i].m_ex - emy[i].m_estep >= 0)emy[i].m_ex -= emy[i].m_estep;
				else emy[i].m_ex = 0;
			}
			else if (emy[i].m_edir == DEF_DIRECT_DOWN)
			{
				if (emy[i].m_ey + emy[i].m_estep <= 800 - 50)emy[i].m_ey += emy[i].m_estep;
				else emy[i].m_ey = 800 - 50;
			}
			else if (emy[i].m_edir == DEF_DIRECT_RIGHT)
			{
				if (emy[i].m_ex + emy[i].m_estep <= 800 - 50)emy[i].m_ex += emy[i].m_estep;
				else emy[i].m_ex = 800 - 50;
			}
		}
	}
	void Message()//������Ϸ��ʾ
	{
		MessageBox(NULL, L"1Ϊ����A��2ΪҰ�ȴ���", L"��ѡ������", MB_OK);
		int c = _getch(); ChoosePeople(c);
		if (c == DEF_DIRECT_ONE)
		{
			MessageBox(NULL, L"��ѡ���˶���A��", L"��ʾ", MB_OK);
		}
		else if (c == DEF_DIRECT_TWO)
		{
			MessageBox(NULL, L"��ѡ����Ұ�ȴ���", L"��ʾ", MB_OK);
		}
		MessageBox(NULL, L"1Ϊ��ͨ2Ϊ�е�3Ϊ����", L"��ѡ���Ѷ�", MB_OK);
		c = _getch();
		ChooseHard(c);
	}
	void Work()//����
	{
		Message();
		DrawPeople_and_Enemy();
		clock_t starts = clock();
		while (1)
		{
			GetMoveEnemy();
			if (_kbhit()/*����Ƿ��û����̺����Ǿͷ���1*/)
			{
				int key = _getch();
				if (key == DEF_KEY_ESC)
				{
					MessageBox(NULL, L"�����˳�", L"��ʾ", MB_OK);//ESC�˳�
					break;
				}
				//DrawWars(key);
				GetMovePeople(key);
			}
			if (!jug_and_print())
			{
				clock_t ends = clock();
				string s;
				double endtime = (double)(ends - starts) / CLOCKS_PER_SEC;//����ʱ��
				MessageBox(NULL, L"��Ϸ�������Ĵ��ʱ��Ϊ��", L"��ʾ", MB_OK);
				cout << endtime << "s" << endl;
				break;
			}
			DrawPeople_and_Enemy();
			Sleep(20);
		}
	}void ChoosePeople(int key)
	{
		pDola.ChoosePeople(key);
	}
	void ChooseHard(int key)
	{
		if (key == DEF_DIRECT_ONE)
		{
			pDola.ChooseHard(key);
			tot = 1;
			for (int i = 1; i <= tot; i++)
			{
				emy[i].ChooseHard(key);
			}
		}
		else if (key == DEF_DIRECT_TWO)
		{
			pDola.ChooseHard(key);
			tot = 2;
			for (int i = 1; i <= tot; i++)
			{
				emy[i].ChooseHard(key);
			}
		}
		else if (key == DEF_DIRECT_THREE)
		{
			pDola.ChooseHard(key);
			tot = 4;
			for (int i = 1; i <= tot; i++)
			{
				emy[i].ChooseHard(key);
			}
		}
	}
	bool jug_and_print()//�жϵ�ǰ��״̬�Ƿ�Ϊ�������������ӡ�����������Ǵ�ӡʱ�䣩
	{
		
		int f = tot;
		for (int i = 1; i <= tot; i++)
		{
			if (pDola.m_y + 50 < emy[i].m_ey)continue;
			if (pDola.m_y > emy[i].m_ey + 50)continue;
			if (pDola.m_x + 50 < emy[i].m_ex)continue;
			if (pDola.m_x > emy[i].m_ex + 50)continue;
			f--;
		}
		if (f == tot)return true;
		return false;
	}
};

int main()
{
	CDraw draw;
	draw.Work();
	return 0;
}
