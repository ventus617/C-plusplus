#include<iostream>
using namespace std;

class C2
{
public:
	int m_a;
	C2()
	{
		m_a = 10;
	}

	//operator int ��������,�޲�,�޷�������
	//������Ҫ����һ�����ص�ǰ���͵�һ��ֵ
	operator int()
	{
		return m_a;
	}
	int operator+(int a)
	{
		return m_a + a;
	}

	//�����ȼ������⣺
	//���ز�����>>��������
};

int main()
{
	C2 tst;
	int a = 0;
	a =tst;
	cout << a << endl;//10

	int b = 0;

	//ƥ�� int����
	b = tst;//a=tst.m_a;
	cout << b << endl;//10
	//---------------------------
	int c=tst + 10;
	cout << c << endl;//tst.m_a+10



	return 0;
}