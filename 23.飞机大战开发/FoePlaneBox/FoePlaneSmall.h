#pragma once
#include"FoePlane.h"
class CFoePlaneSmall :public CFoePlane
{
public:
	CFoePlaneSmall();
	~CFoePlaneSmall();
public:
	virtual void InitFoe()override;

	virtual void ShowFoe()override;

	virtual bool IsHitPlayer(CPlayerPlane& player)override;

	virtual bool IsHitGunner(CGunner* pGun)override;

};

