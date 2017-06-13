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
	//vec3 mousePos;

	vector <shared_ptr<Unit>>selectedUnits;
	SCameraState cameraHotkeys[12];
	vector <shared_ptr<Unit>>controlGroups[10];


public:
	
	Player(string);
	~Player();

	template<typename T>
	void buildStructure(vec3 pos)
	{
		//TODO building UI
		//other buildings...
		//myBuildings.push_back(new Barracks(pos, 2000, &armorUpgrades));//TODO mouse pos
		myBuildings.emplace_back(new T(pos, 2000, &armorUpgrades));//TODO mouse pos
	}

	template<typename T>
	void Player::trainUnit(shared_ptr<Building> target,unsigned int buildTime) {
		//TODO how to choose building... static? control groups?
		target->train<T>(&weaponUpgrades, &armorUpgrades, buildTime);
	}

	Grid* grid;
	struct Details* details; 


	unsigned int getResources();
	void updateResources(unsigned int);
	unsigned int getEnergy();
	void updateEnergy(unsigned int);
	unsigned int getWeaponUpgrades();
	unsigned int getArmorUpgrades();
	unsigned int* getWeaponUpgradesPtr();
	unsigned int* getArmorUpgradesPtr();
	unsigned int getSupply();
	string getSupplyToPrint();

	void upgradeWeapons();
	void upgradeArmor();

	void setCameraHotkey(int key, SCameraState cameraState);
	SCameraState jumpToCameraHotkey(int key);

	void select();

	void repair(Worker* selected);
	//TODO obsluga myszki

	
	void buildStructure();
	void buildStructure(vec3 pos);
//	void trainUnit(shared_ptr<Building> target);
	void createWorker();
	
	void addNewUnit(Unit*);

	vector<shared_ptr<Unit>> getMyUnits();
	vector<shared_ptr<Building>> getMyBuildings();
	vector<shared_ptr<Unit>> getSelectedUnits();
	
	void addToSelectedUnits(shared_ptr<Unit> target);
	void clearSelectedUnits();
	vec3 calculateFormation();
	vector<vec3> calculateFormationDestinations(vec3,vec3);
	void addToControlGroup(int, vector<shared_ptr<Unit>> selectedUnits);
	void jumpToControlGroup(int);

	void cleanMyDeadEntities();
	void clearMemory();

	
	void buildGenerator(const vec3& pos);
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