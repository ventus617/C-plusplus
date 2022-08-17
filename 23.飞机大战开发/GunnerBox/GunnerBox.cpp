#include"GunnerBox.h"
#include"../GameConfig/GameConfig.h"

//��ֻ�����ͳ�ȥ���ڵ��Ķ���
CGunnerBox::CGunnerBox()
{

}
CGunnerBox::~CGunnerBox()
{
	list<CGunner*>::iterator ite = m_listGun.begin();
	while (ite != m_listGun.end())
	{
		if (*ite)//�ڵ�ָ���Ƿ�Ϊ��
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
		//1.m_listGun.erase(ite); ���յ������ 
	}
	m_listGun.clear();//2.�������н��
}

void CGunnerBox::ShowAllGunner()
{
	for (CGunner* pGun : m_listGun)//������ʾ�����ڵ�
	{
		/*if (pGun)
		{
			pGun->ShowGunner();
		}
		*/
		pGun ? pGun->ShowGunner() : (void)0;
	}
}

void CGunnerBox::MoveAllGunner(int step)
{
	list<CGunner*>::iterator ite = m_listGun.begin();
	while (ite != m_listGun.end())
	{
		if (*ite)//�ڵ�ָ���Ƿ�Ϊ��
		{
			(*ite)->MoveGunner(step);
			if ((*ite)->m_y <= -IMG_GUNNER_HEIGHT) //�ж��Ƿ����
			{
				delete (*ite);//�����ڵ�
				(*ite) = nullptr;

				ite = m_listGun.erase(ite);//ɾ����Ӧ�Ľڵ� ��ָ����һ��
				continue;//����ִ����һ��ѭ�� ����������Ĵ���
			}
		}
		ite++;
		
	}

}