#include "stdafx.h"
#include "Targetable.h"


Targetable::Targetable()
{
	/*for(int i=0;i<targetedBy.size();i++)
	{
		targetedBy[i].reset();
	}
	targetedBy.clear();*/
}

Targetable::Targetable(vec3 Vpos)
	:
	Entity(Vpos)
{
	upgrades = NULL;
	isDead = false;
}

Targetable::Targetable(vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades)
	:
	Entity(Vpos),
	hitPoints(IHitPoints),
	maxHitPoints(IHitPoints)
{
	upgrades = new Upgrades(armorUpgrades);
	isDead = false;
}

Targetable::Targetable(string Stype, vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades)
	:
	Entity(Vpos),
	hitPoints(IHitPoints),
	maxHitPoints(IHitPoints),
	type(Stype)
{
	upgrades = new Upgrades(armorUpgrades);
	isDead = false;
}

Targetable::Targetable(string Stype, vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades, unsigned int* weaponUpgrades)
	:
	Entity(Vpos),
		hitPoints(IHitPoints),
		maxHitPoints(IHitPoints),
		type(Stype)
	{
		upgrades = new Upgrades(weaponUpgrades, armorUpgrades);
		isDead = false;
	}

unsigned Targetable::getResources()
{
	return 0;
}

void Targetable::setResources(unsigned int)
{
}


void Targetable::takeDamage(unsigned int damageValue) {
	if (damageValue - (*this->upgrades->armorUpgradesPtr) >= hitPoints) {
		setHitPoints(0);
		this->onDead();//this->onDead(); //zmniejszyc wektor 

					   // delete(this); //TODO czy tak mozna?

	}
	else setHitPoints(hitPoints - (damageValue - (*this->upgrades->armorUpgradesPtr)));
}

unsigned int Targetable::getHitPoints()
{
	return hitPoints;
}

void Targetable::attack(Targetable * target)
{
}

void Targetable::setHitPoints(unsigned int IhitPoints)
{
	hitPoints = IhitPoints;
}

bool Targetable::getIsDead()
{
	return isDead;
}
string Targetable::getType()
{
	return type;
}

Targetable::~Targetable()
{
	if(upgrades!=NULL) //nie wszystkie targetable maja upgrady...
		delete(upgrades); //TODO przywrocic
}

void Targetable::setIsDead(bool value)
{
	isDead = value;
}

void Targetable::setTarget(shared_ptr<Targetable>)
{
}

void Targetable::onDead()
{
	isDead = true;
	for (int i = 0; i<targetedBy.size(); i++)
	{
		targetedBy[i]->setTarget(NULL);
	}
	//TODO animacje
}
void Targetable::addToTargetedby(shared_ptr<Targetable>targetingUnit)
{
	targetedBy.emplace_back(targetingUnit);//TODO ogarnac
}

