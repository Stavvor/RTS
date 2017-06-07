#include "stdafx.h"
#include "Barracks.h"


Barracks::Barracks()
{
	
}


Barracks::~Barracks()
{
}

Barracks::Barracks(vec3 VmousePos, unsigned int hpValue, unsigned int* armorUpgrades)
	:
	Building(VmousePos, hpValue, armorUpgrades) //TODO FIX hp
{
}
	

void Barracks::train(unsigned int* weaponUpgrades, unsigned int* armorUpgrades,unsigned int time)
{
	//TODO wrzucamy do kolejki
	Unit* temp;	
	temp = new Soldier("Infantry", 8, 50, 20, 7, "Soldier", getPosition(), 50, 0.5, weaponUpgrades, armorUpgrades);
	//string name, string Stype, vec3 position, unsigned int ICooldoown, unsigned int hitPoints, float speed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades
	this->getProductionQueue()->push(temp);
	totalProductionTime = time;
}

void Barracks::takeDamage()
{
	
}
