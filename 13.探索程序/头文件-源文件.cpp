#include<iostream>
using namespace std;
#include"aa.h"

/*
ͷ�ļ� �� Դ�ļ� ����:
ͷ�ļ�: ��������������������������Ķ���..��
Դ�ļ�: �����Ķ��塢�����Ķ���ʵ�֡����б����������Ķ���..��

������ͷ�ļ�����������
������Դ�ļ���������



������ͷ�ļ����������ģ����Դ�ļ�֮�����϶��¶������б����



*/


int main()
{
	cout << a << endl;//10
	fun();//���ú���

	//cout << b << endl;//error LNK2005: "int b" (?b@@3HA) �Ѿ��� aa.obj �ж���


	//-------------------------------------

	CTest tst;
	cout << tst.m_a << endl;//10

	cout << tst.m_b << "  " << CTest::m_b << endl;//30 30

	cout << tst.m_c << endl;//40

	tst.fun();
	tst.fun2();
	tst.fun3();
	tst.fun4();
	/*
	void CTest::fun()
	void CTest::fun2()
	void CTest::fun3()const
	void CTest::fun4()
	*/
	return 0;
}