//#include<iostream>
//using namespace std;
//
//class Cman
//{
//public:
//	int m_money;
//	Cman(int m)
//	{
//		m_money = m;
//	}
//	void Cost(int n)
//	{
//		m_money -= n;
//	}
//	void Show()
//	{
//		cout << "m_money=" << m_money << endl;
//
//	}
//};
//
//class Cyellow :public Cman
//{
//public:
//	Cyellow(int m) :Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "������" << endl;
//	}
//};
//class Cwhite :public Cman
//{
//public:
//	Cwhite(int m) :Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "Steak" << endl;
//	}
//};
//class Cblack :public Cman
//{
//public:
//	Cblack(int m) :Cman(m)
//	{
//
//	}
//	void Eat()
//	{
//		cout << "Curry" << endl;
//	}
//};
//
////����ָ�룬����ͬһ�����������ͣ���ߴ��븴���Ժ���չ��
////�׶ˣ�����ָ��ֻ��ʹ�ø���ĳ�Ա��������ֱ��ʹ������ĳ�Ա
//void fun1(Cman* pman)
//{
//	pman->Cost(10);
//	pman->Show();
//	//((Cyellow*)pman)->Eat();//���������� ����һ��ͨ�õ�����
//}
//
//class family
//{
//public:
//	Cman* peo[3];
//	family()
//	{
//		peo[0] = new Cyellow(100);
//		peo[1] = new Cblack(200);
//		peo[2] = new Cwhite(300);
//	}
//};
//
//int main()
//{
//	fun1(new Cyellow(100));
//
//
//	//-------------------------------
//	Cman* pPeo = new Cyellow(100);
//	/*pPeo->Eat();*/
//	//�ɹ�ָ��һ�����ຯ��
//	//void (Cyellow:: * p_fun)() = &Cyellow::Eat;
//	void (Cman :: * p_fun)() =(void (Cman :: * )()) &Cyellow::Eat;//ǿת
//	//��˿���ʹ�ø���ָ�� ָ��һ��ָ�� ��ָ��ָ��һ�����ຯ��
//	(pPeo->*p_fun)();
//
//	return 0;
//}