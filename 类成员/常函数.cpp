#include<iostream>
using namespace std;


class C7
{
public:
	int m_a;
	const int m_b;
	mutable int m_c;//mutable ���εĳ�Ա �����ڳ��������޸�
	C7():m_a(10),m_b(20)
	{
		m_c = 30;
	}

	//������:�ڳ������в����޸����Ա����,�����Ǳ������ǳ����������޸�
	void fun(/* const C7 * const this */) const
	{

	/*	�޷��޸�
		m_a = 10;
		m_b = 20;*/

		cout << m_a << " " << m_b << endl;//��������ʹ��

		//fun2();//�൱�ڰ�fun��this���ݸ���fun2 �ǲ��Ϸ��� ���Ͳ�ͬ

		//const C7 tst1;
		//const C7* const pthis1 = &tst1;
		//C7* const pthis2 = pthis1;//��ȫ���𽵵͵Ĳ��� ������

		fun3();//����������������� ����������ͬ ��ȫ������ͬ ����

		fun4();//��̬��Ա������this ��û�ж��󶼿���ʹ�ã���˺Ϸ�

		//�޸� ͨ����һ��ָ�� ָ��ÿռ�ĵ�ַ ���޸Ŀռ�
		int* p = (int*)&this->m_a;
		*p = 100;
		cout << this->m_a << endl;//100


		m_c = 100;//�����޸ķ���
		cout << m_c << endl;
	}

	//һ�㺯������this��ָ�򲻿��޸� ����thisָ��Ŀռ�ֵ�����޸�
	void fun2(/*  C7 * const this */) 
	{

		/*	���޸�*/
			this->m_a = 10;
			/*m_b = 20;*/
			fun();//�Ϸ�,�ǰ�ȫ���������Ĳ���,����ִ��

		//C7 tst1;
		//C7* const pthis2 = &tst1;
		//const C7* const pthis1 = pthis2;//��ȫ�������ߵĲ��� ����
	}

	void fun3()const
	{
		cout << "void fun3()const" << endl;
	}

	static void fun4()//����thisָ�� �������������� �������޵��ö���ʱ�Ϸ�������û��thisָ�봫�ݣ�ָ����
	{
		cout << "static void fun4()" << endl;
	}
};


int main04()
{
	int a = 10;
	const int b = 20;
	int* p = &a;
	//����ָ��
	const int* p2 = &b;
	//const ����* p2 ������p2ָ��Ŀռ��ǳ��� ��b�����޸� ����ָ����Ըı䣨��˿��Բ���ʼ����
	p2 = &a;
	//*p2 = 40;//�Ƿ�


	const int* p8 = &a;//����ͨ��ָ�����޸�ָ��ı���������ָ��ı���������������޸ģ��������������const���ͣ��򲻿����޸�
	/*
	*p2 = 50;
	�Ƿ�*/
	a = 50;
	 

	//ָ�볣��
	int* const p3 = &a;
	//const���� p2������ָ�뱾���ǳ�������Ҫ��ʼ���������ɸ�ָ�� ���ǿռ����ݿ��Ըı�
	*p3 = 40;
	//p3 = &b; //�Ƿ�


	const int* const p4 = &b;//�൱�����߽�� ��Ҫ��ʼ�� ���ܸı�ָ�� ���ܸı�ռ�
	//�Ƿ�
	//p4 = &a;
	//*p4 = 40;

	C7 tst;
	tst.fun();


	return 0;
}