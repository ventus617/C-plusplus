//#include<iostream>
//using namespace std;
//
//
//// �̳з�ʽ�������˸���ĳ�Ա�������е�ʹ�õķ�Χ���̳з�ʽ�ͷ������η� 
//// ��ͬ�����˳�Ա�ķ��ʿ���Ȩ��
//// private���������ּ̳з�ʽ�¶��ǲ��ɷ��ʵ�
//// �жϷ������η��Ƿ�ȼ̳з�ʽ�����ͣ������������Ϊ�̳з�ʽͬһ����ķ�ʽ
//// ������ͣ��򱣳��ڸ����еķ������εȼ�
//// 
//// public:�����̳� 
//// �����Ա����		�����Ա����
//// public			public
//// private			���ɷ���
//// protected		protected
//// 
//// 
//// 
//// private:˽�м̳� 
//// �����Ա����		�����Ա����
//// public			private
//// private			���ɷ���
//// protected		private
//// 
//// 
//// 
//// protected:�����̳�
//// �����Ա����		�����Ա����
////	public			protected
////	private			���ɷ���
////	protected		protected
////
//
//
//class Father
//{
//public:
//	int m_pub;
//protected:
//	int m_pro;
//private:
//	int m_pri;
//public:
//	Father():m_pri(10)
//	{
//		m_pub = 10;
//		m_pro = 20;
//		m_pri = 30;
//	}
//	//�����������ʹ�ø����˽������
//	int Getpri()
//	{
//		return m_pri;
//	}
//};
//
//class Son :private Father
//{
//public:
//
//
//
//	//void showPublic()
//	//{
//	//	cout << m_pub << endl;
//	//	cout << m_pro << endl;//�ܱ��������� �����ڼ̳е�����ʹ�� ������������ʹ��
//	//	/*cout << m_pri << endl; ���ɷ��ʵ�����*/
//	//	//�����˽�г�Ա���� ��ʹpublic�̳�Ҳ�޷�ʹ�� 
//	//	//privateֻ��������ʹ�� ���Լ�ʹ�� ��ʹ�̳�Ҳ������ʹ��
//	//	cout << Getpri() << endl;
//	//}
//	
//
//
//
//	//void showprotected()
//	//{
//	//	cout << m_pub << endl;//���ԣ�������
//	//	cout << m_pro << endl;//���ԣ�������
//	///*	cout << m_pri << endl; ���ɷ���*/
//	//}
//
//
//
//
//	void showprivate()
//	{
//		cout << m_pub << endl;
//		cout << m_pro << endl;
//		/*cout << m_pri << endl; ���ɷ��ʵ�*/
//	}
//
//};
//
////��ʾ���������п���ʹ�������m_pro���� 
////�������ڼ̳�m_pro����ʱ������Ϊ�ܱ���Ȩ��
////class Csonson :public Son
////{
////public:
////	void show()
////	{
////		cout << m_pro << endl;
////		cout << m_pub << endl;
////	}
////};
//
//int main03()
//{
//	Son son;
//	
//	son.showprivate();
//	
//
//
//	return 0;
//}