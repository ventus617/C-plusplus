#pragma once
#include"CHouse.h"
#include"config.h"
class CPeople
{
public:
	int m_money;
	string m_strName;
public:
	CPeople();
	~CPeople();
public:
	bool BuyAnimal(CAnimal* pAni, Ani_Kind kind);
	CCage* CreateCage();
	void PushAnimal(CCage* pCage, CAnimal* pAni);
	void PushCage(CHouse* pHouse, CCage* pCage);
	void KillAnimal(CHouse* pHouse, int id);
	void DestoryCage(CHouse* pHouse, int id);
	void LookAnimal(CHouse* pHouse, int id);
	void LookAnimal(CHouse* pHouse);
	void PlayWithAnimal(CHouse* pHouse, int id);
	void InitPeople(string name, int money);
	void ShowPeople();
};
