#include "stdafx.h"
#include "MechT2.h"


MechT2::MechT2()
{
}

MechT2::MechT2(string Stype, unsigned int Idamage, unsigned int IattackCooldown, float Frange, float FscanRange, string Sname, vec3 Vpos,
	unsigned int IhitPoints, float Fspeed, unsigned int* weaponUpgrades, unsigned int* armorUpgrades, bool value)
	:
	CombatUnit(Stype, Idamage, IattackCooldown, Frange, FscanRange, Sname, Vpos, IhitPoints, Fspeed, weaponUpgrades, armorUpgrades,value)
{
}

MechT2::~MechT2()
{
}

void MechT2::drawSelf()
{
	vec3 temp = this->getPosition();
	glPushMatrix();
	glTranslatef(temp.x, temp.y + 2, temp.z);
	glScalef(2, 2, 2);
	//-2.0f
	//-5.0f
	if (this->getTarget() != NULL)
	{
		float angle = atan2(this->getTarget()->getPosition().x - this->getPosition().x, this->getTarget()->getPosition().z - this->getPosition().z);
		angle = angle * (180 / 3.14);
		glPushMatrix();
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::mechHeadT2);
		glCallList(Resources::mechGatlingT2);
		glPushMatrix();
		glTranslatef(1.5f, 2.2f, 1.7f);
		glutSolidSphere(rand() % 3, 10, 10);
		glTranslatef(-3.0f, 0.0f, 0.0f);
		glutSolidSphere(rand() % 3, 10, 10);
		glPopMatrix();
		glPopMatrix();
		//glCallList(tankT2Wieza);
		//glCallList(tankT2Dzialko);
		glCallList(Resources::mechLegsT2);
		//glCallList(tankT2);
	}
	else
	{
		this->calculateVecAngle();
		glRotatef(this->angle, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::mechLegsT2);
		glCallList(Resources::mechGatlingT2);
		glCallList(Resources::mechHeadT2);


		float rotateAngle = glutGet(GLUT_ELAPSED_TIME)/100;
		float rotate = sin(0.1*rotateAngle);
		glPushMatrix();
		glRotatef(rotate, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::mechGatlingT2);
		glCallList(Resources::mechHeadT2);
		glPopMatrix();
		glCallList(Resources::mechLegsT2);
	}

	//glutWireCube(1.0f);
	glPopMatrix();
}

GLuint MechT2::chooseIcon()
{
	auto hp = this->getNormalizedHitPoints();
	if (hp >= 0.666)
		return Resources::mechT2IconG;
	if (hp > 0.333 && hp < 0.666)
		return Resources::mechT2IconY;
	if (hp <= 0.333)
		return Resources::mechT2IconR;
	return 0;
}