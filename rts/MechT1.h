#pragma once
class MechT1: public CombatUnit{
private:
	
public:
	MechT1();
	MechT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades);
	~MechT1();

	void drawSelf() override;
};

