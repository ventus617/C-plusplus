#pragma once
#include<easyx.h>
#include"../PlayerPlane/PlayerPlane.h"
class CFoePlane
{
public:
	IMAGE m_foe;
	int m_x;
	int m_y;
	int m_blood;
	int m_showid;
	int m_points;
public:
	CFoePlane();
	virtual ~CFoePlane();
public:
	virtual void InitFoe() = 0;
	virtual void ShowFoe() = 0;
	void MoveFoe(int step);
	virtual bool IsHitPlayer(CPlayerPlane& player) = 0;
	virtual bool IsHitGunner(CGunner* pGun) = 0;
};