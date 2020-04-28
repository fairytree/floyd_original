#include"Floyd.h"
#include "Graph.h"
#include"TSP.h"

int main() {
	Graph graph;
	graph.print();
	Floyd floyd(graph);
	floyd.printPathto();


	//  test example
	//  ����ͼ�����ࣺ1��������ͼ��2��������ͼ
	//	2
	//	����ͼ�Ķ�������ͱߵ�������
	//	6 6
	//	������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��
	//	2 5 2
	//	5 3 4
	//	3 4 6
	//	4 1 8
	//	1 6 10
	//	6 2 12
	//  TSP path: 1-->4-->3-->5-->2-->6-->1
	//  TSP cost:42.0

	// Run the solver, the first node is # 1. 
	TSP solver(1, graph.adjMatrix());

	// Prints: [0, 3, 2, 4, 1, 5, 0]
	// Print: 42.0
	solver.print();

	return 0;
}

