#pragma once

class TankT1 :
	public CombatUnit
{
public:
	TankT1();
	TankT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value);
	~TankT1();

	void drawSelf() override;
	GLuint chooseIcon() override;
};

