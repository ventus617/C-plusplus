
#include<iostream>
using namespace std;
//
////*
//* 3个要点：
//* 1.这个类最多只有一个实例(对象)
//* 2.它必须自己创建这个实例（而不是调用者创建）。(利用引用或者指针)
//* 3.它必须自己想整个系统提供全局访问点访问这个实例。
//*/


//懒汉式：什么时候用 什么时候创建，时间换空间（饿的时候才去做饭，会浪费时间等一段时间才能吃）


//class CSingleton
//{
//private:
//	static CSingleton* m_pSin;//防止被修改
//private://构造私有化
//	CSingleton()
//	{
//		m_a = 10;
//	}
//	/*CSingleton(const CSingleton&)
//	{
//
//	}*/
//	CSingleton(const CSingleton& /*tst*/) = delete;//弃用的函数 不让使用拷贝构造
//	~CSingleton(){}
//	//不能放在析构里面来回收 可能会栈溢出（delete m_pSin的时候由于m_pSin是自己的对象，所以delete其实是调用了自己的析构来回收m_pSin,因此会一直死循环）
//	//~CSingleton() { if (m_pSin)
//	/*{
//		delete m_pSin;
//		m_pSin = nullptr;
//	}
//}*/
//public:
//	//它必须自己想整个系统提供全局访问点访问这个实例。
//	 static CSingleton* CreateSingleton()
//	{
//		 //它必须自己创建这个实例（而不是调用者创建）。
//			//加锁
//		 if(m_pSin==nullptr)//最多只有一个实例 即返回的一定是第一次创建成功的空间地址
//		 {
//			//多线程下会失效，可能会创建出多个对象，加锁解决
//		 m_pSin = new CSingleton; 
//		 }
//			//解锁
//		return m_pSin;//创建对象 返回对象地址
//	}
//	 static void DestorySingleton(CSingleton* &psin)
//		 //加参优化(传入该指针的空间) 使得被销毁后 其实际为空 无非法值
//	 {
//		 if (m_pSin)
//		 {
//			 delete m_pSin;
//			 //是使得类中的m_pSin为空
//			 m_pSin = nullptr;
//		 }
//		 //是使得在类外调用对象的指针psin为空
//		 psin = nullptr;
//	 }
//
//
//public:
//	int m_a;
//
//};
//CSingleton* CSingleton::m_pSin = nullptr;
//
//int main()
//{
//
//	//构造私有化，使得在类外定义对象非法
//	//不是自己创建的实例 仍是调用者创建的
//	/*CSingleton sin1;
//	CSingleton sin2;*/
//
//	CSingleton* pSin1 = CSingleton::CreateSingleton();
//	cout << pSin1->m_a << " " << pSin1<< endl;	
//
//	CSingleton* pSin2 = CSingleton::CreateSingleton();
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	pSin1->m_a = 20;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	//默认的拷贝构造 会给了一个新的对象
//	//CSingleton sin(*pSin1);
//
//	//cout << &sin << " " << pSin1 << endl;
//
//	//不会影响到原对象的值
//	//sin.m_a = 30; 
//
//	//cout << pSin1->m_a << endl;
//
//
//	//回收
//
//	//1.CSingleton::DestorySingleton();
//	pSin1->DestorySingleton(pSin1);//2.
//	if (pSin1)
//	{
//		cout << pSin1->m_a << endl;
//	}
//
//
//	return 0;
//}


//
//class CSingleton
//{
//public:
//	int m_a;
//
//private:
//	CSingleton()
//	{
//		m_a = 10;
//	}
//	CSingleton(const CSingleton&) = delete;
//	~CSingleton(){}
//public:
//	//静态局部变量 创建之后就会一直存在 直到程序被销毁
//	static CSingleton* CreateSingleton()
//	{
//		//多线程下不会创建出多个变量
//		static CSingleton sin;
//
//		return &sin;
//	}
//
//};
//
//int main()
//{
//	CSingleton*pSin1=CSingleton::CreateSingleton();
//	CSingleton*pSin2=CSingleton::CreateSingleton();
//
//	cout << pSin1->m_a << " " << pSin1 << endl;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	pSin1->m_a = 20;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//
//	return 0;
//}




//
////饿汉式：程序创建之初将这个唯一的实例创建出来,一直等待来用,空间换时间（先把饭做好放在桌子上，等着人饿了之后来吃）
//class CSingleton
//{
//private:
//	static CSingleton sin;
//public:
//	
//	int m_a;
//
//private:
//	CSingleton()
//	{
//		m_a = 10;
//	}
//	CSingleton(const CSingleton&) = delete;
//	~CSingleton() {}
//public:
//	//静态局部变量 创建之后就会一直存在 直到程序被销毁
//	static CSingleton* CreateSingleton()
//	{
//		return &sin;
//	}
//
//};
//
//CSingleton CSingleton::sin; 
//
////private是访问修饰符 代表是在类内才可以访问（加上作用域之后 相当于是在类内 因此可以访问） 但是静态成员的初始化是在类外
//
//int main()
//{
//	CSingleton* pSin1 = CSingleton::CreateSingleton();
//	CSingleton* pSin2 = CSingleton::CreateSingleton();
//
//	cout << pSin1->m_a << " " << pSin1 << endl;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	pSin1->m_a = 20;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//
//	return 0;
//}


