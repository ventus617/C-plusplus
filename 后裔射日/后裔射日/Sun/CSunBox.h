#pragma once
#include"CSun.h"
#include<list>

using namespace std;

class CSunBox
{
public:
	list<CSun*>m_issun;
public:
	CSunBox();
	~CSunBox();
public:
	//void MoveAllSun();
	void ShowAllSun();
}; 



