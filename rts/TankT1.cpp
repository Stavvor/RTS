#include "stdafx.h"
#include "TankT1.h"


TankT1::TankT1()
{
}

TankT1::TankT1(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades,value)
{
}

TankT1::~TankT1()
{
}

void TankT1::drawSelf()
{
	vec3 temp = this->getPosition();
	glPushMatrix();
	glTranslatef(temp.x, temp.y + 0.5, temp.z);
	glScalef(0.6, 0.6, 0.6);
	glDisable(GL_CULL_FACE);
	//-2.0f
	//-5.0f
	if (this->getTarget() != NULL)
	{
		float angle = atan2(this->getTarget()->getPosition().x - this->getPosition().x, this->getTarget()->getPosition().z - this->getPosition().z);
		angle = angle * (180 / 3.14);
		glPushMatrix();
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::tankTowerT2);
		glCallList(Resources::tankCannonT2);
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
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

GLuint TankT1::chooseIcon()
{
	auto hp = this->getNormalizedHitPoints();

	if (hp >= 0.666)
		return Resources::tankT2IconG;
	if (hp > 0.333 && hp < 0.666)
		return Resources::tankT2IconY;
	if (hp <= 0.333)
		return Resources::tankT2IconR;
	return 0;
}