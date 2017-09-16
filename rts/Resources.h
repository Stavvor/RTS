#pragma once

class Resources
{
private:
	
public:
#pragma region models
	//Mecht1
	static GLuint mechHeadT1;
	static GLuint mechLegsT1;
	static GLuint mechGatlingT1;

	static GLuint mechT1IconR;
	static GLuint mechT1IconY;
	static GLuint mechT1IconG;
	//Mecht2
	static GLuint mechHeadT2;
	static GLuint mechLegsT2;
	static GLuint mechGatlingT2;

	static GLuint mechT2IconR;
	static GLuint mechT2IconY;
	static GLuint mechT2IconG;
	//Tankt1
	static GLuint tankT1;
	static GLuint tankTowerT1;
	static GLuint tankCannonT1;

	static GLuint tankT1Icon;
	//Tankt2
	static GLuint tankT2;
	static GLuint tankTowerT2;
	static GLuint tankCannonT2;
	
	static GLuint tankT2IconR;
	static GLuint tankT2IconY;
	static GLuint tankT2IconG;
	///////
	static GLuint reconPlane;
	static GLuint reconPlaneIcon;

	static GLuint fighterT1;
	static GLuint fighterT1Icon;

	static GLuint fighterT2;
	static GLuint fighterT2Icon;

	static GLuint bomberT1;
	static GLuint bomberT1ICon;

	static GLuint bomberT2;
	static GLuint bomberT2Icon;


	static GLuint worker;
	static GLuint workerIcon;

	static GLuint transporter;
	static GLuint transporterIcon;


	static GLuint factory;

	static GLuint crystals;
	static GLuint crystalsTex;

	static GLuint shadow;
	static GLuint unitCircle;
#pragma endregion

#pragma region tekstury
	//BMP
	static GLuint ground;

	static GLuint mechTexture;
	static GLuint mechHeadT1Tex;
	static GLuint mechLegsT1Tex;
	static GLuint mechGatlingT1Tex;

	static GLuint tankTexture;

	static GLuint buildingTexture;
	static GLuint buildingSteel;
	//PNG
	static GLuint mineralIcon;
	static GLuint energyIcon;
	static GLuint supplyIcon;

	static GLuint overlay;

	static GLuint FloorPNG;
	static GLuint factoryTex;
	static GLuint victory;
#pragma endregion

	static GLuint heightMap;
	static GLuint terrain;

	static vector<vec3> mineralLayout;
	static vector<vec3> enemiesPos;
	

	Resources();
	static GLuint LoadObj(char * file);
	static GLuint LoadTexture(char * file, int magFilter, int minFilter);

	static void loadModels();
	static void loadTextures();


	void loadBMPTextures();

	void loadPNGTextures();
	
	void Initializiation();
	void setLayout();
	~Resources();
};

