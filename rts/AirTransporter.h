#pragma once
#include "UtilityUnit.h"
class AirTransporter :public UtilityUnit{
private:
	const int maxCapacity=20;
	vector <Unit*> pickedUnits;
public:
	AirTransporter();
	int capacity;
	void onRecivedRightClick(Unit* target); //TODO ogarnac obsluge myszki;
	void pickUp(Unit* target);
	void dropOff(Unit* target);
	void dropAll(); 
	virtual ~AirTransporter();
};

