//#include<iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int m_b;
//	CTest()
//	{
//		m_a = 10;
//	}
//	//CTest(int a) //ת�����캯�������Է�����ʽ����ת��
//	//{
//	//	m_a = a;
//	//}
//	
//	//CTest(int a, int b)//���ܷ�����ʽ����ת�� �﷨����
//	//{
//	//	m_a = a;
//	//	m_b = b;
//	//}
//
//	//CTest(int a, int b=60)//��ɴ�һ����������ʽ Ҳ�ܷ�����ʽ����ת��
//	//{
//	//	m_a = a;
//	//	m_b = b;
//	//}
//
//
//	//�ؼ��� explicit: ��ֹ������ʽ����ת�������ι��캯��
//	explicit CTest(int a=30, int b = 60)//��ɲ��ò�������ʽ Ҳ�ܷ�����ʽ����ת��
//	{
//		m_a = a;
//		m_b = b;
//	}
//};
//
//
//int main()
//{
//	
//
//	//CTest tst;
//
//	CTest tst2(20);
//
//
//	//cout << tst.m_a << " " << tst2.m_a << endl;
//
//	CTest tst3 = 30;//��ʽ����ת�� ƥ��ת�����캯�� ��ֵ ��ɴ�����ʽ ���뺯��
//	cout << tst3.m_a << endl;
//
//	//	CTest tst4 = 40,50;
//	CTest tst4(40, 50);//ֻ����ʾ���ù��캯��
//
//	//--------------------------
//	CTest tst5 = 70;
//	cout << tst5.m_a << endl;
//
//	CTest tst6 = 0;//Ҳ�ܷ�����ʽ����ת�� ���0��ֵ����һ������
//	cout << tst6.m_a << " " << tst6.m_b << endl;
//
//
//	CTest tst7(110);//��ʾ���ò���explicitӰ��
//	cout << tst7.m_a <<" " << tst7.m_b << endl;
//
//	CTest tst8=120;//����explicit���κ� ����ֹ��ʽ����ת��
//
//	return 0;
//}