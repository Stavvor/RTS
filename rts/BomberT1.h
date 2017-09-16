#pragma once
class BomberT1 : public CombatUnit
{
public:
	BomberT1();
	BomberT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value);
	~BomberT1();

	void drawSelf() override;
	GLuint chooseIcon() override;
};

