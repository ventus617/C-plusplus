//#include<iostream>
//using namespace std;
//
//class Cfather
//{
//public:
//	Cfather()
//	{
//		cout << "Cfather()" << endl;
//	}
//	virtual ~Cfather()
//	{
//		cout << "~Cfather()" << endl;
//	}
//};
//class Cson :public Cfather
//{
//public:
//	int* m_p;
//public:
//	Cson()
//	{
//		cout << "Cson()" << endl;
//		m_p = new int(10);
//	}
//	~Cson()
//	{
//		cout << "~Cson()" << endl;
//		if (m_p)
//		{
//			delete m_p;
//			m_p = nullptr;
//		}
//	}
//};
//
//int main()
//{
//	Cson* pson = new Cson;
//
//	delete pson;
//	pson = nullptr;
//
//	/*
//	Cfather()
//	Cson()
//	~Cson()
//	~Cfather()
//	*/
//	//��������
//	//--------------------------------
//
//	cout << "---------------------" << endl;
//	Cfather* pfa = new Cson;
//	delete pfa;
//	//delete ���տռ�֮ǰ�� ���յ��ø�ָ������͵�����,���Ǹ�����ָ��Ŀռ�
//	//������������new������ �ᵼ���ڴ�й© ���������������
//  //��������Ŀռ����溬�и���ĳ�Ա ������ִ������������� ���ֿռ仹�и����ԱҲҪ������ ��ô��ʱ���ֻ�ȥ���������ĸ��������
//	// Cson()����virtual�ؼ��������� ������ָ��ָ���������ʱ,��ʱ��������������Ϊ�麯��,��������д,ʵ���ϵ��õ������������
//	//ʵ���������������ڱ��������涼��һ����
//	//pfa->~Cfather()
//	pfa = nullptr;
//
//	/*
//	Cfather()
//	Cson()
//	~Cfather()
//	*/
//	//ȱ��~Cson()
//	return 0;
//}