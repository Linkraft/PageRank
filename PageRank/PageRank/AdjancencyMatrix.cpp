#include "AdjancencyMatrix.h"

// O(n^3 * log(n))
AdjacencyMatrix::AdjacencyMatrix(Graph g) {
	size = g.getCount();
	named = g.getNamed();
	IDs = g.getIDs();
	// O(number of nodes * number of nodes) below
	matrixArray = vector<vector<double>>(size, vector<double>(size, 0));
	emplaceMaps(); // O(n)
	setMatrix();   // O(n^3 * log(n))
}

// O(number of nodes)
void AdjacencyMatrix::emplaceMaps() {
	unsigned int number = 0;
	// O(number of nodes)
	for (auto iter = IDs.begin(); iter != IDs.end(); iter++) {
		stringed.emplace(iter->first, number);
		numbered.emplace(number, iter->first);
		number++;
	}
}

// O(number of nodes * number of nodes * number of nodes * log(number of nodes)
// aka O(n^3 * log(n))
void AdjacencyMatrix::setMatrix() {
	for (auto j = stringed.begin(); j != stringed.end(); j++) {
		string nodeName = j->first;
		double pageRank, outdegree;
		// O(log(number of nodes))
		outdegree = named.at(nodeName)->getOutDegree();
		if (outdegree == 0) pageRank = 0;
		else pageRank = 1 / outdegree;
			// O(number of nodes)
		for (unsigned int i = 0; i < size; i++) {
			// O(log(number of nodes))
			vector<string> neighbors = named.at(j->first)->getNeighbors();
			if (neighbors.size() > 0) {
				// O(number of nodes)
				for (unsigned int k = 0; k < neighbors.size(); k++) {
					// O(log(number of nodes)
					int l = stringed.at(neighbors[k]);
					if (i == l) {
						matrixArray[j->second][i] = pageRank;
					}
				}
			}
			else { matrixArray[j->second][i] = 0; }
		}
	}
}

// O(number of nodes * number of nodes)
void AdjacencyMatrix::powerIterate(unsigned int numIter) {
	double init = (double)1 / (double)size;
	// O(number of nodes * number of nodes)
	iterArray = vector<vector<double>>(1, vector<double>(size, init));
	// O(1)
	for (unsigned int iter = 1; iter < numIter; iter++) {
		vector<double> sums;
		// O(number of nodes)
		for (unsigned int i = 0; i < size; i++) {
			double sum = 0;
			// O(number of nodes)
			for (unsigned int j = 0; j < size; j++) {
				double sum1 = matrixArray[j][i];
				double sum2 = iterArray[0][j];
				sum += sum1 * sum2;
			}
		sums.push_back(sum);
		}
		// O(number of nodes)
		for (unsigned int i = 0; i < size; i++) iterArray[0][i] = sums[i];
	}
}

// O(number of nodes)
void AdjacencyMatrix::printIter() {
	// O(number of nodes)
	for (unsigned int i = 0; i < size; i++) {
		cout << fixed << setprecision(2);
		cout << "[" << iterArray[0][i] << "]" << endl;
	}
}

// O(number of nodes * number of nodes)
void AdjacencyMatrix::printMatrix() {
	// O(number of nodes)
	for (unsigned int i = 0; i < size; i++) {
		// O(number of nodes)
		for (unsigned int j = 0; j < size; j++) {
			cout << fixed << setprecision(2);
			cout << "[" << matrixArray[j][i] << "] ";
		}
		cout << endl;
	}
}

// O(number of nodes)
void AdjacencyMatrix::printPageRanks() {
	// O(number of nodes)
	for (unsigned int i = 0; i < size; i++) {
		cout << fixed << setprecision(2);
		cout << numbered[i] << " " << iterArray[0][stringed[numbered[i]]] << endl;
	}
}