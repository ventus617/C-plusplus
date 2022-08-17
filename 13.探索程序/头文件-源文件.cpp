#include<iostream>
using namespace std;
#include"aa.h"

/*
头文件 和 源文件 区别:
头文件: 变量的声明、函数的声明、类的定义..等
源文件: 变量的定义、函数的定义实现、类中变量、函数的定义..等

单独的头文件不会参与编译
单独的源文件会参与编译



单独的头文件不参与编译的，多个源文件之间自上而下独立进行编译的



*/


int main()
{
	cout << a << endl;//10
	fun();//调用函数

	//cout << b << endl;//error LNK2005: "int b" (?b@@3HA) 已经在 aa.obj 中定义


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