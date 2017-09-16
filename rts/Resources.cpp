#include "stdafx.h"
#include "Resources.h"
#pragma warning (disable : 4996)

//Mecht1
GLuint Resources::mechHeadT1;
GLuint Resources::mechLegsT1;
GLuint Resources::mechGatlingT1;

GLuint Resources::mechT1IconR;
GLuint Resources::mechT1IconY;
GLuint Resources::mechT1IconG;



GLuint Resources::mechHeadT2;
GLuint Resources::mechLegsT2;
GLuint Resources::mechGatlingT2;

GLuint Resources::mechT2IconR;
GLuint Resources::mechT2IconY;
GLuint Resources::mechT2IconG;

//Tank1
GLuint Resources::tankT1;
GLuint Resources::tankTowerT1;
GLuint Resources::tankCannonT1;

GLuint Resources::tankT1Icon;
//Tank2
GLuint Resources::tankT2;
GLuint Resources::tankTowerT2;
GLuint Resources::tankCannonT2;

GLuint Resources::tankT2IconR;
GLuint Resources::tankT2IconY;
GLuint Resources::tankT2IconG;

GLuint Resources::reconPlane;
GLuint Resources::reconPlaneIcon;

GLuint Resources::fighterT1;
GLuint Resources::fighterT1Icon;

GLuint Resources::fighterT2;
GLuint Resources::fighterT2Icon;

GLuint Resources::bomberT1;
GLuint Resources::bomberT1ICon;

GLuint Resources::bomberT2;
GLuint Resources::bomberT2Icon;

GLuint Resources::worker;
GLuint Resources::workerIcon;

GLuint Resources::transporter;
GLuint Resources::transporterIcon;

GLuint Resources::factory;

GLuint Resources::crystals;
GLuint Resources::crystalsTex;

GLuint Resources::shadow;
GLuint Resources::unitCircle;

#pragma region tekstury
//BMP
GLuint Resources::ground;
GLuint Resources::factoryTex;

GLuint Resources::mechTexture;
GLuint Resources::mechHeadT1Tex;
GLuint Resources::mechLegsT1Tex;
GLuint Resources::mechGatlingT1Tex;

GLuint Resources::tankTexture;

GLuint Resources::buildingTexture;
GLuint Resources::buildingSteel;
//PNG
GLuint Resources::mineralIcon;
GLuint Resources::energyIcon;
GLuint Resources::supplyIcon;

GLuint Resources::overlay;

GLuint Resources::FloorPNG;
#pragma endregion

#pragma region inne
GLuint Resources::heightMap;
GLuint Resources::terrain;
GLuint Resources::victory;
#pragma endregion

vector<vec3> Resources::mineralLayout;
vector<vec3> Resources::enemiesPos;

Resources::Resources()
{
}


Resources::~Resources()
{
}

void Resources::loadModels()
{
	//HQ
	
	//Factory
	factory= LoadObj("resources/models/Factory.obj");
	//Airport

	//Generator

	//Worker

	//Transporter

	//ReconPlane
	reconPlane = LoadObj("resources/models/reconPlane.obj");
	//MechT1

	//MechT2
	mechHeadT2 = LoadObj("resources/models/glowa.obj");
	mechLegsT2 = LoadObj("resources/models/nogi.obj");
	mechGatlingT2 = LoadObj("resources/models/gatling.obj");

	//TankT1

	//TankT2
	tankT2 = LoadObj("resources/models/TankT2.obj");
	tankTowerT2 = LoadObj("resources/models/TankT2Wieza.obj");
	tankCannonT2 = LoadObj("resources/models/TankT2Dzialko.obj");

	//FighterT1

	//FighterT2


	//BomberT1

	//BomberT2

	crystals = LoadObj("resources/models/crystals.obj");
	
	shadow = LoadObj("resources/models/shadow.obj");
	unitCircle = LoadObj("resources/models/unitCircle.obj");

	//TODO dowac modele na bierzaco
}

void Resources::loadBMPTextures()
{
	ground = LoadTexture("resources\\textures\\terrainGrey.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	factoryTex= LoadTexture("resources\\textures\\factoryTex.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	buildingSteel = LoadTexture("resources\\textures\\factoryTex.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	crystalsTex= LoadTexture("resources\\textures\\crystals1.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	mechTexture= LoadTexture("resources\\textures\\mechTexture.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	mechHeadT1Tex=LoadTexture("resources\\textures\\mechGoraTex.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	mechLegsT1Tex=LoadTexture("resources\\textures\\mechNogiTex.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	//mechGatlingT1Tex=LoadTexture("resources\\textures\\mechTexture.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	tankTexture=LoadTexture("resources\\textures\\tankTexture.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	buildingTexture= LoadTexture("resources\\textures\\buildingTexture.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
}

void Resources::loadPNGTextures()
{
	Texture texture;
	texture.Load("resources\\textures\\Floor.png", GL_RGBA);
	FloorPNG = texture.GetID();

	texture.Load("resources\\textures\\heightmap.png", GL_RGB);
	heightMap = texture.GetID();

	texture.Load("resources\\textures\\mineralIcon.png", GL_RGBA);
	mineralIcon = texture.GetID();

	texture.Load("resources\\textures\\energyIcon1.png", GL_RGBA);
	energyIcon = texture.GetID();

/*	texture.Load("resources\\textures\\supplyIcon.png", GL_RGBA);
	supplyIcon = texture.GetID();

	texture.Load("resources\\textures\\overlay.png", GL_RGBA);
	overlay = texture.GetID();*/

	texture.Load("resources\\textures\\mechT2IconR.png", GL_RGBA);
	mechT2IconR = texture.GetID();

	texture.Load("resources\\textures\\mechT2IconY.png", GL_RGBA);
	mechT2IconY = texture.GetID();

	texture.Load("resources\\textures\\mechT2IconG.png", GL_RGBA);
	mechT2IconG = texture.GetID();

	texture.Load("resources\\textures\\tankT2IconR.png", GL_RGBA);
	tankT2IconR = texture.GetID();

	texture.Load("resources\\textures\\tankT2IconY.png", GL_RGBA);
	tankT2IconY = texture.GetID();

	texture.Load("resources\\textures\\tankT2IconG.png", GL_RGBA);
	tankT2IconG = texture.GetID();
	
	texture.Load("resources\\textures\\victory.png", GL_RGBA);
	victory = texture.GetID();
}
void Resources::Initializiation()
{
	loadModels();
	loadBMPTextures();
	loadPNGTextures();
}

GLuint Resources::LoadTexture(char * file, int magFilter, int minFilter) {

	// Odczytanie bitmapy
	Bitmap *tex = new Bitmap();
	if (!tex->loadBMP(file)) {
		printf("ERROR: Cannot read texture file \"%s\".\n", file);
		return -1;
	}

	// Utworzenie nowego id wolnej tekstury
	GLuint texId;
	glGenTextures(1, &texId);

	// "Bindowanie" tekstury o nowoutworzonym id
	glBindTexture(GL_TEXTURE_2D, texId);

	// Okreœlenie parametrów filtracji dla tekstury
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter); // Filtracja, gdy tekstura jest powiêkszana
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter); // Filtracja, gdy tekstura jest pomniejszana

																	  // Wys³anie tekstury do pamiêci karty graficznej zale¿nie od tego, czy chcemy korzystaæ z mipmap czy nie
	if (minFilter == GL_LINEAR_MIPMAP_LINEAR || minFilter == GL_LINEAR_MIPMAP_NEAREST) {
		// Automatyczne zbudowanie mipmap i wys³anie tekstury do pamiêci karty graficznej
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, tex->width, tex->height, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
	}
	else {
		// Wys³anie tekstury do pamiêci karty graficznej 
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->width, tex->height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex->data);
	}

	// Zwolnienie pamiêci, usuniêcie bitmapy z pamiêci - bitmapa jest ju¿ w pamiêci karty graficznej
	delete tex;

	// Zwrócenie id tekstury
	return texId;
}


GLuint Resources::LoadObj(char * file) {

	FILE * fp = fopen(file, "r");

	if (fp == NULL) {
		printf("ERROR: Cannot read model file \"%s\".\n", file);
		return -1;
	}

	std::vector<vec3> * v = new std::vector<vec3>();
	std::vector<vec3> * n = new std::vector<vec3>();
	std::vector<vec3> * t = new std::vector<vec3>();
	std::vector<SFace> * f = new std::vector<SFace>();

	char buf[128];

	while (fgets(buf, 128, fp) != NULL) {
		if (buf[0] == 'v' && buf[1] == ' ') {
			vec3 * vertex = new vec3();
			sscanf_s(buf, "v %f %f %f", &vertex->x, &vertex->y, &vertex->z);
			v->push_back(*vertex);
		}
		if (buf[0] == 'v' && buf[1] == 't') {
			vec3 * vertex = new vec3();
			sscanf_s(buf, "vt %f %f", &vertex->x, &vertex->y);
			t->push_back(*vertex);
		}
		if (buf[0] == 'v' && buf[1] == 'n') {
			vec3 * vertex = new vec3();
			sscanf_s(buf, "vn %f %f %f", &vertex->x, &vertex->y, &vertex->z);
			n->push_back(*vertex);
		}
		if (buf[0] == 'f' && buf[1] == ' ') {
			SFace * face = new SFace();
			sscanf_s(buf, "f %d/%d/%d %d/%d/%d %d/%d/%d",
				&face->v[0], &face->t[0], &face->n[0],
				&face->v[1], &face->t[1], &face->n[1],
				&face->v[2], &face->t[2], &face->n[2]
			);
			f->push_back(*face);
		}
	}

	fclose(fp);

	GLuint dlId;
	dlId = glGenLists(1);

	glNewList(dlId, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < f->size(); ++i) {
		for (int j = 0; j < 3; ++j) {

			vec3 * cv = &(*v)[((*f)[i].v[j] - 1)];
			vec3 * ct = &(*t)[((*f)[i].t[j] - 1)];
			vec3 * cn = &(*n)[((*f)[i].n[j] - 1)];

			glTexCoord2f(ct->x, ct->y);
			glNormal3f(cn->x, cn->y, cn->z);
			glVertex3f(cv->x, cv->y, cv->z);
		}
	}
	glEnd();
	glEndList();
	delete v;
	delete n;
	delete t;
	delete f;

	return dlId;

}

void Resources::setLayout()
{
		mineralLayout.push_back({ 63.0f,0.0f,30.0f });
		mineralLayout.push_back({ 55.0f,0.0f,35.0f });
		mineralLayout.push_back({ 45.0f,0.0f,40.0f });
		mineralLayout.push_back({ 38.0f,0.0f,47.0f });
		mineralLayout.push_back({ 35.0f,0.0f,57.0f });

		enemiesPos.push_back({ 170.0f,0.0f,170.0f });
		enemiesPos.push_back({ 150.0f,0.0f,150.0f });
		enemiesPos.push_back({ 140.0f,0.0f,150.0f });
		enemiesPos.push_back({ 150.0f,0.0f,140.0f });
		enemiesPos.push_back({ 110.0f,0.0f,140.0f });

}
