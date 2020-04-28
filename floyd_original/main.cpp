//#include"Floyd.h"
#include"Floyd_new.h"
#include "Graph.h"
#include"TSP.h"

int main() {

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

	// ����ͼ��
	Graph graph;
	// ��ӡͼ��
	graph.print();
	
	// ��Floyd Algorithm����������֮����̾�����Ϣ������ӡ��
	floyd(graph);
	
	//Floyd floyd(graph);
	//floyd.printPathto();
	
	// ��Travelling_Salesman_Problem(TSP) Algorithm����������ж�������·����Ϣ��
	TSP tspSolver(1, graph.adjMatrix());
	//��ӡTSP���
	tspSolver.print();

	return 0;
}

