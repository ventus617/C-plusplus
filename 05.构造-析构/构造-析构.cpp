#include<iostream>
using namespace std;


class CTest
{
public:
	int m_nA;
	int* m_p;
	//��������ʱ���Զ����ã�����ʼ�����г�Ա����
	CTest()
	{
		m_nA = 10;
		m_p = nullptr;
	}
	CTest(int a)
	{
		m_nA = a;
		m_p = new int(a);
	}

	//void my_delete()
	//{
	//	if (m_p)
	//	{
	//		delete m_p;
	//		m_p = nullptr;
	//	}
	//}

	//��������---------------------------------
	//������ ~+����,�޲�,ɾ�������Ѿ������ж���ı���
	//Ĭ�ϵ��������������������Ϊ��
	//�����б�������Ĭ���ṩһ����������
	//һ���ֶ��ع������������������������ṩĬ�ϵ���������
	
	//�����������ڽ����ˣ��������֮ǰ��ȥ�Զ����á�
	//�ڻ��ն���ռ�֮ǰ��ȥ���ն���Ŀռ䣬���������Ŀռ����ȥ���ն���Ŀռ�
	//���ã��������г�Ա��������Ŀռ䣬�����ռ䱾���޹�
	//������new�����Ķ���Ķ����ռ䣬���ǻ���m_p������ջ���ռ�
	//������Ĭ�ϣ������ֶ��ع����������������������������Ҳ��������������һ��
	~CTest()
	{
		if (m_p)
		{
			delete m_p;
			m_p = nullptr;
		}
	}

};

int main02()
{
	//CTest tst;//�޲εĳ�ʼ��
	//cout << tst.m_nA << endl;
	//CTest tst2(20);//���ڶ�������ʱ�򣬾͵ó�ʼ����
	//cout << tst2.m_nA << endl;
	//CTest tst3(40);
	//cout << tst3.m_nA << "  " <<*tst3.m_p << endl;
	//tst3.my_delete();


	CTest tst4(50);//��{}��ִ�У�����������}��ִ��
	CTest* pTst = new CTest(60);
	cout << pTst->m_nA << " " << *pTst->m_p << endl;
	delete pTst;
	pTst = nullptr;
	return 0;
}