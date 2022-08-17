/*
编译期:将源代码文件交给编译器 编译、生成,最终生成一个可执行程序的过程,静态或者全局在此时期可见

运行期:指向程序的过程交给操作系统去运行,退出的过程,堆和栈是在运行期才可见

编译期分配内存，就是用静态或全局数组。这是在编译的时候确定的。
运行期分配内存，就是用malloc()之类的函数，在堆上分配内存。
编译期内存错误，就是比如某个数据段DATA段或者CODE段等等，超过跑这个程序的目标机的存储器的限制。比如DOS下，DATA段不能超过64K吧。
运行期内存错误，就是运行的时候发生的，比如申请不到内存，内存越界访问，等等。


类中编译期:访问修饰符 和 作用域

定义类对象,引用,指针 属于运行期的东西（因为要分配内存） 

指针在运行期仅仅是使用指针指向的地址来使用 而不去管作用域和访问修饰符


*/
#include<iostream>
using namespace std;
class AA
{
public:
	virtual void fun() = 0;
};

char buffer[16] = { 0 };

class Ctest:public AA {
private:
	void fun()
	{
		cout << "void fun()" << endl;

	}
	void fun2()
	{
		cout << "void fun2()" << endl;
	}

public:
	void Getfun()
	{
		printf("%p \n", &Ctest::fun2);

		sprintf_s(buffer, 16, "%d \n", &Ctest::fun2);	//获取他的地址输入到buffer中
		cout << buffer << endl;
	}
};


int main()
{

//#if __cplusplus
//#define nn 10
//#else
//#define nn 20
//#endif
//	//编译期确定的
//	int a = nn;
//	cout << a << endl;
//	//---------------------------------
//
//
//	//运行期确定的
//	int MM = 0;
//	cin >> MM;
//	if (MM == 10)
//	{
//		cout << "10" << endl;
//	}
//	else
//	{
//		cout << "20" << endl;
//	}

	//----------------------------------
	const int len = 1000000000000;
	//int arr[len] = { 0 };//编译期报错

	int len2 = 1000000000000;
	/*new int[len2]; *///运行期报错

	Ctest tst;
	AA* pp = &tst;
	pp->fun();
	tst.Getfun();


	int a = atoi(buffer);//将buffer里面的fun2的地址转换为10进制
	void(*p_fun)() =(void(*)()) a;//将a强转为对应函数类型 p_fun获得buffer内的地址
	(*p_fun)();

	
	return 0;
}