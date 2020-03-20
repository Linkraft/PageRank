#pragma once
#include <vector>
#include <sstream>
using namespace std;

class Node {
	public:
		Node();
		Node(string value);
		void addNeighbor(string nodeName);
		string getValue();
		double getOutDegree();
		vector<string> getNeighbors();
		string getNeighbor(unsigned int index);
	
	private:
		// List of outdegree'd neighbors
		vector<string> neighbors;
		string value;
		double outdegree;
};