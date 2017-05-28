#pragma once
#include "Building.h"
class Barracks :public Building{
private:
	
public:
	Barracks();
	Barracks(vec3 Vpos ,unsigned int IHitPoints, unsigned int* armorUpgrades);
	void train(unsigned int* weaponUpgrades, unsigned int* armorUpgrades, unsigned int time);
	void takeDamage();
	~Barracks();
};

