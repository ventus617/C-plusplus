#include<iostream>
using namespace std;


class C5
{
public:
	void fun1()const
	{
		cout << "void fun1()const" << endl;
	}
	static void fun2()
	{
		cout << "static void fun2()" << endl;
	}
	void fun3()
	{
		cout << "void fun3()" << endl;
	}
};

int main()
{
	const C5 tst;//��������
	tst.fun1();
	tst.fun2();
	//tst.fun3(); //���������ܵ�����ͨ���� ��ȫ���𽵵͵Ĳ���  --����Կռ���˵ const*p�������˿ռ� *const p������ָ�� �ռ�δ������ �����ǰ�ȫ���𽵵�
	// C5 *const pthis=&tst;�Ƿ�
	//const C5 *const pthis1=&tst;�Ϸ�
	// 
	// 
	//���ƣ�
	//const int a = 10;
	//int* const p = &a;//���Ͳ�ͬ ��ȫ���𽵵͵Ĳ���


	return 0;
}