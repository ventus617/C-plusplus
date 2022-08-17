#pragma once

//声明变量

//定义应该放在源文件中
//int a;
////变量的定义但没有初始化
//int b = 10;
////变量的定义并且初始化

extern int a;//变量的声明


//声明函数

void fun();//函数的声明


//------------------------------------

//int b = 20;//定义 可能会导致重定义问题 相当于在aa.h中定义一次 又在所需源文件中定义了一次
//error LNK2005: "int b" (?b@@3HA) 已经在 aa.obj 中定义


class CTest
{
public:
	int m_a;
	static int m_b;
	const int m_c;//在构造函数的初始化参数列表中初始化
public:
	CTest() ;//构造的声明
	~CTest() ;//析构的声明
	void fun();
	static void fun2();
	void fun3()const;
	virtual void fun4();
};

//类外定义且初始化
//int CTest::m_b = 30;//重定义: error LNK2005: "public: static int CTest::m_b" (?m_b@CTest@@2HA) 已经在 aa.obj 中定义