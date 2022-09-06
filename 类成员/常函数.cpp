#include<iostream>
using namespace std;


class C7
{
public:
	int m_a;
	const int m_b;
	mutable int m_c;//mutable 修饰的成员 可以在常函数中修改
	C7():m_a(10),m_b(20)
	{
		m_c = 30;
	}

	//常函数:在常函数中不能修改类成员属性,无论是变量还是常量都不可修改
	void fun(/* const C7 * const this */) const
	{

	/*	无法修改
		m_a = 10;
		m_b = 20;*/

		cout << m_a << " " << m_b << endl;//可以正常使用

		//fun2();//相当于把fun的this传递给了fun2 是不合法的 类型不同

		//const C7 tst1;
		//const C7* const pthis1 = &tst1;
		//C7* const pthis2 = pthis1;//安全级别降低的操作 不允许

		fun3();//允许调用其他常函数 两者类型相同 安全级别相同 允许

		fun4();//静态成员函数无this 有没有对象都可以使用，因此合法

		//修改 通过另一个指针 指向该空间的地址 来修改空间
		int* p = (int*)&this->m_a;
		*p = 100;
		cout << this->m_a << endl;//100


		m_c = 100;//正规修改方法
		cout << m_c << endl;
	}

	//一般函数：仅this的指向不可修改 但是this指向的空间值可以修改
	void fun2(/*  C7 * const this */) 
	{

		/*	可修改*/
			this->m_a = 10;
			/*m_b = 20;*/
			fun();//合法,是安全级别提升的操作,允许执行

		//C7 tst1;
		//C7* const pthis2 = &tst1;
		//const C7* const pthis1 = pthis2;//安全级别升高的操作 允许
	}

	void fun3()const
	{
		cout << "void fun3()const" << endl;
	}

	static void fun4()//内无this指针 若调用其他函数 当其内无调用对象时合法，否则没有this指针传递，指向不明
	{
		cout << "static void fun4()" << endl;
	}
};


int main04()
{
	int a = 10;
	const int b = 20;
	int* p = &a;
	//常量指针
	const int* p2 = &b;
	//const 修饰* p2 ，表明p2指向的空间是常量 即b不可修改 但是指向可以改变（因此可以不初始化）
	p2 = &a;
	//*p2 = 40;//非法


	const int* p8 = &a;//不能通过指针来修改指向的变量，但是指向的变量本身可以自行修改，如果变量本身是const类型，则不可以修改
	/*
	*p2 = 50;
	非法*/
	a = 50;
	 

	//指针常量
	int* const p3 = &a;
	//const修饰 p2，表明指针本身是常量，需要初始化，即不可改指向 但是空间内容可以改变
	*p3 = 40;
	//p3 = &b; //非法


	const int* const p4 = &b;//相当于两者结合 需要初始化 不能改变指向 不能改变空间
	//非法
	//p4 = &a;
	//*p4 = 40;

	C7 tst;
	tst.fun();


	return 0;
}