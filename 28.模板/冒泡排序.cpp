
//#include<iostream>
//#include<stdlib.h>
//
//using namespace std;
//
//template<typename T>
//bool rule(T a,T b)
//{
//	return a > b;
//}
//
//
////函数重载
//bool rule(int  a, int b)
//{
//	return a > b;
//}
//
//
//bool rule(double a, double b)
//{
//	return a > b;
//}
//
//
//template<typename T>
//void BubbleSort(T* p, int len,bool(*p_rule)(T,T))//地址 长度 利用函数指针和参数来重载rule
//{
//	if (p == nullptr)return;
//
//	
//	//冒泡排序 第一次循环是一共有len-1个数需要进行排序（最后一个数没必要去比较）
//	//		  第二次循环是排序完后剩下的无序队列长度
//
//	for (int i = 0; i < len-1; i++)
//	{
//		for (int j = 0; j < len - i-1; j++)
//		{
//			if ((*p_rule)(p[j],p[j + 1]))
//			{
//				T temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
//			}
//		}
//	}
//
//
//}
//
//
//
//int main()
//{
//
//	srand((unsigned int)time(0));
//	int arr[20];
//	for (int i = 0; i < 20; i++)
//	{
//		arr[i] = rand() % 20+1;
//	}
//	//BubbleSort(arr, 20);
//	BubbleSort(arr, 20, &rule);
//	for (int k : arr)
//	{
//		cout << k << " ";
//	}
//	cout << endl;
//
//	double arr1[10] = {2.2,3.3,5.5,4.4,6.6,9.9,8.8,7.7,10.10,1.1};
//	
//	/*BubbleSort(arr1, 10);*/
//	BubbleSort(arr1,10, &rule);
//	for (double j : arr1)
//	{
//		cout << j << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}