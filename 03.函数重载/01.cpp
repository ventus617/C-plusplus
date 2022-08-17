#include<iostream>
using namespace std;

int main01()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};


	//在for内定义的i，仅属于for的局部变量，外部不能使用
	for (int i=0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//增强范围的for循环
	//前面是单个类型变量，后面是数组名  是把arr挨个赋值给v
	for (int v : arr)
	{
		cout << v <<" ";

	}
	cout << endl;

	//不可通过指针遍历new的数组，因为指针不知道数组大小，仅知道首地址
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