
#include<iostream>
using namespace std;

template<typename T=long>
class CTest
{
public:
	T m_t;
	CTest()
	{
		m_t = 10;
	}
	CTest(T t)
	{
		m_t = t;
	}
};

//类模板 需要从右向左一次指定默认的类型，中间不能有间断
//少一种自动推导的方式 因此只有默认和显示指定

template<typename T,typename K=char>
class CTest2
{
public:
	T m_t;
	CTest2()
	{
		m_t = 10;
	}
	CTest2(T t)
	{
		m_t = t;
	}
	void fun()
	{
		cout << typeid(T).name() << endl;
		cout << typeid(K).name() << endl;
	}
};

template<typename T>
class CTest3
{
public:
	T m_t;
	CTest3()
	{
		m_t = 10;
	}
	template<typename K>
	void fun()
	{
		cout << typeid(T).name() << endl;
		cout << typeid(K).name() << endl;
	}
	template<typename K>
	void fun(K k)
	{
		cout << typeid(T).name() << endl;
		cout << typeid(K).name() << endl;
	}

	template<typename K>
	void fun2();
	template<typename K>
	void fun3(K k);
};



//得先指出类的模板 再指出在类中声明的函数模板
//再用正常的 类名<typename>::函数  来定义  (使用时 指定类中使用的类型) 
template<typename T>	//类模板
template<typename K>	//函数模板
void CTest3<T>::fun2()
{
	cout << "void CTest3<T>::fun2<K>()" << endl;
	cout << typeid(T).name() << endl;
	cout << typeid(K).name() << endl;

}


template<typename T>
template<typename K>
void CTest3<T>::fun3(K k)
{
	cout << "void CTest3<int>::fun3(double k)" << endl;
}



class AA
{
public:
	int m_a;
	AA()
	{
		m_a = 10;
	}
};


//自动识别引用的变量的 类型
//如果想要一个类中 包含另一个类的情况
template<typename T>
class BB
{
public:
	T m_t;//传的类的话 就是AA m_t
	BB(T &t)//传的是AA的对象 aa
	{
		m_t = t;// 相当于m_t这个对象赋值为aa这个对象
	}

};

//由于BB传的类型不确定 所以也得typename T
template<typename T>
class CC
{
public:
	BB<T> m_b; //BB的类的一个 不确定的类型传入
	CC(T &t):m_b(t) //值传入 来完成赋值
	{
		
	}
};


int main()
{
	//得显示告诉系统 是什么类型 不然不知道给多大的空间
	CTest<int> tst; //类似 list<int> lst
	cout << tst.m_t << endl;
	CTest<short> tst2(20);
	cout << tst2.m_t << endl;

	//CTest<>tst3(20);//非法操作 在没有默认指定的时候 必须显示指定


	//int* p = nullptr;
	//CTest<> tst4(p);//指针和long型没法自动转换 得强转 类型不匹配 非法报错

	long a = 30;
	CTest<>tst4(a);
	cout << tst4.m_t << endl;

	CTest2<long> tst5;
	tst5.fun();

	CTest2<long, int> tst6;
	tst6.fun();

	CTest3<int> tst7;
	tst7.fun<char>();//如果不传参 且无默认 得显示指定
	tst7.fun(12.3);//在类里面的函数 也可以自动匹配

	CTest3<int> tst8;
	tst8.fun2<short>();

	tst8.fun3(12.3);

	AA aa;
	aa.m_a = 20;

	BB<AA>bb(aa);//创建对象时 确定对象的类型是BB 里面的typename的对象是显示赋值AA 给BB的对象bb 传的是AA的对象aa
	cout << bb.m_t.m_a << endl;//

	CC<AA>cc(aa);//同理 确定BB中使用的类型是AA  这里的辅助和上面一样 相当于是对象与对象之前的赋值 而这个对象包含一系列小变量m_a
	cout<<cc.m_b.m_t.m_a << endl;//



	return 0;
}