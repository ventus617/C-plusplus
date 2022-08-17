#include<iostream>
using namespace std;

//C++内函数内参数可以带默认值(不传实参时，使用的默认值)
//如果不给c，c默认输出40，如果给c，c会用给的值
void fun(int a, int b, int c=40)
{
	cout << a << " " << b << " " << c << endl;
}

//多个参数制定默认值，必需从右向左依次指定，不能有间断
void fun1(int a, int b, int c = 300)
{
	cout << a << " " << b << " " << c << endl;
}
//void fun2(int a=110, int b, int c = 330)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//实参不能在形参尾，即形参必需在实参前




//在声明处赋予默认值，不可在定义处赋予默认值
void fun4(int a, int b=20);


//相互调用时，声明和定义得分开，这样对方才能认识
void f1();
void f2();
void f1()
{
	f2();
}
void f2()
{
	f1();
}


int main02()
{
	fun(10, 20, 30);
	fun1(10, 20);//赋值顺序是从左往右
	fun1(30, 10);
	fun4(20);

	{
		void fun4(int a, int b = 40);
		fun4(15);
	}


	return 0;
}





void fun4(int a, int b)
{
	cout << "fun4:" << a << " " << b << endl;
}