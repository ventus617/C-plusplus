#include<iostream>
using namespace std;

/*
函数重载：多个函数的关系
在同一作用域下，函数名相同，参数列表不同(参数类型，数量，顺序不同)，返回值不做要求
在调用时，根据实参自动匹配所需的重载函数
*/
//int add(int a, int b, double c);//和下面两个add 也是函数重载的关系

//类型不同
int add(int a, int b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}

//数量不同
void fun(int a, int b)
{
	cout << "fun(int a,int b)" << a << " " << b << endl;
}
void fun(int a)
{
	cout << "fun(int a)" << a << endl;
}

//顺序不同
void fun1(int a, char b)
{
	cout << "fun(int a,char b)" << a << " " << b << endl;
}
void fun1(char b,int a)
{
	cout << "fun(char b,int a)" << b <<" "<<a<< endl;
}
//不是函数重载 是重定义 p[]==*(p+0)==*p
//void fun2（int *p)
//{
//	cout << "void fun2（int *p)" << endl;
//}
//void fun2(int p[])
//{
//	cout << "void fun2(int p[])" << endl;
//}

//不是函数重载 是重定义 const是修饰int的，本质上还是int
//void fun3(const int a)
//{
//	cout << "void fun3(const int a)" << endl;
//}
//void fun3(int a)
//{
//	cout << "void fun3(int a)" << endl;
//}


//区分是函数重载，但是都只需要一个参数的时候会报错，出现二义性,则需要局部去声明一下
void fun5(int a)
{
	cout << "void fun4(int a)" <<a<< endl;
}



//也就是不单独声明的时候，20是有效的，单独声明的时候20是无效的
void fun5(int a, int b = 50)//是定义处默认值，是无用的，以声明为准，若后续或者前面没有声明，则该处是声明与定义是一起的，是有效的
{
	cout << "void fun4(int a, int b = 20)" <<a<<" "<<b<< endl;
}

int main03()
{
	int a = 10, b = 20;
	double c = 1.1, d = 2.2;
	cout << add(a, b) << endl;
	cout << add(c, d) << endl;

	fun(10);
	fun(10, 20);

	fun1(30, 'a');
	fun1('a', 30);

	void (*p)(int) = &fun5;
	void(*p1)(int, int) = &fun5;
	(*p)(19);
	(*p1)(20,30);//用指针的话，必需重新赋值，不会去使用默认值
	/*
	* 隐式的
	void (*p)(int) = fun5;
	void(*p1)(int, int) = fun5;
	p(19);
	p1(20,30);
	*/

	void fun5(int a);//声明局部化
	fun5(20);
	//若需要调用另外一个的
	//用{}括起来表示一层内嵌，否则也会出现二义性
	{
		void fun5(int a, int b = 20);
		fun5(49);
	}




	return 0;
}