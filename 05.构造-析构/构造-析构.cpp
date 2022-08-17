#include<iostream>
using namespace std;


class CTest
{
public:
	int m_nA;
	int* m_p;
	//定义对象的时候，自动调用，来初始化类中成员属性
	CTest()
	{
		m_nA = 10;
		m_p = nullptr;
	}
	CTest(int a)
	{
		m_nA = a;
		m_p = new int(a);
	}

	//void my_delete()
	//{
	//	if (m_p)
	//	{
	//		delete m_p;
	//		m_p = nullptr;
	//	}
	//}

	//析构函数---------------------------------
	//函数名 ~+类名,无参,删除的是已经在类中定义的变量
	//默认的析构函数，函数体代码为空
	//空类中编译器会默认提供一个析构函数
	//一旦手动重构了析构函数，编译器不会提供默认的析构函数
	
	//对象声明周期结束了，对象回收之前，去自动调用。
	//在回收对象空间之前，去回收额外的空间，回收完额外的空间后再去回收对象的空间
	//作用：回收类中成员额外申请的空间，与对象空间本身无关
	//即回收new出来的额外的堆区空间，不是回收m_p变量的栈区空间
	//无论是默认，还是手动重构的析构函数，都不允许带参数，也不允许定义多个，仅一份
	~CTest()
	{
		if (m_p)
		{
			delete m_p;
			m_p = nullptr;
		}
	}

};

int main02()
{
	//CTest tst;//无参的初始化
	//cout << tst.m_nA << endl;
	//CTest tst2(20);//类在定义对象的时候，就得初始化了
	//cout << tst2.m_nA << endl;
	//CTest tst3(40);
	//cout << tst3.m_nA << "  " <<*tst3.m_p << endl;
	//tst3.my_delete();


	CTest tst4(50);//在{}内执行，析构函数在}处执行
	CTest* pTst = new CTest(60);
	cout << pTst->m_nA << " " << *pTst->m_p << endl;
	delete pTst;
	pTst = nullptr;
	return 0;
}