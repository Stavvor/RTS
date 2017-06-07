#include "stdafx.h"
#include "Player.h"


Player::Player(string Sname)
	:
	name (Sname)
{
	resources = 400;
	energy = 100;
	supply = 0;
	weaponUpgrades = 0;
	armorUpgrades = 0;
}

unsigned int Player::getResources()
{
	return resources;
}

void Player::updateResources(unsigned int value)
{
	resources += value;
}

unsigned int Player::getEnergy()
{
	return energy;
}

unsigned int Player::getWeaponUpgrades()
{
	return weaponUpgrades;
}

unsigned int Player::getArmorUpgrades()
{
	return armorUpgrades;
}

unsigned int* Player::getWeaponUpgradesPtr()
{
	return &weaponUpgrades;
}

unsigned int* Player::getArmorUpgradesPtr()
{
	return &armorUpgrades;
}

unsigned Player::getSupply()
{
	return supply;
}

string Player::getSupplyToPrint()
{
	string output = to_string(supply);
	output.append("/100");
	output;
	return output;
}

void Player::upgradeWeapons()
{
	weaponUpgrades++;
}

void Player::upgradeArmor()
{
	armorUpgrades++;
}

void Player::setCameraHotkey(int key, SCameraState cameraState)
{
	cameraHotkeys[key - 1] = cameraState;
}

SCameraState Player::jumpToCameraHotkey(int key)
{
	return cameraHotkeys[key - 1];
}

void Player::select()
{
	//TODO 
}

void Player::repair(Worker* selected)
{

	Targetable*target; //TODO cel
	//selected->repair(target);
	
}

void Player::buildStructure()
{
	//TODO UI budowania...
	//inne budynki....
	//myBuildings.push_back(new Barracks({ 0,0,0 }, 2000, &armorUpgrades));//TODO mouse pos
	myBuildings.emplace_back(new Barracks({ 0,0,0 }, 2000, &armorUpgrades));//TODO mouse pos

}

void Player::buildStructure(vec3 pos)
{
	//TODO UI budowania...
	//inne budynki....
	//myBuildings.push_back(new Barracks(pos, 2000, &armorUpgrades));//TODO mouse pos
	myBuildings.emplace_back(new Barracks(pos, 2000, &armorUpgrades));//TODO mouse pos
}

void Player::trainUnit(shared_ptr<Building> target) {
	//TODO jak wybrac budynek
	
	target->train(&weaponUpgrades, &armorUpgrades,5);
	
}

void Player::createWorker()
{
	//TODO UI budowania...
	//inne budynki....
	//myUnits.push_back(new Worker("Test", "Mechanical", { 0,0,0 },25, 50, 0.0f, 0.0f, 0.0f, &armorUpgrades)); //TODO nazwa temp do testu miningu zmienic
	myUnits.emplace_back(new Worker("Test", "Mechanical", { 0,0,0 },25, 50, 0.0f, 0.0f, 0.0f, &armorUpgrades)); //TODO nazwa temp do testu miningu zmienic
	supply++;//TODO ustawic limit, potencjalnie wagi jednostek
}

void Player::addNewUnit(Unit*temp)
{
	myUnits.emplace_back(temp);
	supply++;//TODO ustawic limit, potencjalnie wagi jednostek
}

vector<shared_ptr<Unit>> Player::getMyUnits()
{
	return  myUnits;
}

vector<shared_ptr<Building>> Player::getMyBuildings()
{
	return myBuildings;
}

vector<shared_ptr<Unit>> Player::getSelectedUnits()
{
	return selectedUnits;
}

void Player::addToSelectedUnits(shared_ptr<Unit> target)
{
	selectedUnits.emplace_back(target);//TODO
}

void Player::clearSelectedUnits()
{
	selectedUnits.clear();
}

void Player::addToControlGroup(int at, vector<shared_ptr<Unit>> selectedUnits)
{
	controlGroups[at] = selectedUnits;
}
void Player::jumpToControlGroup(int at)
{
	selectedUnits = controlGroups[at];
}
void Player::cleanDeadEntities()
{
	if (myUnits.empty() && myBuildings.empty()) 
		return;
	else {
		for (int i = 0; i < myBuildings.size(); i++){
			if (myBuildings.at(i)->getIsDead()){
				myBuildings.at(i).reset();
				myBuildings.erase(myBuildings.begin() + i);
			}
		}
		for (int i = 0; i < myUnits.size(); i++) {
			if (myUnits.at(i)->getIsDead()){
				player->grid->leave(myUnits.at(i)->getCurrentXPos(), myUnits.at(i)->getCurrentZPos());//TODO czyscimy wskazniki z gridu
				myUnits.at(i).reset();
				myUnits.erase(myUnits.begin() + i);
				supply--;
			}	
		}
	}
}

void Player::clearMemory()
{
	for (int i = 0; i < myBuildings.size(); i++) {
		myBuildings.at(i).reset();
		myBuildings.erase(myBuildings.begin() + i);
	}
	for (int i = 0; i<myUnits.size(); i++)
	{
		myUnits.at(i).reset();
		myUnits.erase(myUnits.begin() + i);
	}
	//TODO przeniesc mineralfields gdzie indziej... zeby nie tylko gracz mial do nich dostep
}

Player::~Player()
{
	delete(grid);
}

