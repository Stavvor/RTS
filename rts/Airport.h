#pragma once
#include "Building.h"
class Airport :public Building{
private:

public:
	Airport();
	Airport(vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades);
	//void train();
	~Airport();

	void drawSelf() override;
};

