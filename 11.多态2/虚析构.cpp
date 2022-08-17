//#include<iostream>
//using namespace std;
//
//class Cfather
//{
//public:
//	Cfather()
//	{
//		cout << "Cfather()" << endl;
//	}
//	virtual ~Cfather()
//	{
//		cout << "~Cfather()" << endl;
//	}
//};
//class Cson :public Cfather
//{
//public:
//	int* m_p;
//public:
//	Cson()
//	{
//		cout << "Cson()" << endl;
//		m_p = new int(10);
//	}
//	~Cson()
//	{
//		cout << "~Cson()" << endl;
//		if (m_p)
//		{
//			delete m_p;
//			m_p = nullptr;
//		}
//	}
//};
//
//int main()
//{
//	Cson* pson = new Cson;
//
//	delete pson;
//	pson = nullptr;
//
//	/*
//	Cfather()
//	Cson()
//	~Cson()
//	~Cfather()
//	*/
//	//正常回收
//	//--------------------------------
//
//	cout << "---------------------" << endl;
//	Cfather* pfa = new Cson;
//	delete pfa;
//	//delete 回收空间之前是 回收调用该指针的类型的析构,而非根据所指向的空间
//	//若子类里面有new的内容 会导致内存泄漏 解决方法：虚析构
//  //由于子类的空间里面含有父类的成员 所以先执行子类的析构后 发现空间还有父类成员也要被回收 那么此时便又会去调用真正的父类的析构
//	// Cson()是由virtual关键字引导的 当父类指针指向子类对象时,此时父类析构函数变为虚函数,被子类重写,实际上调用的是子类的析构
//	//实际上析构的名字在编译器里面都是一样的
//	//pfa->~Cfather()
//	pfa = nullptr;
//
//	/*
//	Cfather()
//	Cson()
//	~Cfather()
//	*/
//	//缺少~Cson()
//	return 0;
//}