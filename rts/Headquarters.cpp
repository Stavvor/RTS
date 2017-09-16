#include "stdafx.h"
#include "Headquarters.h"


Headquarters::Headquarters()
{
}

Headquarters::Headquarters(vec3 VmousePos, unsigned int hpValue, unsigned int* armorUpgrades)
	:
	Building(VmousePos, hpValue, armorUpgrades) //TODO FIX hp
{
}

Headquarters::~Headquarters()
{
}

void Headquarters::drawSelf()
{
	//glDisable(GL_LIGHTING);
	//glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	vec3 temp = this->getPosition();
	glPushMatrix();

	
	glTranslatef(temp.x, temp.y, temp.z);
	glScalef(4, 4, 4);
	glColor3f(0, 0, 1);
	glCallList(Resources::factory);
	glRotatef(22, 0, 1, 0);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_TEXTURE_2D);
}
