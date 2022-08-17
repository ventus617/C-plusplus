#include<iostream>
using namespace std;
//这里的空类是指一个看似空类的类
//实际上：空类是没有数据成员，没有函数的类，例如 class Empty { };

//类 即数据（成员属性）+算法（成员函数）
//对象 即类的一个实例，具体的概念，真正存在于内存中

//类命名 一般以 大C 开头
//class 定义类的关键字 类是一个抽象的概念（并非要具体占用空间，相当于描述一个class类型的变量） 
// 类成员访问修饰符：默认是私有的（private），描述类成员所能使用的范围，访问控制，访问权限
// private：只能在类内成员中使用
// protected：类内 和 子类 中可以使用
// public：无约束，在任何地方只要能定义对象，都可以使用（类内与类外都能使用）
// 
// 
// 
// 
//成员变量（成员属性）一般是以m_开头
//可以理解为一个结构体，但内嵌对应函数
//仅在实际定义变量时，才会在内存开辟空间
class CPeople
{
//会向下继承访问修饰符，直到碰见另一个访问修饰符
public:
	string m_strName;
protected:
	int m_strAge;
private:
	bool m_sex;

public:
	//成员函数（方法）

	void show()
	{
		cout << "void show()" << endl;
		cout << "m_sex=" << m_sex << ",m_strAge=" << m_strAge << endl;
	}
	//公共的set接口
	void SetAge(int age)
	{
		m_strAge = age;
	}
	void SetSex(bool sex)
	{
		m_sex = sex;
	}	
	//公共的get接口
	int GetAge()
	{
		return m_strAge;
	}
	int GetSex()
	{
		return m_sex;
	}
	//--------------------------
	void Init()
	{
		m_strName = "小兰";
		m_strAge = 21;
		m_sex = false;
	}
	//--------------------------
	/*
	
		即使在一个看似空类中都会有一个默认的函数，构造函数
		默认的构造函数:函数名为当前类名，无参数，没有返回值（并不是void 是真的没有返回值），函数体代码为空，是未初始化的值
		定义对象时,自动去调用该函数,用来初始化类成员属性
		构造函数可以多个，相当于函数重载
		一旦手动重构了任何的构造函数，编译器就不会提供默认的构造函数


	*/
	CPeople()
	{
		cout << "Cpeople" << endl;
		m_strName = "小兰";
		m_sex = false;
		m_strAge = 21;
	}
	CPeople(string name)//带参数的构造函数
	{
		cout << "Cpeople" << endl;
		m_strName = name;
		m_sex = false;
		m_strAge = 21;
	}
};

int main02()
{
	CPeople peo;//对象，才会在内存真实开辟空间
	peo.m_strName = "牛东东";
	cout << peo.m_strName << endl;
	peo.SetAge (20);
	peo.SetSex (true);
	peo.show();

	cout << "GetAge==" << peo.GetAge() << endl;
	cout << "GetSex==" << peo.GetSex() << endl;


	CPeople peo3;
	peo3.m_strName = "牛冬冬";
	peo3.SetAge(20);
	peo3.SetSex(true);

	CPeople peo2;
	peo2.m_strName = "马西西";
	peo2.SetAge(20);
	peo2.SetSex(false);
	CPeople peo4;
	cout << peo4.m_strName << endl;
	cout << peo4.GetAge()<< endl;
	cout << peo4.GetSex() << endl;

	CPeople peo5;//自动调用带参数的构造函数
	cout << peo5.m_strName << endl;
	cout << peo5.GetAge() << endl;
	cout << peo5.GetSex() << endl;

	return 0;
}