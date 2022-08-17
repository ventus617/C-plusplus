#pragma once
#include"FoePlane.h"
class CFoePlaneBig:public CFoePlane
{
public:
	CFoePlaneBig();
	~CFoePlaneBig();
public:
	virtual void InitFoe()override;

	virtual void ShowFoe()override;
	
	virtual bool IsHitPlayer(CPlayerPlane& player)override;
	
	virtual bool IsHitGunner(CGunner* pGun)override;
	
};



