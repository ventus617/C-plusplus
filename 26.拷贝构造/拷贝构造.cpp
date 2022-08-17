#include<iostream>
using namespace std;

class CTest
{
public:
	int m_a;
	int* m_p;
	CTest()
	{
		m_a = 10;
		m_p = nullptr;
	}
	CTest(int a)
	{
		m_a = a;
		m_p = new int(a);
	}
	
	
	/*
	* 
	即使在一个看似空类的类中,编译器都会默认提供一个拷贝构造函数，函数名为当前的类名，参数为当前类对象的 **引用**
	函数体代码不为空，形参对象中的成员给this对象中的成员依次进行初始化操作
	

	一旦手动重构了拷贝构造函数,编译器就不会提供默认的了
	当一个同类中的对象给另一个对象进行初始化操作时，调用拷贝构造函数 CTest tst3(tst2);

	在一个看似空类的类中提供的默认的拷贝构造函数是一个浅拷贝,可能会有浅拷贝的问题。
	1.当一个对象通过指针修改了指向空间里的数据时，另一个对象在使用时,使用的是修改之后的值。
	2.在回收空间时，同一块内存可能被回收两次，造成非法访问不属于自己的空间（被回收一次之后就不属于自己了）


	解决浅拷贝办法：1.深拷贝  2.避免浅拷贝 针对于函数参数为复合类型（结构体或类） 尽量用指针或引用传递
	*/


	//CTest(const CTest& tst):m_a(tst.m_a) //当前类对象的引用 
	//{
	//	cout << "CTest(const CTest& tst)" << endl;
	//}

		CTest(const CTest& tst):m_a(tst.m_a)/*,m_p(tst.m_p)*/ //当前类对象的引用 
	{
		cout << "CTest(const CTest& tst)" << endl;
		
		m_p = nullptr;
		if (tst.m_p)
		{
			this->m_p = new int(*tst.m_p);//重新申请一个新的m_p指向的空间
		}
		
	}
	~CTest()
	{
		if (m_p)//判断指针
		{
			delete m_p;//回收空间
			m_p = nullptr;
		}
	}

	//即使在空类中都会默认提供一个 operator= 的函数,参数为当前类对象的*引用*，返回值为对象的引用，函数体代码不为空

	//形参对象中的成员给this对象中的成员依次进行赋值;

	//一旦手动重构了 operator= 的函数，编译器就不会提供默认的了,

	//当同类中的一个对象给另一个对象进行赋值操作，operator= 函数
	//默认的operator= 的函数 也是一个浅拷贝，也会有浅拷贝的两个问题

	//CTest& operator=(const CTest& tst)//返回CTest类型 并且是&类型
	//{
	//	this->m_a = tst.m_a;
	//	this->m_p = tst.m_p;

	//	return *this;//返回指针指向的空间 即引用的空间

	//}



	//解决办法:深拷贝

	CTest& operator=(const CTest& tst)//返回CTest类型 并且是&类型
	{
		if (this != &tst)//判断是不是自己
		{

			this->m_a = tst.m_a;
			//this->m_p = tst.m_p;
			if (tst.m_p)
			{
				if (this->m_p)//该类型不适用于数组 数组因为最开始new的长度可能不同 因此最好是重新new一个相同大小的空间 再赋值
				{
					*this->m_p = *tst.m_p;
				}
				else
				{
					this->m_p = new int(*tst.m_p);
				}
			}
			else
			{
				if (this->m_p)
				{
					delete this->m_p;
					this->m_p = nullptr;
				}
				else
				{
					//都为空 没必要赋值操作
				}
			}
			return *this;//返回指针指向的空间 即引用的空间
			//return (CTest&)tst;// 得强转 因为返回的类型是CTest& 而不是const CTest&

			//或者如下方法：

			//const CTest& operator=(const CTest & tst)//返回CTest类型 并且是&类型
			//{
			//	if (this != &tst)//判断是不是自己
			//	{

			//		this->m_a = tst.m_a;
			//		//this->m_p = tst.m_p;
			//		if (tst.m_p)
			//		{
			//			if (this->m_p)//该类型不适用于数组 数组因为最开始new的长度可能不同 因此最好是重新new一个相同大小的空间 再赋值
			//			{
			//				*this->m_p = *tst.m_p;
			//			}
			//			else
			//			{
			//				this->m_p = new int(*tst.m_p);
			//			}
			//		}
			//		else
			//		{
			//			if (this->m_p)
			//			{
			//				delete this->m_p;
			//				this->m_p = nullptr;
			//			}
			//			else
			//			{
			//				//都为空 没必要赋值操作
			//			}
			//		}
			//		return tst; //将返回类型变成const 虽然拷贝构造里面也是默认const 也可以实现连等 但是重载操作符的本意是 CTest类型的
		}
	}
};

//void fun(CTest &tst) //尽量用指针 或者 引用
//{
//	cout << tst.m_a << " " << *tst.m_p << endl;
//}


int main()
{
	CTest tst;

	CTest tst2(10);
	
	tst2 = tst; //赋值 

	cout << tst2.m_a << endl;

	CTest tst3(30);
	CTest tst4;
	tst4 = tst3;
	cout << tst4.m_a << " " << *tst4.m_p << endl;


	{

	//CTest tst;

	//CTest tst2(20);

	//CTest tst3(tst2);
	//cout << tst3.m_a << endl;


	}
	
	//CTest tst2(20);

	//CTest tst3(tst2);
	//cout << tst3.m_a <<" " <<*tst3.m_p<< endl;

	//*tst2.m_p = 30;
	//cout << tst3.m_a << " " << *tst3.m_p << endl;

	{
		/*CTest tst2(20);

		CTest tst3(tst2);
		cout << tst3.m_a << " " << *tst3.m_p << endl;

		*tst2.m_p = 30;
		cout << tst3.m_a << " " << *tst3.m_p << endl;*/
	}
	{
		//CTest tst4(40);
		//fun(tst4);//传递之后 形参会被回收 回收形参之后 指针指向的空间被回收 所以程序崩溃 相当于浅拷贝
		////最好还是使用指针（回收的是形参指针（相当于回收一个存了 传入的地址的 空间） 不是回收指向的空间）或者引用（是相对于对原空间的重新命名）不会被回收
	}
	

	return 0;

}

/*
	一个看似空类的空类中也有的 哪些默认的函数：4个函数
	//实际上的空类是没有数据成员，没有函数的类，例如 class Empty { };
	//

	默认的无参构造函数
	析构函数
	拷贝构造函数
	默认的operator=



*/