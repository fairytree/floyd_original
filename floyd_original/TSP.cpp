#include "TSP.h"

//Time complexity - O(2^n * n^2)
//Space complexity - O(n * 2^n)

TSP::TSP(int startNode, const std::vector<std::vector<double>>& adjMatrix)
{
	// The finished state is when the finished state mask has all bits are set to 1 (meaning all the nodes have been visited).
	// example:  1100(the right most number represents the 1st room) means the 1st and 2nd room are unvisited, the 3rd and 4th are visited. 
	_allRoomVisited = (1 << adjMatrix.size()) - 1;
	_startNode = startNode - 1;
}

TSP::~TSP()
{
}

void TSP::solver(const std::vector<std::vector<double>>& adjMatrix)
{
	int roomVisited = 1 << _startNode;

	 // state record robot's current position and rooms that have been visited
	std::vector<std::vector<double>> state(adjMatrix.size(), std::vector<double>((1 << adjMatrix.size()), NULL));

	// prev record the path
	std::vector<std::vector<int>> pathTo(adjMatrix.size(), std::vector<int>((1 << adjMatrix.size()), NULL));

	_minPathCost = tspRecursive(_startNode, roomVisited, state, pathTo, adjMatrix);

	// Regenerate path
	int index = _startNode;
	while (true) {
		_path.push_back(index);
		int nextRoomIndex = pathTo[index][roomVisited];
		if (nextRoomIndex == NULL) {
			break;
		}
		int nextVisited = roomVisited | (1 << nextRoomIndex);
		roomVisited = nextVisited;
		index = nextRoomIndex;
	}
	_path.push_back(_startNode);
}


double TSP::tspRecursive(int robotPosition, int& roomVisited, std::vector<std::vector<double>>& state,
	std::vector<std::vector<int>>& pathTo, const std::vector<std::vector<double>>& adjMatrix)
{
	// Done this tour. Return cost of going back to start node.
	if (roomVisited == _allRoomVisited) {
		return adjMatrix[robotPosition][_startNode];
	}

	// Return cached answer if already computed.
	if (state[robotPosition][roomVisited] != NULL) {
		return state[robotPosition][roomVisited];
	}

	double minCost = DBL_MAX;
	int index = -1;
	for (int nextRoomIndex = 0; nextRoomIndex < adjMatrix.size(); nextRoomIndex++) {
		// Skip if the next room has already been visited.
		if ((roomVisited & (1 << nextRoomIndex)) != 0) {
			continue;
		}
		int nextVisited = roomVisited | (1 << nextRoomIndex);
		double newCost = adjMatrix[robotPosition][nextRoomIndex] + tspRecursive(nextRoomIndex, nextVisited, state, pathTo, adjMatrix);
		if (newCost < minCost) {
			minCost = newCost;
			index = nextRoomIndex;
		}
	}

	pathTo[robotPosition][roomVisited] = index;
	return state[robotPosition][roomVisited] = minCost;
}

// Print path and cost
void TSP::print()
{
	std::cout << "Travelling_Salesman_Problem Solution: " << std::endl;
	std::cout << "Path: ";
	for (auto n : _path) {
		std::cout << n + 1 << "-->";
	}

	std::cout << " Path cost: " << _minPathCost << std::endl;
}
