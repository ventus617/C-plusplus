//#include<iostream>
//using namespace std;
//
//
///*
//
//继承：子类包含父类，可以使用父类的成员，会为父类的成员开辟对应的空间
//子类对象成员属性在内存空间中,排布顺序：先父类成员 再子类成员
//
//*/
////父类（基类）
//class CFather
//{
//public:
//	int m_fa;
//	int m_money=200;
//	void show_fa()
//	{
//		cout << "void show_fa()" << endl;
//	}
//	void show()
//	{
//		cout << "CFather::show()" << endl;
//	}
//};
//
////子类（派生类） 类名 + ： + 继承方式 + 基类
//class CSon :public CFather
//{
//public:
//	int m_son = 10;
//	int m_money;
//	void show_son()
//	{
//		cout << "void show_son()" << endl;
//		m_fa = 10;
//		show_fa();
//		cout << "m_fa==" << m_fa << endl;
//	}
//	void show()
//	{
//		cout << "CSon::show()" << endl;
//	}
//};
//
//int main()
//{
//	CSon son;
//	son.show_son();
//	son.m_fa = 20;
//	cout << son.m_fa << endl;
//	son.show_fa();
//	cout << "----------" << endl;
//	cout << sizeof(CFather) << " " <<sizeof(son) <<endl;//4 8 创建了其成员空间
//
//	cout << &son << " " <<&son.m_fa<<" "<<&son.m_son << endl;//会先开辟父类成员的空间 再开辟自己成员的空间
//	son.m_money = 100;
//
//
//
//	//按照作用域去区别相同的成员
//	//如果想要使用同名的父类成员，需要显示的指明作用域
//	//子类和父类有重名成员时
//	//未指定作用域时，默认输出子类的money
//	cout << son.m_money << endl;
//	cout << son.CSon::m_money << endl;
//
//
//	cout << son.CFather::m_money << endl;
//
//	//针对函数
//	son.show();
//	son.CSon::show();
//	son.CFather::show();
//
//	son.CFather::m_money = 150;
//	cout << son.CFather::m_money << endl;
//
//
//	//-----------------------------------
//	//内存排布中即使有相同成员 也是先写完父 再写子
//	cout << &son << endl;
//	cout << &son.m_fa << endl;
//	cout << &son.CFather::m_money << endl;
//	cout << &son.m_son << endl;
//	cout << &son.CSon::m_money << endl;
//
//	return 0;
//}