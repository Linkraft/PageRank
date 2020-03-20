#include "Graph.h"
#include <iostream>
#include <iomanip>

class AdjacencyMatrix {
public:
	AdjacencyMatrix(Graph g);
	void emplaceMaps();
	void setMatrix();
	void powerIterate(unsigned int numIter);
	void printIter();
	void printMatrix();
	void printPageRanks();
private:
	unsigned int size;
	map<string, int> stringed;
	map<int, string> numbered;
	map<string, Node*> named;
	map<string, vector<string>> IDs;
	vector<vector<double>> iterArray;
	vector<vector<double>> matrixArray;
};