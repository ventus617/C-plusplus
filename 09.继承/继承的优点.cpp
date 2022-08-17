//#include<iostream>
//using namespace std;
///*
//继承的优点：
//把一些功能相似的类中的公共成员抽离出来,形成一个类,这个类作为一个父类,各个子类继承这个父类
//提高代码复用性、扩展性
//*/
//
//class Cman
//{
//public:
//	int m_money;
//	Cman(int m)
//	{
//		m_money = m;
//	}
//	void Cost(int n)
//	{
//		m_money -= n;
//	}
//	void Show()
//	{
//		cout << "m_money=" << m_money << endl;
//
//	}
//};
//
//class Cyellow:public Cman
//{
//public:
//	Cyellow(int m):Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "马西西" << endl;
//	}
//};
//class Cwhite:public Cman
//{
//public:
//	Cwhite(int m) :Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "Steak" << endl;
//	}
//};
//class Cblack:public Cman
//{
//public:
//	Cblack(int m) :Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "Curry" << endl;
//	}
//};
//int main04()
//{
//	Cyellow C1(200);
//	C1.Cost(20);
//	C1.Show();
//	C1.Eat();
//
//
//	Cwhite C2(140);
//	C2.Cost(40);
//	C2.Show();
//	C2.Eat();
//
//
//	Cblack C3(180);
//	C3.Cost(80);
//	C3.Show();
//	C3.Eat();
//
//	return 0;
//}