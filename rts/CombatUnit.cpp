#include "stdafx.h"
#include "CombatUnit.h"


CombatUnit::CombatUnit()
{
}

CombatUnit::CombatUnit(string Stype, unsigned int Idamage, unsigned int ICooldown, float Frange, float FscanRange,string Sname, vec3 Vpos, unsigned int IhitPoints, float Fspeed, 
	unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	Unit(Stype,Sname, Vpos, ICooldown,Frange, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades),
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
	cout << "atakuje" << endl;
	if (targetInRange()) {
		if(target->getHitPoints()> damage + 2 * (*this->upgrades->weaponUpgradesPtr))
			target->takeDamage(damage + 2 * (*this->upgrades->weaponUpgradesPtr));  //TODO dodac wartosc upgradu gdy uporam sie z *owner (damage+owner->getWeaponUpgrades)
		else
		{

			target->takeDamage(target->getHitPoints());
			target->onDead();
		}
	}
	else {
		cout << "za daleko" << endl;
	}
	
}

void CombatUnit::doAction()
{
		attack(this->getTarget());
}

CombatUnit::~CombatUnit()
{
	
}
