#include<iostream>
using namespace std;

class C3
{
public:
	//常量定义就得初始化，一旦初始化不可更改
	const int m_a;//const 仅修饰 仍是对象
	int m_b;
	C3():m_a(10)// :对象（值） 表示初始化参数列表
		//构造函数的初始化参数列表： 在函数参数列表后面（） 然后 :要初始化成员属性（初始化值）
		//是一个真正初始化类成员的地方,一般的成员属性也可以放在初始化参数列表中进行初始化
		//常量成员必需放在初始化参数列表中
		//初始化多个成员用,分割
		//先计算函数参数，再执行初始化参数列表，最后执行函数体代码
		//初始化参数列表存在于所以构造函数中
	{
		m_b = 20;
		//m_a = 10;//认为是一个赋值操作 不认为是一个初始化操作
	}

	//C3(int a) :m_a(a), m_b(a)
	//{
	//	cout << "C3(int a) :m_a(a), m_b(a)" << m_a << " " << m_b << endl;
	//}


	//出现 地址值 和 所需要的值
	//原因：根据类成员在C3里面声明的顺序 小端小尾的方式赋值
	//C3(int a) :m_a(m_b), m_b(a)
	//{
	//	cout << "C3(int a) :m_a(a), m_b(a)" << m_a << " " << m_b << endl;
	//}

	//C3(int a) : m_b(a),m_a(m_b)
	//{
	//	cout << "C3(int a) :m_a(a), m_b(a)" << m_a << " " << m_b << endl;
	//}
	// 
	
	//得按照声明或者定义的顺序
	C3(int a) : m_a(a), m_b(m_a)
	{
		cout << "C3(int a) :m_a(a), m_b(a)" << m_a << " " << m_b << endl;
	}
};


int main03()
{
	cout << sizeof(C3) << endl;//8 常量const 成员 也占4字节
	C3 tst;
	cout << tst.m_a << " " << tst.m_b << endl;

	C3 tst3(40);
	cout << tst3.m_a << " " << tst3.m_b << endl;

	cout << "------------------------" << endl;
	C3 tst2(50);



	return 0;
}