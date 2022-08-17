#include<iostream>
using namespace std;

//C++中的结构体
/*
C++中的结构体和类区别：

1.默认的访问修饰符不同，结构体--public 类--private
2.默认的继承方式不同，结构体--public 类--private
*/
struct Node
{
	int m_data;
	Node* pNext;
	Node(int v) //结构体构造函数
	{
		m_data = v;
		pNext = nullptr;
	}
	~Node() //结构体析构函数
	{

	}
};


class CMyList
{
public:
	Node* m_phead;//头指针
	Node* m_pend;//尾指针
	int m_length;//链表的长度
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
			pTemp = m_phead;//标记
			m_phead = m_phead->pNext;//移动
			delete pTemp;
		}
		m_pend = nullptr;
		m_phead = nullptr;
		m_length = 0;

	}
public:
	void PushBcak(int vc)//插入
	{
		Node* P_node = new Node(vc);
		if (m_phead)//非空链表
		{
			m_pend->pNext = P_node;//尾指针链接该节点
			m_pend = P_node;//尾指针指向该节点
			m_pend->pNext = nullptr;
		}
		else//空链表
		{
			m_phead = P_node;
			m_pend = P_node;
			m_pend->pNext = nullptr;
		}
		
		m_length++;//长度++
	}
	void popFront()//从头开始出
	{
		if (m_phead)
		{
			Node* p_temp = m_phead;
			if (m_pend==m_phead)//单个节点
			{
				m_pend = m_phead = nullptr;
				
			}
			else//多个结点
			{
				
				m_phead = m_phead->pNext;
				
			}
			delete p_temp;
			p_temp = nullptr;
			m_length--;
		}
	}
	int GetLen()//获取链表长度
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