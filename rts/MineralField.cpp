#include "stdafx.h"
#include "MineralField.h"


MineralField::MineralField()
{
	resources=50;//TODO fix
}

MineralField::MineralField(unsigned int IResources, vec3 Vpos)
	:
	Targetable(Vpos),
	resources(IResources)
{
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
}
