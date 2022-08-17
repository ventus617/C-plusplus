#include"CBlackBox.h"
#include"../GameConfig/GameConfig.h"

CBlackBox::CBlackBox()
{

}
CBlackBox::~CBlackBox()
{
	list<CBlackOne*>::iterator ite = m_listBlack.begin();
	while (ite != m_listBlack.end())
	{
		if (*ite)//如果有棋子
		{
			delete(*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_listBlack.clear();//回收所有空节点
}

void CBlackBox::ShowAllBlack()
{
	for (CBlackOne* pOne : m_listBlack)
	{
		pOne ? pOne->ShowPlayer() : void(0);
	}
}

