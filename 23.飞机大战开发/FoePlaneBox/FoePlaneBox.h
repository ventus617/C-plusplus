#pragma once
#include<list>
using namespace std;
#include"FoePlane.h"


class CFoePlaneBox
{
public:
	list<CFoePlane*> m_listFoe;
	list<CFoePlane*> m_listBoomFoe;
public:
	CFoePlaneBox();
	~CFoePlaneBox();
	
public:
	void ShowAllFoe();
	void ShowAllBoomFoe();
	void MoveAllFoe();
};