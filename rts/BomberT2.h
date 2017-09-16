#pragma once
class BomberT2 : public CombatUnit
{
public:
	BomberT2();
	BomberT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value);
	~BomberT2();

	void drawSelf() override;
	GLuint chooseIcon();
};

