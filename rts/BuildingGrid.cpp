#include "stdafx.h"
#include "BuildingGrid.h"

BuildingGrid::BuildingGrid()
{
}

bool BuildingGrid::testGrid(int size, int x, int z)
{
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
bool BuildingGrid::test(int x, int z)
{
	if (mesh[x][z] != 0) return false;

	return true;
}
bool BuildingGrid::test2x2(int x, int z)
{
	if (mesh[x + 1][z + 0] != 0) return false;
	if (mesh[x + 0][z + 1] != 0) return false;
	if (mesh[x + 1][z + 1] != 0) return false;

	return true;
}

bool BuildingGrid::test3x3(int x, int z)
{
	if (mesh[x + 1][z + 0] != 0) return false;
	if (mesh[x + 0][z + 1] != 0) return false;
	if (mesh[x + 1][z + 1] != 0) return false;

	if (mesh[x + 2][z + 0] != 0) return false;
	if (mesh[x + 2][z + 1] != 0) return false;
	if (mesh[x + 2][z + 2] != 0) return false;
	if (mesh[x + 1][z + 2] != 0) return false;
	if (mesh[x + 0][z + 2] != 0) return false;

	return true;
}

bool BuildingGrid::test4x4(int x, int z)
{
	if (mesh[x + 1][z + 0] != 0) return false;
	if (mesh[x + 0][z + 1] != 0) return false;
	if (mesh[x + 1][z + 1] != 0) return false;

	if (mesh[x + 2][z + 0] != 0) return false;
	if (mesh[x + 2][z + 1] != 0) return false;
	if (mesh[x + 2][z + 2] != 0) return false;
	if (mesh[x + 1][z + 2] != 0) return false;
	if (mesh[x + 0][z + 2] != 0) return false;

	if (mesh[x + 3][z + 0] != 0) return false;
	if (mesh[x + 3][z + 1] != 0) return false;
	if (mesh[x + 3][z + 2] != 0) return false;
	if (mesh[x + 3][z + 3] != 0) return false;
	if (mesh[x + 2][z + 3] != 0) return false;
	if (mesh[x + 1][z + 3] != 0) return false;
	if (mesh[x + 0][z + 3] != 0) return false;

	return true;
}

void BuildingGrid::fill2x2(int x, int z)
{
	mesh[x + 0][z + 0] = 1;
	mesh[x + 1][z + 0] = 1;
	mesh[x + 0][z + 1] = 1;
	mesh[x + 1][z + 1] = 1;
}

void BuildingGrid::fill3x3(int x, int z)
{
	mesh[x + 1][z + 0] = 1;
	mesh[x + 0][z + 1] = 1;
	mesh[x + 1][z + 1] = 1;

	mesh[x + 2][z + 0] = 1;
	mesh[x + 2][z + 1] = 1;
	mesh[x + 2][z + 2] = 1;
	mesh[x + 1][z + 2] = 1;
	mesh[x + 0][z + 2] = 1;
}

void BuildingGrid::fill4x4(int x, int z)
{
	mesh[x + 1][z + 0] = 1;
	mesh[x + 0][z + 1] = 1;
	mesh[x + 1][z + 1] = 1;

	mesh[x + 2][z + 0] = 1;
	mesh[x + 2][z + 1] = 1;
	mesh[x + 2][z + 2] = 1;
	mesh[x + 1][z + 2] = 1;
	mesh[x + 0][z + 2] = 1;

	mesh[x + 3][z + 0] = 1;
	mesh[x + 3][z + 1] = 1;
	mesh[x + 3][z + 2] = 1;
	mesh[x + 3][z + 3] = 1;
	mesh[x + 2][z + 3] = 1;
	mesh[x + 1][z + 3] = 1;
	mesh[x + 0][z + 3] = 1;
}

void BuildingGrid::fill(int x, int z)
{
	mesh[x][z] = 1;
}

void BuildingGrid::free(int x, int z)
{
	mesh[x][z] = 0;
}


bool BuildingGrid::testSize(int size, int x, int z)
{
	switch (size) {
	case 2:
		if (x > gridsize - 2 || z > gridsize - 1) {
			//TODO alert nie mozna budowac
			return false;
		}
		break;
	case 3:
		if (x > gridsize - 3 || z > gridsize - 2) {
			return false;
		}
		break;

	case 4:
		if (x > gridsize - 4 || z > gridsize - 3) {
			return false;
		}
		break;
	}
	return true;
}

bool BuildingGrid::testNeighbours(int size, int x, int z)
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
bool  BuildingGrid::testColision(shared_ptr<Unit> u, int x, int z)
{
	if(occupying[x][z] == NULL|| occupying[x][z] == u)
	{
		return true;
	}
	else return false;
}
void  BuildingGrid::occupy(shared_ptr<Unit> u, int x, int z)
{
	occupying[x][z]=u;
}
void  BuildingGrid::leave(int x, int z)
{
	occupying[x][z] = NULL;
}
shared_ptr<Targetable> BuildingGrid::searchTargets(int i, int j,float r)
{
	int range = ceil(r);
	int row_limit = 99;
	if (row_limit > 0) {
		int column_limit = 99;
		for (int x = max(0, i - range); x <= min(i + range, row_limit); x++) {
			for (int y = max(0, j - range); y <= min(j + range, column_limit); y++) {
				if (x != i || y != j) {
					try {
						if (occupying[x][y] != NULL)
							return occupying[x][y];
					}
					catch (int ex) {
						;
					}
					
				}
			}
		}
	}
	return NULL;
}
BuildingGrid::~BuildingGrid()
{
}

