#pragma once


class Worker :public UtilityUnit
{
private:
	unsigned int collectingRate = 5;
	unsigned int repairRate = 5; //TODO adjust
	
	vec3 currentMineralField;
	vec3 headquarters;
	bool hasMinerals;
	unsigned int carrying;
	//MineralField* myMineral;
	//Targetable* myTarget;
public:
	unsigned int miningCooldown;
	void doAction();
	void returnMinerals() override;
	Worker();
	Worker(string Sname, string Stype, vec3, unsigned int Icooldown ,unsigned int, float, float, float, unsigned int* armorUpgrades);
	~Worker();
	void moveCommand() override; //TODO virtual;
	void updateMiningCooldown(unsigned int);
	void setMiningCooldown(unsigned int);
	void goToMiningLocation() override;
	bool getHasMinerals() override;
	void setHasMinerals(bool) override;


	//TODO jak rozwiazac budowanie
	void mine(shared_ptr<Targetable>) override;
	void repair(shared_ptr<Targetable> target) override;

	void drawSelf() override;

};
