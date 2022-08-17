#include<iostream>
using namespace std;
#include"c1test.h"


//作用范围是整个程序都可以直接使用
/*C1 tst2(20)*/;//程序创建运行，全局对象被创建，在主函数之前调用构造进行初始化
//在主函数执行完毕，程序退出之前调用析构函数回收对象
//生命周期伴随着程序创建到销毁

static C1 tst3(40);//生命周期同全局对象，作用域不同，仅在当前文件中可使用，不能跨文件使用
int main()
{
	extern C1 tst2;
	cout << tst2.m_a << endl;

	extern C1* Ptst2;
	cout << Ptst2->m_a << endl;

	cout << "-------------" << endl;
	{
		C1 tst(2);//局部栈区对象，遇到函数返回，或者 } 时生命周期结束
	}

	//在main函数结束时（return 时），栈区回收栈区内对象
	//析构会在return之前回收

	C1* p1 = new C1(20);//在delete的时候，调用析构函数，先回收C1中额外申请的，再回收p1的new的
	//new 堆区的对象，生命周期遇到delete回收
	delete p1;
	p1 = nullptr;
	cout << "-------------" << endl;
	return 0;
}