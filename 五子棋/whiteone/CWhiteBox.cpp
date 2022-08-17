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
		if (*ite)//���������
		{
			delete(*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_listWhite.clear();//�������пսڵ�
}

void CWhiteBox::ShowAllWhite()
{
	for (CWhiteOne* pOne : m_listWhite)
	{
		pOne ? pOne->ShowPlayer() : void(0);
	}
}

