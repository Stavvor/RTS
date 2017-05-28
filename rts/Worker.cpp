#include "stdafx.h"
#include "Worker.h"

Worker::Worker()
{
}

Worker::Worker(string Sname, string Stype, vec3 Vpos, unsigned int Icooldown, unsigned int IHitPoints, float FSpeed, float FRange, float FScanRange, unsigned int* armorUpgrades)
	:
	UtilityUnit(Sname, Stype, Vpos, Icooldown, IHitPoints, FSpeed, FRange, FScanRange, armorUpgrades)
{
	//myMineral = NULL;
	//myTarget = NULL;
}

void Worker::moveCommand()
{
	if(getHasMinerals())
	{
		setDestination({ 0.0f,0.0f,0.0f });
	}
	else
	{
		setDestination(this->getTarget()->getPosition());
	}
}

void Worker::mine(shared_ptr<Targetable> target)
{
	//TODO ruch
	
	unsigned int test = target->getResources();
	if (target->getResources() <= collectingRate){
		target->setResources(0);
		//TODO ruch
		player->updateResources(target->getResources());
		setTarget(NULL);
		//TODO alert koniec mineralow
	}
	else
	{
		target->setResources(target->getResources() - collectingRate);
		//TODO ruch
		player->updateResources(collectingRate);
	}
	
	
}

void Worker::repair(shared_ptr<Targetable> target)
{
	if (typeid(target) != typeid(Building*) || (typeid(target) != typeid(Unit*) && target->getType() == "Mechanical")) {
		//TODO alert: to nie jest budynek
		return;
	}
	//ruch
	if(target->maxHitPoints-target->getHitPoints()<=repairRate){
		target->setHitPoints(target->maxHitPoints);
		//setTarget(NULL);
	}
	else 
	{
		target->setHitPoints(target->getHitPoints()+repairRate);
	}
	//return;
}

Worker::~Worker()
{
}

void Worker::doAction()
{
	this->setDestination(getTarget()->getPosition());
	mine(this->getTarget());
	//repair(this->getTarget());
	//TODO rozroznic akcje po celu
}
bool Worker::getHasMinerals()
{
	return hasMinerals;
}
void Worker::setHasMinerals(bool v)
{
	hasMinerals = v;
}