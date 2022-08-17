#include "CHouse.h"
CHouse::CHouse()
{

}
CHouse::~CHouse()
{
	list<CCage*>::iterator ite = m_pCage.begin();
	while (ite!=m_pCage.end())//遍历笼子链表 
	{
		
		if (*ite)//笼子存在
		{
			delete* ite;//笼子删除
			*ite = nullptr;
		}
		//第一个方法
		//ite = m_pCage.erase(ite);//节点删除
		ite++;

	}
	//第二个方法
	m_pCage.clear();
}