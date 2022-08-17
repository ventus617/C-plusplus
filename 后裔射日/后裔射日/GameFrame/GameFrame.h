#pragma once
#include<easyx.h>
#include<map>
#include<iostream>
using namespace std;
//����һ���ص�����
LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

#define INIT_MSG_MAP(MSG_ID,MSG_T)\
m_MsgMap[MSG_ID].MSG_TYPE = MSG_T;\
m_MsgMap[MSG_ID].MSG_FUN.p_fun_##MSG_T = &CGameFrame::On_##MSG_ID;

class CGameFrame
{
	//WindowProc �� CGameFrame �����ѿ���ֱ��ʹ��˽�г�Ա
	friend LRESULT CALLBACK WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);
protected:
	HWND m_hwnd;//���ھ��
private:
	bool m_isQuit;//�˳���ʶ��false���˳���true�˳�
	//#define EM_MOUSE	1
	//#define EM_KEY	2
	//#define EM_CHAR	4
	//#define EM_WINDOW	8
	typedef void(CGameFrame::*P_FUN_EM_MOUSE)(POINT);//������͵���Ϣ������
	typedef void(CGameFrame::* P_FUN_EM_KEY)(WPARAM);//�������͵���Ϣ������
	typedef void(CGameFrame::* P_FUN_EM_CHAR)(WPARAM);//�ַ����͵���Ϣ������
	typedef void(CGameFrame::* P_FUN_EM_WINDOW)(WPARAM,LPARAM);//�������͵���Ϣ������
	struct MSG_TYPE_FUN
	{
		size_t MSG_TYPE;
		union FUN 
		{
			P_FUN_EM_MOUSE p_fun_EM_MOUSE;//������
			P_FUN_EM_KEY p_fun_EM_KEY;//�������
			P_FUN_EM_CHAR p_fun_EM_CHAR;//�ַ����
			P_FUN_EM_WINDOW p_fun_EM_WINDOW;//�������
		}MSG_FUN;
		
	};
	map<UINT, MSG_TYPE_FUN>m_MsgMap;//��Ϣӳ���
public:
	CGameFrame():m_isQuit(false)
	{

	}
	virtual ~CGameFrame()
	{

	}
	//��ȡ�˳���ʶ
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
		//INIT_MSG_MAP(WM_CLOSE, EM_WINDOW);//ע�͵����ȴ����ػ����رմ��ڣ���������˳���߼�����
		INIT_MSG_MAP(WM_TIMER, EM_WINDOW);
		
	}
public:
	//TODO 1.����,��ʼ������
	void InitGame(int x, int y, int width, int height, const TCHAR* pTitle)
	{
		//HWND ���ھ������ʶ��ǰ����
		m_hwnd = ::initgraph(width, height,0);//��������


		::MoveWindow(m_hwnd/*���ھ��*/, x, y/*ָ��λ��*/, width, height/*���ڴ�С*/, true);//true�������ƶ���ϣ���Ҫ����ˢ��
		::setbkcolor(RGB(0xff, 0xff, 0xff));//���ô��ڵı�����ɫ	
		//���ô��ڵı���
		::SetWindowText(m_hwnd, pTitle);

		
		::cleardevice();//Ŀ���������õ���ɫ������Ч

		InitMsgMap();

		//Ϊ����ָ��һ���ص�����
		::SetWindowLong(m_hwnd, GWL_WNDPROC, (LONG)&WindowProc);

		//������Ϸ�ĳ�ʼ��
		On_Init();
	}

	//TODO: 2.�ػ棬��ʾ���ڵĺ���
	void PaintGame()
	{
		::BeginBatchDraw();//��ʼ������ͼ
		::cleardevice();//����

		On_Paint();//������Ϸ�Ļ�ͼ����


		::EndBatchDraw();//������ͼ����
	}

	//TODO 3.��Ϸ���еĺ���
	//void RunGame()
	//{
	//	ExMessage msg;
	//	while (1)
	//	{
	//		::getmessage(&msg);//����Ϣ�������л�ȡ��Ϣ,��ȡ����������Ϣ
	//		if (msg.message == WM_LBUTTONDOWN)
	//		{
	//		//	int x=msg.x;//��ȡ��갴��
	//		//	int y=msg.y;
	//			POINT po = { msg.x,msg.y };
	//			On_WM_LBUTTONDOWN(po);
	//		}
	//		if (msg.message == WM_CLOSE)//����Ǵ��ڹرյ���Ϣ
	//		{
	//			CloseGame();
	//			break;
	//		}
	//		PaintGame();
	//	}

	//}
	//TODO 4.�رմ��ڻ�����Դ
	void CloseGame()
	{
		On_Close();
		::MessageBox(m_hwnd, L"��ӭ�´μ�����ˣ", L"��ʾ", MB_OK);//����һ����ʾ��
		::closegraph();//�رմ���
		m_isQuit = true;
	}

	//������Ϸ������д����ʵ�ֵĺ���
	virtual void On_Init() = 0;//������Ϸ�ĳ�ʼ��
	
	virtual void On_Paint() = 0;//������Ϸ�Ļ�ͼ����
	virtual void On_Close() = 0;//������Ϸ�Ļ�����Դ

	//����������д��Ӧ�Ĵ�����
	virtual void On_WM_LBUTTONDOWN(POINT po) {}//���������µĴ�����
	virtual void On_WM_RBUTTONDOWN(POINT po) {}//����Ҽ����µĴ�����

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

��Ϸ�ǣ��������ļ� main.cpp �� GameFrame.h
�Զ���һ��������Ϸ�࣬�̳�CGameFrame �࣬�������е� On_Init(),On_Paint(),On_Close()���麯���ھ������еĶ���ʵ��
�� ������Ϸ��ԭ�ļ��У�ʹ��CREAT_OBJECT WND_PARAM �꣬ ���ݶ�Ӧ�Ĳ���

������������Ϣ���������Ҫ����д��Ӧ����Ϣ������������
	virtual void On_WM_LBUTTONDOWN(POINT po)//���������µĴ�����

	virtual void On_WM_RBUTTONDOWN(POINT po)//����Ҽ����µĴ�����

	virtual void On_WM_KEYDOWN(WPARAM w)

	virtual void On_WM_CHAR(WPARAM w)

	virtual void On_WM_TIMER(WPARAM w,LPARAM l)

	virtual void On_WM_MOUSEMOVE(POINT po)

	�����Ҫ������Ϣ�������� ���� InitMsgMap()��������ӣ�ʹ�� INIT_MSG_MAP �����)
*/