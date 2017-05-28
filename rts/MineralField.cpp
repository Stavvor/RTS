#include "stdafx.h"
#include "MineralField.h"


MineralField::MineralField()
{
	resources=50;
}

MineralField::MineralField(unsigned int IResources, vec3 Vpos)
	:
	resources(IResources),
	position(Vpos)
{
	isEmpty = false;
}

void MineralField::setResources(unsigned int IResources)
{
	if (IResources == 0)
		isEmpty = true;
	resources = IResources;
}

unsigned int MineralField::getResources()
{
	return resources;
}

MineralField::~MineralField()
{
}
