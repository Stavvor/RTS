#pragma once
class Transporter :public UtilityUnit{
private:
	const int maxCapacity=20;
	vector <Unit*> pickedUnits;
public:
	Transporter();
	Transporter(string Sname, string Stype, vec3, unsigned int Icooldown, unsigned int, float, float, float, unsigned int* armorUpgrades);
	~Transporter();
	int capacity;
	void onRecivedRightClick(Unit* target); //TODO ogarnac obsluge myszki;
	void pickUp(Unit* target);
	void dropOff(Unit* target);
	void dropAll(); 

	void drawSelf() override;
	
};

