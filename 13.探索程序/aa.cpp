#include"aa.h"
#include<iostream>
using namespace std;


int a = 10;

void fun()
{
	cout << "void fun()" << endl;
}

//---------------------------------
//���еĳ�Ա������Դ�ļ��ж�����Ҫ����  ����������
CTest::CTest():m_a(10),m_c(20)
{

	cout << "CTest::CTest()" << m_a << endl;
}
CTest::~CTest()
{
	cout<<"CTest::~CTest()"<<endl;
	
}

void CTest::fun()
{
	cout << "void CTest::fun()" << endl;
}

//�������ⲿ��˵������Ч
//�����ⶨ�徲̬��Ա����,�ؼ���static ȥ��
void CTest::fun2()
{
	cout << "void CTest::fun2()" << endl;
}
//�����ⶨ�峣����,�ؼ���const����
void CTest::fun3()const
{
	cout << "void CTest::fun3()const" << endl;
}
//�������ⲿ��˵������Ч
//�����ⶨ���麯��,�ؼ���virtual ȥ��
void CTest::fun4()
{
	cout << "void CTest::fun4()" << endl;
 }
//����Դ�ļ��ж����ҳ�ʼ��
int CTest::m_b = 30;
