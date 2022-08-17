//#include<iostream>
//using namespace std;
//
//
//class CAA
//{
//public:
//	//函数重载
//	void fun(/* CAA* const pthis */int a, int b)
//	{
//		/*cout << "void fun(int a)" <<a<<" "<<b<<endl;*/
//		cout << this << endl;
//	}
//	/*void  fun(char a)
//	{
//		cout << "void fun(char a)" << a << endl;
//	}*/
//};
//
////引入了父类之后,隐藏: 子类和父类定义了同名的成员 子类会把父类的成员隐藏掉
////除非声明作用域 默认使用子类的作用域 来隐藏掉了在父类中同名的成员  
//class CBB :public CAA
//{
//public:
//	void  fun(char a)
//	{
//		/*cout << "void fun(char a)" << a << endl;*/
//			cout << this << endl;
//	}
//};
//int main03()
//{
//	CAA aa;
//	aa.fun(10,20);
//	CBB bb;
//	//bb.fun('a');
//	////bb.fun(10, 20);//匹配子类函数 作用域是BB 函数重载需要在同一作用域下
//	//bb.CAA::fun(10, 20);//显示指定的使用父类的同名函数 指定作用域
//	bb.fun('a');
//
//
//	//在继承下 父类的指针可以直接指向（不用强转）任何一个子类对象,或者说 子类对象将自己的首地址传给父类指针,这时子类对象可以通过父类指针来调用父类函数
//	 
//
//	//保证子类对象可以成功调用父类的函数
//	 
//
//	//继承的父类的指针this在子类对象想要调用父类函数时,和子类指针this指向的是同一地址,指向同一对象
//	
//
//	//也就是父类可以指向所有子类对象
//	CAA* const pthis = &bb;
//	cout << &bb <<endl;
//	return 0;
//}