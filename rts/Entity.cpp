#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity(vec3 Vpos)
	:
	pos(Vpos)
{
}

vec3 Entity::getPosition()
{
	return pos;
}

void Entity::setPosition(vec3 Vpos)
{
	pos = Vpos;
}

void Entity::setPosition(GLdouble x, GLdouble y, GLdouble z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}
/*
void Entity::setDestination(GLdouble x, GLdouble y, GLdouble z)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
}
*/

Entity::~Entity()
{

}

ostream & operator<<(ostream & out, const vec3 & pos)
{
	out << "x: " << pos.x << " y: " << pos.y << " z: " << pos.z << endl;
	return out;
}
