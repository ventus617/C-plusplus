#include<iostream>
using namespace std;


int main01()
{
	//malloc��̬����ռ䣬����
	//ǰ�������践�ص�ָ�����ͣ���ַ��������������ռ��С
	int * p1=(int *)malloc(sizeof(int));
	*p1 = 10;
	cout << *p1 << endl;
	free(p1);//�ͷſռ�
	p1 = NULL;
	//calloc��̬����ռ䣬��������ʼ��Ĭ��Ϊ0
	int* q1 = (int*)calloc(1, sizeof(int));
	cout << *q1 << endl;
	free(q1);
	q1 = NULL;
	//--------------------------------------------

	//C++��ֱ����new����ռ� ����������Ŀռ��С ���ص��ǵ�ַ 
	//ͬ�������ڶ���
	//�ؼ��� new - delete
	int *p2=new int;
	*p2 = 20;
	cout << *p2 << endl;
	delete p2;
	p2 = NULL;

	//��������ռ��ͬʱ���г�ʼ��
	int* p3 = new int(30);
	cout << *p3 << endl;
	delete p3;
	p3 = NULL;


	//------------------------------
	int*p4=new int[5];
	/*memset(p4, 0, sizeof(int) * 5);
	��һ�ָ�ֵ��ʽ���൱�ڰ��յ�ַ��ֵ
	һ���VALд��0���ɹ���ֵΪ0��Ĭ��0�������д������������1 2 3 4�᷵�ظ�ֵ�ĵ�ַ
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
	delete[]p4;//ɾ��ָ�������ָ�� ��Ҫ��[]
	p4 = NULL;

	int* p5 = new int[5]();//���������ͬʱ��ʼ������ǰ���͵ĳ�ֵΪ0
	for (int i = 0; i < 5; i++)
	{
		cout << p5[i] << " ";
	}
	cout << endl;
	delete[]p5;
	p5 = NULL;


	int* p6 = new int[5]{1,2,3,4,5};//���������ʼ��ָ����ֵ
	for (int i = 0; i < 5; i++)
	{
		cout << p6[i] << " ";
	}
	cout << endl;
	delete[]p6;
	p6 = NULL;


	return 0;
}