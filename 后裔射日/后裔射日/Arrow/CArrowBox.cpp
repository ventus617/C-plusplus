#include"CArrowBox.h"
#include"../GameConfig/CGameConfig.h"


CArrowBox::CArrowBox()
{

}
CArrowBox::~CArrowBox()
{
	list<CArrow*>::iterator ite = m_isarrow.begin();
	while (ite != m_isarrow.end())
	{
		if (*ite)
		{
			delete(*ite);
			(*ite) = nullptr;
		}ite++;
	}m_isarrow.clear();
}

void CArrowBox::MoveAllArrow(int step)
{
	list<CArrow*>::iterator ite = m_isarrow.begin();
	while (ite != m_isarrow.end())
	{
		if (*ite)
		{
			(*ite)->MoveArrow(step);
		}
		if ((*ite)->m_x >= IMG_BK_ONE_WIDTH || (*ite)->m_y <= -IMG_ARR_HEIGHT)
		{
			delete (*ite);
			(*ite) = nullptr;
			ite = m_isarrow.erase(ite);
			continue;
		}ite++;
	}
}

void CArrowBox::ShowAllArrow()
{
	for (CArrow* pArr: m_isarrow)
	{
		if (pArr)
		{
			pArr->ShowArrow();
		}
	}
}