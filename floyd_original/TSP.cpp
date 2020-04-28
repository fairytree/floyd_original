#include "TSP.h"

//Time complexity - O(2^n * n^2)
//Space complexity - O(2^n)


TSP::TSP(int startNode, const std::vector<std::vector<double>>& adjMatrix)
	: _adjMatrix(adjMatrix), _nodeNum(adjMatrix.size()), _startNode(startNode - 1)
{
	// The finished state is when the finished state mask has all bits are set to
	// one (meaning all the nodes have been visited).
	_finishedState = (1 << _nodeNum) - 1;
}

TSP::~TSP()
{
}


// Returns the optimal tour for the traveling salesman problem.
std::vector<int> TSP::getTour() {
	if (!_ranSolver) {
		solve();
	}
	return _tour;
}

// Returns the minimal tour cost.
double TSP::getTourCost() {
	if (!_ranSolver) {
		solve();
	}
	return _minTourCost;
}

void TSP::solve() {
	// Run the solver
	int state = 1 << _startNode;
	std::vector<std::vector<double>> memo(_nodeNum, std::vector<double>((1 << _nodeNum), NULL));
	std::vector<std::vector<int>> prev(_nodeNum, std::vector<int>((1 << _nodeNum), NULL));
	_minTourCost = tsp(_startNode, state, memo, prev);

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
	_ranSolver = true;
}

double TSP::tsp(int i, int& state, std::vector<std::vector<double>>& memo,
	std::vector<std::vector<int>>& prev) {

	// Done this tour. Return cost of going back to start node.
	if (state == _finishedState) {
		return _adjMatrix[i][_startNode];
	}

	// Return cached answer if already computed.
	if (memo[i][state] != NULL) {
		return memo[i][state];
	}

	double minCost = DBL_MAX;
	int index = -1;
	for (int next = 0; next < _nodeNum; next++) {

		// Skip if the next node has already been visited.
		if ((state & (1 << next)) != 0) {
			continue;
		}

		int nextState = state | (1 << next);
		double newCost = _adjMatrix[i][next] + tsp(next, nextState, memo, prev);
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
	std::cout << "Tour: " << std::endl;
	for (auto n : getTour()) {
		std::cout << n + 1 << "-->";
	}

	std::cout << " Tour cost: " << getTourCost() << std::endl;
}