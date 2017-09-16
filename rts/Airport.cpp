#include "stdafx.h"
#include "Airport.h"


Airport::Airport()
{
}

Airport::Airport(vec3 VMousePos, unsigned int IHpValue, unsigned int* armorUpgrades)
	:
	Building(VMousePos, IHpValue, armorUpgrades)
{
}
/*
void Airport::train()
{

}
*/

Airport::~Airport()
{
}

void Airport::drawSelf()
{
	glDisable(GL_CULL_FACE);
	vec3 temp = this->getPosition();
	glPushMatrix();


	glTranslatef(temp.x, temp.y, temp.z);
	glScalef(4, 4, 4);

	glCallList(Resources::factory);
	glRotatef(22, 0, 1, 0);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}
