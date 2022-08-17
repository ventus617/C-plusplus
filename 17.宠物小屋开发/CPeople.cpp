#include "CPeople.h"
#include<iostream>
using namespace std;
CPeople::CPeople()
{
	m_money = 0;
	m_strName = "";
}
CPeople::~CPeople()
{

}
#define BUY_ANIMAL(ANI_COST)\
if ((m_money - ANI_COST) >= 0)\
{\
	m_money -= ANI_COST;\
	return true;\
}\
else\
{\
	cout << "���,ûǮ" << endl;\
	return false;\
}

bool CPeople::BuyAnimal(CAnimal* pAni, Ani_Kind kind)
{
	if (pAni == nullptr) {
		cout << "�����ָ��Ϊ��" << endl;
		return false;
	}
	switch (kind)
	{
	case Ani_cat:
	{
		BUY_ANIMAL(CAT_COST)
		/*if ((m_money - CAT_COST) >= 0)
		{
			m_money -= CAT_COST;
			return true;
		}
		else
		{
			cout << "���,ûǮ" << endl;
			return false;
		}*/
	}
	break;
	case Ani_dog:
	{
		BUY_ANIMAL(DOG_COST)
		/*if ((m_money - DOG_COST) >= 0)
		{
			m_money -= DOG_COST;
			return true;
		}
		else
		{
			cout << "���,ûǮ" << endl;
			return false;
		}*/
	}
	break;
	case Ani_snake:
	{
		BUY_ANIMAL(SNAKE_COST)
	/*	if ((m_money - SNAKE_COST) >= 0)
		{
			m_money -= SNAKE_COST;
			return true;
		}
		else
		{
			cout << "���,ûǮ" << endl;
			return false;
		}*/
	}
	break;
	}
	return true;
}
CCage* CPeople::CreateCage()
{
	CCage* pCage = new CCage;
	cout << "���������ӵ�ID(id>=0)" << endl;
	int id = 0;
	cin >> id;
	while ((int)id < 0)
	{
		cout << "�������������ӵ�ID(id>=0)" << endl;
		cin >> id;
	}
	pCage->InitCage(id);
	return pCage;
}
void CPeople::PushAnimal(CCage* pCage, CAnimal* pAni)
{
	if (pCage == nullptr || pAni == nullptr)
	{
		cout << "���ӻ���Ϊ��" << endl;
		return;
	}
	pCage->m_pAni = pAni; //��Ӷ���
	cout << "����ɹ���ӵ�������" << endl;
}
void CPeople::PushCage(CHouse* pHouse, CCage* pCage)
{
	if (pCage == nullptr || pHouse == nullptr)
	{
		cout << "���ӻ���Ϊ��" << endl;
		return;
	}
	pHouse->m_pCage.push_back(pCage);
	cout << "���ӳɹ����ڷ�����" << endl;
}
void CPeople::KillAnimal(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite && (*ite)->m_id==id)//ƥ��ID
		{
			if ((*ite)->m_pAni)//�����Ƿ񲻴���
			{
				delete (*ite)->m_pAni;//���ն���Ŀռ�
				(*ite)->m_pAni = nullptr;
				cout << "ɱ������ɹ�" << endl;
				
			}
			else
			{
				cout << "�ҵ�������,�����ﲻ����" << endl;
			}
			return;
		}
		ite++;
	}
	cout << "û��ƥ�䵽���ӵ�ID=" << id << endl;

}
void CPeople::DestoryCage(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite && (*ite)->m_id == id)//ƥ��ID
		{
			if ((*ite)->m_pAni)//�����Ƿ񲻴���
			{
				delete (*ite)->m_pAni;//���ն���Ŀռ�
				(*ite)->m_pAni = nullptr;

			}
			delete (*ite);//�������ӵĿռ�
			(*ite)= nullptr;
			pHouse->m_pCage.erase(ite);
			cout << "�������ӳɹ�" << endl;
			return;
		}
		ite++;
	}
	cout << "û��ƥ�䵽���ӵ�ID=" << id << endl;
}
void CPeople::LookAnimal(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return;
	}

	for (CCage* v : pHouse->m_pCage)
	{
		if (v && v->m_id == id)
		{
			cout << "����ID=" << v->m_id << ":";
			if (v->m_pAni)
			{
				 v->m_pAni->ShowAnimal();
			}
			else
			{
				cout << "û�ж���" << endl;
			}
			return;
		}
	}
	cout << "û��ƥ�䵽���ӵ�ID=" << id << endl;
}
void CPeople::LookAnimal(CHouse* pHouse)
{
	if (pHouse == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite)
		{
			cout << "���ӵ�ID=" << (*ite)->m_id << ",";
			if ((*ite)->m_pAni)//�����Ƿ񲻴���
			{
				cout << "�����˶���:";
				(*ite)->m_pAni->ShowAnimal();
			}
			else
			{
				cout << "�ҵ�������,�����ﲻ����" << endl;
			}
		}
		ite++;
	}
}
void CPeople::PlayWithAnimal(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite && (*ite)->m_id == id)//ƥ��ID
		{
			if ((*ite)->m_pAni)//�����Ƿ񲻴���
			{
				cout << m_strName << "������ˣ...";
				(*ite)->m_pAni->PlayAnimal();

			}
			else
			{
				cout << "�Լ�����ˣ" << endl;
			}
			return;
		}
		ite++;
	}
	cout << "û��ƥ�䵽���ӵ�ID=" << id << endl;
}
void CPeople::InitPeople(string name, int money)
{
	m_money = money;
	m_strName = name;

}
void CPeople::ShowPeople()
{
	cout << m_strName << " ʣ��Ǯ����" << m_money << endl;
}