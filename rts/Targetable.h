#pragma once

struct Upgrades {
	unsigned int* weaponUpgradesPtr;
	unsigned int* armorUpgradesPtr;
	Upgrades(unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
		:
		weaponUpgradesPtr(weaponUpgrades),
		armorUpgradesPtr(armorUpgrades)
	{}
	Upgrades(unsigned int* armorUpgrades)
		:
		armorUpgradesPtr(armorUpgrades)
	{}
};

class Targetable :public Entity
{
private:
	unsigned int hitPoints;
	bool isDead;
	string type;
public:
	vector<shared_ptr<Targetable>>targetedBy;
	Upgrades* upgrades;
	Targetable();
	Targetable(vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades);
	Targetable(string Stype, vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades);
	Targetable(string Stype, vec3 Vpos, unsigned int IHitPoints, unsigned int* armorUpgrades, unsigned int* WeaponUpgrades);
	
	//TODO przeladowany konstruktor ogarniajacy budowany typ ze wzgledu na upgrady nie teraz bo jestem pijany
	unsigned int maxHitPoints;

	virtual unsigned int getResources();
	virtual void setResources(unsigned int);
	virtual void attack(Targetable * target);
	void setHitPoints(unsigned int IHitPoints);
	unsigned int getHitPoints();
	void takeDamage(unsigned int value);
	bool getIsDead();
	void setIsDead(bool);
	void addToTargetedby(shared_ptr<Targetable>targetingUnit);
	virtual void setTarget(shared_ptr<Targetable>);
	void onDead();
	string getType();
	virtual ~Targetable();
};

