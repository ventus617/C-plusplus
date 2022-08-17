//#include<iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int m_b;
//	CTest()
//	{
//		m_a = 10;
//	}
//	//CTest(int a) //转换构造函数：可以发生隐式类型转换
//	//{
//	//	m_a = a;
//	//}
//	
//	//CTest(int a, int b)//不能发生隐式类型转换 语法错误
//	//{
//	//	m_a = a;
//	//	m_b = b;
//	//}
//
//	//CTest(int a, int b=60)//变成传一个参数的形式 也能发生隐式类型转换
//	//{
//	//	m_a = a;
//	//	m_b = b;
//	//}
//
//
//	//关键字 explicit: 禁止发生隐式类型转换，修饰构造函数
//	explicit CTest(int a=30, int b = 60)//变成不用参数的形式 也能发生隐式类型转换
//	{
//		m_a = a;
//		m_b = b;
//	}
//};
//
//
//int main()
//{
//	
//
//	//CTest tst;
//
//	CTest tst2(20);
//
//
//	//cout << tst.m_a << " " << tst2.m_a << endl;
//
//	CTest tst3 = 30;//隐式类型转换 匹配转换构造函数 将值 变成传参形式 传入函数
//	cout << tst3.m_a << endl;
//
//	//	CTest tst4 = 40,50;
//	CTest tst4(40, 50);//只能显示调用构造函数
//
//	//--------------------------
//	CTest tst5 = 70;
//	cout << tst5.m_a << endl;
//
//	CTest tst6 = 0;//也能发生隐式类型转换 会把0赋值给第一个参数
//	cout << tst6.m_a << " " << tst6.m_b << endl;
//
//
//	CTest tst7(110);//显示调用不受explicit影响
//	cout << tst7.m_a <<" " << tst7.m_b << endl;
//
//	CTest tst8=120;//当被explicit修饰后 被禁止隐式类型转换
//
//	return 0;
//}