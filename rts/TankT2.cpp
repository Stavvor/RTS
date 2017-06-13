#include "stdafx.h"
#include "TankT2.h"

TankT2::TankT2()
{
}

TankT2::TankT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades)
{
}

TankT2::~TankT2()
{
}

void TankT2::drawSelf()
{
	vec3 temp = this->getPosition();
	glPushMatrix();
	glTranslatef(temp.x, temp.y, temp.z);
	//-2.0f
	//-5.0f
	if (this->getTarget() != NULL)
	{
		float angle = atan2(this->getTarget()->getPosition().x - this->getPosition().x, this->getTarget()->getPosition().z - this->getPosition().z);
		angle = angle*(180 / 3.14);
		glPushMatrix();
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::tankTowerT2);
		glCallList(Resources::tankCannonT2);
		glPushMatrix();
		glTranslatef(1.5f, 2.2f, 1.7f);
		glutSolidSphere(rand() % 3, 10, 10);
		glTranslatef(-3.0f, 0.0f, 0.0f);
		glutSolidSphere(rand() % 3, 10, 10);
		glPopMatrix();
		glPopMatrix();
		
		glCallList(Resources::tankT2);
	}
	else
	{
		this->calculateVecAngle();
		glRotatef(this->angle, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::tankT2);
		glCallList(Resources::tankTowerT2);
		glCallList(Resources::tankCannonT2);
	}

	//glutWireCube(1.0f);
	glPopMatrix();
}
