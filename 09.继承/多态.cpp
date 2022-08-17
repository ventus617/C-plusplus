#include<iostream>
using namespace std;

/*
多态:相同的行为方式导致了不同行为结果，同一行语句展示了多种不同的表现形态，多态性
在继承 父类指针可以指向任何继承于该类的子类，多种子类具有多种形态由父类的指针进行同一管理，
父类的指针具有多种子类的形态，即多态

条件：
1.存在继承关系
2.参数：父类的指针指向子类对象
3.virtual ：定义虚函数的关键字
4.子类定义重写了父类的虚函数


重写：子类定义了和父类的虚函数一模一样(函数类型 函数名 参数 返回值)的函数
一旦子类重写了父类的虚函数，子类的这个函数加不加 virtual 关键字都认为是虚函数
*/
class Cman
{
public:
	int m_money;
	Cman(int m)
	{
		m_money = m;
	}
	void Cost(int n)
	{
		m_money -= n;
	}
	void Show()
	{
		cout << "m_money=" << m_money << endl;

	}
	virtual void Eat()
	{

	}
};

class Cyellow :public Cman
{
public:
	Cyellow(int m) :Cman(m)
	{

	}
	virtual void Eat()//加不加 virtual都可以 前提是重写了父类的虚函数
	{
		cout << "马西西" << endl;
	}
};
class Cwhite :public Cman
{
public:
	Cwhite(int m) :Cman(m)
	{

	}
	void Eat()
	{
		cout << "Steak" << endl;
	}
};

typedef void (Cman::* p_fun)();
void fun1(Cman* pman, p_fun pp)
{
	pman->Cost(10);
	pman->Show();
	//((Cyellow*)pman)->Eat();//不能这样做 不是一个通用的做法
	(pman->*pp)();//是给了一个指向子类函数的指针函数
}

//使用多态方式
void fun(Cman* pp)
{
	pp->Cost(20);
	pp->Eat();
	pp->Show();
}
int main()
{
	fun1(new Cyellow(100), (p_fun) & (Cyellow::Eat));
	fun1(new Cwhite(100), (p_fun) & (Cwhite::Eat));
	fun(new Cyellow(20));
	return 0;
}