#pragma once
#include "Building.h"
class Generator :public Building{
private:
	unsigned int cooldown;
public:
	unsigned int maxCooldown;
	Generator();
	Generator(vec3 Vpos,unsigned int IHitPoints, unsigned int* armorUpgrades);
	~Generator();

	void updateCooldown(unsigned int) override;

	void drawSelf() override;
};

