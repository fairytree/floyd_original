#include"Floyd.h"
#include "Graph.h"


int main() {
	
	Graph graph;
	graph.print();
	Floyd floyd(graph);
	floyd.printPathto();
	return 0;
}

