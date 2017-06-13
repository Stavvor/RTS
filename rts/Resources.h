#pragma once
#include "Game.h"


class Resources
{
private:
	
public:
#pragma region models
	//Mecht1
	static GLuint mechHeadT1;
	static GLuint mechLegsT1;
	static GLuint mechGatlingT1;
	//Mecht2
	static GLuint mechHeadT2;
	static GLuint mechLegsT2;
	static GLuint mechGatlingT2;
	//Tankt1
	static GLuint tankT1;
	static GLuint tankTowerT1;
	static GLuint tankCannonT1;
	//Tankt2
	static GLuint tankT2;
	static GLuint tankTowerT2;
	static GLuint tankCannonT2;
	

	static GLuint reconPlane;

	static GLuint fighterT1;
	static GLuint fighterT2;

	static GLuint bomberT1;
	static GLuint bomberT2;

	static GLuint worker;

	static GLuint transporter;
#pragma endregion

#pragma region tekstury

#pragma endregion




	vector<vec3> mineralLayout;
	vector<vec3> enemiesPos;

	Resources();
	~Resources();
	static void loadModels();
	static void loadTextures();
	
	static GLuint LoadObj(char * file);


	void setLayout();
	
};

