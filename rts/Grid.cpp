#include "stdafx.h"
#include "Grid.h"

Grid::Grid()
{
}

void Grid::prepareGrid()
{
	matrixArray.resize(GRIDSIZE, vector<int>(GRIDSIZE, 0));
	occupying.resize(GRIDSIZE, vector<shared_ptr<Unit>>(GRIDSIZE, 0));
}

bool Grid::testGrid(int size, int x, int z)
{
	if (x < 0 || z < 0){
		cout << "Tu nie mozna budowac!" << endl;
		return false;
	}
	if (!testSize(size, x, z)) {
		cout << "Tu nie mozna budowac!" << endl;
		return false;
	}

	if (!testNeighbours(size, x, z)) {
		cout << "Tu nie mozna budowac!" << endl;
		return false;
	}

	switch (size) {
	case 2:
		fill2x2(x, z);
		return true;
	case 3:
		fill3x3(x, z);
		return true;
	case 4:
		fill4x4(x, z);
		return true;
	}
}
bool Grid::test(int x, int z)
{
	if (matrixArray[x][z] != 0) return false;

	return true;
}
bool Grid::test2x2(int x, int z)
{
	if (matrixArray[x + 1][z + 0] != 0) return false;
	if (matrixArray[x + 0][z + 1] != 0) return false;
	if (matrixArray[x + 1][z + 1] != 0) return false;

	return true;
}

bool Grid::test3x3(int x, int z)
{
	if (matrixArray[x + 1][z + 0] != 0) return false;
	if (matrixArray[x + 0][z + 1] != 0) return false;
	if (matrixArray[x + 1][z + 1] != 0) return false;

	if (matrixArray[x + 2][z + 0] != 0) return false;
	if (matrixArray[x + 2][z + 1] != 0) return false;
	if (matrixArray[x + 2][z + 2] != 0) return false;
	if (matrixArray[x + 1][z + 2] != 0) return false;
	if (matrixArray[x + 0][z + 2] != 0) return false;

	return true;
}

bool Grid::test4x4(int x, int z)
{

	if (matrixArray[x + 1][z + 0] != 0) return false;
	if (matrixArray[x + 0][z + 1] != 0) return false;
	if (matrixArray[x + 1][z + 1] != 0) return false;

	if (matrixArray[x + 2][z + 0] != 0) return false;
	if (matrixArray[x + 2][z + 1] != 0) return false;
	if (matrixArray[x + 2][z + 2] != 0) return false;
	if (matrixArray[x + 1][z + 2] != 0) return false;
	if (matrixArray[x + 0][z + 2] != 0) return false;

	if (matrixArray[x + 3][z + 0] != 0) return false;
	if (matrixArray[x + 3][z + 1] != 0) return false;
	if (matrixArray[x + 3][z + 2] != 0) return false;
	if (matrixArray[x + 3][z + 3] != 0) return false;
	if (matrixArray[x + 2][z + 3] != 0) return false;
	if (matrixArray[x + 1][z + 3] != 0) return false;
	if (matrixArray[x + 0][z + 3] != 0) return false;

	return true;
}

void Grid::fill2x2(int x, int z)
{
	matrixArray[x + 0][z + 0] = 1;
	matrixArray[x + 1][z + 0] = 1;
	matrixArray[x + 0][z + 1] = 1;
	matrixArray[x + 1][z + 1] = 1;
}

void Grid::fill3x3(int x, int z)
{
	matrixArray[x + 1][z + 0] = 1;
	matrixArray[x + 0][z + 1] = 1;
	matrixArray[x + 1][z + 1] = 1;

	matrixArray[x + 2][z + 0] = 1;
	matrixArray[x + 2][z + 1] = 1;
	matrixArray[x + 2][z + 2] = 1;
	matrixArray[x + 1][z + 2] = 1;
	matrixArray[x + 0][z + 2] = 1;
}

void Grid::fill4x4(int x, int z)
{
	matrixArray[x + 1][z + 0] = 1;
	matrixArray[x + 0][z + 1] = 1;
	matrixArray[x + 1][z + 1] = 1;

	matrixArray[x + 2][z + 0] = 1;
	matrixArray[x + 2][z + 1] = 1;
	matrixArray[x + 2][z + 2] = 1;
	matrixArray[x + 1][z + 2] = 1;
	matrixArray[x + 0][z + 2] = 1;

	matrixArray[x + 3][z + 0] = 1;
	matrixArray[x + 3][z + 1] = 1;
	matrixArray[x + 3][z + 2] = 1;
	matrixArray[x + 3][z + 3] = 1;
	matrixArray[x + 2][z + 3] = 1;
	matrixArray[x + 1][z + 3] = 1;
	matrixArray[x + 0][z + 3] = 1;
}

void Grid::fill(int x, int z)
{
	matrixArray[x][z] = 1;
}

void Grid::free(int x, int z)
{
	matrixArray[x][z] = 0;
}


bool Grid::testSize(int size, int x, int z)
{
	switch (size) {
	case 2:
		if (x > GRIDSIZE - 2 || z > GRIDSIZE - 1) {
			//TODO alert nie mozna budowac
			return false;
		}
		break;
	case 3:
		if (x > GRIDSIZE - 3 || z > GRIDSIZE - 2) {
			return false;
		}
		break;

	case 4:
		if (x > GRIDSIZE - 4 || z > GRIDSIZE - 3) {
			return false;
		}
		break;
	}
	return true;
}

bool Grid::testNeighbours(int size, int x, int z)
{
	switch (size) {
	case 2:
		return test2x2(x, z);
		break;
	case 3:
		return test3x3(x, z);
		break;
	case 4:
		return test4x4(x, z);
		break;
	}
}
void  Grid::testColision(shared_ptr<Unit> u, int i, int j)
{
	int range = 1;
	int row_limit = 1024;
	if (row_limit > 0) {
		int column_limit = 1024;
		for (int x = max(0, i - range); x <= min(i + range, row_limit); x++) {
			for (int y = max(0, j - range); y <= min(j + range, column_limit); y++) {
				if (x != i || y != j) {
					
					if (occupying[x][y] != NULL&&occupying[x][y] != u)
					{
						//potencjalna kolizja
						vec3 targetPos = occupying[x][y]->getPosition();
						vec3 myPos = u->getPosition();
						float distance = sqrt(pow((myPos.x - targetPos.x), 2) + pow((myPos.y - targetPos.y), 2) + pow((myPos.z - targetPos.z), 2));
						if (distance < 0.75f) {//TODO uzaleznic od modelu
							//u->setDestination();
						}
					}
						
						
				}
			}
		}
	}
}
void  Grid::occupy(shared_ptr<Unit> u, int x, int z)
{
	occupying[x][z]=u;
}
void  Grid::leave(int x, int z)
{
	occupying[x][z] = NULL;
}
shared_ptr<Targetable> Grid::searchTargets(int i, int j,float r)
{
	int range = ceil(r);
	int row_limit = 1024;
	if (row_limit > 0) {
		int column_limit = 1024;
		for (int x = max(0, i - range); x <= min(i + range, row_limit); x++) {
			for (int y = max(0, j - range); y <= min(j + range, column_limit); y++) {
				if (x != i || y != j) {
						if (occupying[x][y] != NULL)
							return occupying[x][y];
				}
			}
		}
	}
	return NULL;
}
Grid::~Grid()
{
	matrixArray.resize(1, vector<int>(1, 0));//TODO zapytac
	occupying.resize(1, vector<shared_ptr<Unit>>(1, 0));
}

