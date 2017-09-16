#pragma once
class MechT2 : public CombatUnit 
{
public:
	MechT2();
	MechT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value);
	~MechT2();
	void drawSelf() override;
	GLuint chooseIcon();
};

