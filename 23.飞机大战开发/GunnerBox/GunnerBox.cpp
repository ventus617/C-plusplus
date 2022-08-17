#include"GunnerBox.h"
#include"../GameConfig/GameConfig.h"

//是只负责发送出去的炮弹的动作
CGunnerBox::CGunnerBox()
{

}
CGunnerBox::~CGunnerBox()
{
	list<CGunner*>::iterator ite = m_listGun.begin();
	while (ite != m_listGun.end())
	{
		if (*ite)//炮弹指针是否为空
		{
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
		//1.m_listGun.erase(ite); 回收单个结点 
	}
	m_listGun.clear();//2.回收所有结点
}

void CGunnerBox::ShowAllGunner()
{
	for (CGunner* pGun : m_listGun)//遍历显示所有炮弹
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
		if (*ite)//炮弹指针是否为空
		{
			(*ite)->MoveGunner(step);
			if ((*ite)->m_y <= -IMG_GUNNER_HEIGHT) //判断是否出界
			{
				delete (*ite);//回收炮弹
				(*ite) = nullptr;

				ite = m_listGun.erase(ite);//删除对应的节点 并指向下一个
				continue;//继续执行下一次循环 不遍历下面的代码
			}
		}
		ite++;
		
	}

}