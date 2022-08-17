//#include<iostream>
//using namespace std;
//
//class C1
//{
//public:
//	int m_a;
//
//	char* m_p;
//	C1()
//	{
//		m_a = 10;
//		m_p = new char('b');
//	}
//public:
//	int add(int a)
//	{
//		return m_a + a;
//	}
//
//	//operator 重载操作符的关键字,本质上是一个函数,通过这个函数来扩展操作符的功能
//	//函数名为: operator 加上要重载的操作符 如果从表面重载的意义上来看 相当于把函数名变成了操作符
//	//参数首先根据 操作符 的使用方法有关,考虑顺序（和写的顺序有关）、数量（必须和操作符的运算规则匹配）、类型得相同, 然后和类内的成员个数有关
//	//返回值:一般是要有返回值的,为了和后续的操作符继续操作
//	int operator+(int a)
//	{
//		return m_a + a;
//	}
//
//	int operator=(int a)
//	{
//		m_a = a;
//		return m_a;
//	}
//	int operator+=(int a)
//	{
//		m_a += a;
//		return m_a;
//	}
//	//int operator++(/* C1 const * this */)
//	//{
//	//	//左++
//	//	return ++m_a;
//	//}
//	//int operator++(int)
//	//{
//	//	//右++ C++标准内定义的一个形式 比左++多指定一个整形的参数,只是为了区分,没有其他的含义
//	//	return m_a++;
//	//}
//	char operator*()
//	{
//		return *m_p;
//	}
//	int operator* (int a)
//	{
//		return a * m_a;
//	}
//};
//
////10+tst;
////类内,类外重载同一个操作符：
////参数差异,类内的重载操作符由于有默认的this指针是在第一个参数位置,所以比类外少一个参数,并且类内顺序必需第一个是this指针
////类外可以调整参数顺序
//int operator +(int a, C1& tst)//在类外重载
//{
//	return a + tst.m_a;
//}
//int operator +( C1& tst,int a)//在类外重载
//{
//	return a + tst.m_a;
//}
//
//int operator++(C1&tst)
//{
//	//左++
//	return ++tst.m_a;
//}
//int operator++(C1&tst,int)
//{
//	//右++ C++标准内定义的一个形式 比左++多指定一个整形的参数,只是为了区分,没有其他的含义
//	return tst.m_a++;
//}
//
////重载输入输出
//ostream& operator<<(ostream& os, C1& tst)
//{
//	os << tst.m_a;
//	return os;
//}
//
//istream& operator>>(istream& is, C1& tst)
//{
//	is >> tst.m_a;
//	return is;
//}
//
////必需是类成员函数,不能在类外重载‘=’操作符，出于安全性原因
////int operator=(int &a, C1& tst)
////{
////	a = tst.m_a;
////	return a;
////}
////不能在类外重载的操作符:= () [] ->
//
//
////不能改变操作符的使用规则,不允许使用默认参数
//char operator +( C1& tst,char a/*='a'*/)//在类外重载
//{
//	return a + *tst.m_p;
//}
////类外必须至少包含一个自定义类型(类、结构体),是属于对操作符功能的扩展,而非重定义或者新定义
////int operator+(int a, int b)
////{
////	return a + b;
////}
//
//
//int main()
//{
//	////C1 tst;
//	//////tst + 10;//tst.m_a+10;
//	////int a = tst.add(10);
//	////cout << a << endl;//20
//
//	////int b = tst.operator+(10);
//	////cout << b << endl;//20
//	////
//	////int c = tst + 10;
//	////cout << c << endl;//20
//	//////int d = 10 + tst;//顺序错误 不可使用
//
//	////tst = 20;
//	////cout << tst.m_a << endl;
//
//	////C1 tst2;
//	////tst2 = tst = 30;//有返回值就可以进行连等操作
//	////cout << tst.m_a << " " << tst2.m_a << endl;
//	////
//	////tst2 = tst += 20;//50
//
//	////cout << tst2.m_a << " " << tst.m_a << endl;
//
//	////int d = ++tst;
//	////cout << d << " " << tst.m_a << endl;//51 51
//	////int e = tst++;
//	////cout << e << " " << tst.m_a << endl;//51 52
//	//C1 tst;
//
//	////int f = 10 + tst;
//	////cout << f << endl;
//
//	//////int g=tst+10; //将类内的注释掉,匹配一个类外的
//	////cout << tst.operator+(10) << endl;//类内
//	////cout << ::operator+(tst, 10) << endl;//类外全局
//
//	////int h = tst++;//类内类外同时存在,会产生歧义;
//	////cout << h << " " << tst.m_a << endl;
//	////h = ++tst;
//	////cout << h << " " << tst.m_a << endl;
//
//	//cin >> tst;
//
//	//cout << tst;
//
//	//int a = 10;
//
//	////类外重载=的错误示例
//	////a = tst;
//
//	////10 = tst;
//
//	////int& aa = 10;
//	C1 tst;
//	cout << *tst << endl;//b
//
//	cout << tst * 20 << endl;;//200
//
//	cout << tst + 'a' << endl;
//	//如果里面的参数可以使用默认的
//	//那么就改变了 + 号的使用规则 变成：
//	//tst +; //用法错误
//	return 0;
//}