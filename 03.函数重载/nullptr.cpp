#include<iostream>
using namespace std;

void fun11 (int a)
{
	cout << "void fun11(int a)" << endl;
}

void fun11(int* p)
{
	cout << "void fun11(int *p)" << endl;
}

void fun12(int* p)
{
	cout << "void fun12(int* p)" << endl;
}

void fun12(char* p)
{
	cout << "void fun12(char* p)" << endl;
}

/*
NULL��������һ���꣬�滻0  nullptr��������C++��һ���ؼ���,����һ����ָ��
���岻ͬ��NULL�������ͺ�ָ�루�������ͣ���nullptr����һ��ָ��

C++����nullptr
NULL ���ͺͿ�ָ�� ���岻��ȷ
*/

int main04()
{
	int* p = NULL;//��������һ���꣬�滻0
	int* p1 = 0;
	int* p2 = nullptr;//��������һ���ؼ���

	fun11(NULL);// void fun11(int a)
	fun11(nullptr);//void fun11(int *p)

	//fun12(nullptr); ������

	//����ǿת��ƥ���Ӧ���غ���
	fun12((char*)nullptr);
	fun12((int*)nullptr);


	return 0;
}
