#include "stdafx.h"
#include "BomberT1.h"


BomberT1::BomberT1()
{
}

BomberT1::BomberT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades)
{
}

BomberT1::~BomberT1()
{
}

void BomberT1::drawSelf()
{

}
