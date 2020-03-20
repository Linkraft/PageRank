#pragma once
#include "Node.h"
#include <map>

class Graph {
public:
	Graph();
	void addNode(string nodeName);
	void addConnection(string from, string to);
	void mapGraph();
	unsigned int getCount();
	vector<Node*> getNodes();
	Node* getNode(int index);
	const map<string, Node*> getNamed();
	const map<string, vector<string>> getIDs();

private:
	bool mapped;
	unsigned int count;
	vector<Node*> nodes;
	map<string, Node*> named;
	map<string, vector<string>> IDs;
};
