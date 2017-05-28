#pragma once
class Targetable;

class Entity
{
private:
	vec3 pos;
	
public:
	Entity();
	Entity(vec3 Vpos);
	//pure virtual//


	//virtual
	virtual bool getIsDead() = 0;
	//functions

	vec3 getPosition();
	void setPosition(vec3 Vpos);
	void setPosition(GLdouble x, GLdouble y, GLdouble z);
	void setDestination(GLdouble x, GLdouble y, GLdouble z);
	//<< op overload
	friend ostream & operator<<(ostream& out, const vec3& pos);

	virtual ~Entity();
};

