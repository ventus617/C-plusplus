
#include<iostream>
using namespace std;
//
////*
//* 3��Ҫ�㣺
//* 1.��������ֻ��һ��ʵ��(����)
//* 2.�������Լ��������ʵ���������ǵ����ߴ�������(�������û���ָ��)
//* 3.�������Լ�������ϵͳ�ṩȫ�ַ��ʵ�������ʵ����
//*/


//����ʽ��ʲôʱ���� ʲôʱ�򴴽���ʱ�任�ռ䣨����ʱ���ȥ���������˷�ʱ���һ��ʱ����ܳԣ�


//class CSingleton
//{
//private:
//	static CSingleton* m_pSin;//��ֹ���޸�
//private://����˽�л�
//	CSingleton()
//	{
//		m_a = 10;
//	}
//	/*CSingleton(const CSingleton&)
//	{
//
//	}*/
//	CSingleton(const CSingleton& /*tst*/) = delete;//���õĺ��� ����ʹ�ÿ�������
//	~CSingleton(){}
//	//���ܷ����������������� ���ܻ�ջ�����delete m_pSin��ʱ������m_pSin���Լ��Ķ�������delete��ʵ�ǵ������Լ�������������m_pSin,��˻�һֱ��ѭ����
//	//~CSingleton() { if (m_pSin)
//	/*{
//		delete m_pSin;
//		m_pSin = nullptr;
//	}
//}*/
//public:
//	//�������Լ�������ϵͳ�ṩȫ�ַ��ʵ�������ʵ����
//	 static CSingleton* CreateSingleton()
//	{
//		 //�������Լ��������ʵ���������ǵ����ߴ�������
//			//����
//		 if(m_pSin==nullptr)//���ֻ��һ��ʵ�� �����ص�һ���ǵ�һ�δ����ɹ��Ŀռ��ַ
//		 {
//			//���߳��»�ʧЧ�����ܻᴴ����������󣬼������
//		 m_pSin = new CSingleton; 
//		 }
//			//����
//		return m_pSin;//�������� ���ض����ַ
//	}
//	 static void DestorySingleton(CSingleton* &psin)
//		 //�Ӳ��Ż�(�����ָ��Ŀռ�) ʹ�ñ����ٺ� ��ʵ��Ϊ�� �޷Ƿ�ֵ
//	 {
//		 if (m_pSin)
//		 {
//			 delete m_pSin;
//			 //��ʹ�����е�m_pSinΪ��
//			 m_pSin = nullptr;
//		 }
//		 //��ʹ����������ö����ָ��psinΪ��
//		 psin = nullptr;
//	 }
//
//
//public:
//	int m_a;
//
//};
//CSingleton* CSingleton::m_pSin = nullptr;
//
//int main()
//{
//
//	//����˽�л���ʹ�������ⶨ�����Ƿ�
//	//�����Լ�������ʵ�� ���ǵ����ߴ�����
//	/*CSingleton sin1;
//	CSingleton sin2;*/
//
//	CSingleton* pSin1 = CSingleton::CreateSingleton();
//	cout << pSin1->m_a << " " << pSin1<< endl;	
//
//	CSingleton* pSin2 = CSingleton::CreateSingleton();
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	pSin1->m_a = 20;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	//Ĭ�ϵĿ������� �����һ���µĶ���
//	//CSingleton sin(*pSin1);
//
//	//cout << &sin << " " << pSin1 << endl;
//
//	//����Ӱ�쵽ԭ�����ֵ
//	//sin.m_a = 30; 
//
//	//cout << pSin1->m_a << endl;
//
//
//	//����
//
//	//1.CSingleton::DestorySingleton();
//	pSin1->DestorySingleton(pSin1);//2.
//	if (pSin1)
//	{
//		cout << pSin1->m_a << endl;
//	}
//
//
//	return 0;
//}


//
//class CSingleton
//{
//public:
//	int m_a;
//
//private:
//	CSingleton()
//	{
//		m_a = 10;
//	}
//	CSingleton(const CSingleton&) = delete;
//	~CSingleton(){}
//public:
//	//��̬�ֲ����� ����֮��ͻ�һֱ���� ֱ����������
//	static CSingleton* CreateSingleton()
//	{
//		//���߳��²��ᴴ�����������
//		static CSingleton sin;
//
//		return &sin;
//	}
//
//};
//
//int main()
//{
//	CSingleton*pSin1=CSingleton::CreateSingleton();
//	CSingleton*pSin2=CSingleton::CreateSingleton();
//
//	cout << pSin1->m_a << " " << pSin1 << endl;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	pSin1->m_a = 20;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//
//	return 0;
//}




//
////����ʽ�����򴴽�֮�������Ψһ��ʵ����������,һֱ�ȴ�����,�ռ任ʱ�䣨�Ȱѷ����÷��������ϣ������˶���֮�����ԣ�
//class CSingleton
//{
//private:
//	static CSingleton sin;
//public:
//	
//	int m_a;
//
//private:
//	CSingleton()
//	{
//		m_a = 10;
//	}
//	CSingleton(const CSingleton&) = delete;
//	~CSingleton() {}
//public:
//	//��̬�ֲ����� ����֮��ͻ�һֱ���� ֱ����������
//	static CSingleton* CreateSingleton()
//	{
//		return &sin;
//	}
//
//};
//
//CSingleton CSingleton::sin; 
//
////private�Ƿ������η� �����������ڲſ��Է��ʣ�����������֮�� �൱���������� ��˿��Է��ʣ� ���Ǿ�̬��Ա�ĳ�ʼ����������
//
//int main()
//{
//	CSingleton* pSin1 = CSingleton::CreateSingleton();
//	CSingleton* pSin2 = CSingleton::CreateSingleton();
//
//	cout << pSin1->m_a << " " << pSin1 << endl;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//	pSin1->m_a = 20;
//	cout << pSin2->m_a << " " << pSin2 << endl;
//
//
//	return 0;
//}


