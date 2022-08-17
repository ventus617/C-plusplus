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
	cout << "穷鬼,没钱" << endl;\
	return false;\
}

bool CPeople::BuyAnimal(CAnimal* pAni, Ani_Kind kind)
{
	if (pAni == nullptr) {
		cout << "动物的指针为空" << endl;
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
			cout << "穷鬼,没钱" << endl;
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
			cout << "穷鬼,没钱" << endl;
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
			cout << "穷鬼,没钱" << endl;
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
	cout << "请输入笼子的ID(id>=0)" << endl;
	int id = 0;
	cin >> id;
	while ((int)id < 0)
	{
		cout << "请重新输入笼子的ID(id>=0)" << endl;
		cin >> id;
	}
	pCage->InitCage(id);
	return pCage;
}
void CPeople::PushAnimal(CCage* pCage, CAnimal* pAni)
{
	if (pCage == nullptr || pAni == nullptr)
	{
		cout << "笼子或动物为空" << endl;
		return;
	}
	pCage->m_pAni = pAni; //添加动物
	cout << "动物成功添加到笼子中" << endl;
}
void CPeople::PushCage(CHouse* pHouse, CCage* pCage)
{
	if (pCage == nullptr || pHouse == nullptr)
	{
		cout << "笼子或房子为空" << endl;
		return;
	}
	pHouse->m_pCage.push_back(pCage);
	cout << "笼子成功放在房子里" << endl;
}
void CPeople::KillAnimal(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "房子为空" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite && (*ite)->m_id==id)//匹配ID
		{
			if ((*ite)->m_pAni)//动物是否不存在
			{
				delete (*ite)->m_pAni;//回收动物的空间
				(*ite)->m_pAni = nullptr;
				cout << "杀死动物成功" << endl;
				
			}
			else
			{
				cout << "找到了笼子,但动物不存在" << endl;
			}
			return;
		}
		ite++;
	}
	cout << "没有匹配到笼子的ID=" << id << endl;

}
void CPeople::DestoryCage(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "房子为空" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite && (*ite)->m_id == id)//匹配ID
		{
			if ((*ite)->m_pAni)//动物是否不存在
			{
				delete (*ite)->m_pAni;//回收动物的空间
				(*ite)->m_pAni = nullptr;

			}
			delete (*ite);//回收笼子的空间
			(*ite)= nullptr;
			pHouse->m_pCage.erase(ite);
			cout << "销毁笼子成功" << endl;
			return;
		}
		ite++;
	}
	cout << "没有匹配到笼子的ID=" << id << endl;
}
void CPeople::LookAnimal(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "房子为空" << endl;
		return;
	}

	for (CCage* v : pHouse->m_pCage)
	{
		if (v && v->m_id == id)
		{
			cout << "笼子ID=" << v->m_id << ":";
			if (v->m_pAni)
			{
				 v->m_pAni->ShowAnimal();
			}
			else
			{
				cout << "没有动物" << endl;
			}
			return;
		}
	}
	cout << "没有匹配到笼子的ID=" << id << endl;
}
void CPeople::LookAnimal(CHouse* pHouse)
{
	if (pHouse == nullptr)
	{
		cout << "房子为空" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite)
		{
			cout << "笼子的ID=" << (*ite)->m_id << ",";
			if ((*ite)->m_pAni)//动物是否不存在
			{
				cout << "看到了动物:";
				(*ite)->m_pAni->ShowAnimal();
			}
			else
			{
				cout << "找到了笼子,但动物不存在" << endl;
			}
		}
		ite++;
	}
}
void CPeople::PlayWithAnimal(CHouse* pHouse, int id)
{
	if (pHouse == nullptr)
	{
		cout << "房子为空" << endl;
		return;
	}
	list<CCage*>::iterator ite = pHouse->m_pCage.begin();
	while (ite != pHouse->m_pCage.end())
	{
		if (*ite && (*ite)->m_id == id)//匹配ID
		{
			if ((*ite)->m_pAni)//动物是否不存在
			{
				cout << m_strName << "正在玩耍...";
				(*ite)->m_pAni->PlayAnimal();

			}
			else
			{
				cout << "自己在玩耍" << endl;
			}
			return;
		}
		ite++;
	}
	cout << "没有匹配到笼子的ID=" << id << endl;
}
void CPeople::InitPeople(string name, int money)
{
	m_money = money;
	m_strName = name;

}
void CPeople::ShowPeople()
{
	cout << m_strName << " 剩余钱数：" << m_money << endl;
}