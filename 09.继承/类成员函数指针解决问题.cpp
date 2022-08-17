//#include<iostream>
//using namespace std;
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
//class Cyellow :public Cman
//{
//public:
//	Cyellow(int m) :Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "马西西" << endl;
//	}
//};
//class Cwhite :public Cman
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
//class Cblack :public Cman
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
//
////父类指针，可以同一多种子类类型，提高代码复用性和扩展性
////弊端：父类指针只能使用父类的成员，而不能直接使用子类的成员
//void fun1(Cman* pman)
//{
//	pman->Cost(10);
//	pman->Show();
//	//((Cyellow*)pman)->Eat();//不能这样做 不是一个通用的做法
//}
//
//class family
//{
//public:
//	Cman* peo[3];
//	family()
//	{
//		peo[0] = new Cyellow(100);
//		peo[1] = new Cblack(200);
//		peo[2] = new Cwhite(300);
//	}
//};
//
//int main()
//{
//	fun1(new Cyellow(100));
//
//
//	//-------------------------------
//	Cman* pPeo = new Cyellow(100);
//	/*pPeo->Eat();*/
//	//成功指向一个子类函数
//	//void (Cyellow:: * p_fun)() = &Cyellow::Eat;
//	void (Cman :: * p_fun)() =(void (Cman :: * )()) &Cyellow::Eat;//强转
//	//因此可以使得父类指针 指向一个指针 该指针指向一个子类函数
//	(pPeo->*p_fun)();
//
//	return 0;
//}