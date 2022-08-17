#pragma once
#include"CAnimal.h"
class CCage
{
public:
	int		m_id;
	CAnimal* m_pAni;
public:
	CCage();
	~CCage();
public:
void InitCage(int id);
};

