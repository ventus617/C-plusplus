#include<iostream>
#include<Windows.h>
using namespace std;

/*
BOOL ��������һ��int���͵ı��� ռ��4���ֽڿռ�

bool ��������һ���ؼ��� ռ��1���ֽڿռ�

TRUE �� �滻 1�� FALSE �滻0
�ؼ��֣�ture �� false��
*/

int main03()
{
	//typedef int BOOL;
	//#define TRUE 1 
	//#define FALSE 0
	BOOL b = TRUE;
	cout << sizeof(b) << " " << sizeof(BOOL) << endl;

	//boll true false C++�ṩ�Ĺؼ��֣���ʾ�������� ռһ���ֽ�
	bool bb = true;//true �� false ��
	cout << sizeof(bb) << " " << sizeof(bool) << endl;


	return 0;
}