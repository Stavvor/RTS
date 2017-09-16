#pragma once
#include "Building.h"

class Factory :public Building {
private:
	
public:
	//TODO probably remove... move mechs into factory
	Factory();
	Factory(vec3 Vpos ,unsigned int IHitPoints, unsigned int* armorUpgrades);
	//void train(unsigned int* weaponUpgrades, unsigned int* armorUpgrades, unsigned int time);
	void takeDamage();
	void drawSelf() override;

	~Factory();
};

