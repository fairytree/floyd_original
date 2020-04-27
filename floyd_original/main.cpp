#include"Floyd.h"
#include "Graph.h"


int main() {
	
	Graph_DG graph(vexnum, edge);
	graph.createGraph(kind);
	graph.print();
	graph.Floyd();
	graph.print_pathTo();
	system("pause");
	return 0;
}

