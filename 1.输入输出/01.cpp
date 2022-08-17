//#include<stdio.h>
#include<iostream>  //输入、输出流文件
using namespace std; //打开标准命名空间

int main01()
{
	int a = 10;
	char b = 'b';
	//printf("%d  %c\n", a, b);
	//scanf_s("%d  %c", &a, &b);
	//printf("%d  %c", a, b);

	//cout :ostream 类型的变量
	//<< :输出操作符 本质上是一个函数
	cout << a << "  " << b<<endl;
	//cin :istream 类型的变量
	//>> :输入操作符 本质上是一个函数
	cin >> a >> b;
	cout << a << "  " << b<<endl;

	return 0;
}