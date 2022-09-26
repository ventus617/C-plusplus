//
//#include<iostream>
//using namespace std;
//int add(int a, int b)
//{
//	return a + b;
//}
//
//class CADD
//{
//public:
//	int m_sum;
//	CADD():m_sum(0)
//	{
//
//	}
//public:
//	//operator()重载的括号
//	int operator()(int a, int b)
//	{
//		m_sum += a + b;//一个缓存上一步结果的效果 是属于扩展 相当于是在这个重载操作符来仿函数的基础上额外扩展一个缓存的功能
//		return a + b;
//	}
//};
//
//int main()
//{
//	cout << add(10, 20)<< endl;
//	CADD Add;
//	cout << Add(30, 50) << endl;
//	cout << Add(50, 60) << endl;
//	cout << Add.m_sum << endl;//一个缓存效果
//
//	return 0;
//}