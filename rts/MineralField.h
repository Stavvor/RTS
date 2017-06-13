#pragma once
class MineralField: public Targetable
{
private:
	unsigned int resources;
public:
	MineralField();
	MineralField(unsigned int, vec3);
	void setResources(unsigned int);
	unsigned int getResources();

	~MineralField();

	void drawSelf() override;

};

