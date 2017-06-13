#pragma once
#define GRIDSIZE 1000

class Grid
{
private:
	//int gridsize = N;
	vector<vector<int>>matrixArray;
	vector<vector<shared_ptr<Unit>>> occupying;
	//TODO przerobic na dynamiczna tablice
//	std::vector < std::vector < int > >MatrixArray;
//	void prepareMatrix() {
//		MatrixArray.resize(N, std::vector<int>(N, 0));
//		MatrixArray[][] =
//	};

public:
	Grid();
	void prepareGrid(); 
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
	void testColision(shared_ptr<Unit> u, int x, int z);
	void occupy(shared_ptr<Unit> u, int x, int z);
	void leave(int x, int z);
	shared_ptr<Targetable> searchTargets(int i, int j,float r);
	~Grid();
};



