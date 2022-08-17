#pragma once
#include<easyx.h>
#include"../GunnerBox/GunnerBox.h"
class CPlayerPlane
{
public:
	IMAGE m_player;
	IMAGE m_playerMask;//����ͼ
	int m_x;
	int m_y;
public:
	CPlayerPlane();
	~CPlayerPlane();
public:
	void InitPlayer();
	void ShowPlayer();
	void MovePlayer(WPARAM direct, int step);
	CGunner* SendGunner();

};

