//#include<stdio.h>
#include<iostream>  //���롢������ļ�
using namespace std; //�򿪱�׼�����ռ�

int main01()
{
	int a = 10;
	char b = 'b';
	//printf("%d  %c\n", a, b);
	//scanf_s("%d  %c", &a, &b);
	//printf("%d  %c", a, b);

	//cout :ostream ���͵ı���
	//<< :��������� ��������һ������
	cout << a << "  " << b<<endl;
	//cin :istream ���͵ı���
	//>> :��������� ��������һ������
	cin >> a >> b;
	cout << a << "  " << b<<endl;

	return 0;
}