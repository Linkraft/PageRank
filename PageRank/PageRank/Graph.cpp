#include "Graph.h"

Graph::Graph() {
	count = 0;
	mapped = false;
}

// O(number of nodes)
void Graph::addNode(string nodeName) {
	if (count != 0) {
		bool uniqueValue = true;
		for (unsigned int i = 0; i < nodes.size(); i++)
			if (nodes[i]->getValue() == nodeName) uniqueValue = false;
		if (uniqueValue) {
			Node* node = new Node(nodeName);
			nodes.push_back(node);
			named.emplace(nodeName, node);
			count++;
		}
	}
	else {
		Node* node = new Node(nodeName);
		nodes.push_back(node);
		named.emplace(nodeName, node);
		count++;
	}
}

// O(number of nodes)
void Graph::addConnection(string from, string to) {
	for (unsigned int i = 0; i < nodes.size(); i++) {
		if (nodes[i]->getValue() == from) {
			Node* node1 = nodes[i];
			node1->addNeighbor(to);
		}
	}
}

// O(number of nodes)
void Graph::mapGraph() {
	if (!mapped) {
		for (unsigned int i = 0; i < nodes.size(); i++)
			IDs.emplace(nodes[i]->getValue(), nodes[i]->getNeighbors());
		mapped = true;
	}
}

unsigned int Graph::getCount() {
	return count; 
}

vector<Node*> Graph::getNodes() {
	return nodes; 
}

Node* Graph::getNode(int index) { 
	return nodes[index];
}

const map<string, Node*> Graph::getNamed() { 
	return named; 
}

const map<string, vector<string>> Graph::getIDs() { 
	return IDs; 
}