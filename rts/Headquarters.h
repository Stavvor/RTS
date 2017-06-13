#pragma once

class Headquarters : public Building
{
public:
	Headquarters();
	Headquarters(vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades);

	~Headquarters();

	void drawSelf() override;
};

