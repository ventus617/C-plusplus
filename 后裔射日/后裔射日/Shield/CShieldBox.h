#pragma once
#include"CShield.h"
#include<list>
using namespace std;
class CShieldBox
{
public:
	list<CShield*>m_isshield;
public:

	CShieldBox();

	~CShieldBox();
public:
	

	void ShowAllShield();


	//void MoveAllShield(int step);

};



