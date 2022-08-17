//#include<iostream>
//using namespace std;
//
//
//class Cfather
//{
//public:
//	virtual void fun()
//	{
//		cout << "Cfather::fun" << endl;
//	}
//	virtual void fun1()
//	{
//		cout << "Cfather::fun1" << endl;
//	}
//};
//
//class Cson :public Cfather
//{
//public:
//	virtual void fun()
//	{
//		cout << "Cson::fun" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Cson::fun2" << endl;
//	}
//	Cson()
//	{
//
//	}
//};
//int main01()
//{
//	typedef void(*pp)();
//	Cfather* p1 = new Cson;
//
//	//int a= *(int *)p1;==_vfptr; 虚指针是四个字节 所以相当于是int* 强转为int*  处于对象空间的首地址,然后取空间得vfptr
//	int a = *(int*)p1;
//
//
//
//	pp q1 = (pp)((int*)a)[0];
//	pp q2 = (pp)((int*)a)[1];
//	pp q3 = (pp)((int*)a)[2];
//	(*q1)();
//	(*q2)();
//	(*q3)();
//	/*
//	Cson::fun
//	Cfather::fun1
//	Cson::fun2
//	*/
//	return 0;
//}