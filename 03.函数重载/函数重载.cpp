#include<iostream>
using namespace std;

/*
�������أ���������Ĺ�ϵ
��ͬһ�������£���������ͬ�������б�ͬ(�������ͣ�������˳��ͬ)������ֵ����Ҫ��
�ڵ���ʱ������ʵ���Զ�ƥ����������غ���
*/
//int add(int a, int b, double c);//����������add Ҳ�Ǻ������صĹ�ϵ

//���Ͳ�ͬ
int add(int a, int b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}

//������ͬ
void fun(int a, int b)
{
	cout << "fun(int a,int b)" << a << " " << b << endl;
}
void fun(int a)
{
	cout << "fun(int a)" << a << endl;
}

//˳��ͬ
void fun1(int a, char b)
{
	cout << "fun(int a,char b)" << a << " " << b << endl;
}
void fun1(char b,int a)
{
	cout << "fun(char b,int a)" << b <<" "<<a<< endl;
}
//���Ǻ������� ���ض��� p[]==*(p+0)==*p
//void fun2��int *p)
//{
//	cout << "void fun2��int *p)" << endl;
//}
//void fun2(int p[])
//{
//	cout << "void fun2(int p[])" << endl;
//}

//���Ǻ������� ���ض��� const������int�ģ������ϻ���int
//void fun3(const int a)
//{
//	cout << "void fun3(const int a)" << endl;
//}
//void fun3(int a)
//{
//	cout << "void fun3(int a)" << endl;
//}


//�����Ǻ������أ����Ƕ�ֻ��Ҫһ��������ʱ��ᱨ�����ֶ�����,����Ҫ�ֲ�ȥ����һ��
void fun5(int a)
{
	cout << "void fun4(int a)" <<a<< endl;
}



//Ҳ���ǲ�����������ʱ��20����Ч�ģ�����������ʱ��20����Ч��
void fun5(int a, int b = 50)//�Ƕ��崦Ĭ��ֵ�������õģ�������Ϊ׼������������ǰ��û����������ô��������붨����һ��ģ�����Ч��
{
	cout << "void fun4(int a, int b = 20)" <<a<<" "<<b<< endl;
}

int main03()
{
	int a = 10, b = 20;
	double c = 1.1, d = 2.2;
	cout << add(a, b) << endl;
	cout << add(c, d) << endl;

	fun(10);
	fun(10, 20);

	fun1(30, 'a');
	fun1('a', 30);

	void (*p)(int) = &fun5;
	void(*p1)(int, int) = &fun5;
	(*p)(19);
	(*p1)(20,30);//��ָ��Ļ����������¸�ֵ������ȥʹ��Ĭ��ֵ
	/*
	* ��ʽ��
	void (*p)(int) = fun5;
	void(*p1)(int, int) = fun5;
	p(19);
	p1(20,30);
	*/

	void fun5(int a);//�����ֲ���
	fun5(20);
	//����Ҫ��������һ����
	//��{}��������ʾһ����Ƕ������Ҳ����ֶ�����
	{
		void fun5(int a, int b = 20);
		fun5(49);
	}




	return 0;
}