#pragma once
#include<easyx.h>
class CTarget
{
public:
	IMAGE m_tar;
	IMAGE m_tarmask;
	int m_x;

	int m_y;
	int f;
public:
	CTarget();
	~CTarget();
public:
	void InitTarget();

	void ShowTarget();

	void MoveTarget(int step);

};




