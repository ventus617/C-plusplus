#include<iostream>
using namespace std;

/*
	在继承下 定义子类对象,虚函数指针指向的是子类的虚函数列表

	在继承下 子类不但继承了父类的成员,并且子类的虚函数列表会继承父类的虚函数列表,保留父类的虚函数地址
	
	如果有重写父类的虚函数,则会在虚函数列表原位置处中覆盖掉同名函数

	如果子类定义了单独的虚函数,则在虚函数列表中不会被看见,但仍是存在的(按声明顺序在结尾往后依次添加)

	



*/

class Cfather
{
public:
	virtual void fun()
	{
		cout << "Cfather::fun" << endl;
	}
	virtual void fun1()
	{
		cout << "Cfather::fun1" << endl;
	}
};

class Cson :public Cfather
{
public:
	virtual void fun()
	{
		cout << "Cson::fun" << endl;
	}
	virtual void fun2()
	{
		cout << "Cson::fun2" << endl;
	}
	Cson()
	{

	}
};
int main()
{

	//子类 父类都有一个虚函数指针 指向自己的虚函数列表
	Cfather fa;
	fa.fun();


	Cson son;
	son.fun();

	son.fun1();
	son.fun2();

	Cfather* pfa = &son;//指向的是子类对象的首地址

	pfa->fun();

	
	//在调用fun函数的时候,我的_vfptf在我所指向的子类中已经初始化了,函数已经被重写了,相当于也是指向子类的虚函数列表
	pfa->fun1();

	return 0;
}