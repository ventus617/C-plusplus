#include"Gunner.h"
#include"../GameConfig/GameConfig.h"

CGunner::CGunner()
{
	m_x = 0;
	m_y = 0;
}
CGunner::~CGunner()
{

}
void CGunner::InitGunner(int x, int y)
{
	::loadimage(&m_gun, L"./res/gunner.jpg");
	m_x = x;
	m_y = y;
}
void CGunner::ShowGunner()
{

	::putimage(m_x, m_y,//放到的目标（窗口）的位置
		IMG_GUNNER_WIDTH, IMG_GUNNER_HEIGHT, //在目标窗口显示该图片的多少
		&m_gun, //源图
		IMG_GUNNER_WIDTH, 0,//从源图的哪个像素位置开始找 （即屏蔽图）
		SRCPAINT); //传输方式位或

	::putimage(m_x, m_y,//放到的目标（窗口）的位置
		IMG_GUNNER_WIDTH, IMG_GUNNER_HEIGHT, //在目标窗口显示该图片的多少
		&m_gun, //源图
		0, 0,//从源图的哪个像素位置开始找（即子弹图）
		SRCAND); //传输方式位或
}
void CGunner::MoveGunner(int step)
{
	m_y -= step; //纵向 向上
}