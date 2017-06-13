#include "stdafx.h"
#include "MechT2.h"


MechT2::MechT2()
{
}

MechT2::MechT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades)
{
}

MechT2::~MechT2()
{
}

void MechT2::drawSelf()
{

}
