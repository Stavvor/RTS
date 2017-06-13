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
	template<typename T>
	void train(unsigned* weaponUpgrades, unsigned* armorUpgrades, unsigned time)
	{
		Unit* temp;
		temp = new T("Infantry", 8, 50, 20, 7, "Soldier", getPosition(), 50, 0.5, weaponUpgrades, armorUpgrades); //TODO adjust parameters
		//string name, string Stype, vec3 position, unsigned int ICooldoown, unsigned int hitPoints, float speed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades
		this->getProductionQueue()->push(temp);
		totalProductionTime = time;
	}
	virtual void updateCooldown(unsigned int);
	//virtual Unit* train(unsigned int* armorUpgrades) = 0;			//przeladowana funkcja do utilityUnitow..
	void setRallyPoint(vec3 mousePos);
	virtual ~Building();
};

