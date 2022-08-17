//#include<iostream>
//using namespace std;
//
//
///*
//
//继承下：构造的执行顺序 父类构造->子类构造->孙子类构造.......析构的执行顺序 孙子类析构->子类析构->父类析构
//
//定义子类对象,先调用子类构造函数,由于子类构造初始化参数列表中会先执行初始化父类空间的成员
//
//会调用父类的构造函数，当子类的构造初始化参数列表执行完毕后，再执行子类的函数体代码
//
//定义子类对象声明周期结束时,自动调用子类析构,析构执行完毕后,才真正回收对象的内存空间
//
//在子类对象内存空间中包含了父类的成员,回收父类成员前要调用父类的析构,再去回收父类的成员
//
//*/
//
//class CStepFather
//{
//public:
//	int m_a;
//	CStepFather()
//	{
//		m_a = 10;
//	}
//	CStepFather(int a)
//	{
//		m_a = a;
//	}
//	~CStepFather()
//	{
//		cout << "CStepFather" << endl;
//	}
//};
//
//class CFather
//{
//public:
//	int m_c;
//	CFather()
//	{
//		m_c = 30;
//	}
//	CFather(int a)
//	{
//		m_c = a;
//	}
//	~CFather()
//	{
//		cout << "CFather" << endl;
//	}
//};
//
//
//
////继承  会先创建父类空间的成员 再创建子类空间的成员
////因此  会先初始化父类成员 再初始化子类成员
//class CSon:public CFather
//{
//public:
//	CStepFather m_stepfather;//相当于属于是子类空间的东西
//	int m_b;
//
//	CSon():m_stepfather(10),CFather(20)
//		//后爹是要加个对象传个对象值
//		//若后续不写父类初始化,或者不写父类初始化的参数值,自动匹配父类里面的一个无参构造
//	{
//
//	}
//	CSon(int a) :m_stepfather(10)
//	{
//
//	}
//
//	CSon(int a,int b)
//		//若都不写 自动匹配无参构造
//	{
//
//	}
//	~CSon()
//	{
//		cout << "CSon" << endl;
//	}
//
//};
//
//
//int main02()
//{
//	/*CSon son;
//	cout << son.m_c << "  " << son.m_stepfather.m_a << endl;
//	CSon son1(10);
//	cout << son1.m_c << "  " << son1.m_stepfather.m_a << endl;
//	CSon son2(10,20);
//	cout << son2.m_c << "  " << son2.m_stepfather.m_a << endl;*/
//
//	CSon son;
//	//析构时 顺序按照内存 从高到低 按照逻辑 从下往上回收空间 
//	//即先回收子类空间 再回收父类空间
//	//先执行子类的析构,再执行子类空间里面的类的析构 再执行父类空间的类的析构
//
//	return 0;
//}
//
//
