#include "stdafx.h"
#include "BomberT1.h"


BomberT1::BomberT1()
{
}

BomberT1::BomberT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades,value)
{
}

BomberT1::~BomberT1()
{
}

void BomberT1::drawSelf()
{

}

GLuint BomberT1::chooseIcon()
{
	auto hp = this->getNormalizedHitPoints();
	if (hp >= 0.666)
		; //TODO Update
		//return Resources::BomberT1IconG;
	if (hp < 0.333 && hp < 0.666)
			;
		//return Resources::BomberT1IconY;
	if(hp<=0.333)
	;
		//return Resources::BomberT1IconR;
	return 0;
}
