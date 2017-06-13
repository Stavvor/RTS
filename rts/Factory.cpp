#include "stdafx.h"
#include "Factory.h"


Factory::Factory()
{
	
}


Factory::~Factory()
{
}

Factory::Factory(vec3 VmousePos, unsigned int hpValue, unsigned int* armorUpgrades)
	:
	Building(VmousePos, hpValue, armorUpgrades) //TODO FIX hp
{
}
	

void Factory::takeDamage()
{
	
}

void Factory::drawSelf()
{
}
