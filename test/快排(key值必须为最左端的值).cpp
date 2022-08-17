#include<iostream>
using namespace std;
int parilition(int left, int right, int arr[])
{
	int key = arr[right];//同一设置快排的最左端数为标识值
	
	while (left < right)//这里是定义了一个标准 以最左端的值为key值 从最右边开始寻找 若要以最右边的为key值 那么就得从最左边开始
	{
		while (left < right && arr[left] <= key)
		{
			left++;
		}arr[right] = arr[left];//当left指向的值大于key值时 跳出循环 把left的值赋给right的指向

		while (left < right && arr[right] >= key)
		{
			right--;
		}arr[left] = arr[right];//当right指向的值小于key值时 跳出循环 把right的值赋给left的指向
		
	}arr[left] = key;//当left>=right时 说明找完了 跳出循环 把key值赋给当前位置
	return left;//返回结束时left的当前位置
}
void quick_sort(int arr[],int left,int right)
{
	if (left < right)//当left==right的时候 表明已经排序完成
	{
		int pos = parilition( left, right, arr);
		quick_sort(arr, left, pos - 1);//向pos的左边区间进行快排
		quick_sort(arr, pos + 1, right);//向pos的右边区间进行快排
	}
}
//-----------------------------------------------------------------------------------------------------
void showarr(int arr[],int length)
{
	for (int v = 0; v < length; v++)
	{
		cout << arr[v] << " ";
	}
	cout << endl;
}
void quicksort(int* a, int left, int right)
{
	int t;

	if (left > right) return;

	int i = left;//i是指向该区间的最左端的位置

	int j = right;//j是指向该区间的最右端的位置



	while (i != j) //当i=j的时候表示该值是小于等于基准值的值
	{
		//先从右边开始找小于基准值的
		while (a[j] >= a[left] && i < j)
			j--;
		//再从左边开始大于基准值的
		while (a[i] <= a[left] && i < j)
			i++;
		if (i < j)
		{

			//交换
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	//把i位置的值和基准值交换
	t = a[i];
	a[i] = a[left];
	a[left] = t;
	//交付一个位置值i给递归
	 
	//递归
	quicksort(a, left, i - 1);
	quicksort(a, i + 1, right);
}

int main()
{
	int arr[20] = { 0 };
	for (int v = 0; v < 20; v++)
	{
		arr[v] = rand() % 91;
	}
	int count = 0;
	for (int v : arr)
	{
		cout << v << " ";
		count += v;
	}
	cout << endl;
	cout << count << endl;
	quicksort(arr, 0, 19);
	count = 0;
	for (int v : arr)
	{
		cout << v << " ";
		count += v;
	}
	cout << endl;
	cout << count << endl;
	return 0;
}