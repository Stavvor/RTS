#pragma once
class MineralField: public Targetable
{
private:
	unsigned int resources;
	unsigned int maxGatherers;
public:
	vector<shared_ptr<Targetable>>targetedBy;
	MineralField();
	MineralField(unsigned int, vec3);
	void setResources(unsigned int);
	unsigned int getResources();

	void drawSelf() override;
	~MineralField();



};

