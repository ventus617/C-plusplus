#include<iostream>
using namespace std;

class C2
{
public:
	int m_a;
	C2()
	{
		m_a = 10;
	}

	//operator int 函数名字,无参,无返回类型
	//但是需要返回一个重载当前类型的一个值
	operator int()
	{
		return m_a;
	}
	int operator+(int a)
	{
		return m_a + a;
	}

	//是优先级的问题：
	//重载操作符>>重载类型
};

int main()
{
	C2 tst;
	int a = 0;
	a =tst;
	cout << a << endl;//10

	int b = 0;

	//匹配 int函数
	b = tst;//a=tst.m_a;
	cout << b << endl;//10
	//---------------------------
	int c=tst + 10;
	cout << c << endl;//tst.m_a+10



	return 0;
}