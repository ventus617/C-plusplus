#include<iostream>
using namespace std;
/*
函数传参3种方式：如果想修改外面的实参，不能用值传递，地址 和 引用传递可以。
如果只是查看实参，首选引用，如果实参是自定义类型，那值传递拷贝一份实参，额外申请空间大小不可控。
对于指针来说，是可控，额外申请指针大小空间。
引用不会额外申请空间
*/

//传出来

////值传递
//void fun(int aa)
//{
//	aa = 40;
//
//}

//地址传递
void fun(int* pa)
{
	*pa = 50;
}

//引用传递
void fun(int& aa)
{
	aa = 60;
}

//是函数重载


//传进去
void fun2(int a)
{
	cout << "void fun2(int a) " << a << endl;
}

void fun2(int& a)
{
	cout << "void fun2(int &a) " << a << endl;
}


//引用 & ：对已存在变量（空间）起别名
//传入的引用不会被回收
int main01()
{
	int a = 10;
	int c=0;
	int& b = a;
	//不管是空间还是地址都一样
	cout << b << " " << a << endl;// 10 10
	cout << &b << " " << &a << endl;// 00CFF82C 00CFF82C

	//对别名赋值，仍会对原空间改变
	b = 20;
	cout << a << endl;//20

	//int& c;定义引用必需要初始化

	int d = 30;

	b = d;//并不是重新引用变量，而是赋值操作

	cout << b << " " << a << endl;
	cout << &a << " " << &b << " " << &d << endl;//a和b完全相同 d的地址和他们完全不同，仅是赋值关系


	//fun(c);   //值传递并不能改变实参,仍会输出原来的值
	//cout << c << endl;

	fun(&a);
	cout << a << endl;

	fun(a);//匹配引用
	cout << a << endl;

	//fun2(a);//二义性

	fun2(10);//值传递，传常数没有二义性，常数匹配值传递

	//void fun2(int& a);//局部声明
	//fun2(a);

	//定义指针区分

	void(*p_fun1)(int a) = &fun2;
	void(*p_fun2)(int& a) = &fun2;
	(*p_fun1)(a);
	(*p_fun2)(a);

	//const
	const int& g = 10;//相当于是把常量区的10的地址空间，命名为b
	int o = 20;
	const int& l = o;
	//相当于是把o的命名给锁定，不允许通过l来修改o，但可以直接通过修改o来修改l
	//即类似指针的const，不能通过指针修改空间，但可以把空间内的值修改了，可以看作一个指向，只不过不额外花费空间，是空间的新命名

	return 0;
}