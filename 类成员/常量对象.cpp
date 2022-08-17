#include<iostream>
using namespace std;


class C5
{
public:
	void fun1()const
	{
		cout << "void fun1()const" << endl;
	}
	static void fun2()
	{
		cout << "static void fun2()" << endl;
	}
	void fun3()
	{
		cout << "void fun3()" << endl;
	}
};

int main()
{
	const C5 tst;//常量对象
	tst.fun1();
	tst.fun2();
	//tst.fun3(); //常量对象不能调用普通函数 安全级别降低的操作  --是针对空间来说 const*p是修饰了空间 *const p是修饰指针 空间未被修饰 所以是安全级别降低
	// C5 *const pthis=&tst;非法
	//const C5 *const pthis1=&tst;合法
	// 
	// 
	//类似：
	//const int a = 10;
	//int* const p = &a;//类型不同 安全级别降低的操作


	return 0;
}