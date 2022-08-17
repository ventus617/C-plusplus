//#include<iostream>
//using namespace std;
//
//void fun32()
//{
//	cout << "void fun32()" << endl;
//}
//void fun22(int a, int b)
//{
//	cout << "void fun(int a, int b)" << endl;
//}
//
///*
//全局函数和类成员函数区别：
//1.作用域不同
//2.重要：类成员函数有 隐藏的this指针 全局函数没有
//
//
//*/
//class Ct
//{
//public:
//	void fun44(/* Ct *const this*/)
//	{
//		cout << "void fun()" << endl;
//	}
//};
//
//int main()
//{
//	void(*p_fun)() = nullptr;//初始化为空
//	void(*p_fun2)() = &fun32;//初始化指向一个函数
//	(*p_fun2)();//调用函数
//
//	//void (*p_fun3)(int,int);
//
//	typedef void(*p_fun11)(int, int);
//	p_fun11 p_fun3 = &fun22;
//	(*p_fun3)(10, 20);
//	//----------------------------------
//	//void (*p_fun)() = &Ct::fun; //Ct::*无法转换为*
//	 
//	//类成员函数指针，::*是一个整体的操作符，不可分开，作用 定义类成员函数指针
//	void (Ct   ::*  p_fun4)() = &Ct::fun44;
//
//	//.* 是一个整体操作符 通过对象调用 类成员函数指针指向的函数
//	Ct tst;
//	(tst .* p_fun4)(); 
//	//.* ->* 是C++中提供的一个整体操作符, 作用:通过对象调用 类成员函数指针指向的函数
//
//	Ct* ppp = new Ct;
//	(ppp ->* p_fun4)();
//	return 0;
//}
