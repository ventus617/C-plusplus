#include"FoePlaneBox.h"
#include<typeinfo>
#include"FoePlaneBig.h"
#include"FoePlaneMiddle.h"
#include"FoePlaneSmall.h"
#include"../GameConfig/GameConfig.h"



CFoePlaneBox::CFoePlaneBox()
{

}
#define DELETE_FOE(LIST)\
 list<CFoePlane*>::iterator ite##LIST =LIST.begin();\
while (ite##LIST != LIST.end())\
{\
	if (*ite##LIST)\
	{\
		delete(*ite##LIST);\
		*ite##LIST = nullptr;\
	}\
	ite##LIST++;\
}\
LIST.clear();//清空节点
CFoePlaneBox::~CFoePlaneBox()
{
	//list<CFoePlane*>::iterator ite = m_listFoe.begin();
	//while (ite != m_listFoe.end())
	//{
	//	if (*ite)
	//	{
	//		delete(*ite);
	//		*ite = nullptr;
	//	}
	//	ite++;
	//}
	//m_listFoe.clear();//清空节点
	DELETE_FOE(m_listFoe);
	DELETE_FOE(m_listBoomFoe);

}
void CFoePlaneBox::ShowAllFoe()
{
	for (CFoePlane* pFoe : m_listFoe)
	{
		pFoe->ShowFoe();
	}
}
void CFoePlaneBox::ShowAllBoomFoe()
{
	for (CFoePlane* pFoe : m_listBoomFoe)
	{
		pFoe->ShowFoe();
	}
}
void CFoePlaneBox::MoveAllFoe()
{
	list<CFoePlane*>::iterator ite = m_listFoe.begin();
	while (ite != m_listFoe.end())
	{
		if (*ite)
		{
			//(*ite)->MoveFoe(8); //无法区别大的和小的飞机
			//RTTI（运行时类型识别）: Run_Time Type Id
			// 
			//typeid(要计算的表达式类型); 类似sizeof()
			// 
			// 父类指针 == typeid（*ite）; ===（CFoePlane*）
			// 
			//*父类指针 == typeid（**ite）; ===*（CFoePlane*）才是引用子类的东西
			// 
			//typeid(int)==type_info //返回的是信息 不是类型


			if (typeid(**ite) == typeid(CFoePlaneBig))//返回的是类型的信息 而不是类型
			{
				(*ite)->MoveFoe(TIMER_FOEBIG_MOVE_STEP);
			}
			if (typeid(**ite) == typeid(CFoePlaneMiddle))//返回的是类型的信息 而不是类型
			{
				(*ite)->MoveFoe(TIMER_FOEMIDDLE_MOVE_STEP);
			}
			if (typeid(**ite) == typeid(CFoePlaneSmall))//返回的是类型的信息 而不是类型
			{
				(*ite)->MoveFoe(TIMER_FOESMALL_MOVE_STEP);
			}

			//判断是否出界
			if ((*ite)->m_y > IMG_BACKGROUND_HEIGHT)
			{
				delete (*ite);//删除该内容
				(*ite) = nullptr;
				ite = m_listFoe.erase(ite);
				continue;
			}

		}
	ite++;
	}
	
}