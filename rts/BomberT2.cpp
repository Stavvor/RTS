#include "stdafx.h"
#include "BomberT2.h"


BomberT2::BomberT2()
{
}

BomberT2::BomberT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades)
{
}

BomberT2::~BomberT2()
{
}

void BomberT2::drawSelf()
{
}
