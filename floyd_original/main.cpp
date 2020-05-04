#include"Floyd.h"
//#include"Floyd_function.h"
#include "Graph.h"
#include"TSP.h"

int main() {

	//  test example
	//  ����ͼ�����ࣺ1��������ͼ��2��������ͼ
	//	2
	//	����ͼ�Ķ�������ͱߵ�������
	//	8 9
	//	������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��
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

	// ����ͼ��
	Graph graph;
	// ��ӡͼ��
	graph.print();
	
	// ��Floyd algorithm(function)����������������֮�����̾��뼰·��������ӡ��
	//floyd(graph);
	
	// ��Floyd algorithm(Class)����������������֮�����̾��뼰·��������ӡ��
	Floyd floyd(graph);
	floyd.generatePath(graph);
	floyd.printPath();
	
	// ��Travelling_Salesman_Problem(TSP) Algorithm����������ж�������·����Ϣ������ӡ
	TSP tspSolver(2, graph);  // 1����ӵ�һ�����㿪ʼ
	tspSolver.generatePath(floyd);
	tspSolver.printPath();

	return 0;
}

