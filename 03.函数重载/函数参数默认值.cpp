#include<iostream>
using namespace std;

//C++�ں����ڲ������Դ�Ĭ��ֵ(����ʵ��ʱ��ʹ�õ�Ĭ��ֵ)
//�������c��cĬ�����40�������c��c���ø���ֵ
void fun(int a, int b, int c=40)
{
	cout << a << " " << b << " " << c << endl;
}

//��������ƶ�Ĭ��ֵ�����������������ָ���������м��
void fun1(int a, int b, int c = 300)
{
	cout << a << " " << b << " " << c << endl;
}
//void fun2(int a=110, int b, int c = 330)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//ʵ�β������β�β�����βα�����ʵ��ǰ




//������������Ĭ��ֵ�������ڶ��崦����Ĭ��ֵ
void fun4(int a, int b=20);


//�໥����ʱ�������Ͷ���÷ֿ��������Է�������ʶ
void f1();
void f2();
void f1()
{
	f2();
}
void f2()
{
	f1();
}


int main02()
{
	fun(10, 20, 30);
	fun1(10, 20);//��ֵ˳���Ǵ�������
	fun1(30, 10);
	fun4(20);

	{
		void fun4(int a, int b = 40);
		fun4(15);
	}


	return 0;
}





void fun4(int a, int b)
{
	cout << "fun4:" << a << " " << b << endl;
}