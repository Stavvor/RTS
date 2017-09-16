#pragma once
class CombatUnit :public Unit {
private:
	unsigned int damage;
	unsigned int killCount;
	float scanRange;
	//
	
public:
	CombatUnit();
	CombatUnit(string SType, unsigned int Idamage, unsigned int IAttackCooldown, float, float, string Sname, vec3 Vpos, unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades,bool enemy);
	virtual ~CombatUnit();
	void doAction();
	void scan();
	void attack(shared_ptr<Targetable>  target);
	//virtual void updateKillCount(); //TODO czy potrzeba funkcji? :|
	

	virtual void drawSelf() override;
};

