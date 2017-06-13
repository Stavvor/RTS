#include "stdafx.h"
#include "UtilityUnit.h"

UtilityUnit::UtilityUnit()
{

}
/**/
UtilityUnit::UtilityUnit( string Sname, string Stype, vec3 Vpos, unsigned int Icooldown, unsigned int IHitPoints, float FSpeed, float FRange, float FScanRange, unsigned int* armorUpgrades)
	:
	Unit(Sname, Stype, Vpos, Icooldown, IHitPoints, FSpeed,FRange, armorUpgrades),
	scanRange(FScanRange)
{
}


void UtilityUnit::mine(shared_ptr<Targetable>) {
	//TODO wykminic jak ma dzialac mining
}

void UtilityUnit::repair(shared_ptr<Targetable>) {
	
}

void UtilityUnit::doAction()
{
	
	this -> mine(this->getTarget());
	this->returnMinerals();
}

UtilityUnit::~UtilityUnit()
{
}

void UtilityUnit::drawSelf()
{
}
