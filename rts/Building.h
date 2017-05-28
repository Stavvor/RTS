#pragma once
class Building :public Targetable{
private:
	string name;
	queue<Unit*>productionQueue;
	vec3 rallyPoint;
	unsigned int productionTime;
public:
	Building();
	Building(vec3 Vpos ,unsigned int IHitPoints, unsigned int* armorUpgrades);
	unsigned int totalProductionTime;
	queue<Unit*>* getProductionQueue();
	unsigned int getProductionTime();
	void setProductionTime(unsigned int);
	void updateProductionTime(unsigned int);
	virtual void queueUnit(unsigned int* armorUpgrades, unsigned int* weaponUpgrades);
	virtual void train(unsigned int* weaponUpgrades, unsigned int* armorUpgrades, unsigned int time)=0;
	//virtual Unit* train(unsigned int* armorUpgrades) = 0;			//przeladowana funkcja do utilityUnitow..
	void setRallyPoint(vec3 mousePos);
	virtual ~Building();
};

