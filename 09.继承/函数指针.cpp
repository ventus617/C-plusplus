//#include<iostream>
//using namespace std;
//
//void fun32()
//{
//	cout << "void fun32()" << endl;
//}
//void fun22(int a, int b)
//{
//	cout << "void fun(int a, int b)" << endl;
//}
//
///*
//ȫ�ֺ��������Ա��������
//1.������ͬ
//2.��Ҫ�����Ա������ ���ص�thisָ�� ȫ�ֺ���û��
//
//
//*/
//class Ct
//{
//public:
//	void fun44(/* Ct *const this*/)
//	{
//		cout << "void fun()" << endl;
//	}
//};
//
//int main()
//{
//	void(*p_fun)() = nullptr;//��ʼ��Ϊ��
//	void(*p_fun2)() = &fun32;//��ʼ��ָ��һ������
//	(*p_fun2)();//���ú���
//
//	//void (*p_fun3)(int,int);
//
//	typedef void(*p_fun11)(int, int);
//	p_fun11 p_fun3 = &fun22;
//	(*p_fun3)(10, 20);
//	//----------------------------------
//	//void (*p_fun)() = &Ct::fun; //Ct::*�޷�ת��Ϊ*
//	 
//	//���Ա����ָ�룬::*��һ������Ĳ����������ɷֿ������� �������Ա����ָ��
//	void (Ct   ::*  p_fun4)() = &Ct::fun44;
//
//	//.* ��һ����������� ͨ��������� ���Ա����ָ��ָ��ĺ���
//	Ct tst;
//	(tst .* p_fun4)(); 
//	//.* ->* ��C++���ṩ��һ�����������, ����:ͨ��������� ���Ա����ָ��ָ��ĺ���
//
//	Ct* ppp = new Ct;
//	(ppp ->* p_fun4)();
//	return 0;
//}
