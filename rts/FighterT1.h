#pragma once
class FighterT1 : public CombatUnit
{
public:
	FighterT1();
	FighterT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades);
	~FighterT1();
};

