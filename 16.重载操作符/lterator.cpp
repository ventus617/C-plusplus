//#include<iostream>
//using namespace std;
//
////C++中的结构体
///*
//C++中的结构体和类区别：
//
//1.默认的访问修饰符不同，结构体--public 类--private
//2.默认的继承方式不同，结构体--public 类--private
//*/
//struct Node
//{
//	int m_data;
//	Node* pNext;
//	Node(int v) //结构体构造函数
//	{
//		m_data = v;
//		pNext = nullptr;
//	}
//	~Node() //结构体析构函数
//	{
//
//	}
//};
//
//class CIterator
//{
//public:
//	Node* m_pTemp;
//	CIterator():m_pTemp(nullptr)
//	{
//		
//	}
//	CIterator(Node * Pnode):m_pTemp(Pnode)
//	{
//		
//	}
//	~CIterator(){}
//public:
//	Node* operator=(Node* Pnode)
//	{
//		m_pTemp = Pnode;
//		return m_pTemp;
//	}
//	bool operator==(Node* Pnode)
//	{
//		return m_pTemp == Pnode;
//	}
//	bool operator!=(Node* Pnode)
//	{
//		return m_pTemp != Pnode;
//	}
//	int operator*()
//	{
//		return m_pTemp->m_data;
//	}
//	Node* operator++()
//	{
//		m_pTemp = m_pTemp->pNext;
//		return m_pTemp;
//	}
//	Node* operator++(int)
//	{
//		Node* pTemp = m_pTemp;
//		m_pTemp = m_pTemp->pNext;
//		return pTemp;
//	}
//	operator bool()
//	{
//		return m_pTemp;
//	}
//};
//
//
//class CMyList
//{
//public:
//	Node* m_phead;//头指针
//	Node* m_pend;//尾指针
//	int m_length;//链表的长度
//public:
//	CMyList()
//	{
//		m_phead = nullptr;
//		m_pend = nullptr;
//		m_length = 0;
//	}
//	~CMyList()
//	{
//		Node* pTemp = nullptr;
//		while (m_phead)
//		{
//			pTemp = m_phead;//标记
//			m_phead = m_phead->pNext;//移动
//			delete pTemp;
//		}
//		m_pend = nullptr;
//		m_phead = nullptr;
//		m_length = 0;
//
//	}
//public:
//	void PushBcak(int vc)//插入
//	{
//		Node* P_node = new Node(vc);
//		if (m_phead)//非空链表
//		{
//			m_pend->pNext = P_node;//尾指针链接该节点
//			m_pend = P_node;//尾指针指向该节点
//			m_pend->pNext = nullptr;
//		}
//		else//空链表
//		{
//			m_phead = P_node;
//			m_pend = P_node;
//			m_pend->pNext = nullptr;
//		}
//
//		m_length++;//长度++
//	}
//	void popFront()//从头开始出
//	{
//		if (m_phead)
//		{
//			Node* p_temp = m_phead;
//			if (m_pend == m_phead)//单个节点
//			{
//				m_pend = m_phead = nullptr;
//
//			}
//			else//多个结点
//			{
//
//				m_phead = m_phead->pNext;
//
//			}
//			delete p_temp;
//			p_temp = nullptr;
//			m_length--;
//		}
//	}
//	int GetLen()//获取链表长度
//	{
//		return m_length;
//	}
//	//void bianli()
//	//{
//	//	Node* pTemp = m_phead; //带参数的构造，operator=
//	//	while (pTemp) //operator ==  operator!=
//	//	{
//	//		cout << pTemp->m_data << " ";//*pTemp; operator*	
//	//		pTemp = pTemp->pNext;//pTemp++ operator++
//	//	}
//	//	cout << endl;
//	//}
//
//	void bianli()
//	{
//		CIterator ite(m_phead);
//		ite = m_phead;
//		while (ite)
//		{
//			cout << *ite << "  ";
//			ite++;
//		}
//		cout << endl;
//	}
//
//
//};
//
//
//int main()
//{
//	Node p1(10);
//	cout << p1.m_data << endl;
//
//	CMyList lst;
//	lst.PushBcak(1);
//	lst.PushBcak(2);
//	lst.PushBcak(3);
//	lst.PushBcak(4);
//	lst.bianli();
//	cout << lst.GetLen() << endl;
//
//	lst.popFront();
//	lst.popFront();
//
//
//	lst.bianli();
//	cout << lst.GetLen() << endl;
//
//	return 0;
//}