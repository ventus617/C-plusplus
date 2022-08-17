#include "CSnake.h"


CREATE_OBJECT(CSnake);
WND_PARAM(300, 600, 600, 600, L"贪吃蛇");

int step = 4;
CSnake::CSnake()
{
	int a = 0;
}

CSnake::~CSnake() //父类是虚析构的时候 才会先执行子类的析构
{
	int a = 0;
}

void CSnake::On_init()
{
	int a = 0;
}

void CSnake::On_Paint()
{
	int a = 0;
}

void CSnake::On_Close()
{
	int a = 0;
}

void CSnake::ON_WM_LBUTTONDOWN(POINT po)
{
	int a = 0;
}

