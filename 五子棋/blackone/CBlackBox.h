#pragma once
#pragma once
#include<list>
using namespace std;
#include"CBlackOne.h"
class CBlackBox
{
public:
	list<CBlackOne*> m_listBlack;
public:
	CBlackBox();
	~CBlackBox();
public:
	void ShowAllBlack();
	
};