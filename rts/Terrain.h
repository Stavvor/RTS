#pragma once
class Terrain
{
private:
	GLuint terrain;
	const float maxHeight=30;
	const float maxPixelColor=256*256*256;
	unsigned char* pixelArray;
	int mapWidth;
public:
	Terrain();
	~Terrain();
	void initialization();	//TODO pamietac
	GLuint generateTerrain();
	unsigned char* ReadBMP(char* filename);
	void drawTerrain();
	float getHeight(unsigned char*,int x, int z);
	unsigned char* readBMP(char* filename, int* w);

	
	//getHight(int x, int z,);
};

