#include"CShieldBox.h"


CShieldBox::CShieldBox()
{

}

CShieldBox::~CShieldBox()
{
	list<CShield*>::iterator ite = m_isshield.begin();
	while (ite != m_isshield.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
		}ite++;
	}m_isshield.clear();
}
void CShieldBox::ShowAllShield()
{
	for (CShield* pShe : m_isshield)
	{
		if (pShe)
		{
			pShe->ShowShield();
		}
	}
}
