#include "stdafx.h"
#include "Generator.h"

Generator::Generator()
{
}

Generator::Generator(vec3 VMousePos, unsigned int IHpValue, unsigned int* armorUpgrades)
	:
	Building(VMousePos, IHpValue, armorUpgrades)
{
	cooldown = 0;
	maxCooldown = 100;//TODO fix
}
/*
void Generator::train()
{
}
*/
Generator::~Generator()
{
}

void Generator::updateCooldown(unsigned int value)
{
	cooldown += value;
	if(cooldown>=maxCooldown)
	{
		player->updateEnergy(4);
		cooldown = 0;
	}
	
}

void Generator::drawSelf()
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
