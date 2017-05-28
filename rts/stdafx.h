// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <iostream>
#include <tchar.h>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <typeinfo>
#include <GL/freeglut.h>		//#include <GL/glut.h> 
#include <mutex>
#include <memory>
//#include <windows.h>


using namespace std;

#include "targetver.h"
#include "vectors.h"
#include "Camera.h"
#include "KeyFlags.h"
#include "Entity.h"
#include "Targetable.h"
#include "MineralField.h"
#include "Unit.h" 
#include "UtilityUnit.h"
#include "CombatUnit.h"
#include "Building.h"
#include "Worker.h"
#include "Soldier.h"
#include "Barracks.h"
#include "Factory.h"
#include "Airport.h"
#include "Generator.h"
#include "BuildingGrid.h"
#include "Player.h"
#include "AirTransporter.h"

extern Player* player;

// TODO: reference additional headers your program requires here
