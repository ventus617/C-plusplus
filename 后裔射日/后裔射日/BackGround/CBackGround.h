#pragma once
#include<easyx.h>


class CBackGround
{
public:
	int m_x;
	int m_y;
	IMAGE m_back;
public:
	CBackGround();

	~CBackGround();
public:
	void InitBack(int tot);//选择哪一个环境 宇宙还是地球

	void ShowBack();

	void MoveBack(int step);
};







