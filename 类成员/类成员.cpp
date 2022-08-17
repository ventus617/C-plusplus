#include<iostream>
using namespace std;

//对象属于定义成员  成员必须要有定义 才能使用 
//空类定义对象的大小1个字节，来占位，表示对象真实存在于内存空间中
//定义对象的大小应该包含，类中成员属性，类成员属性是属于对象的，定义对象时存在
// 定义多个对象存在多份成员属性，彼此独立 
//大小应满足字对齐，根据上一个类成员的类型的大小来占位
// 
// 
//类成员属于对象  函数是存在类的，只要定义类就可以使用
// 类函数属于类，在编译器存在，存在与否和对象是否存在无关 
// 函数不属于对象
// 只有一份，多个对象共享这一份函数
// 
//
//

class C2
{
public:
	
	//this可以调用private的对象,可以调用所有类内的成员
	//this指针 当前类对象的指针 【类名*const this】 作为一个中间接口 将对象和函数链接起来
	//指向调用该函数中的对象，函数中调用类成员是通过this 指针调用的
	void show(/* C2 * const this */)
	{
		cout <<m_a<< "void show()" << endl;
		cout << this->m_a << "void show()" << endl;//this指针 表明指向m_a 成员通过this 指针调用
	}
	//放在后面也可以 因为是通过this指针调用 不是从全局寻找
	int m_a;
	char m_c;
};
int main01()
{
	C2 tst2;
	C2 tst3;
	cout << &tst2.m_a << " " << &tst3.m_a << endl;
	//表示不同成员的同一种属性拥有不同地址，是不同的
	tst2.m_a = 10;
	tst3.m_a = 20;

	cout << tst2.m_a << " " << tst3.m_a << endl;
	//如何区分调用的谁的m_a
	//类中的非静态成员函数，都会有一个默认的const隐藏的参数(处于所有参数最前面)this指针
	//this 指针由编译器默认添加的第一个参数
	tst2.show();
	tst3.show();

	return 0;
}