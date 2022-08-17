#include<iostream>
using namespace std;

//C++�еĽṹ��
/*
C++�еĽṹ���������

1.Ĭ�ϵķ������η���ͬ���ṹ��--public ��--private
2.Ĭ�ϵļ̳з�ʽ��ͬ���ṹ��--public ��--private
*/
struct Node
{
	int m_data;
	Node* pNext;
	Node(int v) //�ṹ�幹�캯��
	{
		m_data = v;
		pNext = nullptr;
	}
	~Node() //�ṹ����������
	{

	}
};


class CMyList
{
public:
	Node* m_phead;//ͷָ��
	Node* m_pend;//βָ��
	int m_length;//����ĳ���
public:
	CMyList()
	{
		m_phead = nullptr;
		m_pend = nullptr;
		m_length = 0;
	}
	~CMyList()
	{
		Node* pTemp = nullptr;
		while (m_phead)
		{
			pTemp = m_phead;//���
			m_phead = m_phead->pNext;//�ƶ�
			delete pTemp;
		}
		m_pend = nullptr;
		m_phead = nullptr;
		m_length = 0;

	}
public:
	void PushBcak(int vc)//����
	{
		Node* P_node = new Node(vc);
		if (m_phead)//�ǿ�����
		{
			m_pend->pNext = P_node;//βָ�����Ӹýڵ�
			m_pend = P_node;//βָ��ָ��ýڵ�
			m_pend->pNext = nullptr;
		}
		else//������
		{
			m_phead = P_node;
			m_pend = P_node;
			m_pend->pNext = nullptr;
		}
		
		m_length++;//����++
	}
	void popFront()//��ͷ��ʼ��
	{
		if (m_phead)
		{
			Node* p_temp = m_phead;
			if (m_pend==m_phead)//�����ڵ�
			{
				m_pend = m_phead = nullptr;
				
			}
			else//������
			{
				
				m_phead = m_phead->pNext;
				
			}
			delete p_temp;
			p_temp = nullptr;
			m_length--;
		}
	}
	int GetLen()//��ȡ������
	{
		return m_length;
	}
	void bianli()
	{
		Node* pTemp = m_phead;
		while (pTemp)
		{
			cout << pTemp->m_data << " ";
			pTemp = pTemp->pNext;
		}
		cout << endl;
	}
};


int main01()
{
	Node p1(10);
	cout << p1.m_data << endl;

	CMyList lst;
	lst.PushBcak(1);
	lst.PushBcak(2);
	lst.PushBcak(3);
	lst.PushBcak(4);
	lst.bianli();
	cout << lst.GetLen()<< endl;
	
	lst.popFront();
	lst.popFront();


	lst.bianli();
	cout << lst.GetLen() << endl;

	return 0;
}