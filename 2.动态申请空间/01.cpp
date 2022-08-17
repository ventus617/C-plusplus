#include<iostream>
using namespace std;


int main01()
{
	//malloc动态申请空间，堆区
	//前面是所需返回的指针类型（地址），后者是所需空间大小
	int * p1=(int *)malloc(sizeof(int));
	*p1 = 10;
	cout << *p1 << endl;
	free(p1);//释放空间
	p1 = NULL;
	//calloc动态申请空间，堆区，初始化默认为0
	int* q1 = (int*)calloc(1, sizeof(int));
	cout << *q1 << endl;
	free(q1);
	q1 = NULL;
	//--------------------------------------------

	//C++中直接用new申请空间 后面是所需的空间大小 返回的是地址 
	//同样存在于堆区
	//关键字 new - delete
	int *p2=new int;
	*p2 = 20;
	cout << *p2 << endl;
	delete p2;
	p2 = NULL;

	//可以申请空间的同时进行初始化
	int* p3 = new int(30);
	cout << *p3 << endl;
	delete p3;
	p3 = NULL;


	//------------------------------
	int*p4=new int[5];
	/*memset(p4, 0, sizeof(int) * 5);
	是一种赋值方式，相当于按照地址赋值
	一般把VAL写成0，成功赋值为0（默认0），如果写其他具体数字1 2 3 4会返回该值的地址
	*/

	for (int i = 0; i < 5; i++)
	{
		p4[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << p4[i] << " ";
	}
	cout << endl;
	delete[]p4;//删除指向数组的指针 需要带[]
	p4 = NULL;

	int* p5 = new int[5]();//申请数组的同时初始化，当前类型的初值为0
	for (int i = 0; i < 5; i++)
	{
		cout << p5[i] << " ";
	}
	cout << endl;
	delete[]p5;
	p5 = NULL;


	int* p6 = new int[5]{1,2,3,4,5};//申请数组初始化指定的值
	for (int i = 0; i < 5; i++)
	{
		cout << p6[i] << " ";
	}
	cout << endl;
	delete[]p6;
	p6 = NULL;


	return 0;
}