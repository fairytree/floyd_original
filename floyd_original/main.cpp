#include"Floyd.h"
//#include"Floyd_function.h"
#include "Graph.h"
#include"TSP.h"

int main() {

	//  test example
	//  输入图的种类：1代表有向图，2代表无向图
	//	2
	//	输入图的顶点个数和边的条数：
	//	8 9
	//	请输入每条边的起点和终点（顶点编号从1开始）以及其权重
	//	1 5 10
	//	3 5 10
	//  4 5 10
	//	5 2 10
	//	2 6 10
	//	6 7 10
	//  2 8 10
	//  5 8 1
	//  3 6 1
	//  TSP path:  1-->5-->3-->6-->7-->6-->2-->8-->5-->4-->5-->1
	//  TSP cost:  92

	// 创建图；
	Graph graph;
	// 打印图；
	graph.print();
	
	// 用Floyd algorithm(function)计算任意两个顶点之间的最短距离及路径，并打印；
	//floyd(graph);
	
	// 用Floyd algorithm(Class)计算任意两个顶点之间的最短距离及路径，并打印；
	Floyd floyd(graph);
	floyd.generatePath(graph);
	floyd.printPath();
	
	// 用Travelling_Salesman_Problem(TSP) Algorithm计算遍历所有顶点的最短路径信息，并打印
	TSP tspSolver(2, graph);  // 1代表从第一个顶点开始
	tspSolver.generatePath(floyd);
	tspSolver.printPath();

	return 0;
}

