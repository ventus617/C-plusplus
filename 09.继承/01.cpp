//#include<iostream>
//using namespace std;
//
//
///*
//
//�̳У�����������࣬����ʹ�ø���ĳ�Ա����Ϊ����ĳ�Ա���ٶ�Ӧ�Ŀռ�
//��������Ա�������ڴ�ռ���,�Ų�˳���ȸ����Ա �������Ա
//
//*/
////���ࣨ���ࣩ
//class CFather
//{
//public:
//	int m_fa;
//	int m_money=200;
//	void show_fa()
//	{
//		cout << "void show_fa()" << endl;
//	}
//	void show()
//	{
//		cout << "CFather::show()" << endl;
//	}
//};
//
////���ࣨ�����ࣩ ���� + �� + �̳з�ʽ + ����
//class CSon :public CFather
//{
//public:
//	int m_son = 10;
//	int m_money;
//	void show_son()
//	{
//		cout << "void show_son()" << endl;
//		m_fa = 10;
//		show_fa();
//		cout << "m_fa==" << m_fa << endl;
//	}
//	void show()
//	{
//		cout << "CSon::show()" << endl;
//	}
//};
//
//int main()
//{
//	CSon son;
//	son.show_son();
//	son.m_fa = 20;
//	cout << son.m_fa << endl;
//	son.show_fa();
//	cout << "----------" << endl;
//	cout << sizeof(CFather) << " " <<sizeof(son) <<endl;//4 8 ���������Ա�ռ�
//
//	cout << &son << " " <<&son.m_fa<<" "<<&son.m_son << endl;//���ȿ��ٸ����Ա�Ŀռ� �ٿ����Լ���Ա�Ŀռ�
//	son.m_money = 100;
//
//
//
//	//����������ȥ������ͬ�ĳ�Ա
//	//�����Ҫʹ��ͬ���ĸ����Ա����Ҫ��ʾ��ָ��������
//	//����͸�����������Աʱ
//	//δָ��������ʱ��Ĭ����������money
//	cout << son.m_money << endl;
//	cout << son.CSon::m_money << endl;
//
//
//	cout << son.CFather::m_money << endl;
//
//	//��Ժ���
//	son.show();
//	son.CSon::show();
//	son.CFather::show();
//
//	son.CFather::m_money = 150;
//	cout << son.CFather::m_money << endl;
//
//
//	//-----------------------------------
//	//�ڴ��Ų��м�ʹ����ͬ��Ա Ҳ����д�길 ��д��
//	cout << &son << endl;
//	cout << &son.m_fa << endl;
//	cout << &son.CFather::m_money << endl;
//	cout << &son.m_son << endl;
//	cout << &son.CSon::m_money << endl;
//
//	return 0;
//}