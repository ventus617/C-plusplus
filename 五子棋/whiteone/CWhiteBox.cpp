#include"CWhiteBox.h"
#include"../GameConfig/GameConfig.h"

CWhiteBox::CWhiteBox()
{
	
}
CWhiteBox::~CWhiteBox()
{
	list<CWhiteOne*>::iterator ite = m_listWhite.begin();
	while (ite != m_listWhite.end())
	{
		if (*ite)//如果有棋子
		{
			delete(*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_listWhite.clear();//回收所有空节点
}

void CWhiteBox::ShowAllWhite()
{
	for (CWhiteOne* pOne : m_listWhite)
	{
		pOne ? pOne->ShowPlayer() : void(0);
	}
}

