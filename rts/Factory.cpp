#include "stdafx.h"
#include "Factory.h"


Factory::Factory()
{
	
}


Factory::~Factory()
{
}

Factory::Factory(vec3 VmousePos, unsigned int hpValue, unsigned int* armorUpgrades)
	:
	Building(VmousePos, hpValue, armorUpgrades) //TODO FIX hp
{
}
	

void Factory::takeDamage()
{
	
}

void Factory::drawSelf()
{
	glDisable(GL_CULL_FACE);
	vec3 temp = this->getPosition();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(temp.x, temp.y, temp.z);
	glScalef(4, 4, 4);
	
	glCallList(Resources::factory);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}
