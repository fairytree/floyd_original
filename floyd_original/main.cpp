#include"Floyd.h"
#include "Graph.h"
#include"TSP.h"

int main() {
	Graph graph;
	graph.print();
	Floyd floyd(graph);
	floyd.printPathto();


	// Create adjacency matrix
	//int n = 6;
	//std::vector<std::vector<double>> distanceMatrix(n, std::vector<double>(n, DBL_MAX));
	//distanceMatrix[1][4] = distanceMatrix[4][1] = 2;
	//distanceMatrix[4][2] = distanceMatrix[2][4] = 4;
	//distanceMatrix[2][3] = distanceMatrix[3][2] = 6;
	//distanceMatrix[3][0] = distanceMatrix[0][3] = 8;
	//distanceMatrix[0][5] = distanceMatrix[5][0] = 10;
	//distanceMatrix[5][1] = distanceMatrix[1][5] = 12;

	// Run the solver
	TSP solver(1, graph.adjMatrix());

	// Prints: [0, 3, 2, 4, 1, 5, 0]
	// Print: 42.0
	solver.print();

	return 0;
}

