#pragma once
class Unit :public Targetable {
private:
	string name;
	float speed;
	float range;
	vec3 destination;
	shared_ptr<Targetable> target;
	unsigned int movePoints;
	unsigned int cooldown;
	bool isPickedUp;
	int currentXpos;
	int currentZpos;
	bool isMoving;
	//
	
public:
	//Targetable* target;		//TODO roziwazac cel...
	Unit();
	Unit(string name, string Stype, vec3 position, unsigned int ICooldoown, float range, unsigned int hitPoints, float speed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades); //CombatUnit constructor
	Unit(string name, string Stype,  vec3 position, unsigned int ICooldoown,  unsigned int hitPoints, float speed, float range, unsigned int* armorUpgrades);	//UtilityUnit constructor
	//Unit(string Sname, string Stype, vec3 Vpos, unsigned int IAttackCooldown, unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades);
	irrklang::ISound* snd;
	string getName();
	vec3 dir;
	float angle;
	float currAngle;
	unsigned int maxCooldown;
	unsigned int getCooldown();

	void updateCooldown(unsigned int value);
	void setCooldown(unsigned int value);
	vec3 getUnitPos();
	void updateUnitPos(vec3 newPos);
	void moveTo();
	shared_ptr<Targetable> getTarget();
	void setTarget(shared_ptr<Targetable> currTarget)override; //TODO obsluga myszki
	void setIsPickedUp(bool value);
	bool getIsPickedUp();
	bool targetInRange();//TODO virtual??
	virtual void goToMiningLocation();
	virtual void attack(Targetable* target);
	virtual void mine(MineralField* target);
	virtual void doAction();
	virtual void moveCommand(); //TODO virtual;
	virtual void setHasMinerals(bool);
	virtual bool getHasMinerals();
	virtual void returnMinerals();
	virtual void drawSelf() override;
	virtual ~Unit(); 
	//void updateMovePoints(unsigned int value);
	//unsigned int getMovePoints();
	float getRange();
	vec3 getDestination();
	void setDestination(vec3 location);
	int getCurrentXPos();
	int getCurrentZPos();
	void setCurrentGridPos(int x, int z);
	void setIsMoving(bool);
	bool getIsMoving();
	void calculateVecAngle();
};

