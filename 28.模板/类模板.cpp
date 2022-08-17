
#include<iostream>
using namespace std;

template<typename T=long>
class CTest
{
public:
	T m_t;
	CTest()
	{
		m_t = 10;
	}
	CTest(T t)
	{
		m_t = t;
	}
};

//��ģ�� ��Ҫ��������һ��ָ��Ĭ�ϵ����ͣ��м䲻���м��
//��һ���Զ��Ƶ��ķ�ʽ ���ֻ��Ĭ�Ϻ���ʾָ��

template<typename T,typename K=char>
class CTest2
{
public:
	T m_t;
	CTest2()
	{
		m_t = 10;
	}
	CTest2(T t)
	{
		m_t = t;
	}
	void fun()
	{
		cout << typeid(T).name() << endl;
		cout << typeid(K).name() << endl;
	}
};

template<typename T>
class CTest3
{
public:
	T m_t;
	CTest3()
	{
		m_t = 10;
	}
	template<typename K>
	void fun()
	{
		cout << typeid(T).name() << endl;
		cout << typeid(K).name() << endl;
	}
	template<typename K>
	void fun(K k)
	{
		cout << typeid(T).name() << endl;
		cout << typeid(K).name() << endl;
	}

	template<typename K>
	void fun2();
	template<typename K>
	void fun3(K k);
};



//����ָ�����ģ�� ��ָ�������������ĺ���ģ��
//���������� ����<typename>::����  ������  (ʹ��ʱ ָ������ʹ�õ�����) 
template<typename T>	//��ģ��
template<typename K>	//����ģ��
void CTest3<T>::fun2()
{
	cout << "void CTest3<T>::fun2<K>()" << endl;
	cout << typeid(T).name() << endl;
	cout << typeid(K).name() << endl;

}


template<typename T>
template<typename K>
void CTest3<T>::fun3(K k)
{
	cout << "void CTest3<int>::fun3(double k)" << endl;
}



class AA
{
public:
	int m_a;
	AA()
	{
		m_a = 10;
	}
};


//�Զ�ʶ�����õı����� ����
//�����Ҫһ������ ������һ��������
template<typename T>
class BB
{
public:
	T m_t;//������Ļ� ����AA m_t
	BB(T &t)//������AA�Ķ��� aa
	{
		m_t = t;// �൱��m_t�������ֵΪaa�������
	}

};

//����BB�������Ͳ�ȷ�� ����Ҳ��typename T
template<typename T>
class CC
{
public:
	BB<T> m_b; //BB�����һ�� ��ȷ�������ʹ���
	CC(T &t):m_b(t) //ֵ���� ����ɸ�ֵ
	{
		
	}
};


int main()
{
	//����ʾ����ϵͳ ��ʲô���� ��Ȼ��֪�������Ŀռ�
	CTest<int> tst; //���� list<int> lst
	cout << tst.m_t << endl;
	CTest<short> tst2(20);
	cout << tst2.m_t << endl;

	//CTest<>tst3(20);//�Ƿ����� ��û��Ĭ��ָ����ʱ�� ������ʾָ��


	//int* p = nullptr;
	//CTest<> tst4(p);//ָ���long��û���Զ�ת�� ��ǿת ���Ͳ�ƥ�� �Ƿ�����

	long a = 30;
	CTest<>tst4(a);
	cout << tst4.m_t << endl;

	CTest2<long> tst5;
	tst5.fun();

	CTest2<long, int> tst6;
	tst6.fun();

	CTest3<int> tst7;
	tst7.fun<char>();//��������� ����Ĭ�� ����ʾָ��
	tst7.fun(12.3);//��������ĺ��� Ҳ�����Զ�ƥ��

	CTest3<int> tst8;
	tst8.fun2<short>();

	tst8.fun3(12.3);

	AA aa;
	aa.m_a = 20;

	BB<AA>bb(aa);//��������ʱ ȷ�������������BB �����typename�Ķ�������ʾ��ֵAA ��BB�Ķ���bb ������AA�Ķ���aa
	cout << bb.m_t.m_a << endl;//

	CC<AA>cc(aa);//ͬ�� ȷ��BB��ʹ�õ�������AA  ����ĸ���������һ�� �൱���Ƕ��������֮ǰ�ĸ�ֵ ������������һϵ��С����m_a
	cout<<cc.m_b.m_t.m_a << endl;//



	return 0;
}