#include<iostream>
using namespace std;

/*

static数据成员在类外定义和初始化是为了保证只被定义和初始化一次,在类内初始化便会使得所有对象都有一个静态成员

静态成员属性：不属于成员 属性类，只有一份 在编译期存在 ，存在与否与 和 是否定义对象无关， 多个对象共享这一份静态成员属性
定义且初始化：在类外进行初始化 格式：类型  类名::静态成员属性= 初始值

静态成员函数：只能使用静态的成员属性，不能使用一般的成员属性
原因：this只能用于非静态函数内 无法使用this指针，则无法调用普通成员属性
属于类的,有没有对象都可以使用,只有一份，编译期存在，多个对象共享


静态成员函数 和 普通成员函数根本区别：
静态成员函数 无this指针
普通成员函数 有this指针

1.静态成员函数 没有隐藏的this指针
2.静态成员函数 只能使用静态的成员属性
3.静态成员函数 可以类名作用域直接调用，也可以用对象调用，普通成员函数只能通过对象调用
*/
class C1
{
public:
	static int m_a;
	C1()
	{
		m_b = 20;
		cout << m_a << endl;//不在构造函数类初始化， 初始化一般是在类外 ，可以在构造函数中使用
	}
	int m_b;
	static void fun()
	{
		cout << m_a << endl;//静态成员有没有对象都可以使用
		//this->m_b;//this只能用于非静态函数内
		cout << "static void fun()" << endl;
		//fun2(); //对面普通成员函数也不能调用 需要this指针
		fun3();//可以调用静态成员函数 因为静态成员函数有没有对象都可以使用
	}

	void fun2()
	{
		cout << "void fun2()" << endl;
	}

	static void fun3()
	{
		cout << "static void fun3()" << endl;
	}
};

//静态类成员 初始化
int C1::m_a = 10;

int main02()
{
	//C1 tst;
	//cout << sizeof(C1) << " " << sizeof(tst) << endl;// 1 1

	//C1* p = nullptr;
	//cout << p->m_a << endl; //正常调用 表明不是成员 属于类
	//C1 tst1;
	//C1 tst2;
	//cout << tst1.m_a << " " << &tst1.m_a << endl;
	//cout << tst2.m_a << " " << &tst2.m_a << endl;
	//表明确实是一份


	//在没有对象时，可以类名作用域 直接调用
	cout << C1::m_a << endl;//10 可以直接调用
	C1::m_a = 20;

	C1 tst3;//有对象后 可以通过对象调用
	cout << tst3.m_a << endl;

	C1::fun();

	C1 tst4;
	tst4.fun();
	return 0;
}