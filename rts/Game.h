#pragma once
#include "SoundPlayer.h"

class Game
{
private:
	Grid *grid;
	
	vector<vec3>mineralLayout;
	vector<vec3>enemiesLayout;
	
	GLuint terrain;
	Terrain*terrainPtr;
	Resources* resources;
	bool menu, standard, defense;

	
	unsigned int weaponUpgrades;
	unsigned int armorUpgrades;

	bool finished;

public:
	Game();
	~Game();
	
	bool quit;
	void initialization();
	void cleanGlobalDeadEntities();
	void drawCube(GLuint AllTexture);
	vector<shared_ptr<Unit>>enemies;
	vector <shared_ptr<Targetable>>entities;
	
	SoundPlayer* soundPlayer;
	void drawResourcesIcons();
	void drawResourcesIcons(bool);
	void drawUnitIcons();
	void drawMinimap();
	void drawUI();
	void drawStatistics(int oldtimeSinceStart, int w, int h);
	void drawGameplay();
	void drawMenu();

	void IsFinished();
	void setFinished();
	bool getFinished();
	void drawNotEnoughResourcesAlert();
	void drawVictoryScreen();
	void drawHealthbars(vector<shared_ptr<Unit>> units);
	void render();

	void startStandard();
	void startDefense();

	bool inMenu();
	bool inGame();
	void goToMenu();
	void manageMenu();

	static SCameraState playerCamera;
	static void initCamera();


	vector<shared_ptr<Unit>> Game::getEnemies()
	{
		return enemies;
	}
	vector <shared_ptr<Targetable>> Game::getGameEntities()
	{
		return entities;
	}

	void spawnMinerals(vector<vec3>);
	void spawnEnemies(vector<vec3>);
};


