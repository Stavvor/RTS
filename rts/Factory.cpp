#include "stdafx.h"
#include "Factory.h"


Factory::Factory()
{
}

Factory::Factory(vec3 VMousePos, unsigned int IHpValue, unsigned int* armorUpgrades)
	:
	Building(VMousePos, IHpValue, armorUpgrades)
{	
}
/*
void Factory::train()
{
}
*/
Factory::~Factory()
{
}
