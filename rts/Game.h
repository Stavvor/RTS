#pragma once
#include "SoundPlayer.h"

class Game
{
private:
	Grid *grid;
	vector <shared_ptr<Targetable>>entities;
	vector<vec3>mineralLayout;
	SoundPlayer* soundPlayer;
public:
	Game();
	~Game();
	void cleanGlobalDeadEntities();

	void drawTerrain();

	static SCameraState playerCamera;
	static void initCamera();
	vector <shared_ptr<Targetable>>getEntities();
	void spawnMinerals(vector<vec3>);
};

inline void Game::drawTerrain()
{

	//glDisable(GL_LIGHTING);
	glBegin(GL_TRIANGLE_STRIP);

	/*{
			  //.
		
		//.		.
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-30.0f, 0.0f, 130.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(130, 0.0f, 130);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-30, 0.0f, -30);

		
		//.		.

		//.		
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(130.0f, 0.0f, -30.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(130, 0.0f, 130);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-30, 0.0f, -30);
		

		
	}*/

	{
		for(int i=0;i<GRIDSIZE;i++)
		{
			for(int j=0;j<GRIDSIZE;j++)
			{
				
			}
		}
	}


	glEnd();
	//glEnable(GL_LIGHTING);

}

