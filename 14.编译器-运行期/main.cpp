/*
������:��Դ�����ļ����������� ���롢����,��������һ����ִ�г���Ĺ���,��̬����ȫ���ڴ�ʱ�ڿɼ�

������:ָ�����Ĺ��̽�������ϵͳȥ����,�˳��Ĺ���,�Ѻ�ջ���������ڲſɼ�

�����ڷ����ڴ棬�����þ�̬��ȫ�����顣�����ڱ����ʱ��ȷ���ġ�
�����ڷ����ڴ棬������malloc()֮��ĺ������ڶ��Ϸ����ڴ档
�������ڴ���󣬾��Ǳ���ĳ�����ݶ�DATA�λ���CODE�εȵȣ���������������Ŀ����Ĵ洢�������ơ�����DOS�£�DATA�β��ܳ���64K�ɡ�
�������ڴ���󣬾������е�ʱ�����ģ��������벻���ڴ棬�ڴ�Խ����ʣ��ȵȡ�


���б�����:�������η� �� ������

���������,����,ָ�� ���������ڵĶ�������ΪҪ�����ڴ棩 

ָ���������ڽ�����ʹ��ָ��ָ��ĵ�ַ��ʹ�� ����ȥ��������ͷ������η�


*/
#include<iostream>
using namespace std;
class AA
{
public:
	virtual void fun() = 0;
};

char buffer[16] = { 0 };

class Ctest:public AA {
private:
	void fun()
	{
		cout << "void fun()" << endl;

	}
	void fun2()
	{
		cout << "void fun2()" << endl;
	}

public:
	void Getfun()
	{
		printf("%p \n", &Ctest::fun2);

		sprintf_s(buffer, 16, "%d \n", &Ctest::fun2);	//��ȡ���ĵ�ַ���뵽buffer��
		cout << buffer << endl;
	}
};


int main()
{

//#if __cplusplus
//#define nn 10
//#else
//#define nn 20
//#endif
//	//������ȷ����
//	int a = nn;
//	cout << a << endl;
//	//---------------------------------
//
//
//	//������ȷ����
//	int MM = 0;
//	cin >> MM;
//	if (MM == 10)
//	{
//		cout << "10" << endl;
//	}
//	else
//	{
//		cout << "20" << endl;
//	}

	//----------------------------------
	const int len = 1000000000000;
	//int arr[len] = { 0 };//�����ڱ���

	int len2 = 1000000000000;
	/*new int[len2]; *///�����ڱ���

	Ctest tst;
	AA* pp = &tst;
	pp->fun();
	tst.Getfun();


	int a = atoi(buffer);//��buffer�����fun2�ĵ�ַת��Ϊ10����
	void(*p_fun)() =(void(*)()) a;//��aǿתΪ��Ӧ�������� p_fun���buffer�ڵĵ�ַ
	(*p_fun)();

	
	return 0;
}