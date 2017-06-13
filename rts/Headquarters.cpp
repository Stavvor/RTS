#include "stdafx.h"
#include "Headquarters.h"


Headquarters::Headquarters()
{
}

Headquarters::Headquarters(vec3 VmousePos, unsigned int hpValue, unsigned int* armorUpgrades)
	:
	Building(VmousePos, hpValue, armorUpgrades) //TODO FIX hp
{
}

Headquarters::~Headquarters()
{
}

void Headquarters::drawSelf()
{
}
