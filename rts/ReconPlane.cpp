#include "stdafx.h"
#include "ReconPlane.h"


ReconPlane::ReconPlane()
{
}

ReconPlane::ReconPlane(string Sname, string Stype, vec3 Vpos, unsigned int Icooldown, unsigned int IHitPoints, float FSpeed, float FRange, float FScanRange, unsigned int* armorUpgrades)
	:
	UtilityUnit(Sname, Stype, Vpos, Icooldown, IHitPoints, FSpeed, FRange, FScanRange, armorUpgrades)
{
	maxCooldown = 200;//TODO adjust
					  //myMineral = NULL;
					  //myTarget = NULL;
}

ReconPlane::~ReconPlane()
{
}

void ReconPlane::drawSelf()
{
	vec3 temp = this->getPosition();

	glPushMatrix();
	this->calculateVecAngle();

	glTranslatef(temp.x, temp.y+5, temp.z);
	glRotatef(this->angle, 0.0f, 1.0f, 0.0f);
	glScalef(4,4,4);
	glCallList(Resources::reconPlane);

	glPopMatrix();
}

GLuint ReconPlane::chooseIcon()
{
	auto hp = this->getNormalizedHitPoints();

	if (hp >= 0.666)
		;
		//return Resources::tankT2IconG;
	if (hp < 0.333 && hp < 0.666)
		;
		//return Resources::tankT2IconY;
	if (hp <= 0.333)
		;
		//return Resources::tankT2IconR;
	return 0;
}
