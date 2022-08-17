//����class�����ķ�װ˼��
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
	int m_x;//����
	int m_y;

	int m_direction;//����

	int m_step;//ÿ���ƶ��ľ���

	//����ͼƬ����
	IMAGE m_imagUp;
	IMAGE m_imagDown;
	IMAGE m_imagLeft;
	IMAGE m_imagRight;
public:
	Cmali()
	{
		/*
		::�����������
		�����ʾȫ��������
		
		*/
		::initgraph(600,600,0);//���ô��ڴ�С
		::setbkcolor(RGB(255,255,255));//���ô��ڱ�����ɫ
		::cleardevice();//Ŀ���������õı���ɫ������Ч
		 //����Լ�� 600*600

		 //------------ͼƬ��Դ��IMAGE������-----------------
		::loadimage(&m_imagUp, "./res/mali-up.bmp");//ʹ�ö��ֽ��ַ���
		::loadimage(&m_imagDown, "./res/mali-down.bmp");
		::loadimage(&m_imagLeft, "./res/mali-left.bmp");
		::loadimage(&m_imagRight, "./res/mali-right.bmp");
		//------------------------------------------------------
		 m_x=300;//���� ͼƬ���Ͻǵ�����
		 m_y=300;
		 m_direction=DEF_DIRECT_RIGHT;//����
		 ::putimage(m_x, m_y, &m_imagRight);

		 m_step=2;//ÿ���ƶ��ľ���

		

		
	}
	~Cmali()
	{
		//4.
		::closegraph();//�رմ���
	}

public:

	//2.
	void showmali()
	{
		::BeginBatchDraw();//��ʼ������ͼ
		::cleardevice();//����


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


		::EndBatchDraw();//����������ͼ
	}

	void Movemali(int direction)
	{

		switch (direction)
		{
		case DEF_DIRECT_UP:
			if ((m_y - m_step) >= 0)m_y -= m_step;
			else m_y = 2;
			m_direction = direction;//��������
			break;
		case DEF_DIRECT_DOWN:
			if ((m_y + m_step) <= 540)m_y += m_step;//540=600-ͼƬ�߶�
			else m_y = 538;
			m_direction = direction;//��������
			break;
		case DEF_DIRECT_LEFT:
			if ((m_x - m_step) >= 0)m_x -= m_step;
			else m_x = 2;
			m_direction = direction;//��������
			break;
		case DEF_DIRECT_RIGHT:
			if ((m_x - m_step) <= 540)m_x += m_step;//540=600-ͼƬ���
			else m_x = 540;
			m_direction = direction;//��������
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
				::MessageBox(NULL, "�����˳�", "��ʾ", MB_OK);//��������ʾ������Ϸ
				break;
			}

			Movemali(key);//�ƶ�
			//m_direction = key;//�������� ������������� 
			//��Ϊ�䲻��˫���壬�����Ǽ�ֵ��ʱ��Ż�˫����
			//keyֵ��ˢ�µģ�����ֵ�ǲ��̶��ģ���Ϊ���ܼ�������ᵼ��ֵ�ǲ��̶��ģ�һ�����Ǽ�ֵ���ͻ�ֱ�ӽ�����������������
			showmali();//ˢ��



			Sleep(10);//˯��ʱ��10�����˾Ͳ���ϵͳ��ͣ��
		}

	}
};


int main()
{
	Cmali mali;
	mali.runMail();
	//system("pause");//��ͣ

	return 0;
}