#pragma once
#include"FoePlane.h"
class CFoePlaneMiddle :public CFoePlane
{
public:
	CFoePlaneMiddle();
	~CFoePlaneMiddle();
public:
	virtual void InitFoe()override;

	virtual void ShowFoe()override;

	virtual bool IsHitPlayer(CPlayerPlane& player)override;

	virtual bool IsHitGunner(CGunner* pGun)override;

};

