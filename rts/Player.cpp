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
	grid = new Grid();
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

void Player::updateEnergy(unsigned int value)
{
	energy += value;
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
	//TODO unit selecting
}

void Player::repair(Worker* selected)
{

	Targetable*target; //TODO target
	//selected->repair(target);
	
}


void Player::buildStructure()
{
	//TODO remove
	//TODO building UI
	//other buildings...
	//myBuildings.push_back(new Barracks({ 0,1,0 }, 2000, &armorUpgrades));//TODO mouse pos
	myBuildings.emplace_back(new Factory({ 0,1,0 }, 2000, &armorUpgrades));//TODO mouse pos

}


void Player::buildStructure(vec3 pos)
{
	{
		//TODO building UI
		//other buildings...
		//myBuildings.push_back(new Barracks(pos, 2000, &armorUpgrades));//TODO mouse pos
		myBuildings.emplace_back(new Factory(pos, 2000, &armorUpgrades));//TODO mouse pos
	}
}

void Player::createWorker()
{
	//TODO building UI
	//other buildings...
	//myUnits.push_back(new Worker("Test", "Mechanical", { 0,0,0 },25, 50, 0.0f, 0.0f, 0.0f, &armorUpgrades)); //TODO nazwa temp do testu miningu zmienic

	myUnits.emplace_back(new Worker("Test", "Mechanical", { 0,0,0 },25, 50, 0.0f, 0.0f, 0.0f, &armorUpgrades)); //TODO nazwa temp do testu miningu zmienic
	//Unit* temp= new Worker("Test", "Mechanical", { 0,0,0 }, 25, 50, 0.0f, 0.0f, 0.0f, &armorUpgrades);
	supply++;//TODO set limit? 
}

void Player::addNewUnit(Unit*temp)
{
	myUnits.emplace_back(temp);
	supply++;//TODO set limit...
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

vec3 Player::calculateFormation()
{
	float minZ = GRIDSIZE;
	float minX = GRIDSIZE;
	float maxZ = 0;
	float maxX = 0;
	for (int i = 0; i < selectedUnits.size(); i++)
	{
		if (selectedUnits[i]->getPosition().x >= maxX)
			maxX = selectedUnits[i]->getPosition().x;
		if (selectedUnits[i]->getPosition().x <= minX)
			minX = selectedUnits[i]->getPosition().x;
		if (selectedUnits[i]->getPosition().z >= maxZ)
			maxZ = selectedUnits[i]->getPosition().z;
		if (selectedUnits[i]->getPosition().z <= minZ)
			minZ = selectedUnits[i]->getPosition().z;
	}
	///
	vec3 A, B, C, D;

	A = { minX,1.0f,minZ };
	B = { minX,1.0f,maxZ };
	C = { maxX,1.0f,maxZ };
	D = { maxX,1.0f,minZ };


	///NW min
	///SE max

	


	float bottom = (A.x + B.x) / 2;
	float side = (A.z + D.z) / 2 ;
	
	
	vec3 mid{ bottom,1.0f,side };
	return mid;

}

vector<vec3> Player::calculateFormationDestinations(vec3 middle,vec3 dest)
{
	vector<vec3>destinations;
	for(auto unit:selectedUnits)
	{
		float unitX = unit->getPosition().x;
		float unitZ = unit->getPosition().z;

		//vec3 newDest;
		vec3 tempDest;

		if(unitX>middle.x)
		{
			float tempX = unitX - middle.x;
			//newDest.x=middle.x + temp;
			//unitX += middle.x;
			tempDest.x = dest.x + tempX;
		}
		else
		{
			float tempX = middle.x- unitX;
			//newDest.x = middle.x - temp;
			//unitX -= middle.x;
			tempDest.x = dest.x - tempX;
		}

		if (unitZ>middle.z)
		{
			float tempZ = unitZ - middle.z;
			//newDest.z = middle.z+temp;
			//unitZ += middle.z;
			tempDest.z= dest.z + tempZ;
		}
		else
		{
			float tempZ = middle.z- unitZ;
			//newDest.z = middle.z-temp;
			//unitZ -= middle.z;
			tempDest.z = dest.z + tempZ;
		}
		tempDest.y = 1.0f;
		//vec3 tempDest = { newDest.x,1.0f,newDest.z };//TODO Y
		destinations.push_back(tempDest);
	}
	
	return destinations;
}

void Player::addToControlGroup(int at, vector<shared_ptr<Unit>> selectedUnits)
{
	controlGroups[at] = selectedUnits;
}
void Player::jumpToControlGroup(int at)
{
	selectedUnits = controlGroups[at];
}
void Player::cleanMyDeadEntities()
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
				this->grid->leave(myUnits.at(i)->getCurrentXPos(), myUnits.at(i)->getCurrentZPos());//TODO clearing pointers from grid.. testtestestest
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
	//TODO move mineralfield somewhere else??
}

Player::~Player()
{
	delete(grid);
}

void Player::buildGenerator(const vec3& pos)
{
	//TODO building UI
	//other buildings...
	//myBuildings.push_back(new Barracks(pos, 2000, &armorUpgrades));//TODO mouse pos
	myBuildings.emplace_back(new Generator(pos, 2000, &armorUpgrades));//TODO mouse pos
}

