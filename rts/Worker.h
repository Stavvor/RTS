#pragma once
#include "UtilityUnit.h"

class Worker :public UtilityUnit
{
private:
	unsigned int collectingRate = 5;
	unsigned int repairRate = 5; //TODO adjust
	bool hasMinerals;
	//MineralField* myMineral;
	//Targetable* myTarget;
public:
	void doAction();
	Worker();
	Worker(string Sname, string Stype, vec3, unsigned int Icooldown ,unsigned int, float, float, float, unsigned int* armorUpgrades);
	void moveCommand() override; //TODO virtual;
	bool getHasMinerals() override;
	void setHasMinerals(bool) override;


	//TODO jak rozwiazac budowanie
	void mine(shared_ptr<Targetable>);
	void repair(shared_ptr<Targetable> target);

	~Worker();
};
