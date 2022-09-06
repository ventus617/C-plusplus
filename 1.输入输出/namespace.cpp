#include<iostream>
using namespace std;

//int a = 10;
//:: 作用域运算符  一般来说，前面放作用域，后面放成员，如果前面省略，则是默认使用全局的作用域

//namespace：C++的关键字 定义命名空间 作用：区分同一作用域下相同的成员

//1.打开命名空间，打开一次，成员可以直接去使用，但是小心与其他命名空间成员冲突

//2.如果定义了全局的a，再用using namespace打开AA命名空间内的a，使用::a 还是会去选择全局的a 因为其优先级最高

//3.显示地指定作用域 命名空间::成员  每次使用需指定命名空间

//4.using 列表： using 命名空间::成员


namespace AA
{
	int a = 30;
	void fun()
	{
		std::cout << "BB:fun()" << std::endl;
	}
};

//using namespace AA; //则使用的变量是变成AA命名空间的变量


namespace BB
{
	int a = 40;
	void fun()
	{
		std::cout << "AA:fun()" << std::endl;
	}
};
//sing namespace BB;

int main ()
{
	//int a = 10;
	//cout << a << endl;

	//
	//cout << ::a << endl;//输出全局变量的a 
	//cout << AA::a << endl;
	//cout << BB::a << endl;
	////---------------------------------
	//::fun();//AA:fun()
	//BB::fun();//它俩相同


	//AA::fun();//使用AA空间内的fun()函数
	using BB::a; //明确声明了使用哪个命名空间中的成员，
	std::cout << a << std::endl;//当未指明作用域时（using namespace xx）或(::XX)，默认使用在函数内using XX: XX 的该成员XX

	//不可同时多次使用using 打开不同的命名空间，会产生矛盾
	//using AA::a; //error C2874:using 声明导致多次声明"<未知>
	return 0;
}