//#include<iostream>
//using namespace std;
//
////静态函数没有virtual 因为流程和虚函数不一致,前者没有this指针,不能拥有对象,后者需要对象来调用__vfptr虚指针
//class Cpeople
//{//包含纯虚函数的类,即抽象类,不允许实例化（不能去定义对象）
//public:
//	/*virtual void Eat()
//	{
//		
//
//	}*/
//	//virtual void Eat();//只声明 不定义 
//	virtual void Eat() = 0;//纯虚函数,在奔雷中可以不用定义实现,当前类中的该类型 不允许实例化
//
//	virtual void fun() = 0;//若在子类中不定义 报错, 即在子类中不存在重写该函数,但是该函数在父类是纯虚函数
//};
//
////派生类--具体类:一定要定义实现抽象类中的纯虚函数
//
//class Cyellow :public Cpeople
//{
//public:
//	void Eat()
//	{
//		cout << "马西西" << endl;
//	}
//	virtual void fun()//子类的virtual可写可不写
//	{
//		cout << "李马马" << endl;
//	}
//};
//
//
//int main()
//{
//	//Cpeople peo;//抽象类不允许定义对象 包含纯虚函数
//
//	Cpeople* ppeo = new Cyellow;
//	ppeo->Eat();
//
//	Cpeople* ppe = new Cyellow;
//	ppe->fun();
//
//	return 0;
//}


/*
*虚函数实现多态缺点：
1.效率低,速度慢,流程太多
2.空间内存,定义对象会多分配虚函数指针的空间,多个对象会有多份虚函数指针,
虚函数列表占用空间,随着继承的层级越来越多,虚函数列表只会越来越大
3.安全性：类中的私有函数最好不要定义为虚函数, 因为虚函数可以通过取地址的方式去强行在类外调用
*/