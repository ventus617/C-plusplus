//#pragma once
//
////宏的作用:"替换"
//
//
//// \; 连接当前行和下一行,一般最后一行不加\,加上则还要连接下一行内容 反斜杠后面不要加任何的字符（空格,TAB,注释也不行）
//
//#define NN 10
//#define AA for(int i=0;i<NN;i++){\
//cout << i << endl;\
//}
//
////int a;
//
// 
////宏可以带参数,参数也是一个替换的作用,但是也仅仅只是一个替换作用,不会去自动计算参数,也不会做表达式求解
//#define BB(COUNT)\
//	for(int i=0;i<COUNT;i++){\
//	cout << i << endl;\
//	}
//
//
//
//#define CC(A,B) A*B
//
//#define DD(A,B)  (A)*(B)
//
//#define EE(A,B)  ((A)*(B))
//
////---------------------------------
//
//// #:将宏的参数转换为字符串,相当于加上 双引号
//
//#define FF(PARAM) #PARAM
//
//
////#@：将宏的参数转换为字符,相当于加上了 单引号
//#define HH(PARAM) #@PARAM
//
//
////##：连接组合成一个变量,拼接作用
//
//#define JJ  int a##b=10;
//
//#define KK(PARAM) int a##PARAM=10;
//
//#include<iostream>
//using namespace std;
//
//class CAA {
//public:
//	void fun()
//	{
//		cout << "CAA::fun" << endl;
//	}
//	void fun2()
//	{
//		cout << "CAA::fun2" << endl;
//	}
//};
//
//class CBB {
//public:
//	void fun()
//	{
//		cout << "CBB::fun" << endl;
//	}
//	void fun2()
//	{
//		cout << "CBB::fun2()" << endl;
//	}
//};
//
//#define MM(CLASS_NAME)\
//	CLASS_NAME aa6##CLASS_NAME;\
//	aa6##CLASS_NAME.fun();\
//	aa6##CLASS_NAME.fun2();
//
//#define RR(PARAM) int a=PARAM;
////宏本身不会做语法检查,编译期间才会检查