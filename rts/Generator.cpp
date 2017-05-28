#include "stdafx.h"
#include "Generator.h"

Generator::Generator()
{
}

Generator::Generator(vec3 VMousePos, unsigned int IHpValue, unsigned int* armorUpgrades)
	:
	Building(VMousePos, IHpValue, armorUpgrades)
{
}
/*
void Generator::train()
{
}
*/
Generator::~Generator()
{
}
