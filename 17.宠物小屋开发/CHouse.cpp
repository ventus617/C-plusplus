#include "CHouse.h"
CHouse::CHouse()
{

}
CHouse::~CHouse()
{
	list<CCage*>::iterator ite = m_pCage.begin();
	while (ite!=m_pCage.end())//������������ 
	{
		
		if (*ite)//���Ӵ���
		{
			delete* ite;//����ɾ��
			*ite = nullptr;
		}
		//��һ������
		//ite = m_pCage.erase(ite);//�ڵ�ɾ��
		ite++;

	}
	//�ڶ�������
	m_pCage.clear();
}