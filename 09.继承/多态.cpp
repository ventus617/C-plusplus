#include<iostream>
using namespace std;

/*
��̬:��ͬ����Ϊ��ʽ�����˲�ͬ��Ϊ�����ͬһ�����չʾ�˶��ֲ�ͬ�ı�����̬����̬��
�ڼ̳� ����ָ�����ָ���κμ̳��ڸ�������࣬����������ж�����̬�ɸ����ָ�����ͬһ����
�����ָ����ж����������̬������̬

������
1.���ڼ̳й�ϵ
2.�����������ָ��ָ���������
3.virtual �������麯���Ĺؼ���
4.���ඨ����д�˸�����麯��


��д�����ඨ���˺͸�����麯��һģһ��(�������� ������ ���� ����ֵ)�ĺ���
һ��������д�˸�����麯�����������������Ӳ��� virtual �ؼ��ֶ���Ϊ���麯��
*/
class Cman
{
public:
	int m_money;
	Cman(int m)
	{
		m_money = m;
	}
	void Cost(int n)
	{
		m_money -= n;
	}
	void Show()
	{
		cout << "m_money=" << m_money << endl;

	}
	virtual void Eat()
	{

	}
};

class Cyellow :public Cman
{
public:
	Cyellow(int m) :Cman(m)
	{

	}
	virtual void Eat()//�Ӳ��� virtual������ ǰ������д�˸�����麯��
	{
		cout << "������" << endl;
	}
};
class Cwhite :public Cman
{
public:
	Cwhite(int m) :Cman(m)
	{

	}
	void Eat()
	{
		cout << "Steak" << endl;
	}
};

typedef void (Cman::* p_fun)();
void fun1(Cman* pman, p_fun pp)
{
	pman->Cost(10);
	pman->Show();
	//((Cyellow*)pman)->Eat();//���������� ����һ��ͨ�õ�����
	(pman->*pp)();//�Ǹ���һ��ָ�����ຯ����ָ�뺯��
}

//ʹ�ö�̬��ʽ
void fun(Cman* pp)
{
	pp->Cost(20);
	pp->Eat();
	pp->Show();
}
int main()
{
	fun1(new Cyellow(100), (p_fun) & (Cyellow::Eat));
	fun1(new Cwhite(100), (p_fun) & (Cwhite::Eat));
	fun(new Cyellow(20));
	return 0;
}