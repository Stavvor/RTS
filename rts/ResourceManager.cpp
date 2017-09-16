#include "stdafx.h"
#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
	notEnough = false;
	_txtFrame = 0;
}

void ResourceManager::txtFrame()
{
	_txtFrame++;
	if(_txtFrame==100)
	{
		notEnough = false;
		_txtFrame = 0;
	}
}

bool ResourceManager::buildCommand(int mineralCost, int energyCost)
{
	updateResources();
	if (resources < mineralCost || energy < energyCost)
	{
		notEnough = true;
		return false;
	}
	else
	{
		subtractResources(mineralCost, energyCost);
		return true;
	}

}

void ResourceManager::repairTick()
{
	updateResources();
	if (resources < 5 || energy < 3)
	{
		notEnough = true;
	}
	else
	{
		subtractResources(5, 3);
	}
}

void ResourceManager::updateResources()
{
	resources = player->getResources();
	energy = player->getEnergy();
}


void ResourceManager::subtractResources(int mineralValue, int energyValue)
{
	auto newResourceValue = resources - mineralValue;
	auto newEnergyValue = energy - energyValue;
	player->setResources(newResourceValue);
	player->setEnergy(newEnergyValue);
}
ResourceManager::~ResourceManager()
{
}