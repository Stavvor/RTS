#include "stdafx.h"
#include "rts.h"

Game* game;
Player* player;
SoundPlayer* soundPlayer;

vector<shared_ptr<Targetable>> minerals;//TODO wywalic stad...

int mouseX;
int mouseY;

int oldTimeSinceStart = 0;

int w;
int h;

int main(int argc, char**argv){

	
	#pragma region testy jednostek
	/*
	////////////////////////////////////			TEST TWORZENIA I CZYSZCZENIA OBIEKTOW
	Player* player;
	player = new Player("testPlayer");
	player->buildStructure();
	player->trainUnit(player->getMyBuildings()[0]);
	player->trainUnit(player->getMyBuildings()[0]);
	//player->getMyCombatUnits()[0]->takeDamage(50);
	//player->getMyBuildings()[0]->takeDamage(2000);

	char exit=0;
	while (exit != 'q') {
		player->cleanDeadEntities();
		cin >> exit;
	}
	player->clearMemory();
	delete(player);
	return 0;
	*/
	
	////////////////////////////////////			TEST OBLICZANIA ODLEGLOSCI
	/*

	unsigned int upgrade = 0; //potrzebne na sztywno bo defaultowo gracz ma zawsze 0 i inaczej sie wywali....
	vec3 posA = { 0,0,0 };
	//vec3 posB = { 6.0,0,0 };  //jest ok
	vec3 posB = { 6.1,0,0 };	//za daleko; dziala!!!!
	
	Unit* a;
	Unit* b;
	a = new Soldier("Infantry", 8, 6, 7, "Soldier", posA, 50, 0.5, &upgrade, &upgrade);
	b = new Soldier("Infantry", 8, 6, 7, "Soldier", posB, 50, 0.5, &upgrade, &upgrade);
	//a->setPosition(posA);
	//b->setPosition(posB);

	a->attack(b);						//powinno wyswietlac za daleko

	delete(a);
	delete(b);
	return 0;
	*/
	
	////////////////////////////////////			TEST UPGRADOW
	/*
	
	Player*player;
	player = new Player("testPlayer");
	vec3 posA = { 0,0,0 };

	player->buildStructure();
	player->upgradeWeapons();
	player->trainUnit(player->getMyBuildings()[0]);
	
	cout<< *player->getMyUnits()[0]->upgrades->weaponUpgradesPtr << endl;
	player->upgradeWeapons();
	player->upgradeWeapons();		//DZIALA! wskaznik na strukture z upgradami w Targetable
	player->upgradeWeapons();
	cout << *player->getMyUnits()[0]->upgrades->weaponUpgradesPtr << endl;
	player->clearMemory();

	delete(player);
	return 0;
	*/
	////////////////////////////////////			TEST KALKULACJI DMGU, wspolpracy z upgradami 
	/*
	unsigned int weaponUpgradeA = 3;
	unsigned int armorUpgradeA = 0;

	unsigned int weaponUpgradeB = 0;
	unsigned int armorUpgradeB = 0;

	vec3 posA = { 0,0,0 };
	vec3 posB = { 0,0,0 };

	Unit* a;
	Unit* b;

	a = new Soldier("Infantry", 8, 6, 7, "Soldier", posA, 50, 0.5, &weaponUpgradeA, &armorUpgradeA);
	b = new Soldier("Infantry", 8, 6, 7, "Soldier", posB, 50, 0.5, &weaponUpgradeB, &armorUpgradeB);

	//a->setPosition(posA);
	//b->setPosition(posB);

	a->attack(b);

	cout << a->getHitPoints() << endl;
	cout << b->getHitPoints() << endl;

	delete(a);
	delete(b);
	return 0;
	*/
	////////////////////////////////////			targetowanie budynkow dzialaaa....
	/*
	Player* player;
	player = new Player("testPlayer");
	player->buildStructure();
	player->trainUnit(player->getMyBuildings()[0]);
	cout << player->getMyBuildings()[0]->getHitPoints() << endl;
	player->getMyUnits()[0]->attack(player->getMyBuildings()[0]);
	cout << player->getMyBuildings()[0]->getHitPoints() << endl;
	player->clearMemory();
	delete(player);
	return 0;
	*/
	
	////////////////////////////////////			test naprawy		
	/*
	unsigned int armorUpgradeA = 0;
	Unit* unit;
	vec3 posA = { 0,0,0 };
	unit = new Worker("worker",posA, 40, 1,5,6, &armorUpgradeA);
	delete(unit);
    return 0;
	*/
	/*
	////////////////////////////////////			test podnoszenia jednostek
	Player* player;
	player = new Player("testPlayer");
	player->buildStructure();
	player->trainUnit(player->getMyBuildings()[0]);
	AirTransporter* transporter;
	transporter = new AirTransporter();
	transporter->setPosition({ 0,0,0 });
	transporter->pickUp(player->getMyUnits()[0]);
	cout<<"przed "<<player->getMyUnits()[0]->getIsPickedUp()<<endl;
	cout << player->getMyUnits()[0]->getPosition() << endl;
	transporter->setPosition({ 50,150,0 });
	transporter->dropAll();
	cout << "po " << player->getMyUnits()[0]->getIsPickedUp() << endl;
	cout << player->getMyUnits()[0]->getPosition() << endl;
	player->clearMemory();
	delete(player);
	delete(transporter);
	return 0;
	*/
	////////////////////////////////////			test podnoszenia jednostek
	/*
	Player* player;
	player = new Player("testPlayer");
	player->clearMemory();

	player->buildStructure();
	player->getMyBuildings()[0]->setHitPoints(1);
	Worker* worker;
	worker = new Worker();
	Worker* worker1;
	worker1 = new Worker();
	cout << player->getMyBuildings()[0]->getHitPoints()<<endl;
	worker->repair(player->getMyBuildings()[0]);
	worker1->repair(player->getMyBuildings()[0]); //TODO jak to zrownoleglic?? czy OnTimer wystarczy?
 	cout << player->getMyBuildings()[0]->getHitPoints() << endl;
	delete(player);
	delete(worker);
	delete(worker1);
	*/
	////////////////////////////////////			test gridu
	/*
	player = new Player("test Player");
	player->buildStructure();
	player->trainUnit(player->getMyBuildings()[0]);
	BuildingGrid a;
	a.testGrid(2, 0, 0);
	a.testGrid(2, 120, 85);
	*/
	////////////////////////////////////			test zbierania risorcow
	/*
	Targetable* mineral;
	mineral = new MineralField();	//TODO zrobic narzedzie do czyszczenia entities nie nalezacych do gracza
	player->createWorker();
	player->getMyUnits()[0]->setTarget(mineral);
	Targetable*test= player->getMyUnits()[0]->getTarget();
	cout << player->getResources() << endl;
	*/
#pragma endregion 

	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 

	glutCreateWindow("openGl rtsgame");

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);

	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);

	glutMouseFunc(OnMouseKeyPress);
	//glutMouseFunc(OnMouseKeyUp);

	glutSpecialFunc(OnSpecialKeyPress);
	glutSpecialUpFunc(OnSpecialKeyUp);
	
	glutPassiveMotionFunc(MouseCords);
	glutMouseWheelFunc(mouseWheel);
	//TODO callbacki wszystkie interakcje jednostek ktore nie sa instantowe...
	glutTimerFunc(17, OnTimer, 0);
	glutTimerFunc(17, unitDetails, 0);
	glutTimerFunc(17, actionTimer, 0);
	glutTimerFunc(17, queueManager, 0);
	glutTimerFunc(17, posManager, 0);
	glutTimerFunc(17, attackManager, 0);
	glutTimerFunc(1200, attackCooldown, 0);
	//glutIgnoreKeyRepeat(1); //TODO sprwdzic repetycje
	
	player = new Player("testPlayer");
	
	/*
	player->buildStructure();
	player->trainUnit(player->getMyBuildings()[0]);
	player->trainUnit(player->getMyBuildings()[0]);
	player->getMyUnits()[1]->setPosition({ 3.0f,0.0f,2.0f });
	player->trainUnit(player->getMyBuildings()[0]);
	player->getMyUnits()[2]->setPosition({ 4.0f,0.0f,3.0f });
	*/
	
	//player->createWorker();
	//player->getMyUnits()[0]->setTarget(mineral);
	player->buildStructure();
	//player->trainUnit(player->getMyBuildings()[0]);
	//player->trainUnit(player->getMyBuildings()[0]);
	//player->getMyUnits()[1]->setPosition({1.0f,0.0f,2.0f});
	
	//player->getMyUnits()[0]->getHasMinerals();
	//cout << player->getResources() << endl;

	glEnable(GL_DEPTH_TEST);
	const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position[] = { 50.0f, 50.0f, 50.0f, 0.0f };
	const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	const GLfloat mat_specular[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	const GLfloat mat_shininess[] = { 100.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	

	Resources* resources;
	resources = new Resources;
	Resources::loadModels();

	game = new Game();
	player->grid->prepareGrid();
	game->initCamera();
	resources->setLayout();
	game->spawnMinerals(resources->mineralLayout);
	
	soundPlayer = new SoundPlayer;
	soundPlayer->loadAllSounds();
	soundPlayer->playSound(soundPlayer->terran1);
	
	//game->playMusic();

	//Resources::loadTextures();
	
	
	//TODO gamemode menu....

	while(!KeyFlags::keystate[27])
	{
		glutMainLoopEvent();
		//glutMainLoop();
	}
	
	player->clearMemory();
	delete player;
	delete game;
	delete soundPlayer;
	delete resources;
	return 0;
}

// Obs³uga zdarzenia, gdy zostanie wciœniêty klawisz - zdarzenie nieoodporne na repetycjê klawiszy.
void OnKeyPress(unsigned char key, int x, int y) {
	printf("KeyPress: %c\n", key);
	if (!KeyFlags::keystate[key]) {
		OnKeyDown(key, x, y); // Emulacja zdarzenia zwi¹zanego z pojedynczym wciœniêciem klawisza
	}
	KeyFlags::keystate[key] = true;
}

void OnKeyDown(unsigned char key, int x, int y) {
	//printf("KeyDown: %c\n", key);
	
	/*if (key == 27) { // ESC - wyjœcie
		//TODO czyscic pamiec przed zakonczeniem gry
		
		glutLeaveMainLoop(); //TODO WTF dlaczego
	}*/
	if (glutGetModifiers() == 2)
	{
		switch (key)
		{
		case 17:
			player->addToControlGroup(0, player->getSelectedUnits());
			break;
		case 23:
			player->addToControlGroup(1, player->getSelectedUnits());
			break;
		case 5:
			player->addToControlGroup(2, player->getSelectedUnits());
			break;
		case 18:
			player->addToControlGroup(3, player->getSelectedUnits());
			break;
		case 20:
			player->addToControlGroup(4, player->getSelectedUnits());
			break;
		case 25:
			player->addToControlGroup(5, player->getSelectedUnits());
			break;
		case 37:
			player->addToControlGroup(6, player->getSelectedUnits());
			break;
		case 9:
			player->addToControlGroup(7, player->getSelectedUnits());
			break;
		case 15:
			player->addToControlGroup(8, player->getSelectedUnits());
			break;
		case 16:
			player->addToControlGroup(9, player->getSelectedUnits());
			break;
		
		}
	}
	if(glutGetModifiers()== 1)
	{
		switch(key)
		{
		case 'Q'://'q' || 'Q' //tODO resolve
		
			for (auto building : player->getMyBuildings())
			{
				player->trainUnit<MechT2>(building, 5);
			}
			break;
		
		case 'W':
		
			for (auto building : player->getMyBuildings())
			{
				player->trainUnit<TankT2>(building, 5);
			}
			break;
		
		case 'E':
		
			for (auto building : player->getMyBuildings())
			{
				player->trainUnit<FighterT2>(building, 5);
			}
			break;
		
		case 'R':
		
			for (auto building : player->getMyBuildings())
			{
				player->trainUnit<BomberT2>(building, 5);
			}
			break;
		
		}
	}

	switch (key)
	{
	case '1':
		player->jumpToControlGroup(0);
		break;
	case '2':
		player->jumpToControlGroup(1);
		break;
	case '3':
		player->jumpToControlGroup(2);
		break;
	case '4':
		player->jumpToControlGroup(3);
		break;
	case '5':
		player->jumpToControlGroup(4);
		break;
	case '6':
		player->jumpToControlGroup(5);
		break;
	case '7':
		player->jumpToControlGroup(6);
		break;
	case '8':
		player->jumpToControlGroup(7);
		break;
	case '9':
		player->jumpToControlGroup(8);
		break;
	case '0':
		player->jumpToControlGroup(9);
		break;
	}
	switch(key)
	{
	case 'q':
	{
		for (auto building : player->getMyBuildings())
		{
			player->trainUnit<MechT1>(building, 5);
		}
		break;
	}
	case 'w':
	{
		for (auto building : player->getMyBuildings())
		{
			player->trainUnit<TankT1>(building, 5);
		}
		break;
	}
	case 'e':
	{
		for (auto building : player->getMyBuildings())
		{
			player->trainUnit<FighterT1>(building, 5);
		}
		break;
	}
	case 'r':
	{
		for (auto building : player->getMyBuildings())
		{
			player->trainUnit<BomberT1>(building, 5);
		}
		break;
	}
	case 't':
	{
		
		player->createWorker();//TODO FIX
	}

	case 's':{
		for (auto unit : player->getSelectedUnits())
		{
			unit->setDestination(unit->getPosition());
			unit->dir = unit->dir;
		}
	}
		break;
	 
	}

}

void OnKeyUp(unsigned char key, int x, int y) {
	printf("KeyUp: %c\n", key);
	KeyFlags::keystate[key] = false;
}

// Aktualizacja stanu gry - wywo³ywana za poœrednictwem zdarzenia-timera.
void OnTimer(int id) {
	
	// Chcemy, by ta funkcja zosta³a wywo³ana ponownie za 17ms.
	glutTimerFunc(17, OnTimer, 0);

	/**/
	Quadtree<shared_ptr<Unit>>quadtree(AABB(Point(0, 0), Point(200, 200)));
	for (auto unit : player->getMyUnits())
	{
		quadtree.insert(Data<shared_ptr<Unit>>(Point(unit->getPosition().x, unit->getPosition().z), unit));
	}
	for(auto unit : player->getMyUnits())
	{
		auto potentialCollision = quadtree.queryRange(AABB(Point(unit->getPosition().x, unit->getPosition().z), Point(4.0, 4.0)));
		if(potentialCollision.size()==1)
		{
			continue;
		}
		else
		{
			float ignoreX = unit->getPosition().x;
			float ignoreZ = unit->getPosition().z;
			vec3 myPos = unit->getPosition();
			for (auto collidingUnit : potentialCollision)
			{
				vec3 targetPos = collidingUnit.load->getPosition();

				if (collidingUnit.load->getPosition().x != ignoreX, collidingUnit.load->getPosition().z != ignoreZ)
				{
					float x = unit->dir.x;
					float y = 1.0f;
					float z = unit->dir.z;
					//data.Height[(int)(player.getPosZ() + player.getDirZ()*player.GetSpeed()) - 1][(int)(player.getPosX() + player.getDirX()*player.GetSpeed()) - 1] == '1' || game.getNoclip())
					float distance = sqrt(pow((myPos.x + x*0.2 - targetPos.x), 2) + pow((myPos.y + y*0.2 - targetPos.y), 2) + pow((myPos.z + z*0.2 - targetPos.z), 2));
					if (distance<2.0f)
						unit->setDestination(unit->getPosition());
					
					/*auto direction = unit->dir;
					vec3 newUDest;
					newUDest.x = direction.x*0.2 + unit->getPosition().x;
					newUDest.y = direction.y*0.2 + unit->getPosition().y;
					newUDest.z = direction.z*0.2 + unit->getPosition().z;*/

					/*auto collidingUnitDirection = collidingUnit.load->dir;
					collidingUnitDirection.x = -collidingUnitDirection.x;
					collidingUnitDirection.y = -collidingUnitDirection.y;
					collidingUnitDirection.z = -collidingUnitDirection.z;
					vec3 newDest;
					newDest.x = collidingUnitDirection.x*0.2 + collidingUnit.load->getPosition().x;
					newDest.y = collidingUnitDirection.y*0.2 + collidingUnit.load->getPosition().y;
					newDest.z = collidingUnitDirection.z*0.2 + collidingUnit.load->getPosition().z;
					collidingUnit.load->dir=collidingUnitDirection;
					collidingUnit.load->setDestination(newDest);*/
					//collidingUnit.load->setDestination(collidingUnit.load->getPosition());
				}
			}
		}
			
		potentialCollision.clear();
		//TODO pooprawic to zeby jakos wygladalo...
	}

	for (auto unit : player->getMyUnits())
	{
		vec3 currentPos = unit->getPosition();
		vec3 destination = unit->getDestination();
		currentPos = { currentPos.x, 0.0f, currentPos.z };
		float x = unit->dir.x;
		float y = 1.0f;
		float z = unit->dir.z;
		vec3 newPos = { currentPos.x + x*0.2,currentPos.y + y*0.2,currentPos.z + z*0.2 };
		float estTarget = 0.1;
		if (abs(currentPos.x - destination.x) > estTarget || abs(currentPos.z - destination.z) > estTarget)
		{
			unit->calculateVecAngle();
			unit->setPosition(newPos);
			unit->setIsMoving(true);
		}
		else
		{
			unit->setIsMoving(false);
		}
	}

		/*
		 for (auto unit : player->getMyUnits())
		{
			vec3 currentPos = unit->getPosition();
			vec3 destination = unit->getDestination();
			currentPos = { currentPos.x, 0.0f, currentPos.z };//TODO  ignorujemy Y.....

			if (currentPos.x > destination.x&&grid->test(floor(currentPos.x - 0.05), unit->getCurrentZPos()))
			{
				currentPos.x -= 0.05f;//TODO narazie stala wartosc, zamienic na predkosc
			}
			else
			{
				unit->setDestination({ currentPos.x, currentPos.y, currentPos.z });
			}
			if (currentPos.x < destination.x&&grid->test(floor(currentPos.x + 0.05), unit->getCurrentZPos()))
			{
				currentPos.x += 0.05f;
			}
			else
			{
				unit->setDestination({ currentPos.x, currentPos.y, currentPos.z });
			}
			if (currentPos.z > destination.z&&grid->test(unit->getCurrentXPos(), floor(currentPos.z - 0.05)))
			{
				currentPos.z -= 0.05f;
			}
			else
			{
				unit->setDestination({ currentPos.x, currentPos.y, currentPos.z });
			}
			if (currentPos.z<destination.z&&grid->test(unit->getCurrentZPos(), floor(currentPos.z + 0.05)))
			{
				currentPos.z += 0.05f;
			}
			else
			{
				unit->setDestination({ currentPos.x, currentPos.y, currentPos.z });
			}

			if (destination.x != 0 && destination.y != 0 && destination.z != 0)
			{
				unit->setPosition(currentPos.x, 0, currentPos.z);
			}

		}
		 */
		if (KeyFlags::isUpKeyPressed || KeyFlags::mouseTriggerCameraUp) {
			Game::playerCamera.pos.x += Game::playerCamera.dir.x * Game::playerCamera.speed;
			//playerCamera.pos.y += playerCamera.dir.y * playerCamera.speed;
			Game::playerCamera.pos.z += Game::playerCamera.dir.z * Game::playerCamera.speed;

		}

		if (KeyFlags::isDownKeyPressed || KeyFlags::mouseTriggerCameraDown) {
			Game::playerCamera.pos.x -= Game::playerCamera.dir.x * Game::playerCamera.speed;
			//playerCamera.pos.y -= playerCamera.dir.y * playerCamera.speed;
			Game::playerCamera.pos.z -= Game::playerCamera.dir.z * Game::playerCamera.speed;
		}

		if (KeyFlags::isLeftKeyPressed || KeyFlags::mouseTriggerCameraLeft) {
			Game::playerCamera.pos.x += Game::playerCamera.dir.z * Game::playerCamera.speed;
			Game::playerCamera.pos.z += -Game::playerCamera.dir.x * Game::playerCamera.speed;
		}

		if (KeyFlags::isRightKeyPressed || KeyFlags::mouseTriggerCameraRight) {
			Game::playerCamera.pos.x -= Game::playerCamera.dir.z * Game::playerCamera.speed;
			Game::playerCamera.pos.z -= -Game::playerCamera.dir.x * Game::playerCamera.speed;
		}
		//TODO skosy
		if (KeyFlags::keystate['q']) {
				float b = atan2(Game::playerCamera.dir.z, Game::playerCamera.dir.x);
				float a = -0.05f;

				Game::playerCamera.dir.x = cos(b + a);
				Game::playerCamera.dir.z = sin(b + a);
			/*for(auto unit: player->getMyUnits())	//TODO test miningu, przenisc
			{
				vec3 myPos = unit->getPosition();
				shared_ptr<Targetable> closest;
				float maxDistance = GRIDSIZE*sqrt(2);
				for(auto mineral : game->getEntities())
				{
					vec3 targetPos = mineral->getPosition();
					float distance=sqrt(pow((myPos.x - targetPos.x), 2) + pow((myPos.y - targetPos.y), 2) + pow((myPos.z - targetPos.z), 2));
					if(distance<=maxDistance)
					{
						closest = mineral;
						maxDistance = distance;
					}
				}
				unit->setTarget(closest);
			}*/
	
			}
		if (KeyFlags::keystate['e']) {
				float a = atan2(Game::playerCamera.dir.z, Game::playerCamera.dir.x);
				float b = 0.05f;

				Game::playerCamera.dir.x = cos(a + b);
				Game::playerCamera.dir.z = sin(a + b);
			}
		
		/*	if (glutGetModifiers() == 2) {
				switch (key)
				{
				case GLUT_KEY_F1:
					player->setCameraHotkey(1, playerCamera);
					break;
				case GLUT_KEY_F2:
					player->setCameraHotkey(2, playerCamera);
					break;
				case GLUT_KEY_F3:
					player->setCameraHotkey(3, playerCamera);
					break;
				case GLUT_KEY_F4:
					player->setCameraHotkey(4, playerCamera);
					break;
				case GLUT_KEY_F5:
					player->setCameraHotkey(5, playerCamera);
					break;
				case GLUT_KEY_F6:
					player->setCameraHotkey(6, playerCamera);
					break;
				case GLUT_KEY_F7:
					player->setCameraHotkey(7, playerCamera);
					break;
				case GLUT_KEY_F8:
					player->setCameraHotkey(8, playerCamera);
					break;
				case GLUT_KEY_F9:
					player->setCameraHotkey(9, playerCamera);
					break;
				case GLUT_KEY_F10:
					player->setCameraHotkey(10, playerCamera);
					break;
				case GLUT_KEY_F11:
					player->setCameraHotkey(11, playerCamera);
					break;
				case GLUT_KEY_F12:
					player->setCameraHotkey(12, playerCamera);
					break;

				}
			}*/

}
void OnSpecialKeyPress(int key, int x, int y)
{
	if(glutGetModifiers()==2){
		switch (key)
		{
		case GLUT_KEY_F1:
			player->setCameraHotkey(1, Game::playerCamera);
			break;
		case GLUT_KEY_F2:
			player->setCameraHotkey(2, Game::playerCamera);
			break;
		case GLUT_KEY_F3:
			player->setCameraHotkey(3, Game::playerCamera);
			break;
		case GLUT_KEY_F4:
			player->setCameraHotkey(4, Game::playerCamera);
			break;
		case GLUT_KEY_F5:
			player->setCameraHotkey(5, Game::playerCamera);
			break;
		case GLUT_KEY_F6:
			player->setCameraHotkey(6, Game::playerCamera);
			break;
		case GLUT_KEY_F7:
			player->setCameraHotkey(7, Game::playerCamera);
			break;
		case GLUT_KEY_F8:
			player->setCameraHotkey(8, Game::playerCamera);
			break;
		case GLUT_KEY_F9:
			player->setCameraHotkey(9, Game::playerCamera);
			break;
		case GLUT_KEY_F10:
			player->setCameraHotkey(10, Game::playerCamera);
			break;
		case GLUT_KEY_F11:
			player->setCameraHotkey(11, Game::playerCamera);
			break;
		case GLUT_KEY_F12:
			player->setCameraHotkey(12, Game::playerCamera);
			break;
		}
	}
	else
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			KeyFlags::isUpKeyPressed = true;
			if (!KeyFlags::isUpKeyPressed) {
				OnKeyDown(key, x, y);
			}
			break;
		case GLUT_KEY_DOWN:
			KeyFlags::isDownKeyPressed = true;
			if (!KeyFlags::isDownKeyPressed) {
				OnKeyDown(key, x, y);
			}
			break;
		case GLUT_KEY_LEFT:
			KeyFlags::isLeftKeyPressed = true;
			if (!KeyFlags::isLeftKeyPressed) {
				OnKeyDown(key, x, y);
			}
			break;
		case GLUT_KEY_RIGHT:
			KeyFlags::isRightKeyPressed = true;
			if (!KeyFlags::isRightKeyPressed) {
				OnKeyDown(key, x, y);
			}
			break;
		}
		switch (key)
		{
		case GLUT_KEY_F1:
			Game::playerCamera = player->jumpToCameraHotkey(1);
			break;
		case GLUT_KEY_F2:
			Game::playerCamera = player->jumpToCameraHotkey(2);
			break;
		case GLUT_KEY_F3:
			Game::playerCamera = player->jumpToCameraHotkey(3);
			break;
		case GLUT_KEY_F4:
			Game::playerCamera = player->jumpToCameraHotkey(4);
			break;
		case GLUT_KEY_F5:
			Game::playerCamera = player->jumpToCameraHotkey(5);
			break;
		case GLUT_KEY_F6:
			Game::playerCamera = player->jumpToCameraHotkey(6);
			break;
		case GLUT_KEY_F7:
			Game::playerCamera = player->jumpToCameraHotkey(7);
			break;
		case GLUT_KEY_F8:
			Game::playerCamera = player->jumpToCameraHotkey(8);
			break;
		case GLUT_KEY_F9:
			Game::playerCamera = player->jumpToCameraHotkey(9);
			break;
		case GLUT_KEY_F10:
			Game::playerCamera = player->jumpToCameraHotkey(10);
			break;
		case GLUT_KEY_F11:
			Game::playerCamera = player->jumpToCameraHotkey(11);
			break;
		case GLUT_KEY_F12:
			Game::playerCamera = player->jumpToCameraHotkey(12);
			break;

		}
	}
}
void OnSpecialKeyUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		KeyFlags::isUpKeyPressed = false;
		break;
	case GLUT_KEY_DOWN:
		KeyFlags::isDownKeyPressed = false;
		break;
	case GLUT_KEY_LEFT:
		KeyFlags::isLeftKeyPressed = false;
		break;
	case GLUT_KEY_RIGHT:
		KeyFlags::isRightKeyPressed = false;
		break;
	}
}

void OnModifiedDown(unsigned char key, int i, int y)
{
	
}

void raycast(int x,int y,vec3* dest, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end)
{
	double matModelView[16], matProjection[16];
	int viewport[4];
	glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
	glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	double winX = (double)x;
	double winY = viewport[3] - (double)y;
	gluUnProject(winX, winY, 0.0, matModelView, matProjection, viewport, &Mouse::mouseLeftClickPos_start.x, &Mouse::mouseLeftClickPos_start.y, &Mouse::mouseLeftClickPos_start.z);
	gluUnProject(winX, winY, 1.0, matModelView, matProjection, viewport, &Mouse::mouseLeftClickPos_end.x, &Mouse::mouseLeftClickPos_end.y, &Mouse::mouseLeftClickPos_end.z);
	//cout << "x: " << m_start.x << "y: " << m_start.y << "z: " << m_start.z << endl;
	dest->y = 1.0f;
	float t = (0 - Mouse::mouseLeftClickPos_start.y) / (Mouse::mouseLeftClickPos_end.y - Mouse::mouseLeftClickPos_start.y);
	
	dest->x = t*(Mouse::mouseLeftClickPos_end.x - Mouse::mouseLeftClickPos_start.x) + Mouse::mouseLeftClickPos_start.x;
	/*if (dest->x < 0)
		dest->x = 0;
	if (dest->x > GRIDSIZE)
		dest->x = GRIDSIZE;*/
	dest->z = t*(Mouse::mouseLeftClickPos_end.z - Mouse::mouseLeftClickPos_start.z) + Mouse::mouseLeftClickPos_start.z;
	/*if (dest->z < 0)
		dest->z = 0;
	if (dest->z > GRIDSIZE)
		dest->z = GRIDSIZE;*/

}
void raycastEnd(int x, int y, vec3* dest, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end)
{
	double matModelView[16], matProjection[16];
	int viewport[4];
	glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
	glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	double winX = (double)x;
	double winY = viewport[3] - (double)y;
	gluUnProject(winX, winY, 0.0, matModelView, matProjection, viewport, &Mouse::mouseLeftUpPos_start.x, &Mouse::mouseLeftUpPos_start.y, &Mouse::mouseLeftUpPos_start.z);
	gluUnProject(winX, winY, 1.0, matModelView, matProjection, viewport, &Mouse::mouseLeftUpPos_end.x, &Mouse::mouseLeftUpPos_end.y, &Mouse::mouseLeftUpPos_end.z);
	//cout << "x: " << m_start.x << "y: " << m_start.y << "z: " << m_start.z << endl;
	dest->y = 1.0f;
	float t = (0 - Mouse::mouseLeftUpPos_start.y) / (Mouse::mouseLeftUpPos_end.y - Mouse::mouseLeftUpPos_start.y);
	dest->x = t*(Mouse::mouseLeftUpPos_end.x - Mouse::mouseLeftUpPos_start.x) + Mouse::mouseLeftUpPos_start.x;
	if (dest->x < 0)
		dest->x = 0;
	if (dest->x > GRIDSIZE)
		dest->x = GRIDSIZE;
	dest->z = t*(Mouse::mouseLeftUpPos_end.z - Mouse::mouseLeftUpPos_start.z) + Mouse::mouseLeftUpPos_start.z;
	if (dest->z < 0)
		dest->z = 0;
	if (dest->z > GRIDSIZE)
		dest->z = GRIDSIZE;
}
void OnMouseKeyPress(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {//TODO check in sc
		if (KeyFlags::keystate['w'] || KeyFlags::keystate['W'])
		{
			if (player->grid->testGrid(4, floor(Mouse::destStart.x), floor(Mouse::destStart.z)))
			{
				vec3 pos = { floor(Mouse::destStart.x),1.0f,floor(Mouse::destStart.z) };
				player->buildStructure<Generator>(pos);
			}
			//TODO a move implementation
		}
		if (KeyFlags::keystate['e'] || KeyFlags::keystate['E'])
		{
			if (player->grid->testGrid(4, floor(Mouse::destStart.x), floor(Mouse::destStart.z)))
			{
				vec3 pos = { floor(Mouse::destStart.x),1.0f,floor(Mouse::destStart.z) };
				
				player->buildStructure<Factory>(pos);
			}
			//TODO a move implementation
		}
		if (KeyFlags::keystate['r'] || KeyFlags::keystate['R'])
		{
			if (player->grid->testGrid(4, floor(Mouse::destStart.x), floor(Mouse::destStart.z)))
			{
				vec3 pos = { floor(Mouse::destStart.x),1.0f,floor(Mouse::destStart.z) };

				player->buildStructure<Factory>(pos);
			}
			//TODO a move implementation
		}
		//TODO if 'T' 
		//structure (HQ)
		
	}

	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
		raycastEnd(x, y, &Mouse::moveTo, &Mouse::mouseLeftClickPos_start, &Mouse::mouseLeftClickPos_end);

		if(player->getSelectedUnits().size()==1){
			for (auto unit : player->getSelectedUnits())
			{
				if (unit->getTarget() != NULL)
					unit->setTarget(NULL);
				unit->setDestination(Mouse::moveTo);
				unit->dir.x = unit->getDestination().x - unit->getPosition().x;
				unit->dir.z = unit->getDestination().z - unit->getPosition().z;

				float hyp = sqrt(unit->dir.x*unit->dir.x + unit->dir.z*unit->dir.z);
				unit->dir.x /= hyp;
				unit->dir.z /= hyp;
			}
		}
		if(player->getSelectedUnits().size()>1)
		{
			auto unit = player->getSelectedUnits();
			//vec2 formationDest(destStart.x, destStart.z);
			auto destinations=player->calculateFormationDestinations(player->calculateFormation(), Mouse::moveTo);
			//auto destinations = player->calculateFormationDestinations(formationDest);
			//cout << Mouse::destStart << endl;
			for(int i=0;i<unit.size();i++)
			{
				if (unit[i]->getTarget() != NULL)
					unit[i]->setTarget(NULL);

				unit[i]->setDestination(destinations[i]);

				unit[i]->dir.x = unit[i]->getDestination().x - unit[i]->getPosition().x;
				unit[i]->dir.z = unit[i]->getDestination().z - unit[i]->getPosition().z;

				float hyp = sqrt(unit[i]->dir.x*unit[i]->dir.x + unit[i]->dir.z*unit[i]->dir.z);
				unit[i]->dir.x /= hyp;
				unit[i]->dir.z /= hyp;
			}
		}

		return;
	}


	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		raycast(x, y, &Mouse::destStart, &Mouse::mouseLeftClickPos_start, &Mouse::mouseLeftClickPos_end);
		/*
		double matModelView[16], matProjection[16];
		int viewport[4];
		glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
		glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		double winX = (double)x;
		double winY = viewport[3] - (double)y;
		gluUnProject(winX, winY, 0.0, matModelView, matProjection, viewport, &mouseLeftClickPos_start.x, &mouseLeftClickPos_start.y, &mouseLeftClickPos_start.z);
		gluUnProject(winX, winY, 1.0, matModelView, matProjection, viewport, &mouseLeftClickPos_end.x, &mouseLeftClickPos_end.y, &mouseLeftClickPos_end.z);
		//cout << "x: " << m_start.x << "y: " << m_start.y << "z: " << m_start.z << endl;
		destStart.y = 1.0f;
		float t = (0 - mouseLeftClickPos_start.y) / (mouseLeftClickPos_end.y - mouseLeftClickPos_start.y);
		destStart.x = t*(mouseLeftClickPos_end.x - mouseLeftClickPos_start.x) + mouseLeftClickPos_start.x;
		destStart.z = t*(mouseLeftClickPos_end.z - mouseLeftClickPos_start.z) + mouseLeftClickPos_start.z;


		//player->getMyUnits()[0]->setDestination(destStart);
		*/
	}
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {
		//cout << "puszczono lewy przycisk" << endl;

		raycast(x, y, &Mouse::destEnd, &Mouse::mouseLeftUpPos_start, &Mouse::mouseLeftUpPos_end);
		if (!glutGetModifiers() == 1)//dodawanie do zaznaczenia...
		{
			player->clearSelectedUnits();
		}
		
		for (auto unit : player->getMyUnits())
		{
			vec3 pos = unit->getPosition();

			vec3 vertexA = {Mouse::destStart.x,0.0f,Mouse::destStart.z };
			vec3 vertexB = {Mouse::destEnd.x,0.0f,Mouse::destStart.z };
			vec3 vertexC = {Mouse::destEnd.x,0.0f,Mouse::destEnd.z };

			if((pos.x>=vertexA.x && pos.x <=vertexB.x) && (pos.z >= vertexB.z && pos.z <= vertexC.z))
			{
				player->addToSelectedUnits(unit);
			}

			vec3 vertexAI = {Mouse::destStart.x,0.0f,Mouse::destStart.z };
			vec3 vertexBI = {Mouse::destStart.x,0.0f,Mouse::destEnd.z };
			vec3 vertexCI = {Mouse::destEnd.x,0.0f,Mouse::destEnd.z };

			if ((pos.x <= vertexAI.x && pos.x >= vertexCI.x) && (pos.z >= vertexAI.z && pos.z <= vertexBI.z))
			{
				player->addToSelectedUnits(unit);
			}

			vec3 vertexAII = {Mouse::destStart.x,0.0f,Mouse::destStart.z };
			vec3 vertexBII = {Mouse::destEnd.x,0.0f,Mouse::destEnd.z };
			vec3 vertexCII = {Mouse::destEnd.x,0.0f,Mouse::destStart.z };

			if ((pos.x<= vertexBII.x && pos.x>=vertexAII.x) && (pos.z<= vertexCII.z && pos.z>= vertexBII.z))
			{
				player->addToSelectedUnits(unit);
			}

			vec3 vertexAIII = {Mouse::destStart.x,0.0f,Mouse::destStart.z };
			vec3 vertexBIII = {Mouse::destEnd.x,0.0f,Mouse::destEnd.z };
			vec3 vertexCIII = {Mouse::destStart.x,0.0f,Mouse::destEnd.z };

			if ((pos.x<= vertexCIII.x&& pos.x >= vertexBIII.x) && (pos.z <= vertexAIII.z && pos.z >= vertexCIII.z))
			{
				player->addToSelectedUnits(unit);
			}
			/*
			//cout << "unit x: " << pos.x << "unit y: " << pos.y << "unit z: " << pos.z << endl;


			
			if (pos.x >= destStart.x&&pos.x <= destEnd.x&&pos.z >= destStart.z&&pos.z <= destEnd.z) {//lewo gora
				//player->addToSelectedUnits(unit);
				unit->setDestination(destEnd);
			}
			if (-pos.x <= -destStart.x&&pos.x >= -destEnd.x && pos.z <= destStart.z&&pos.z >= destEnd.z) {//lewo dol
				 //player->addToSelectedUnits(unit);
				unit->setDestination(destEnd);
			}
			if (pos.x <= destStart.x&&pos.x >= destEnd.x && pos.z <= destStart.z&&pos.z >= destEnd.z) {//prawo dol
				//player->addToSelectedUnits(unit);
				unit->setDestination(destEnd);
			}
			if (-pos.x >= -destStart.x&&-pos.x <= -destEnd.x&&pos.z >= destStart.z&&pos.z <= destEnd.z) {//prawo gora
				//player->addToSelectedUnits(unit);
				unit->setDestination(destEnd);
			}
			*/
		}
	}
}


void OnMouseKeyUp(int button, int state, int x, int y)
{
}


void MouseCords(int x, int y)
{

	mouseX = x;
	mouseY = y;
	//TODO dopracowywac wartosci
	if (mouseX >= 0 && mouseX <= 3) {
		KeyFlags::mouseTriggerCameraLeft = true;
	}
	else KeyFlags::mouseTriggerCameraLeft = false;

	if (mouseX <= glutGet(GLUT_WINDOW_WIDTH) - 1 && mouseX >= glutGet(GLUT_WINDOW_WIDTH) - 4) {
		KeyFlags::mouseTriggerCameraRight = true;
	}
	else KeyFlags::mouseTriggerCameraRight = false;

	if (mouseY >= 0 && mouseY <= 3) {
		KeyFlags::mouseTriggerCameraUp = true;
	}
	else KeyFlags::mouseTriggerCameraUp = false;

	if (mouseY <= glutGet(GLUT_WINDOW_HEIGHT) - 1 && mouseY >= glutGet(GLUT_WINDOW_HEIGHT) - 4) {
		KeyFlags::mouseTriggerCameraDown = true;
	}
	else KeyFlags::mouseTriggerCameraDown = false;

	//cout << mouseX << endl;
	//cout << mouseY << endl;
}

void mouseWheel(int button, int dir, int x, int y)
{

	if (dir > 0)
	{
		if (Game::playerCamera.pos.y >= Game::playerCamera.minHeight) {
			Game::playerCamera.pos.x += Game::playerCamera.dir.x * Game::playerCamera.speed * 5;
			Game::playerCamera.pos.y += Game::playerCamera.dir.y * Game::playerCamera.speed * 5;
			Game::playerCamera.pos.z += Game::playerCamera.dir.z * Game::playerCamera.speed * 5;
		}
	}
	else
	{
		if (Game::playerCamera.pos.y <= Game::playerCamera.maxHeight){
			Game::playerCamera.pos.x -= Game::playerCamera.dir.x * Game::playerCamera.speed * 5;
			Game::playerCamera.pos.y -= Game::playerCamera.dir.y * Game::playerCamera.speed * 5;
			Game::playerCamera.pos.z -= Game::playerCamera.dir.z * Game::playerCamera.speed * 5;
		}
	}
	

}

void OnRender() {
	soundPlayer->update3DPos(Game::playerCamera.pos,Game::playerCamera.dir,{0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f});
	//TODOgdzie to ustawic?
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(0.902, 0.902, 0.980);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setOrthographicProjection();
	glPushMatrix();

	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = timeSinceStart - oldTimeSinceStart;

	stringstream time;

	oldTimeSinceStart = timeSinceStart;
	
	int secs = (timeSinceStart / 1000) % 60;
	int mins = (timeSinceStart / 60000) % 60;
	int hours = (timeSinceStart / 3600000) % 24;
	time << hours << "H:" << mins << "M:"<<secs<<"S";

	const int font = (int)GLUT_BITMAP_9_BY_15;

	//GLUT_WINDOW_HEIGHT 
	//GLUT_WINDOW_WIDTH
	

	renderBitmapString(w- 320, 30, (void *)font,player->getResources());
	renderBitmapString(w - 220, 30, (void *)font, player->getEnergy());
	renderBitmapString(w - 110, 30, (void *)font, player->getSupplyToPrint().c_str());
	//renderBitmapString(w - 110, 60, (void *)font, player->getMyBuildings().size());		//TODO ogarnac
	renderBitmapString(w - 320, 60, (void *)font, "weapon upgrades");
	renderBitmapString(w - 170, 60, (void *)font, player->getWeaponUpgrades());
	renderBitmapString(w - 320, 90, (void *)font, "armor upgrades");
	renderBitmapString(w - 170, 90, (void *)font, player->getArmorUpgrades());
	renderBitmapString(200, h-280, (void *)font, time.str().c_str());

	stringstream s;
//	uto player->getSelectedUnits();
//	for(int i =0; i < player->getSelectedUnits().size();i++)
	for(auto unit:player->getSelectedUnits())
	{
		int y = 900;
		s << "Name: " << unit->getName();
		renderBitmapString(300, y, (void *)font, s.str().c_str());
		y += 15;
		s.str("");
		s << "Target: " << unit->getTarget();
		renderBitmapString(300, y, (void *)font, s.str().c_str());
		s.str("");
		y += 15;
		s <<"Pos x: "<< unit->getPosition().x << " z: " << unit->getPosition().z;
		renderBitmapString(300, y, (void *)font, s.str().c_str() );
		y += 15;
		s.str("");
		s << "Dir x: "<< unit->getDestination().x << " z: " << unit->getDestination().z;
		renderBitmapString(300, y, (void *)font, s.str().c_str());
		s.str("");
	}
	

	glutWireCube(2.0f);

	glPopMatrix();
	resetPerspectiveProjection();
	
	

	gluLookAt(
		Game::playerCamera.pos.x, Game::playerCamera.pos.y, Game::playerCamera.pos.z, // Pozycja kamery
		Game::playerCamera.pos.x + Game::playerCamera.dir.x, Game::playerCamera.pos.y + Game::playerCamera.dir.y, Game::playerCamera.pos.z + Game::playerCamera.dir.z, // Punkt na ktory patrzy kamera (pozycja + kierunek)
		0.0f, 1.0f, 0.0f // Wektor wyznaczajacy pion
	);

	game->drawTerrain();
	for (auto min : game->getEntities())
	{
		if(!min->getIsDead())
		{
			vec3 temp = min->getPosition();
			glPushMatrix();
			glTranslatef(temp.x, temp.y, temp.z);
			glColor3f(0, 0, 1);
			glutSolidCube(1);
			glPopMatrix();
		}
		
	}

	for (auto unit : player->getMyUnits())
	{
		
		if (!unit->getIsDead())
			unit->drawSelf();
		
	}

	for (auto building : player->getMyBuildings())
	{
		if (!building->getIsDead()) {
			vec3 temp = building->getPosition();
			glPushMatrix();
			glTranslatef(temp.x, temp.y, temp.z);
			glutWireCube(4.0f);
			glPopMatrix();
		}
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}


void OnReshape(int width, int height) {
	w = width;
	h = height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 100.0f);
}

//callbacki do zarzadzania jednostkami
void queueManager(int type){

	for (auto building : player->getMyBuildings())
	{
		if(!building->getProductionQueue()->empty())
		{
			building->updateProductionTime(1);
			if(building->getProductionTime()>=building->totalProductionTime)
			{
				//Unit* temp = building->getProductionQueue()->front();
				//player->getMyUnits().push_back(temp);
				player->addNewUnit(building->getProductionQueue()->front());
				building->getProductionQueue()->pop();
				building->setProductionTime(0);
			}
		}
	}
	glutTimerFunc(1000, queueManager, 0);
}
void attackCooldown(int)
{

	//glutTimerFunc(17, attackCooldown, 0);
}
/*
void repairCommand(int a)
{

	for (auto worker : player->getMyUnits())
	{
//		if (typeid(worker) == typeid(Worker*)) {
			if (worker->getTarget() != NULL) {
				worker->updateWorkProgress(20);
				if (worker->getWorkProgress() == 100) {
					worker->doWork();
				}
			}
		//}
	}
	glutTimerFunc(500, repairCommand, 0);
}
*/
void unitDetails(int)
{


/*	cout <<"resources = "<< player->getResources() << endl; //TODO przetestowac
	
	int i = 0;
	for(auto unit : player->getMyUnits())
	{
		cout << "unit[" << i << "] position " << unit->getPosition() ;
		cout << "unit[" << i << "] destination " << unit->getDestination() << endl;
		cout << "unit[" << i << "] dir " << unit->dir << endl;
		cout << "unit[" << i << "] target " << unit->getTarget() << endl;
		cout << "unit[" << i << "] minerals " << unit->getHasMinerals() << endl;
		i++;
	}
	
	i = 0;
	for (auto buidling : player->getMyBuildings())
	{
		cout << "building[" << i << "] position " << buidling->getPosition() ;
		cout << "building[" << i << "] hitpoints " << buidling->getHitPoints() << endl;
		cout << "building[" << i << "] hitpoints " << buidling->getPosition() << endl;
		i++;
	}

	cout << player->getResources() << endl;
	cout << player->getEnergy() << endl;
	
	cout << player->getMyUnits().size();

	glutTimerFunc(3000, unitDetails, 0);*/
	
}

void actionTimer(int a)
{
	for (auto unit : player->getMyUnits())
	{
		unit->updateCooldown(1);
	}
	for(auto building : player->getMyBuildings())
	{
		building->updateCooldown(1);
	}
	glutTimerFunc(20, actionTimer, 0);
}

void posManager(int a)
{
	
	for (auto unit : player->getMyUnits())
	{
		vec3 pos=unit->getPosition();
		int x = floor(pos.x);
		int z = floor(pos.z);
		if(x>0 && z>0)
		{
			
		
		player->grid->testColision(unit, unit->getCurrentXPos(), unit->getCurrentZPos());
//		if(!player->grid->testColision(unit, x, z))
//		{
//			cout << "kolizja" << endl;
//		}
		//TODO rozwiazac kolizje; test dziala
		if(x!= unit->getCurrentXPos() && z != unit->getCurrentZPos())
		{
			//player->grid->free(unit->getCurrentXPos(), unit->getCurrentZPos());
			player->grid->leave(unit->getCurrentXPos(), unit->getCurrentZPos());
			//player->grid->fill(x, z);
			player->grid->occupy(unit, x, z);
			unit->setCurrentGridPos(x, z);
		}
		else if(x != unit->getCurrentXPos() && z == unit->getCurrentZPos())
		{
			//player->grid->free(unit->getCurrentXPos(),z);
			player->grid->leave(unit->getCurrentXPos(), z);
			//player->grid->fill(x, z);
			player->grid->occupy(unit, x, z);
			unit->setCurrentGridPos(x,z);
		}
		else if(x == unit->getCurrentXPos() && z != unit->getCurrentZPos())
		{
			//player->grid->free(x, unit->getCurrentZPos());
			player->grid->leave(x, unit->getCurrentZPos());
			//player->grid->fill(x, z);
			player->grid->occupy(unit, x, z);
			unit->setCurrentGridPos(x, z);
		}
		if (unit->getTarget() == NULL && !unit->getIsMoving()){	//TODO atak wstrzymany...
			shared_ptr<Targetable>target = player->grid->searchTargets(x, z, unit->getRange());
			if(target!=NULL)
			{
				unit->setTarget(target);
				target->addToTargetedby(unit);//TODO
			}
		}
		if (unit->getTarget() != NULL) {
			if (!unit->targetInRange())
			{
				unit->setTarget(NULL);
			}
		}/**/
		
		}
	}
	glutTimerFunc(20, posManager, 0);
}

void attackManager(int a)
{
	player->cleanMyDeadEntities();
	game->cleanGlobalDeadEntities();
	

	glutTimerFunc(20, attackManager, 0);
}

void renderBitmapString(float x, float y, void *font, int num) {
	glDisable(GL_LIGHTING);
	const char *c;
	glRasterPos2f(x, y);
	string str = to_string(num);
	const char* cstr = str.c_str();
	for (c = cstr; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
	glEnable(GL_LIGHTING);
}

void renderBitmapString(float x, float y, void *font, const char *string) {
	glDisable(GL_LIGHTING);
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
	glEnable(GL_LIGHTING);
}

void drawHealth(float health) {
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(1, 0);
	glVertex2f(1, health);
	glVertex2f(0, health);
	glEnd();
}

void setOrthographicProjection() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScalef(1, -1, 1);
	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}