#include"CSunBox.h"


CSunBox::CSunBox()
{

}
CSunBox::~CSunBox()
{
	list<CSun*>::iterator ite = m_issun.begin();
	while (ite != m_issun.end())
	{
		if (*ite)
		{
			delete (*ite);
			(*ite) = nullptr;
			ite = m_issun.erase(ite);
			continue;
		}ite++;
	}
}

void CSunBox::ShowAllSun()
{
	for (CSun* pSun : m_issun)
	{
		if(pSun)pSun->ShowSun();
	}
}

