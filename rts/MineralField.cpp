#include "stdafx.h"
#include "MineralField.h"


MineralField::MineralField()
{
	resources=1000;//TODO fix
	maxGatherers = 4;
}

MineralField::MineralField(unsigned int IResources, vec3 Vpos)
	:
	Targetable(Vpos),
	resources(IResources)
{
	maxGatherers = 4;
}

void MineralField::setResources(unsigned int IResources)
{
	if (IResources == 0)
		this->setIsDead(true);
	resources = IResources;
}

unsigned int MineralField::getResources()
{
	return resources;
}


MineralField::~MineralField()
{
}

void MineralField::drawSelf()
{
	vec3 temp = this->getPosition();
	glPushMatrix();
	
	glTranslatef(temp.x, temp.y, temp.z);
	glScalef(0.5, 0.5, 0.5);
	glCallList(Resources::crystals);
	glPopMatrix();
}
