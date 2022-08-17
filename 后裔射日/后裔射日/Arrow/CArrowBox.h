#pragma once

#include"CArrow.h"
#include<list>
using namespace std;

class CArrowBox
{
public:
	list<CArrow*>m_isarrow;
public:
	CArrowBox();
	~CArrowBox();
public:

	void MoveAllArrow(int step);

	void ShowAllArrow();

};



