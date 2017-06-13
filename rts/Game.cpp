#include "stdafx.h"
#include "Game.h"

SCameraState Game::playerCamera;

Game::Game()
{
	grid = new Grid;
	
}


Game::~Game()
{
	delete grid;
}

void Game::cleanGlobalDeadEntities()
{
	for (int i = 0; i < entities.size(); i++) {
		if (entities.at(i)->getIsDead()) {
			entities.at(i).reset();
			entities.erase(entities.begin() + i);
		}
	}
}

void Game::initCamera()
{
	playerCamera.pos.x = 0.0f;
	playerCamera.pos.y = 3.75f;
	playerCamera.pos.z = 0.0f;

	playerCamera.dir.x = 1.0f;
	playerCamera.dir.y = -1.0f;
	playerCamera.dir.z = 1.0f;

	playerCamera.speed = .25f;
}

vector<shared_ptr<Targetable>> Game::getEntities()
{
	return entities;
}



void Game::spawnMinerals(vector<vec3> layout)
{
	for(auto pos:layout)
	{
		entities.emplace_back(make_shared <MineralField>(50, pos));//TODO tool for non player owned entities
	}
}
