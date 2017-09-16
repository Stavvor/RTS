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
	void train(unsigned* weaponUpgrades, unsigned* armorUpgrades, unsigned time, string SType, unsigned int Idamage,
		unsigned int IAttackCooldown, float Frange, float FScanRange, string Sname, unsigned int IhitPoints, float Fspeed,bool value)
	{
		Unit* temp;
		auto pos = getPosition();
		vec3 newPos = { pos.x, pos.y,pos.z };
		temp = new T(SType, Idamage, IAttackCooldown, Frange, FScanRange, Sname, newPos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades,value); //TODO adjust parameters
		//string name, string Stype, vec3 position, unsigned int ICooldoown, unsigned int hitPoints, float speed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades
		this->getProductionQueue()->push(temp);
		totalProductionTime = time;
	}
	//Unit(string Sname,string Stype, vec3 Vpos, unsigned int ICooldown, unsigned int IhitPoints, float Fspeed, float Frange, unsigned int* armorUpgrades)
	template<typename T>
	void trainUtility(unsigned* armorUpgrades, unsigned time, string Sname, string Stype, unsigned int Icooldown,
		unsigned int IHitPoints, float speed, float range, float scanRange)
	{
		Unit* temp;
		auto pos = getPosition();
		vec3 newPos = { pos.x+6, pos.y,pos.z-20 };
		temp = new T(Sname, Stype, newPos, Icooldown, IHitPoints, speed, range, scanRange, armorUpgrades); //TODO different constructors
																												  //string name, string Stype, vec3 position, unsigned int ICooldoown, unsigned int hitPoints, float speed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades
		this->getProductionQueue()->push(temp);
		totalProductionTime = time;
	}
	virtual void updateCooldown(unsigned int);
	//virtual Unit* train(unsigned int* armorUpgrades) = 0;			//przeladowana funkcja do utilityUnitow..
	void setRallyPoint(vec3 mousePos);
	virtual ~Building();
};

