#include "stdafx.h"
#include "FighterT2.h"


FighterT2::FighterT2()
{
}

FighterT2::FighterT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades)
{
}

FighterT2::~FighterT2()
{
}

void FighterT2::drawSelf()
{
}
