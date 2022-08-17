#include"aa.h"
#include<iostream>
using namespace std;


int a = 10;

void fun()
{
	cout << "void fun()" << endl;
}

//---------------------------------
//类中的成员函数在源文件中定义需要加上  类名作用域
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

//类声明外部的说明符无效
//在类外定义静态成员函数,关键字static 去掉
void CTest::fun2()
{
	cout << "void CTest::fun2()" << endl;
}
//在类外定义常函数,关键字const保留
void CTest::fun3()const
{
	cout << "void CTest::fun3()const" << endl;
}
//类声明外部的说明符无效
//在类外定义虚函数,关键字virtual 去掉
void CTest::fun4()
{
	cout << "void CTest::fun4()" << endl;
 }
//类外源文件中定义且初始化
int CTest::m_b = 30;
