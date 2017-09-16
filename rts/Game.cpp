#include "stdafx.h"
#include "Game.h"

SCameraState Game::playerCamera;

Game::Game()
{
	grid = new Grid;
	soundPlayer = new SoundPlayer;
	terrainPtr = new Terrain();
	weaponUpgrades = 2;
	armorUpgrades = 2;
	finished = false;
}


Game::~Game()
{
	delete grid;
	delete soundPlayer;
	delete terrainPtr;

	
}
void Game::initialization()
{
	menu = true;
	standard = false;	//gamemode
	defense = false;	//^	

	soundPlayer->loadAllSounds();

	Resources::terrain = terrainPtr->generateTerrain();

	soundPlayer->playSound(soundPlayer->terran1);
	this->spawnMinerals(Resources::mineralLayout);
	this->spawnEnemies(Resources::enemiesPos);	//TODO spawnowac
}

void Game::cleanGlobalDeadEntities()
{
	for (int i = 0; i < entities.size(); i++) {
		if (entities.at(i)->getIsDead()) {
			entities.at(i).reset();
			entities.erase(entities.begin() + i);
		}
	}

	for (int i = 0; i < enemies.size(); i++) {
		if (enemies.at(i)->getIsDead()) {
			enemies.at(i).reset();
			enemies.erase(enemies.begin() + i);
		}
	}

}

void Game::drawResourcesIcons()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 32, 32, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
	// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
	glBindTexture(GL_TEXTURE_2D, Resources::mineralIcon);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTranslatef(25.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(0.9f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(0.9f, 1.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.5f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Resources::energyIcon);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTranslatef(2.5f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(0.9f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(0.9f, 1.5f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.5f);
	glEnd();

	glDisable(GL_BLEND);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Game::drawUnitIcons()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 32, 32, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTranslatef(5.0f, 25.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	//glTranslatef(0.0f, 0.0f, 30.0f);
	// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
	auto vec = player->getSelectedUnits();
	//for (int i = 0; i<10; i++)
	//{
		for (int j = 0; j<vec.size(); j++)
		{
			glTranslatef(1.0f, 0.0f, 0.0f);
			glBindTexture(GL_TEXTURE_2D, vec[j]->chooseIcon());
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex2f(0.9f, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex2f(0.9f, 1.5f);
			glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 1.5f);
			
			glEnd();
			if(j % 9==0 && j!=0)
			{
				glTranslatef(-10.0f,2.0f, 0.0f);
				//glTranslatef(-1.0f, 1.0f, 0.0f);
				//glTranslatef(-2.0f, 0.0f, 0.0f);
			}
		}
	//}
	



	glDisable(GL_BLEND);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

void Game::drawMinimap()
{
	//player->grid;
}

void Game::drawUI()
{
	drawResourcesIcons();
	drawUnitIcons();
	//drawMinimap();

	//TODO targeted/ not targeted
	//draw buidling menu
	//draw units menu

	//TODO upgrades icons

}
void Game::drawVictoryScreen()
{
	drawResourcesIcons(true);
	drawUnitIcons();
}
void Game::drawHealthbars(vector<shared_ptr<Unit>>units)
{
	for (auto unit : units)
	{
		glDisable(GL_LIGHTING);
		auto pos = unit->getPosition();
		glPushMatrix();
		float hp = unit->getNormalizedHitPoints();

		if (hp >= 0.666)
			glColor3f(0, 1, 0);
		if (hp > 0.333 && hp<0.666)
			glColor3f(1, 1, 0);
		if (hp <= 0.333)
			glColor3f(1, 0, 0);

		glTranslatef(pos.x , pos.y + 4, pos.z - 0.125);
		glRotatef(225, 0, 1, 0);

		//glRotatef(90, 0, 0, 1);
		const int numDiv = 10;
		const float sep = 0.04;
		float barHeight = 0.50 / (float)numDiv;

		glBegin(GL_QUADS);
		for (float i = 0; i < hp; i += (sep + barHeight)) {

			glVertex2f(0, i);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex2f(1, i);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex2f(1, i + barHeight);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex2f(0, i + barHeight);
			glNormal3f(0.0f, 0.0f, -1.0f);

		}
		glEnd();

		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}
void Game::drawStatistics(int oldTimeSinceStart, int w, int h)
{
	
}

void Game::drawGameplay()
{
	gluLookAt(
		Game::playerCamera.pos.x, Game::playerCamera.pos.y, Game::playerCamera.pos.z, // Pozycja kamery
		Game::playerCamera.pos.x + Game::playerCamera.dir.x, Game::playerCamera.pos.y + Game::playerCamera.dir.y, Game::playerCamera.pos.z + Game::playerCamera.dir.z, // Punkt na ktory patrzy kamera (pozycja + kierunek)
		0.0f, 1.0f, 0.0f // Wektor wyznaczajacy pion
	);

	glPushMatrix();
	glCallList(Resources::terrain);
	glPopMatrix();

	for (auto min : this->getGameEntities())
	{
		if (!min->getIsDead())
		{
			glEnable(GL_TEXTURE_2D);
			// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBindTexture(GL_TEXTURE_2D, Resources::crystalsTex);
			vec3 temp = min->getPosition();
			min->drawSelf();
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		}

	}

	for (auto worker : player->getMyWorkers())
	{

		//glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBindTexture(GL_TEXTURE_2D, Resources::mineralIcon);
		if (!worker->getIsDead())
		{
			worker->drawSelf();
		}
	}
	for (auto unit : player->getMyUnits())
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBindTexture(GL_TEXTURE_2D, Resources::mineralIcon); 
		if (!unit->getIsDead())
		{
			unit->drawSelf();
		}
		
		//cout << unit->getPosition().y << endl;
	}

	for (auto enemy : this->getEnemies())
	{
		auto pos = enemy->getPosition();

		glEnable(GL_TEXTURE_2D);
		// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBindTexture(GL_TEXTURE_2D, Resources::mechTexture);	
		if (!enemy->getIsDead())
			enemy->drawSelf();
		//cout << unit->getPosition().y << endl;
		glDisable(GL_TEXTURE_2D);
	}


	for (auto building : player->getMyBuildings())
	{
		glEnable(GL_TEXTURE_2D);
		//Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, Resources::buildingTexture);
		if (!building->getIsDead())
			building->drawSelf();
		glDisable(GL_TEXTURE_2D);
		
	}

	drawHealthbars(player->getMyUnits());
	drawHealthbars(this->enemies);

	GLfloat m[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	IsFinished();
	if (!getFinished())
		this->drawUI();
	else drawVictoryScreen();
	glLoadMatrixf(m);

}

void Game::drawMenu()
{
	//

}

void Game::IsFinished()
{
	if (enemies.size() == 0)
		finished = true;
}

void Game::setFinished()
{
	finished = true;
}
void Game::render()
{
	//manageMenu();


	if(menu)
	{
		this->drawMenu();
	}
	if(standard||defense)
	{	
			gameStatistics();
			//drawVictoryScreen();
			this->drawGameplay();
	}
}

void Game::startStandard()
{
	menu = false;
	standard = true;
	defense = false;
	int timeStart=glutGet(GLUT_ELAPSED_TIME);
	//TODO initialization.. spawn units etc..
}

void Game::startDefense()
{
	menu = false;
	standard = false;
	defense = true;
	int timeStart = glutGet(GLUT_ELAPSED_TIME);
	//TODO prepare waves of enemies..
}

bool Game::inMenu()
{
	return menu;
}

bool Game::inGame()
{
	bool state = standard || defense;
	return state;
}

void Game::goToMenu()
{
	menu = true;
	standard = false;
	defense = false;
}

void Game::initCamera()
{
	playerCamera.pos.x = 31.325f;
	playerCamera.pos.y = 26.25f;
	playerCamera.pos.z = 31.625f;

	playerCamera.dir.x = 0.75f;//TODO adjust
	playerCamera.dir.y = -1.0f;
	playerCamera.dir.z = 0.75f;

	playerCamera.speed = .75f;
}





void Game::spawnMinerals(vector<vec3> layout)
{
	for(auto pos:layout)
	{
		entities.emplace_back(make_shared <MineralField>(3500, pos));//TODO tool for non player owned entities
	}
}

void Game::manageMenu()
{

	//TODO
}


void Game::spawnEnemies(vector<vec3> layout)
{
	for (auto pos : layout)
	{
		enemies.emplace_back(make_shared <MechT1>("mechanical", 16, 42, 25, 28, "mecht2",pos, 120, 0.5,&weaponUpgrades , &armorUpgrades,true));//TODO tool for non player owned entities
	}
	vec3 pos = { 190,0,190 };
	enemies.emplace_back(make_shared <TankT2>("mechanical", 16, 42, 25, 28, "mecht2", pos, 400, 0.5, &weaponUpgrades, &armorUpgrades, true));//TODO tool for non player owned entities
}

bool Game::getFinished()
{
	return finished;
}

void Game::drawResourcesIcons(bool)
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 59, 48, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_TEXTURE_2D);
	// Ustawienie sposobu teksturowania - GL_MODULATE sprawia, ¿e œwiat³o ma wp³yw na teksturê; GL_DECAL i GL_REPLACE rysuj¹ teksturê tak jak jest
	glBindTexture(GL_TEXTURE_2D, Resources::victory);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);


	glTranslatef(20.0f, 15.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(20.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(20.0f, 15.f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 15.f);
	glEnd();


	glDisable(GL_BLEND);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
