#include<iostream>
using namespace std;

int a = 10;
//:: �����������  һ����˵��ǰ��������򣬺���ų�Ա�����ǰ��ʡ�ԣ�����Ĭ��ʹ��ȫ�ֵ�������

//namespace��C++�Ĺؼ��� ���������ռ� ���ã�����ͬһ����������ͬ�ĳ�Ա

//1.�������ռ䣬��һ�Σ���Ա����ֱ��ȥʹ�ã�����С�������������ռ��Ա��ͻ

//2.���������ȫ�ֵ�a������using namespace��AA�����ռ��ڵ�a��ʹ��::a ���ǻ�ȥѡ��ȫ�ֵ�a ��Ϊ�����ȼ����

//3.��ʾ��ָ�������� �����ռ�::��Ա  ÿ��ʹ����ָ�������ռ�

//4.using �б� using �����ռ�::��Ա


namespace AA
{
	int a = 30;
	void fun()
	{
		cout << "BB:fun()" << endl;
	}
};
//using namespace AA; //��ʹ�õı����Ǳ��AA�����ռ�ı���


namespace BB
{
	int a = 40;
	void fun()
	{
		cout << "AA:fun()" << endl;
	}
};
using namespace BB;

int main ()
{
	//int a = 10;
	//cout << a << endl;

	//
	//cout << ::a << endl;//���ȫ�ֱ�����a 
	//cout << AA::a << endl;
	//cout << BB::a << endl;
	////---------------------------------
	//::fun();
	//BB::fun();//������ͬ


	//AA::fun();//ʹ��AA�ռ��ڵ�fun()����
	using BB::a; //��ȷ������ʹ���ĸ������ռ��еĳ�Ա����δָ��������ʱ��using namespace xx����Ĭ��ʹ�øó�Ա
	cout << a << endl;

	//���ɶ�ͬһ���������ʹ��using�������ì��
	//using AA::a; //error C2874:using �������¶������"<δ֪>
	return 0;
}