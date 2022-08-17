#include<iostream>
#include<Windows.h>
using namespace std;

/*
BOOL 本质上是一个int类型的别名 占用4个字节空间

bool 本质上是一个关键字 占用1个字节空间

TRUE 宏 替换 1， FALSE 替换0
关键字：ture 真 false假
*/

int main03()
{
	//typedef int BOOL;
	//#define TRUE 1 
	//#define FALSE 0
	BOOL b = TRUE;
	cout << sizeof(b) << " " << sizeof(BOOL) << endl;

	//boll true false C++提供的关键字，表示布尔类型 占一个字节
	bool bb = true;//true 真 false 假
	cout << sizeof(bb) << " " << sizeof(bool) << endl;


	return 0;
}