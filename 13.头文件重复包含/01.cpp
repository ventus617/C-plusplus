#include"b.h"
#include"cc.h"
#include<iostream>
using namespace std;

//同一个头文件 相当于包含了多次
//#include"aa.h"
//#include"aa.h"
 

//类在当前的源文件中,相当于定义了多次

//class CAA {
//public:
//	int m_a;
//	CAA();
//};
//
//class CAA {
//public:
//	int m_a;
//	CAA();
//};



int main()
{
	CBB bb;
	cout << bb.m_aa.m_a << endl;//第一个成员是一个CAA类型的对象 第二个是CAA对象的成员属性

	CCC cc;
	cout << cc.m_aa.m_a << endl;


	return 0;
}