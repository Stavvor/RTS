#include "stdafx.h"
#include "Unit.h"

extern SoundPlayer* soundPlayer; //TODO moze bardziej elegancko??

void Unit::updateUnitPos(vec3 newPos)
{
	setPosition(newPos);
}

shared_ptr<Targetable> Unit::getTarget()
{
	//TODO prawdopodbonie nie potrzebne
	return target;
}

void Unit::setTarget(shared_ptr<Targetable> currTarget)
{
	target = currTarget; //jak wyzej
}

vec3 Unit::getUnitPos()
{
	return getPosition();
}
Unit::Unit()
{
}

Unit::Unit(string Sname, string Stype, vec3 Vpos, unsigned int ICooldown, float Frange, unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	Targetable(Stype, Vpos, IhitPoints, weaponUpgrades, armorUpgrades),
	name(Sname),
	speed(Fspeed),
	range(Frange),
	maxCooldown(ICooldown)
{
	upgrades = new Upgrades(weaponUpgrades, armorUpgrades);
	isPickedUp = false;
	target.reset();
	movePoints = 0;
	destination = { 0,0,0 };
	cooldown = 0;
	dir = { 0,0,0 };
	isMoving = false;
	snd = NULL;
}

Unit::Unit(string Sname,string Stype, vec3 Vpos, unsigned int ICooldown, unsigned int IhitPoints, float Fspeed, float Frange, unsigned int* armorUpgrades)
	: 
	Targetable(Stype, Vpos, IhitPoints, armorUpgrades),
	name(Sname),
	speed(Fspeed),
	range(Frange),
	maxCooldown(ICooldown)
	{
	upgrades = new Upgrades(0, armorUpgrades); //TODO mozna zamienic na NULL zeby bylo ladniej ale musze byc pewien ze utlityUnit nigdy nie sprobuje uzyc tego wskaznika
	isPickedUp = false;
	target.reset();
	destination = { 0,0,0 };
	cooldown = 0;
	isMoving = false;
	snd = NULL;
}

//Unit::Unit(string Sname, string Stype, vec3 Vpos, unsigned int ImaxCooldown, unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
//	:
//	Targetable(Stype, Vpos, IhitPoints, weaponUpgrades, armorUpgrades),
//	name(Sname),
//	speed(Fspeed)
//{
//	upgrades = new Upgrades(weaponUpgrades, armorUpgrades);
//	isPickedUp = false;
//	target = NULL;
//	movePoints = 0;
//	destination = { 0,0,0 };
//	cooldown = 0;
//	maxCooldown = ImaxCooldown;
//}

unsigned Unit::getCooldown()
{
	return cooldown;
}

void Unit::updateCooldown(unsigned int value)
{
	char const* name = "Test";
	//cout<<typeid(*this).name() << endl;
	if(1)
	{
		if(this->getHasMinerals())
		{
			this->returnMinerals();
		}
		if(!this->getHasMinerals() && this->getTarget()!=NULL)
		{
			this->goToMiningLocation();
		}
	}
	cooldown += value;
	if (cooldown >= maxCooldown && this->getTarget() != NULL ) {
		this->doAction();
		//
			soundPlayer->play3DSound(soundPlayer->gatling,this->getPosition(),10.0f,snd);//TODO dodac skladowa jednostki zasieg halasu..
			if (snd)
			{
				irrklang::vec3df pos = { this->getPosition().x,this->getPosition().y,this->getPosition().z }; //TODO updatowanie pozycji mozna przenisc do onrender... albo menegera pozycji zeby bylo bardzie smooth
				snd->setPosition(pos);
			}
		cooldown = 0;
	}
	else if (cooldown >= 2 * maxCooldown)
		cooldown = maxCooldown;
}

void Unit::setCooldown(unsigned int value)
{
	cooldown = value;
}

void Unit::setIsPickedUp(bool value)
{
	isPickedUp = value;
}

bool Unit::getIsPickedUp()
{
	return isPickedUp;
}

void Unit::attack(Targetable * target)
{

}

void Unit::doAction()
{
	
}

void Unit::mine(MineralField* target)
{

}

float Unit::getRange()
{
	return range;
}
vec3 Unit::getDestination()
{
	return destination;
}

void Unit::setDestination(vec3 location)
{
	destination = location;
}

int Unit::getCurrentXPos()
{
	return currentXpos;
}

int Unit::getCurrentZPos()
{
	return currentZpos;
}

void Unit::setCurrentGridPos(int x, int z)
{
	currentXpos = x;
	currentZpos = z;
}

string Unit::getName()
{
	return name;
}

bool Unit::targetInRange()
{
	vec3 targetPos = this->getTarget()->getPosition();
	vec3 myPos = this->getPosition();

	float distance = sqrt(pow((myPos.x - targetPos.x), 2) + pow((myPos.y - targetPos.y), 2) + pow((myPos.z - targetPos.z), 2));
	if (distance<=range) return true;
	else return false;
}

void Unit::goToMiningLocation()
{
}

void Unit::moveCommand()
{
	if(getTarget()!=NULL)
	{
		setDestination(getTarget()->getPosition());
	}

}
void Unit::setHasMinerals(bool)
{
	
}
 bool Unit::getHasMinerals()
{
	 return true;
}

void Unit::returnMinerals()
{
}

Unit::~Unit()
{
}


void Unit::setIsMoving(bool v)
{
	isMoving = v;
}

bool Unit::getIsMoving()
{
	return isMoving;
}

void Unit::calculateVecAngle()
{
	if(this->getDestination().x!=this->getPosition().x && this->getDestination().y != this->getPosition().y && this->getDestination().z != this->getPosition().z)
	{
		angle = atan2(this->getDestination().x - this->getPosition().x, this->getDestination().z - this->getPosition().z);
		angle = angle*(180 / 3.14);
	}
	
	
}

void Unit::drawSelf()
{
}
