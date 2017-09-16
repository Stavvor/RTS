#pragma once
class ReconPlane : public UtilityUnit
{
private:

public:
	ReconPlane();
	ReconPlane(string Sname, string Stype, vec3, unsigned int Icooldown, unsigned int, float, float, float, unsigned int* armorUpgrades);
	~ReconPlane();

	void drawSelf() override;
	GLuint chooseIcon() override;
};

