//#include<iostream>
//#include"def.h"
//using namespace std;
//
//
//
//void fun(int a)
//{
//	cout << "void fun(int a)" <<a<< endl;
//}
//
//void fun(const char* p)
//{
//	cout << "void fun(const char* p)" <<p<< endl;
//}
//
//void fun(char c)
//{
//	cout << "void fun(char c)" << c << endl;
//}
//
//int main()
//{
//	int a = NN;//替换为 : int a=10;
//	cout << a << endl;
//	for (int i = 0; i < NN; i++)
//	{
//		cout << i << endl;
//	}
//	cout << "------------------------" << endl;
//	AA;
//	
//	
//
//	cout << "------------------------" << endl;
//	BB(3);
//	cout << "------------------------" << endl;
//	BB(2 + 3);
//	cout << "------------------------" << endl;
//
//	int aa=CC(2 + 3, 4);//期望;20 实际2+3*4=14
//	cout << aa << endl;
//
//
//	int aa1 = CC((2 + 3), 4);//期望;20 实际20
//	cout << aa1 << endl;
//	int aa2 = DD((2 + 3), 4);//期望;20 实际20
//	cout << aa2 << endl;
//
//	int aa3=DD(3, 4) / DD(2, 6);//期望1 实际36 
//	//（3）*（4）/（2）*（6）=12/2 *6= 6*6= 36
//	cout << aa3 << endl;
//
//
//	int aa4 = EE(3, 4) / EE(2, 6);//期望1 实际1
//	cout << aa4 << endl;
//
//
//	fun(FF(11));// void fun(const char*p)11, "11"
//	fun(FF(abd));//void fun(const char* p)abd
//	fun(FF("bcd"));//void fun(const char* p)"bcd"
//
//	char c = HH(1);
//	cout << c << endl;
//
//
//	fun(HH(a)); //void fun(char c) a
//
//	JJ; //int ab=10;
//	cout << ab << endl;
//
//	KK(1);
//	cout << a1 << endl;
//	KK(2);
//	cout << a2 << endl;
//	//-----------------------------------------
//
//
//	/*CAA aa6;
//	aa6.fun();
//	aa6.fun2();*/
//
//	//CBB aa7;
//	//aa7.fun();
//	//aa7.fun2();
//
//
//	MM(CAA);
//
//	MM(CBB);
//
//
//#define QQ 10
//	int f = QQ;
//
//#undef QQ //取消宏定义
//	int QQ = 20;
//	cout << QQ << endl;
//
//	//RR("123");//宏本身不会做语法检查,编译期间才会检查
//	return 0;
//	
//
//}