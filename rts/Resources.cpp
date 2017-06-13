#include "stdafx.h"
#include "Resources.h"
#pragma warning (disable : 4996)

GLuint Resources::mechHeadT1;
GLuint Resources::mechLegsT1;
GLuint Resources::mechGatlingT1;

GLuint Resources::mechHeadT2;
GLuint Resources::mechLegsT2;
GLuint Resources::mechGatlingT2;

GLuint Resources::tankT1;
GLuint Resources::tankTowerT1;
GLuint Resources::tankCannonT1;

GLuint Resources::tankT2;
GLuint Resources::tankTowerT2;
GLuint Resources::tankCannonT2;

GLuint reconPlane;

GLuint fighterT1;
GLuint fighterT2;

GLuint bomberT1;
GLuint bomberT2;

GLuint worker;

GLuint transporter;


Resources::Resources()
{
}


Resources::~Resources()
{
}

void Resources::loadModels()
{
	//MechT1

	//MechT2
	mechHeadT2 = LoadObj("resources/glowa.obj");
	mechLegsT2 = LoadObj("resources/nogi.obj");
	mechGatlingT2 = LoadObj("resources/gatling.obj");

	//TankT1

	//TankT2
	tankT2 = LoadObj("resources/TankT2.obj");
	tankTowerT2 = LoadObj("resources/TankT2Wieza.obj");
	tankCannonT2 = LoadObj("resources/TankT2Dzialko.obj");




	//TODO dowac modele na bierzaco
}

void Resources::loadTextures()
{
	
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
		mineralLayout.push_back({ 24.0f,0.0f,20.0f });
		mineralLayout.push_back({ 24.0f,0.0f,15.0f });
		mineralLayout.push_back({ 24.0f,0.0f,10.0f });
}
