#pragma once

class Factory :public Building{
private:
	
public:
	//TODO probably remove... move mechs into factory
	Factory();
	~Factory();
	Factory(vec3 Vpos ,unsigned int IHitPoints, unsigned int* armorUpgrades);
	void takeDamage();
	void drawSelf() override;
	template<typename T>
	void train(unsigned int* weaponUpgrades, unsigned int* armorUpgrades, unsigned int time)
	{
		
	}
	

};

