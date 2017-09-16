#include "stdafx.h"
#include "CombatUnit.h"


CombatUnit::CombatUnit()
{
}

CombatUnit::CombatUnit(string Stype, unsigned int Idamage, unsigned int ICooldown, float Frange, float FscanRange,string Sname, vec3 Vpos, unsigned int IhitPoints, float Fspeed, 
	unsigned int* weaponUpgrades, unsigned int* armorUpgrades,bool value)
	:
	Unit(Stype,Sname, Vpos, ICooldown,Frange, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades, value),
	damage (Idamage),
	scanRange (FscanRange)
{
		killCount = 0;
}

void CombatUnit::scan()
{

}

void CombatUnit::attack(shared_ptr<Targetable>  target)
{
	if (targetInRange()) {
		if(target->getHitPoints()> damage + 2 * (*this->upgrades->weaponUpgradesPtr))
			target->takeDamage(damage + 2 * (*this->upgrades->weaponUpgradesPtr));  
		else
		{

			target->takeDamage(target->getHitPoints());
			target->onDead();
			this->setTarget(NULL);
		}
	}
	else {
		cout << "target too far" << endl;
	}
	
}

void CombatUnit::drawSelf()
{

}

void CombatUnit::doAction()
{
		attack(this->getTarget());
}

CombatUnit::~CombatUnit()
{
	
}
