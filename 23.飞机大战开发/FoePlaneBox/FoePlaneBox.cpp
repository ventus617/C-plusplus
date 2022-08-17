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
LIST.clear();//��սڵ�
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
	//m_listFoe.clear();//��սڵ�
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
			//(*ite)->MoveFoe(8); //�޷������ĺ�С�ķɻ�
			//RTTI������ʱ����ʶ��: Run_Time Type Id
			// 
			//typeid(Ҫ����ı��ʽ����); ����sizeof()
			// 
			// ����ָ�� == typeid��*ite��; ===��CFoePlane*��
			// 
			//*����ָ�� == typeid��**ite��; ===*��CFoePlane*��������������Ķ���
			// 
			//typeid(int)==type_info //���ص�����Ϣ ��������


			if (typeid(**ite) == typeid(CFoePlaneBig))//���ص������͵���Ϣ ����������
			{
				(*ite)->MoveFoe(TIMER_FOEBIG_MOVE_STEP);
			}
			if (typeid(**ite) == typeid(CFoePlaneMiddle))//���ص������͵���Ϣ ����������
			{
				(*ite)->MoveFoe(TIMER_FOEMIDDLE_MOVE_STEP);
			}
			if (typeid(**ite) == typeid(CFoePlaneSmall))//���ص������͵���Ϣ ����������
			{
				(*ite)->MoveFoe(TIMER_FOESMALL_MOVE_STEP);
			}

			//�ж��Ƿ����
			if ((*ite)->m_y > IMG_BACKGROUND_HEIGHT)
			{
				delete (*ite);//ɾ��������
				(*ite) = nullptr;
				ite = m_listFoe.erase(ite);
				continue;
			}

		}
	ite++;
	}
	
}