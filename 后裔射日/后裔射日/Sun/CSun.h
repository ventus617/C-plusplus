#pragma once

#include<easyx.h>


class CSun
{
public:
	IMAGE m_sun;
	IMAGE m_sunmask;
	int m_x;

	int m_y;
	int m_blood;
public:

	CSun();

	~CSun();

public:

	void InitSun();

	void ShowSun();
}; 


