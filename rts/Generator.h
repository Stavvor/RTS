#pragma once
#include "Building.h"
class Generator :public Building{
private:

public:
	Generator();
	Generator(vec3 Vpos,unsigned int IHitPoints, unsigned int* armorUpgrades);
	~Generator();
};

