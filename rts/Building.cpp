#include "stdafx.h"
#include "Player.h"
#include "Building.h"


Building::Building(){
}

Building::Building(vec3 VmousePos, unsigned int IhitPoints, unsigned int* armorUpgrades)
	:
	Targetable(VmousePos, IhitPoints, armorUpgrades)
{
	totalProductionTime = 0;
}

queue<Unit*>* Building::getProductionQueue()
{
	return &productionQueue;
}

unsigned Building::getProductionTime()
{
	return productionTime;
}

void Building::setProductionTime(unsigned int value)
{
	productionTime = value;
}

void Building::updateProductionTime(unsigned int value)
{
	productionTime += value;
}

void Building::queueUnit(unsigned int* armorUpgrades, unsigned int* weaponUpgrades)	//TODO dopasowac argument, przeladowac pod wszystkie jednostki
{
	//Unit temp;
	//productionQueue.push();
	//TODO Ontimer(iles tam ms)
	//productionQueue.pop();
	//train(armorUpgrades, weaponUpgrades);//TODO  wybrac dana jednostke..

}

/*
Unit* Building::train()
{
	
}
*/

void Building::setRallyPoint(vec3 mousePos)
{
	//TODO koordy myszki
	//rallyPoint = mousePos;
}

Building::~Building(){

}
