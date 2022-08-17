#pragma once
#include<easyx.h>//ʹ��easyX�ĺ��� һ�����ȫ��������:: ԭ���������Ŀ������������ ����ʹ�õ��Ƿ�easyX�ĺ���
#include<map>
using namespace std;
//����һ���ص�����,����windows������Ϣ�� ���䷭��ת�����ص�������,�ɴ˿�������ʹ�ûص�������ƥ��windows�Զ���ļ�λ
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

#define INIT_MSG_MAP(WM_TYPE,EM_TYPE)\
m_MsgMap[WM_TYPE].MSG_TYPE = EM_TYPE;\
m_MsgMap[WM_TYPE].MSG_FUN.p_fun_##EM_TYPE = &CGameFrame::ON_##WM_TYPE;


class CGameFrame
{
friend LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);
//��Ԫ���� ���ú�����CGameFrame������ ����ֱ��ʹ��CGameFrame��˽�г�Ա

protected:
	HWND m_hwnd; //���ھ��
private:
	bool m_isQuit;//�˳���ʶ,false�ǲ��˳�
	
	/*
	* �����Ǵ���һ��map���� ������Ϣ��ID-uMsg,�͵õ���Ϣ�����,�ɴ�ִ����صĺ���
	* 
	* ����mapֻ��keyֵ��valueֵ ���keyֵ������Ψһ�ı궨 ���Խ����ͺ��������һ���ṹ�� ����Ϊһ��value
	* 
	*/
	typedef void (CGameFrame::* P_FUN_EM_MOUSE)(POINT);			//���������Ϣ������ຯ��ָ��
	typedef void (CGameFrame::*P_FUN_EM_KEY)(WPARAM);			//����������Ϣ������ຯ��ָ��
	typedef void (CGameFrame::* P_FUN_EM_CHAR)(WPARAM);			//�ַ�������Ϣ������ຯ��ָ��
	typedef void (CGameFrame::* P_FUN_EM_WINDOW)(WPARAM,LPARAM);//����������Ϣ������ຯ��ָ��
	struct MSG_TYPE_FUN
	{
		size_t MSG_TYPE;//��Ϣ���
		/*
		#define EM_MOUSE	1
		#define EM_KEY		2
		#define EM_CHAR		4
		#define EM_WINDOW	8
		*/
		union FUN	//ռ��ͬһ���ռ�������÷�
					//�����ڴ棬��size���Ľṹ��Ϊ�Լ��Ĵ�С
					//������ֻ����һ�����ݳ�Ա������ֵ������������ĳ����Ա��ֵ֮�󣬸������е�������Ա�ͱ��δ����״̬�ˡ�
		{
			P_FUN_EM_MOUSE p_fun_EM_MOUSE;	//������ 
			P_FUN_EM_KEY p_fun_EM_KEY;		//�������
			P_FUN_EM_CHAR p_fun_EM_CHAR;	//�ַ����
			P_FUN_EM_WINDOW p_fun_EM_WINDOW;//�������
		}MSG_FUN;
		

	};

	map<UINT, MSG_TYPE_FUN> m_MsgMap;//��Ϣӳ���

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
			//�����Ϣ����
			//m_MsgMap[WM_LBUTTONDOWN].MSG_TYPE = EM_MOUSE;
			//m_MsgMap[WM_LBUTTONDOWN].MSG_FUN.p_fun_mouse = &CGameFrame::ON_WM_LBUTTONDOWN;
		INIT_MSG_MAP(WM_LBUTTONDOWN, EM_MOUSE);
		INIT_MSG_MAP(WM_RBUTTONDOWN, EM_MOUSE);
		INIT_MSG_MAP(WM_MOUSEMOVE, EM_MOUSE);
			//m_MsgMap[WM_RBUTTONDOWN].MSG_TYPE = EM_MOUSE;
			//m_MsgMap[WM_RBUTTONDOWN].MSG_FUN.p_fun_mouse = &CGameFrame::ON_WM_RBUTTONDOWN;

			//������Ϣ����
			//m_MsgMap[WM_KEYDOWN].MSG_TYPE = EM_KEY;
		INIT_MSG_MAP(WM_KEYDOWN, EM_KEY);
			
			//�ַ���Ϣ����
		INIT_MSG_MAP(WM_CHAR, EM_CHAR);

			//������Ϣ����
	//	INIT_MSG_MAP(WM_CLOSE, EM_WINDOW); Ӧ���ȴ����ػ�,����ٹرմ���,�����߼�˳�����,���ܻ��������
		INIT_MSG_MAP(WM_TIMER, EM_WINDOW);
			//m_MsgMap[WM_KEYDOWN].MSG_FUN.p_fun_key = &CGameFrame::ON_WM_KEYDOWN;
	}



public:
	//1.������ʼ������
	void InitWindows(int x, int y, int width, int height, const TCHAR* pTitle)
	{
		//::initgraph(width, height, 0);
		//���ھ�� HWND ,��ʶ��ǰ���ڵ�
		m_hwnd = ::initgraph(width, height, 0);//���ô��ڴ�С

		//�ƶ����ڵ�ָ��λ��
		::MoveWindow(m_hwnd,//���ھ��
			x, y,//ָ��λ��
			width, height,//���ڴ�С
			true); //true:�����ƶ���Ϻ� �Ƿ���Ҫ����ˢ��

		::setbkcolor(RGB(255, 255, 255));//���ô��ڱ�����ɫ

		//���ô��ڱ���
		::SetWindowText(m_hwnd, pTitle);



		::cleardevice();//Ŀ���������õı���ɫ������Ч

		//--------------------------------
		CGameFrame::InitMsg_MAP();

		//---------------------------------
		//Ϊ����ָ��һ���ص�����
		::SetWindowLong(m_hwnd, GWL_WNDPROC,(LONG)&WindowProc);

		//������Ϸ�ĳ�ʼ��
		On_init();
	}



public:
	//2.�ػ�,��ʾ���ڵĺ���
	void PaintGame()
	{
		::BeginBatchDraw();//��ʼ������ͼ
		::cleardevice();//����
		//----------------------------

		//������Ϸ�Ļ�ͼ����
		On_Paint();


		//----------------------------
		::EndBatchDraw();//����������ͼ
	}




	//4.�رմ��� ������Դ
	void CloseGame()
	{
		On_Close();
		//�رմ���
		::closegraph();
		m_isQuit = true;
	}
	//------------------------------���麯����̬��ʽʵ�ּ�----------------------------------------
	//------------------------------����ǿ����д���麯��--------------------------------------------
	virtual void On_init() = 0;
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;
	
	//void On_init()//��ʼ���������Ϸ
	//{

	//}
	//void On_Paint()//������Ϸ�Ļ�ͼ����
	//{

	//}
	//void On_Close()//������Ϸ�Ļ�����Դ
	//{

	//}
	//------------------------------���಻��ǿ����д���麯��------------------------------------------
	




	
	
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
	
	//------------------------------����������д��Ϣ��Ӧ�Ĵ�����------------------------------------



	/*void ON_WM_CLOSE(WPARAM wo, LPARAM lo)
	{
		CGameFrame::CloseGame();
	}*/
};

//��������
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
	��Ϸ��:�������ļ� main.cpp �� GameFrame.h
	�Զ���һ��������Ϸ�ࣺ�̳� CGameFrame �࣬On_Init(),On_Paint(),On_Close() ���麯���ھ�������һ��Ҫ����ʵ�ֵ�
	
	�ھ�����Ϸ��Դ�ļ���,ʹ�� CREATE_OBJECT WND_PARAM ��,���ݶ�Ӧ�Ĳ���

	������������Ϣ,�������Ҫ����д��Ӧ����Ϣ������,���£�
	virtual void ON_WM_LBUTTONDOWN(POINT po)
	virtual void ON_WM_RBUTTONDOWN(POINT po)
	virtual void ON_WM_MOUSEMOVE(POINT po)
	virtual void ON_WM_KEYDOWN(WPARAM wo)
	virtual void ON_WM_CHAR(WPARAM wo)
	virtual void ON_WM_TIMER(WPARAM wo, LPARAM lo)

	�����Ҫ������Ϣ �Լ� ������ ��InitMsgMsp������������ӣ�ʹ��INIT_MSG_MAP ����ӣ�
*/



/*
void RunGame()
	{
		ExMessage msg;
		while (1)
		{
			::getmessage(&msg, -1); //����Ϣ�����л�ȡȫ�������Ϣ

			if (msg.message == WM_LBUTTONDOWN )
			{
				//int x=msg.x; //��ȡ����
				//int y=msg.y;

				POINT po = { msg.x,msg.y };//��װһ�������
				ON_WM_LBUTTONDOWN(po);
			}

			if (msg.message == WM_CLOSE)//����Ǵ��ڹرյ���Ϣ ,easyX���ղ���WM_CLOSE
			{
				CloseGame();
				break;
			}




			//��������Ϣ�� ���»�ͼ
			PaintGame();

		}


	}

*/