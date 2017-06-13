#include "stdafx.h"
#include "Transporter.h"


Transporter::Transporter()
{
}

Transporter::Transporter(string Sname, string Stype, vec3 Vpos, unsigned int Icooldown, unsigned int IHitPoints, float FSpeed, float FRange, float FScanRange, unsigned int* armorUpgrades)
	:
	UtilityUnit(Sname, Stype, Vpos, Icooldown, IHitPoints, FSpeed, FRange, FScanRange, armorUpgrades)
{

}

void Transporter::onRecivedRightClick(Unit * target)
{
	//pickUp(target);
}
/**/
void Transporter::pickUp(Unit * target)
{
	//TODO zrobic limit podniesionych jednostek
	//cout << typeid(target).name() << endl;	wtf
	//string a = typeid(target).name();			WTFFFF  if (typeid(target)=="class Unit *" )?
													  //if (typeid(target)=="class Unit *\n" )?
	if (typeid(target)==typeid(Unit*)){ //czy potrzebne po zmienieniu struktury dziedziczenia?
	pickedUnits.push_back(target);
	target->setIsPickedUp(true);
	}
}

void Transporter::dropOff(Unit * target)
{
	if (pickedUnits.empty())
		return; //TODO komunikat transporter jest pusty..
	for(int i=0;i<pickedUnits.size();i++)
		if (pickedUnits.at(i) == target) {
			target->setIsPickedUp(false);
			target->setPosition(this->getPosition());
		}
			
}	

void Transporter::dropAll()
{
	if (pickedUnits.empty())
		return;	//TODO komunikat transporter jest pusty..
	
	for (int i = 0; i < pickedUnits.size(); i++) {
		if (typeid(pickedUnits.at(i)) == typeid(Unit*)) {
			pickedUnits.at(i)->setIsPickedUp(false);
			pickedUnits.at(i)->setPosition(this->getPosition());
		}
	}
	/**/
}

void Transporter::drawSelf()
{
}


Transporter::~Transporter()
{
}
