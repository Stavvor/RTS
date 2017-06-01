#pragma once

using namespace std;

class Player{
private:
	string name;
	unsigned int resources;
	unsigned int energy;
	unsigned int weaponUpgrades;
	unsigned int armorUpgrades;
	unsigned int supply;

	
	//vector <Building*> myBuildings;
	vector<shared_ptr<Building>>myBuildings;
	//vector <Unit*> myUnits;
	vector<shared_ptr<Unit>>myUnits;
	vec3 mousePos;

	vector <shared_ptr<Unit>>selectedUnits;
	SCameraState cameraHotkeys[12];
	vector <shared_ptr<Unit>>controlGroups[10];


public:
	BuildingGrid* grid;
	struct Details* details; //struktura z atrybutami gracza (latwiejsze rozwiazanie upgradow itd);
	Player(string);
	unsigned int getResources();
	void updateResources(unsigned int);
	unsigned int getEnergy();
	unsigned int getWeaponUpgrades();
	unsigned int getArmorUpgrades();
	unsigned int* getWeaponUpgradesPtr();
	unsigned int* getArmorUpgradesPtr();
	unsigned int getSupply();
	string getSupplyToPrint();// latwiej dodac do wyswietlania "/"

	void upgradeWeapons();
	void upgradeArmor();

	void setCameraHotkey(int key, SCameraState cameraState);
	SCameraState jumpToCameraHotkey(int key);

	void select();

	void repair(Worker* selected);
	//TODO obsluga myszki

	void buildStructure();
	void buildStructure(vec3 pos);
	void trainUnit(shared_ptr<Building> target);
	void createWorker();
	
	void addNewUnit(Unit*);//docelowa funkcja budowania; kolejki budynkow popuja wskazniki po danym czasem a ta funkcja wrzuca do vectora..

	vector<shared_ptr<Unit>> getMyUnits();
	vector<shared_ptr<Building>> getMyBuildings();
	vector<shared_ptr<Unit>> getSelectedUnits();
	
	void addToSelectedUnits(shared_ptr<Unit> target);
	void clearSelectedUnits();

	void addToControlGroup(int, vector<shared_ptr<Unit>> selectedUnits);
	void jumpToControlGroup(int);

	void cleanDeadEntities();
	void clearMemory();

	~Player();
};

/*
struct Details {
	unsigned int* resourcesPtr;
	unsigned int* energyPtr;
	unsigned int* weaponUpgradesPtr;
	unsigned int* armorUpgradesPtr;
	Details(unsigned int resources, unsigned int energy, unsigned int weaponUpgrades, unsigned int armorUpgrades)
		:
		resourcesPtr(&resources),
		energyPtr(&energy),
		weaponUpgradesPtr(&weaponUpgrades),
		armorUpgradesPtr(&armorUpgrades)
	{}
};
*/