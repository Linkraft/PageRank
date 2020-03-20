#include "Node.h"

Node::Node() {};

Node::Node(string value) {
	this->value = value;
	outdegree = 0;
}

void Node::addNeighbor(string nodeName) {
	neighbors.push_back(nodeName);
	outdegree++;
}

string Node::getValue() {
	return value; 

}

double Node::getOutDegree() {
	return outdegree; 
}

vector<string> Node::getNeighbors() {
	return neighbors; 
}

string Node::getNeighbor(unsigned int index) {
	if (index < neighbors.size()) return neighbors[index];
}
