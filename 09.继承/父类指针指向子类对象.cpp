//#include<iostream>
//using namespace std;
//
//class Cman
//{
//public:
//
//
//
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
//
//
//
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
////父类指针，可以统一多种子类类型，提高代码复用性和扩展性
////弊端：父类指针只能使用父类的成员，而不能直接使用子类的成员
//
////在继承下 父类的指针可以直接指向（不用强转）任何一个子类对象,或者说 子类对象将自己的首地址传给父类指针,这时子类对象可以通过父类指针来调用父类函数
//
//
////保证子类对象可以成功调用父类的函数
//
//
////继承的父类的指针this在子类对象想要调用父类函数时,和子类指针this指向的是同一地址,指向同一对象（子类对象的地址会传给父类的this）
//
//
////因此会根据子类的当前对象的属性来进行输出（可以在父类中既定内容，仅传送子类去参与）
//
//
////也就形成了   子类调用父类函数->父类指向子类对象,得到对象地址->用该地址的空间,来使用函数得到所需内容
//
//void fun1(Cman* pman)
//{
//
//
//	pman->Cost(10);
//	pman->Show();
//
//
//}
//
//class family
//{
//
//
//public:
//	Cman* peo[3];
//	family()
//	{
//		peo[0] = new Cyellow(100);
//		peo[1] = new Cblack(200);
//		peo[2] = new Cwhite(300);
//	}
//
//
//};
//
//int main()
//{
//	fun1(new Cyellow(100));
//	family p1;
//	return 0;
//}