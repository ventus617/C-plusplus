#include<iostream>
using namespace std;

/*
	�ڼ̳��� �����������,�麯��ָ��ָ�����������麯���б�

	�ڼ̳��� ���಻���̳��˸���ĳ�Ա,����������麯���б��̳и�����麯���б�,����������麯����ַ
	
	�������д������麯��,������麯���б�ԭλ�ô��и��ǵ�ͬ������

	������ඨ���˵������麯��,�����麯���б��в��ᱻ����,�����Ǵ��ڵ�(������˳���ڽ�β�����������)

	



*/

class Cfather
{
public:
	virtual void fun()
	{
		cout << "Cfather::fun" << endl;
	}
	virtual void fun1()
	{
		cout << "Cfather::fun1" << endl;
	}
};

class Cson :public Cfather
{
public:
	virtual void fun()
	{
		cout << "Cson::fun" << endl;
	}
	virtual void fun2()
	{
		cout << "Cson::fun2" << endl;
	}
	Cson()
	{

	}
};
int main()
{

	//���� ���඼��һ���麯��ָ�� ָ���Լ����麯���б�
	Cfather fa;
	fa.fun();


	Cson son;
	son.fun();

	son.fun1();
	son.fun2();

	Cfather* pfa = &son;//ָ��������������׵�ַ

	pfa->fun();

	
	//�ڵ���fun������ʱ��,�ҵ�_vfptf������ָ����������Ѿ���ʼ����,�����Ѿ�����д��,�൱��Ҳ��ָ��������麯���б�
	pfa->fun1();

	return 0;
}