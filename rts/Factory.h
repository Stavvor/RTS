#pragma once
#include "Building.h"
class Factory :public Building{
private:

public:
	Factory();
	Factory(vec3 Vpos ,unsigned int IHitPoints, unsigned int* armorUpgrades);
	//void train();
	~Factory();
};

