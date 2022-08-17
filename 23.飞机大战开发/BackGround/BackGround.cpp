#include"BackGround.h"
#include"../GameConfig/GameConfig.h"
CBackGround::CBackGround()
{
	m_x = 0;
	m_y = 0;
}
CBackGround::~CBackGround()
{

}
void CBackGround::InitBack()
{
	//加载图片,路径是相对于工程文件所在的路径
	::loadimage(&m_back, L"./res/背景.jpg");// ./同级的目录
	m_x = 0;
	m_y = -IMG_BACKGROUND_HEIGHT;//放进去的时候是 背景图的一半 所以背景图往上半部分是负的值
}
void CBackGround::ShowBack()
{
	::putimage(m_x, m_y, &m_back); //贴图
}
void CBackGround::MoveBack(int step)
{
	m_y += step;
	if (m_y >= 0) //当都为0的时候 已经把另外一半全部打印出来了 所以又得跳到最上面即图片的最开始
	{
		m_y = -IMG_BACKGROUND_HEIGHT;
	}
}