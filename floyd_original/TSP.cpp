#include "TSP.h"

//Time complexity - O(2^n * n^2)
//Space complexity - O(2^n)

TSP::TSP(int startNode, const std::vector<std::vector<double>>& adjMatrix)
{
	// The finished state is when the finished state mask has all bits are set to 1 (meaning all the nodes have been visited).
	_finishedState = (1 << adjMatrix.size()) - 1;
	_startNode = startNode - 1;
	
	std::vector<std::vector<double>> memo(adjMatrix.size(), std::vector<double>((1 << adjMatrix.size()), NULL));
	std::vector<std::vector<int>> prev(adjMatrix.size(), std::vector<int>((1 << adjMatrix.size()), NULL));
	
	int state = 1 << _startNode;
	_minTourCost = tsp(_startNode, state, memo, prev, adjMatrix);

	// Regenerate path
	int index = _startNode;
	while (true) {
		_tour.push_back(index);
		int nextIndex = prev[index][state];
		if (nextIndex == NULL) {
			break;
		}
		int nextState = state | (1 << nextIndex);
		state = nextState;
		index = nextIndex;
	}
	_tour.push_back(_startNode);
}

TSP::~TSP()
{
}

double TSP::tsp(int i, int& state, std::vector<std::vector<double>>& memo,
	std::vector<std::vector<int>>& prev, const std::vector<std::vector<double>>& adjMatrix) 
{
	// Done this tour. Return cost of going back to start node.
	if (state == _finishedState) {
		return adjMatrix[i][_startNode];
	}

	// Return cached answer if already computed.
	if (memo[i][state] != NULL) {
		return memo[i][state];
	}

	double minCost = DBL_MAX;
	int index = -1;
	for (int next = 0; next < adjMatrix.size(); next++) {
		// Skip if the next node has already been visited.
		if ((state & (1 << next)) != 0) {  
			continue;
		}
		int nextState = state | (1 << next);
		double newCost = adjMatrix[i][next] + tsp(next, nextState, memo, prev, adjMatrix);
		if (newCost < minCost) {
			minCost = newCost;
			index = next;
		}
	}

	prev[i][state] = index;
	return memo[i][state] = minCost;
}

// Print path and cost
void TSP::print()
{
	std::cout << "Travelling_Salesman_Problem Solution: " << std::endl;
	std::cout << "Tour: ";
	for (auto n : _tour) {
		std::cout << n + 1 << "-->";
	}

	std::cout << " Tour cost: " << _minTourCost << std::endl;
}
