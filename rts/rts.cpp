#include "stdafx.h"


void attackCooldown(int);
void actionTimer(int);
void unitDetails(int);
void queueManager(int);
void posManager(int a);
void attackManager(int a);

void OnRender();
void OnReshape(int, int);
void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);
void OnTimer(int);
void OnSpecialKeyPress(int key, int x, int y);
void OnSpecialKeyUp(int key, int x, int y);

void OnModifiedDown(unsigned char key, int i, int y);

void OnMouseKeyPress(int button, int state, int x, int y);
void OnMouseKeyUp(int button, int state, int x, int y);
void MouseCords(int x, int y);
void mouseWheel(int button, int dir, int x, int y);

mousePos mouseLeftClickPos_start;
mousePos mouseLeftClickPos_end;
mousePos mouseLeftUpPos_start;
mousePos mouseLeftUpPos_end;

void raycast(int x, int y, vec3* vec3, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end);
void raycastEnd(int x, int y, vec3* vec3, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end);

void renderBitmapString(float x, float y, void *font, int num) {
	const char *c;
	glRasterPos2f(x, y);
	string str=to_string(num);
	const char* cstr=str.c_str();
	for (c = cstr; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void renderBitmapString(float x, float y, void *font, const char *string) {
	const char *c;
	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

int w, h;
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

vec3 destStart;
vec3 destEnd;
Player* player;
Targetable* mineral;
SCameraState playerCamera;

int mouseX;
int mouseY;
int oldTimeSinceStart = 0;



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

	player = new Player("testPlayer");
	
	/*
	player->buildStructure();
	player->trainUnit(player->getMyBuildings()[0]);
	player->trainUnit(player->getMyBuildings()[0]);
	player->getMyUnits()[1]->setPosition({ 3.0f,0.0f,2.0f });
	player->trainUnit(player->getMyBuildings()[0]);
	player->getMyUnits()[2]->setPosition({ 4.0f,0.0f,3.0f });
	*/

	mineral = new MineralField();	//TODO zrobic narzedzie do czyszczenia entities nie nalezacych do gracza
	player->grid = new BuildingGrid();
	
	//player->createWorker();
	//player->getMyUnits()[0]->setTarget(mineral);
	player->buildStructure();
	//player->trainUnit(player->getMyBuildings()[0]);
	//player->trainUnit(player->getMyBuildings()[0]);
	//player->getMyUnits()[1]->setPosition({1.0f,0.0f,2.0f});
	
	//player->getMyUnits()[0]->getHasMinerals();
	//cout << player->getResources() << endl;

	glEnable(GL_DEPTH_TEST);
	
	playerCamera.pos.x = 0.0f;
	playerCamera.pos.y = 3.75f;
	playerCamera.pos.z = 0.0f;

	playerCamera.dir.x = 1.0f;
	playerCamera.dir.y = -1.0f;
	playerCamera.dir.z = 1.0f;

	playerCamera.speed = .1f;

	glutMainLoop();

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
	
	if (key == 27) { // ESC - wyjœcie
		//TODO czyscic pamiec przed zakonczeniem gry
		player->clearMemory();
		delete(player);
		delete(mineral);
		glutLeaveMainLoop(); //TODO WTF dlaczego
	}
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
	auto vec = player->getMyUnits();
	for (int i = 0; i < player->getMyUnits().size(); i++) {
		{
			vec3 currentPos = vec[i]->getPosition();
			vec3 destination = vec[i]->getDestination();
			currentPos = { currentPos.x, 0.0f, currentPos.z };
			/*
			if (currentPos.x > destination.x) currentPos.x -= 0.05f;
			if (currentPos.x < destination.x) currentPos.x += 0.05f;

			if (currentPos.z > destination.z) currentPos.z -= 0.05f;
			if (currentPos.z < destination.z) currentPos.z += 0.05f;
			*/

			
				float x = vec[i]->dir.x;
				float y = 0.0f;
				float z = vec[i]->dir.z;
				vec3 newPos = { currentPos.x+x*0.2,currentPos.y+y*0.2,currentPos.z+z*0.2};

				if (abs(currentPos.x-destination.x)>0.1 || abs(currentPos.z - destination.z)>0.1)
				{
					vec[i]->setPosition(newPos);
					vec[i]->setIsMoving(true);
				}
				else
				{
					vec[i]->setIsMoving(false);
				}
					
			//TODO pooprawic to zeby jakos wygladalo...
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
			playerCamera.pos.x += playerCamera.dir.x * playerCamera.speed;
			//playerCamera.pos.y += playerCamera.dir.y * playerCamera.speed;
			playerCamera.pos.z += playerCamera.dir.z * playerCamera.speed;
		}

		if (KeyFlags::isDownKeyPressed || KeyFlags::mouseTriggerCameraDown) {
			playerCamera.pos.x -= playerCamera.dir.x * playerCamera.speed;
			//playerCamera.pos.y -= playerCamera.dir.y * playerCamera.speed;
			playerCamera.pos.z -= playerCamera.dir.z * playerCamera.speed;
		}

		if (KeyFlags::isLeftKeyPressed || KeyFlags::mouseTriggerCameraLeft) {

			playerCamera.pos.x += playerCamera.dir.z * playerCamera.speed;
			playerCamera.pos.z += -playerCamera.dir.x * playerCamera.speed;
		}

		if (KeyFlags::isRightKeyPressed || KeyFlags::mouseTriggerCameraRight) {
			playerCamera.pos.x -= playerCamera.dir.z * playerCamera.speed;
			playerCamera.pos.z -= -playerCamera.dir.x * playerCamera.speed;
		}
		//TODO skosy

		if (KeyFlags::keystate['b']) {
			auto building = player->getMyBuildings();
			auto var = building[0];
			player->trainUnit(building.at(0));
		}
		if (KeyFlags::keystate['w']) {
			player->createWorker();
		}
	    /*
		if (KeyFlags::keystate['q']) {
			float b = atan2(playerCamera.dir.z, playerCamera.dir.x);
			float a = -0.05f;
			playerCamera.dir.x = cos(b + a);
			playerCamera.dir.z = sin(b + a);
		}
		//obrot w prawo
		if (KeyFlags::keystate['e']) {
			float b = atan2(playerCamera.dir.z, playerCamera.dir.x);
			float a = 0.05f;

			playerCamera.dir.x = cos(b + a);
			playerCamera.dir.z = sin(b + a);
		}
		*/
		if (KeyFlags::keystate['s']) {
			for (auto unit : player->getSelectedUnits())
				unit->setDestination(unit->getPosition());
		}
		if (KeyFlags::keystate['q']) {
			//TODO zmienic kursor do patrolu
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
 			playerCamera = player->jumpToCameraHotkey(1);
			break;
		case GLUT_KEY_F2:
			playerCamera = player->jumpToCameraHotkey(2);
			break;
		case GLUT_KEY_F3:
			playerCamera = player->jumpToCameraHotkey(3);
			break;
		case GLUT_KEY_F4:
			playerCamera = player->jumpToCameraHotkey(4);
			break;
		case GLUT_KEY_F5:
			playerCamera = player->jumpToCameraHotkey(5);
			break;
		case GLUT_KEY_F6:
			playerCamera = player->jumpToCameraHotkey(6);
			break;
		case GLUT_KEY_F7:
			playerCamera = player->jumpToCameraHotkey(7);
			break;
		case GLUT_KEY_F8:
			playerCamera = player->jumpToCameraHotkey(8);
			break;
		case GLUT_KEY_F9:
			playerCamera = player->jumpToCameraHotkey(9);
			break;
		case GLUT_KEY_F10:
			playerCamera = player->jumpToCameraHotkey(10);
			break;
		case GLUT_KEY_F11:
			playerCamera = player->jumpToCameraHotkey(11);
			break;
		case GLUT_KEY_F12:
			playerCamera = player->jumpToCameraHotkey(12);
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

void raycast(int x,int y,vec3* vec3, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end)
{
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

}
void raycastEnd(int x, int y, vec3* vec3, mousePos* mouse_pos, mousePos* mouse_left_click_pos_end)
{
	double matModelView[16], matProjection[16];
	int viewport[4];
	glGetDoublev(GL_MODELVIEW_MATRIX, matModelView);
	glGetDoublev(GL_PROJECTION_MATRIX, matProjection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	double winX = (double)x;
	double winY = viewport[3] - (double)y;
	gluUnProject(winX, winY, 0.0, matModelView, matProjection, viewport, &mouseLeftUpPos_start.x, &mouseLeftUpPos_start.y, &mouseLeftUpPos_start.z);
	gluUnProject(winX, winY, 1.0, matModelView, matProjection, viewport, &mouseLeftUpPos_end.x, &mouseLeftUpPos_end.y, &mouseLeftUpPos_end.z);
	//cout << "x: " << m_start.x << "y: " << m_start.y << "z: " << m_start.z << endl;
	destEnd.y = 1.0f;
	float t = (0 - mouseLeftUpPos_start.y) / (mouseLeftUpPos_end.y - mouseLeftUpPos_start.y);
	destEnd.x = t*(mouseLeftUpPos_end.x - mouseLeftUpPos_start.x) + mouseLeftUpPos_start.x;
	destEnd.z = t*(mouseLeftUpPos_end.z - mouseLeftUpPos_start.z) + mouseLeftUpPos_start.z;
}
void OnMouseKeyPress(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP)) {//TODO sprawdizc w sc
		if (KeyFlags::keystate['g'])
		{
			if (player->grid->testGrid(4, floor(destStart.x), floor(destStart.z)))
			{
				vec3 pos = { floor(destStart.x),1.0f,floor(destStart.z) };
				player->buildStructure(pos);
			}
			//TODO implementacja amove; unit->moveTo(dest); maja atakowac wszystko po drodze
		}
	}

	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {
		raycast(x, y, &destStart, &mouseLeftClickPos_start, &mouseLeftClickPos_end);
		for (auto unit : player->getSelectedUnits())
		{
			if (unit->getTarget() != NULL)
				unit->setTarget(NULL);
			unit->setDestination(destStart);
			unit->dir.x = unit->getDestination().x - unit->getPosition().x;
			unit->dir.z = unit->getDestination().z - unit->getPosition().z;

			float hyp = sqrt(unit->dir.x*unit->dir.x + unit->dir.z*unit->dir.z);
			unit->dir.x /= hyp;
			unit->dir.z /= hyp;
		}

		return;
	}


	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		raycast(x, y, &destStart, &mouseLeftClickPos_start, &mouseLeftClickPos_end);
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

		raycastEnd(x, y, &destEnd, &mouseLeftUpPos_start, &mouseLeftUpPos_end);
		if (!glutGetModifiers() == 1)//dodawanie do zaznaczenia...
		{
			player->clearSelectedUnits();
		}
		
		for (auto unit : player->getMyUnits())
		{
			vec3 pos = unit->getPosition();

			vec3 vertexA = { destStart.x,0.0f,destStart.z };
			vec3 vertexB = { destEnd.x,0.0f,destStart.z };
			vec3 vertexC = { destEnd.x,0.0f,destEnd.z };

			if((pos.x>=vertexA.x && pos.x <=vertexB.x) && (pos.z >= vertexB.z && pos.z <= vertexC.z))
			{
				player->addToSelectedUnits(unit);
			}

			vec3 vertexAI = { destStart.x,0.0f,destStart.z };
			vec3 vertexBI = { destStart.x,0.0f,destEnd.z };
			vec3 vertexCI = { destEnd.x,0.0f,destEnd.z };

			if ((pos.x <= vertexAI.x && pos.x >= vertexCI.x) && (pos.z >= vertexAI.z && pos.z <= vertexBI.z))
			{
				player->addToSelectedUnits(unit);
			}

			vec3 vertexAII = { destStart.x,0.0f,destStart.z };
			vec3 vertexBII = { destEnd.x,0.0f,destEnd.z };
			vec3 vertexCII = { destEnd.x,0.0f,destStart.z };

			if ((pos.x<= vertexBII.x && pos.x>=vertexAII.x) && (pos.z<= vertexCII.z && pos.z>= vertexBII.z))
			{
				player->addToSelectedUnits(unit);
			}

			vec3 vertexAIII = { destStart.x,0.0f,destStart.z };
			vec3 vertexBIII = { destEnd.x,0.0f,destEnd.z };
			vec3 vertexCIII = { destStart.x,0.0f,destEnd.z };

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
		if (playerCamera.pos.y >= playerCamera.minHeight) {
			playerCamera.pos.x += playerCamera.dir.x * playerCamera.speed * 5;
			playerCamera.pos.y += playerCamera.dir.y * playerCamera.speed * 5;
			playerCamera.pos.z += playerCamera.dir.z * playerCamera.speed * 5;
		}
	}
	else
	{
		if (playerCamera.pos.y <= playerCamera.maxHeight){
			playerCamera.pos.x -= playerCamera.dir.x * playerCamera.speed * 5;
			playerCamera.pos.y -= playerCamera.dir.y * playerCamera.speed * 5;
			playerCamera.pos.z -= playerCamera.dir.z * playerCamera.speed * 5;
		}
	}
	

}

void OnRender() {
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
	
	int secs = timeSinceStart / 1000;
	int mins = timeSinceStart / 60000;
	int hours = timeSinceStart / 3600000;

	time << hours << "H:" << mins << "M:"<<secs<<"S";


	const int font = (int)GLUT_BITMAP_9_BY_15;
	
	renderBitmapString(1600, 30, (void *)font,player->getResources());
	renderBitmapString(1700, 30, (void *)font, player->getEnergy());
	renderBitmapString(1800, 30, (void *)font, player->getSupplyToPrint().c_str());
	renderBitmapString(1600, 60, (void *)font, "weapon upgrades");
	renderBitmapString(1750, 60, (void *)font, player->getWeaponUpgrades());
	renderBitmapString(1600, 90, (void *)font, "armor upgrades");
	renderBitmapString(1750, 90, (void *)font, player->getArmorUpgrades());
	renderBitmapString(200, 800, (void *)font, time.str().c_str());

	resetPerspectiveProjection();

	glPopMatrix();
	gluLookAt(
		playerCamera.pos.x, playerCamera.pos.y, playerCamera.pos.z, // Pozycja kamery
		playerCamera.pos.x + playerCamera.dir.x, playerCamera.pos.y + playerCamera.dir.y, playerCamera.pos.z + playerCamera.dir.z, // Punkt na ktory patrzy kamera (pozycja + kierunek)
		0.0f, 1.0f, 0.0f // Wektor wyznaczajacy pion
	);


	
	//siatka
	for (int ix = -5; ix <= 5; ix += 1) {
		for (int iz = -5; iz <= 5; iz += 1) {
			glColor3f(.5f + .1f * ix, .5f - .1f * iz, 0.0f);
			glPushMatrix();
			glTranslatef(ix, 0.0f, iz);
			glutSolidSphere(.05f, 8, 8);
			glPopMatrix();
		}
	}
	
	/*
	for (int i = 0; i < player->getMyUnits().size(); i++) {
		vec3 temp=player->getMyUnits()[i]->getPosition();
		glColor3f(0.0f,0.0f,1.0f);
		glPushMatrix();
		glTranslatef(temp.x,temp.y,temp.z);
		glutWireCube(1.0f);
		glPopMatrix();
	}
	*/
	
	for (auto unit : player->getMyUnits())
	{
		if(!unit->getIsDead()){
			vec3 temp = unit->getPosition();
			if(unit->getName()=="Test")		//TODO przerobic
				glColor3f(0.0f, 1.0f, 0.0f);
			else
				if(unit->getTarget()==NULL)
					glColor3f(0.0f, 0.0f, 1.0f);
				else
					glColor3f(1.0f, 0.0f, 0.0f);
			glPushMatrix();
			glTranslatef(temp.x, temp.y, temp.z);
			glutWireCube(1.0f);
			glPopMatrix();
		}
	}
	for (auto building : player->getMyBuildings())
	{
		if (!building->getIsDead()) {
			vec3 temp = building->getPosition();
			glColor3f(0.0f, 1.0f, 0.0f);
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
	/*
	for (auto unit : player->getMyUnits()) {
		if (typeid(unit) == typeid(CombatUnit*)){
			if (unit->getAttackCooldown()!=unit->maxAttackCooldown ){
				unit->updateAttackCooldown(100);
			}
		}
	}
	glutTimerFunc(100, attackCooldown, 0);
	*/
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
	/**/
	cout <<"resources = "<< player->getResources() << endl; //TODO przetestowac
	int i = 0;
	for(auto unit : player->getMyUnits())
	{
		//cout << "unit[" << i << "] position " << unit->getPosition() ;
		cout << "unit[" << i << "] hitpoints " << unit->getHitPoints() << endl;
		cout << "unit[" << i << "] this " << unit << endl;
		cout << "unit[" << i << "] target " << unit->getTarget() << endl;
		cout << "unit[" << i << "] destination " << unit->getDestination() << endl;
		//cout << "unit[" << i << "] attackcooldown " << unit->getCooldown() << endl;
		i++;
	}
	i = 0;
	for (auto buidling : player->getMyBuildings())
	{

		cout << "building[" << i << "] position " << buidling->getPosition() ;
		cout << "building[" << i << "] hitpoints " << buidling->getHitPoints() << endl;
		i++;
	}

	glutTimerFunc(3000, unitDetails, 0);
	
}

void actionTimer(int a)
{
	for (auto unit : player->getMyUnits())
	{
		unit->updateCooldown(1);
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
		if (unit->getTarget() == NULL && !unit->getIsMoving()){
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
		}

	}
	
	glutTimerFunc(20, posManager, 0);
}

void attackManager(int a)
{
	player->cleanDeadEntities();

	glutTimerFunc(20, attackManager, 0);
}