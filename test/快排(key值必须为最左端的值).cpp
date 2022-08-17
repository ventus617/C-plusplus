#include<iostream>
using namespace std;
int parilition(int left, int right, int arr[])
{
	int key = arr[right];//ͬһ���ÿ��ŵ��������Ϊ��ʶֵ
	
	while (left < right)//�����Ƕ�����һ����׼ ������˵�ֵΪkeyֵ �����ұ߿�ʼѰ�� ��Ҫ�����ұߵ�Ϊkeyֵ ��ô�͵ô�����߿�ʼ
	{
		while (left < right && arr[left] <= key)
		{
			left++;
		}arr[right] = arr[left];//��leftָ���ֵ����keyֵʱ ����ѭ�� ��left��ֵ����right��ָ��

		while (left < right && arr[right] >= key)
		{
			right--;
		}arr[left] = arr[right];//��rightָ���ֵС��keyֵʱ ����ѭ�� ��right��ֵ����left��ָ��
		
	}arr[left] = key;//��left>=rightʱ ˵�������� ����ѭ�� ��keyֵ������ǰλ��
	return left;//���ؽ���ʱleft�ĵ�ǰλ��
}
void quick_sort(int arr[],int left,int right)
{
	if (left < right)//��left==right��ʱ�� �����Ѿ��������
	{
		int pos = parilition( left, right, arr);
		quick_sort(arr, left, pos - 1);//��pos�����������п���
		quick_sort(arr, pos + 1, right);//��pos���ұ�������п���
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

	int i = left;//i��ָ������������˵�λ��

	int j = right;//j��ָ�����������Ҷ˵�λ��



	while (i != j) //��i=j��ʱ���ʾ��ֵ��С�ڵ��ڻ�׼ֵ��ֵ
	{
		//�ȴ��ұ߿�ʼ��С�ڻ�׼ֵ��
		while (a[j] >= a[left] && i < j)
			j--;
		//�ٴ���߿�ʼ���ڻ�׼ֵ��
		while (a[i] <= a[left] && i < j)
			i++;
		if (i < j)
		{

			//����
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	//��iλ�õ�ֵ�ͻ�׼ֵ����
	t = a[i];
	a[i] = a[left];
	a[left] = t;
	//����һ��λ��ֵi���ݹ�
	 
	//�ݹ�
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