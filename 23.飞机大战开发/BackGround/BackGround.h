#pragma once
#include<easyx.h>

class CBackGround
{
public:
	IMAGE m_back;
	int m_x;
	int m_y;

public:
	CBackGround();
	~CBackGround();
public:
	void InitBack();
	void ShowBack();
	void MoveBack(int step);
};