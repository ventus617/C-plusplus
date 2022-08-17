#pragma once
#include"../Arrow/CArrowBox.h"
#include<easyx.h>
class CShield
{
public:
	IMAGE m_she;
	IMAGE m_shemask;
	int m_x;

	int m_y;
public:

	CShield();

	~CShield();
public:
	void InitShield(int x, int y);

	void ShowShield();

	//void MoveShield(int step);

	bool isHitArrow(CArrow* pArr);
};



