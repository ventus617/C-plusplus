#include<iostream>
using namespace std;

int main01()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};


	//��for�ڶ����i��������for�ľֲ��������ⲿ����ʹ��
	for (int i=0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//��ǿ��Χ��forѭ��
	//ǰ���ǵ������ͱ�����������������  �ǰ�arr������ֵ��v
	for (int v : arr)
	{
		cout << v <<" ";

	}
	cout << endl;

	//����ͨ��ָ�����new�����飬��Ϊָ�벻֪�������С����֪���׵�ַ
	//int* p = new int[5]{ 1,2,3,4,5 };
	//for (int v : p)
	//{
	//	cout << v << " ";

	//}
	//cout << endl;

	string str = "abcdef";
	for ( char a: str)
	{
		cout << a << " ";
	}
	cout << endl;




	return 0;
}