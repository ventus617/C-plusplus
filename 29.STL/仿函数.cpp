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
//	//operator()���ص�����
//	int operator()(int a, int b)
//	{
//		m_sum += a + b;//һ��������һ�������Ч�� ��������չ �൱������������ز��������º����Ļ����϶�����չһ������Ĺ���
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
//	cout << Add.m_sum << endl;//һ������Ч��
//
//	return 0;
//}