#pragma once
class ResourceManager
{
private:
	int resources;
	int energy;
	
public:
	ResourceManager();
	
	int _txtFrame;
	bool notEnough;

	void txtFrame();
	bool buildCommand(int mineralCost, int energyCost);
	void repairTick();
	void updateResources();
	void subtractResources(int mineralValue, int energyValue);

	~ResourceManager();
};