//#include"Floyd.h"
#include"Floyd_new.h"
#include "Graph.h"
#include"TSP.h"

int main() {

	//  test example
	//  输入图的种类：1代表有向图，2代表无向图
	//	2
	//	输入图的顶点个数和边的条数：
	//	6 6
	//	请输入每条边的起点和终点（顶点编号从1开始）以及其权重
	//	2 5 2
	//	5 3 4
	//	3 4 6
	//	4 1 8
	//	1 6 10
	//	6 2 12
	//  TSP path: 1-->4-->3-->5-->2-->6-->1
	//  TSP cost:42.0

	// 创建图；
	Graph graph;
	// 打印图；
	graph.print();
	
	// 用Floyd Algorithm计算各顶点对之间最短距离信息，并打印；
	floyd(graph);
	
	//Floyd floyd(graph);
	//floyd.printPathto();
	
	// 用Travelling_Salesman_Problem(TSP) Algorithm计算遍历所有顶点的最短路径信息；
	TSP tspSolver(1, graph.adjMatrix());
	//打印TSP结果
	tspSolver.print();

	return 0;
}

