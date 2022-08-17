#pragma once
#include<list>
using namespace std;
#include"CWhiteOne.h"
class CWhiteBox
{
public:
	list<CWhiteOne*> m_listWhite;
public:
	CWhiteBox();
	~CWhiteBox();
public:
	void ShowAllWhite();
};