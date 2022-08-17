#include "CCage.h"

CCage::CCage()
{
	m_id = 0;
	m_pAni = nullptr;
}
CCage::~CCage()
{
	if (m_pAni)
	{
		delete m_pAni;
		m_pAni = nullptr;
	}

}

void CCage::InitCage(int id)
{
	m_id = id;

}
