#include "stdafx.h"
#include "Airport.h"


Airport::Airport()
{
}

Airport::Airport(vec3 VMousePos, unsigned int IHpValue, unsigned int* armorUpgrades)
	:
	Building(VMousePos, IHpValue, armorUpgrades)
{
}
/*
void Airport::train()
{

}
*/

Airport::~Airport()
{
}
