#pragma once
#define N 100

class BuildingGrid
{
private:
	int gridsize = N;
	int mesh[N][N] = { 0 };
	shared_ptr<Unit> occupying[N][N]={NULL};
public:
	BuildingGrid();
	bool testSize(int size, int x, int z);
	bool testNeighbours(int size, int x, int z);
	bool testGrid(int size, int x, int z);

	bool test(int x, int z);
	bool test2x2(int x, int z);
	bool test3x3(int x, int z);
	bool test4x4(int x, int z);

	void fill2x2(int x, int z);
	void fill3x3(int x, int z);
	void fill4x4(int x, int z);

	void fill(int x, int z);
	void free(int x, int z);
	bool testColision(shared_ptr<Unit> u, int x, int z);
	void occupy(shared_ptr<Unit> u, int x, int z);
	void leave(int x, int z);
	shared_ptr<Targetable> searchTargets(int i, int j,float r);
	~BuildingGrid();
};



