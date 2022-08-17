#include<iostream>
using namespace std;

void fun11 (int a)
{
	cout << "void fun11(int a)" << endl;
}

void fun11(int* p)
{
	cout << "void fun11(int *p)" << endl;
}

void fun12(int* p)
{
	cout << "void fun12(int* p)" << endl;
}

void fun12(char* p)
{
	cout << "void fun12(char* p)" << endl;
}

/*
NULL本质上是一个宏，替换0  nullptr本质上是C++的一个关键字,代表一个空指针
含义不同：NULL代表整型和指针（优先整型），nullptr代表一个指针

C++引入nullptr
NULL 整型和空指针 含义不明确
*/

int main04()
{
	int* p = NULL;//本质上是一个宏，替换0
	int* p1 = 0;
	int* p2 = nullptr;//本质上是一个关键字

	fun11(NULL);// void fun11(int a)
	fun11(nullptr);//void fun11(int *p)

	//fun12(nullptr); 二义性

	//利用强转来匹配对应重载函数
	fun12((char*)nullptr);
	fun12((int*)nullptr);


	return 0;
}
