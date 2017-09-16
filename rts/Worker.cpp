#include "stdafx.h"
#include "Worker.h"

Worker::Worker()
{
	mineralFields = game->entities;
}

Worker::Worker(string Sname, string Stype, vec3 Vpos, unsigned int Icooldown, unsigned int IHitPoints, float FSpeed, float FRange, float FScanRange, unsigned int* armorUpgrades)
	:
	UtilityUnit(Sname, Stype, Vpos, Icooldown, IHitPoints, FSpeed, FRange, FScanRange, armorUpgrades)
{
	headquarters = { 65.0f,0.0f,60.0f };
	currentMineralField = { 0.0f,0.0f,0.0f };
	hasMinerals = false;
	maxCooldown = 200;//TODO adjust
	//myMineral = NULL;
	//myTarget = NULL;
}

Worker::~Worker()
{
}

void Worker::moveCommand()
{
	if(getHasMinerals())
	{
		setDestination(headquarters);
	}
	else
	{
		setDestination(this->getTarget()->getPosition());
	}
}

void Worker::updateMiningCooldown(unsigned int value)
{
	miningCooldown += value;
}

void Worker::setMiningCooldown(unsigned int value)
{
	miningCooldown = value;
}


void Worker::mine(shared_ptr<Targetable> target)
{
		unsigned int test = target->getResources();
		if (target->getResources() <= collectingRate) {
			target->setResources(0);
			target->onDead();
			setTarget(NULL);
			//TODO alert koniec mineralow
			carrying = test;
			hasMinerals = true;
		}
		else
		{
			target->setResources(target->getResources() - collectingRate);
			carrying = collectingRate;
			hasMinerals = true;
		}
}

void Worker::repair(shared_ptr<Targetable> target)
{

}

void Worker::drawSelf()
{
	vec3 temp = this->getPosition();
	glPushMatrix();
	glTranslatef(temp.x, temp.y + 0.5f, temp.z);
	//-2.0f
	//-5.0f
	if (this->getTarget() != NULL)
	{
		float angle = atan2(this->getTarget()->getPosition().x - this->getPosition().x, this->getTarget()->getPosition().z - this->getPosition().z);
		angle = angle*(180 / 3.14);
		glPushMatrix();
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glCallList(Resources::mechHeadT2);
		glCallList(Resources::mechGatlingT2);
		
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
		//glCallList(tankT2);
		//glCallList(tankT2Wieza);
		//glCallList(tankT2Dzialko);
	}

	//glutWireCube(1.0f);
	glPopMatrix();
}


void Worker::doAction()
{
		
		mine(this->getTarget());
	//repair(this->getTarget());
	//TODO rozroznic akcje po celu
}



void Worker::returnMinerals()
{
	if((abs(this->getPosition().x - headquarters.x)>0.5 || abs(this->getPosition().y - headquarters.y)>0.5 || abs(this->getPosition().z - headquarters.z)>0.5))//TODO adjust 0.5
	{ 
		this->setDestination(headquarters);
		this->dir.x = this->getDestination().x - this->getPosition().x;
		this->dir.z = this->getDestination().z - this->getPosition().z;
		float hyp = sqrt(this->dir.x*this->dir.x + this->dir.z*this->dir.z);
		this->dir.x /= hyp;
		this->dir.z /= hyp;	
	}
	else
	{
		player->updateResources(carrying);
		hasMinerals = false;
		carrying = 0;
	}
}

void Worker::goToMiningLocation()
{
	currentMineralField = this->getTarget()->getPosition();
	if (abs(this->getPosition().x - currentMineralField.x)>0.5 || abs(this->getPosition().y -currentMineralField.y)>0.5 || abs(this->getPosition().z - currentMineralField.z)>0.5)//TODO adjust 0.5
	{
		this->setDestination(currentMineralField);
		this->dir.x = this->getDestination().x - this->getPosition().x;
		this->dir.z = this->getDestination().z - this->getPosition().z;
		float hyp = sqrt(this->dir.x*this->dir.x + this->dir.z*this->dir.z);
		this->dir.x /= hyp;
		this->dir.z /= hyp;
	}
	else
	{
		this->updateMiningCooldown(1);
		if (miningCooldown >= maxCooldown+rand()%150 && this->getTarget() != NULL) {
			this->mine(this->getTarget());

			this->setMiningCooldown(0);
		}
		else if (miningCooldown >= 2 * maxCooldown)
			this->setMiningCooldown(maxCooldown);
	}
}

bool Worker::getHasMinerals()
{
	return hasMinerals;
}
void Worker::setHasMinerals(bool v)
{
	hasMinerals = v;
}

GLuint Worker::chooseIcon()
{
	auto hp = this->getNormalizedHitPoints();
	if (hp >= 0.666)
		; //TODO Update
		  //return Resources::BomberT1IconG;
	if (hp < 0.333 && hp < 0.666)
		;
	//return Resources::BomberT1IconY;
	if (hp <= 0.333)
		;
	//return Resources::BomberT1IconR;
	return 0;
}

void Worker::miningOrder()
{
	
}
