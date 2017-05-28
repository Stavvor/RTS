#pragma once
class Soldier: public CombatUnit{
private:
	
public:
	Soldier();
	Soldier(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
		unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades);
	~Soldier();
};

