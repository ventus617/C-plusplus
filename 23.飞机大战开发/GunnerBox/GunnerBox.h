#pragma once
#include<list>
using namespace std;
#include"Gunner.h"
class CGunnerBox
{
public:
	list<CGunner*> m_listGun;
public:
	CGunnerBox();
	~CGunnerBox();
public:
	void ShowAllGunner();
	void MoveAllGunner(int step);
};