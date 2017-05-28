#pragma once
class UtilityUnit:public Unit{
private:
	float scanRange;
public:
	UtilityUnit();
	UtilityUnit(string Sname, string Stype, vec3 Vpos, unsigned int Icooldown, unsigned int IHitPoints, float speed, float range, float scanRange, unsigned int* armorUpgrades);
	void mine();
	virtual ~UtilityUnit();
};

