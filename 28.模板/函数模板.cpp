//
//#include<iostream>
//using namespace std;
//
////int add(int a, int b)
////{
////	return a + b;
////}
//
//// template:定义模板的关键字
//// <>:指定模板的参数列表
//// typename：定义模板类型的关键字
//
////1.模板类型可以通过实参 自动推导（在形参中用到了模板类型的情况下）
////不适应与不同类型的数据传入,因为不存在即兼容一种类型又兼容另一种类型的数据类型
//template<typename T>//函数模板
//T add(T a, T b)		//模板函数
//{
//	T t = a + b;//模板类型可以就单纯理解为 数据类型 自动识别的数据类型
//	cout<<typeid(a).name() <<" " <<t<<" " << typeid(t).name() << endl;
//	return a + b;
//}
//
////2.在调用函数时，显示的指定模板类型
//template<typename T>
//void fun()
//{
//	T t = 10;
//	cout << t << " " << typeid(t).name() << endl;
//}
//
////3.模板类型可以指定默认的类型
//template<typename T =double>
//void fun2()
//{
//	T t = 10;
//	cout << t << " " << typeid(t).name() << endl;
//}
//
//
////确定模板类型有三种方式：显示指定>实参自动推导>默认指定
//
//template<typename T=int>
//void fun3(T t)
//{
//	cout << t << " " << typeid(t).name() << endl;
//}
//
//
////可以多个typename参数
//template<typename T,typename K>
//void fun4(T t,K k)
//{
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//}
//
//
//
//template<typename T, typename K=short,typename M>//显示指定是强转按顺序一个一个给 所以会被覆盖掉 
//void fun5()
//{
//	T t = 10;
//	K k = 20;
//	M m = 30;
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//	cout << m << " " << typeid(m).name() << endl;
//}
//
////对于函数模板类型指定的默认的类型,并没有强转的顺序要求
////一般而言：可以通过实参自动推导的一般放在模板参数列表最后(任何情况都可以放着不动)
////		  有默认的类型放在中间（若默认的类型不想用默认值的时候 可以直接改），必需显式指定的放在最前面
//template<typename T, typename K = short, typename M>
//void fun6(M m)//传入的实参可供推导
//{
//	T t = 10;
//	K k = 20;
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//	cout << m << " " << typeid(m).name() << endl;
//}
//
//
//template<typename T,  typename M ,typename K = short>
//void fun7(M m)
//{
//	T t = 10;
//	K k = 20;
//	cout << t << " " << typeid(t).name() << endl;
//	cout << k << " " << typeid(k).name() << endl;
//	cout << m << " " << typeid(m).name() << endl;
//}
//
////-------------------------------------------------------------
////若模板的声明和定义分开写 那么定义得加上显示声明 且 不具备通用性
//template<typename T>
//void fun8();
//
//template<typename T>
//void fun9(T t);
//
//
//
//int main()
//{
//	cout<<add(20, 30)<<endl;
//	/*cout << add(20, 30.1) << endl;*/
//	double a = 10.1, b = 20.2;
//	cout<<add(a, b) << endl;
//
//	//-------------------------------------
//	fun<int>();//无法自动推导非实参的类型,能推导传入的实参的类型  显示指定
//	fun<short>();
//	//-------------------------------------
//	fun2();
//	//-------------------------------------
//	
//	fun3(a);//10.1 double
//	fun3<short>(a);//10 short
//	//-------------------------------------
//
//
//	fun4('a', 12.3);
//	//-------------------------------------
//
//	fun5<int,long,int>();//没有传入的实参可供推导的类型 得显示指定
//
//	fun6<int>('1');
//
//	//fun7<int,int*,long>('2'); //由于自动匹配和显示指定的类型完全不兼容 因此非法 无匹配的类型
//
//	fun8<long>();
//	/*fun8<int>();*///非法使用显示模板参数
//
//	fun9('a');//无法解析的外部符号"void __cdecl fun9<char>(char)" 
//
//
//
//	return 0;
//}
//
////只是针对于 long类型实现的 不具备通用性
////void fun8<long>()//无法解析的外部符号"void __cdecl fun8<long>(void)"  若不加<>
////{
////	cout << "fun8" << endl;
////}
//
//template<typename T>
//void fun8<T>()//<>:指定模板的参数列表
//{
//	cout << "void fun8<T>" << endl;
//}
//
//
//////只是针对于 long类型实现的 不具备通用性
////void fun9<char>(char t)//非法使用显示模板
////{
////	cout << "void fun9(char t)" << endl;
////}
//
//template<typename T>
//void fun9(T t)
//{
//	cout << "void fun9(T t)" << endl;
//}