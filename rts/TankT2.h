#pragma once
class TankT2 :
	public CombatUnit
{
public:
	TankT2();
	TankT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades);
	~TankT2();

	void drawSelf() override;
};

