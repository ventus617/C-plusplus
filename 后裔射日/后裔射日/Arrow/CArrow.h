#pragma once
#include<easyx.h>
#include"../Sun/CSunBox.h"
class CArrow
{
public:
	IMAGE m_arrow;
	IMAGE m_arrowmask;
	int m_x;

	int m_y;

public:

	CArrow();

	~CArrow();

public:

	void InitArrow(int x, int y);

	void ShowArrow();

	void MoveArrow(int step);

	bool isHitSun(CSun* pSun);
}; 

