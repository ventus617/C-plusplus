#pragma once
#include<easyx.h>
#include"../Target/CTarget.h"
#include"../Arrow/CArrowBox.h"
class CPeople
{
public:
	IMAGE m_Peo;
	IMAGE m_Peomask;
	int m_x;

	int m_y;
public:
	CPeople();

	~CPeople();
public:
	void InitPeo();

	void ShowPeo();

	CArrow* Archery(CTarget& tar);//Éä¼ý

}; 





