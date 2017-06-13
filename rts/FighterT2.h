#pragma once
class FighterT2 : public CombatUnit
{
public:
	FighterT2();
	FighterT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades);
	~FighterT2();

	void drawSelf() override;
};

