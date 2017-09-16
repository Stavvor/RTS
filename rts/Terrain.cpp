#include "stdafx.h"
#include "Terrain.h"
#pragma warning (disable : 4996)

Terrain::Terrain()
{
}


Terrain::~Terrain()
{
}

void Terrain::initialization()
{
	//pixelArray= readBMP("resources\\textures\\heightmap.bmp", &mapWidth);
}


GLuint Terrain::generateTerrain()
{

	float ratio = 1;
	float size = 5;

	vec2 posA(0, ratio);
	vec2 posB(ratio, ratio);
	vec2 posC(ratio, 0);
	vec2 posD(0, 0);

	vec2 pos[4] = { posA,posB,posC,posD };

	glTexCoord2f(0, ratio);
	glTexCoord2f(ratio, ratio);
	glTexCoord2f(ratio, 0);
	glTexCoord2f(0, 0);
	//	Rand 0-3	
	srand(time(NULL));
	
	GLuint list;
	list = glGenLists(1);

	glNewList(list, GL_COMPILE);

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Resources::ground);
	for(int i =0; i < 100; i++)
	{
		for(int j = 0; j < 100 ; j ++)
		{
			//int k = rand() % 4;
			int k = 0;
		
			glBegin(GL_QUADS);
			glTexCoord2f(pos[k % 4].x, pos[k % 4].z);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, size);
			k++;

			glTexCoord2f(pos[k % 4].x, pos[k % 4].z);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(size, -1.0f, size);
			k++;

			glTexCoord2f(pos[k % 4].x, pos[k % 4].z);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(size, -1.0f, 0.0f);
			k++;

			glTexCoord2f(pos[k % 4].x, pos[k % 4].z);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, -1.0f, 0.0f);

			glEnd();
			glTranslatef(0, 0, size -0.0001);

		}
		glTranslatef(size - 0.0001, 0, -100* size - 0.0001);

	}

	glEndList();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	return list;


}

unsigned char* Terrain::readBMP(char* filename,int* w)
{
	int i;
	FILE* f = fopen(filename, "rb");
	unsigned char info[54];
	fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

											   // extract image height and width from header
	int width = *(int*)&info[18];
	*w = width;
	int height = *(int*)&info[22];

	int size = 3 * width * height;
	unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
	fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	fclose(f);

	for (i = 0; i < size; i += 3)
	{
		unsigned char tmp = data[i];
		data[i] = data[i + 2];
		data[i + 2] = tmp;
	}

	return data;
}

void Terrain::drawTerrain()
{
		glDisable(GL_LIGHTING);
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, Resources::zycko);
	
		/*
			00	01	02	03
			10	11	12	13
			20	21	22	23
			30	31	32	33
			40	41	42	43
		 */
	
			//for glV
		int degraded;
		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i < GRIDSIZE; i++) {
			for (int j = 0; j < GRIDSIZE; j++) {
				//glTexCoord2f(0, i%2);
				glVertex3f(i, getHeight(pixelArray,i,j), j);
				//glTexCoord2f(1, 0);
				glVertex3f(i+1, getHeight(pixelArray, i, j), j);
				if(j == GRIDSIZE)
					glVertex3f(i+1, 0, j);//TODO sprawdzic
			}
		}
		glEnd();
	
	//	glDisable(GL_TEXTURE_2D);
	glEndList();
		glEnable(GL_LIGHTING);
}

float Terrain::getHeight(unsigned char* ptr,int x, int z)
{
	//data[j * width + i], data[j * width + i + 1] and data[j * width + i + 2]
	float height = ptr[z*mapWidth+x]+ ptr[z*mapWidth + x+1]+ ptr[z*mapWidth + x+2];
	height += maxPixelColor / 2;
	height /= maxPixelColor / 2;
	height *= maxHeight;
		return height/2;
}

