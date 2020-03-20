#include "Node.h"
#include "Graph.h"
#include "AdjancencyMatrix.h"
using namespace std;

int main()
{
	int numLinks, numIterations;
	cin >> numLinks;
	cin >> numIterations;
	string garbage;
	getline(cin, garbage); // Put the preceding input into the garbage
	Graph g = Graph();
	for (int i = 0; i < numLinks; i++) {
		string input = "";
		string nodeValue1, nodeValue2;
		getline(cin, input);
		stringstream ss(input);
		ss >> nodeValue1; // First value (first website)
		ss >> nodeValue2; // Second value (its neighbor)
		g.addNode(nodeValue1); 
		g.addNode(nodeValue2);
		g.addConnection(nodeValue1, nodeValue2);
	}
	g.mapGraph();
	AdjacencyMatrix AM = AdjacencyMatrix(g);
	AM.powerIterate(numIterations);
	AM.printPageRanks();
	return 0;
}