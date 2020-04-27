#include"Floyd.h"
#include "Graph.h"

bool check(int vexnum, int edge);

int main() {
	int vexnum;
	int edge;
	int kind;

	std::cout << "输入图的种类：1代表有向图，2代表无向图" << std::endl;
	std::cin >> kind;
	//判读输入的kind是否合法
	while (kind != 1 && kind != 2) {
		std::cout << "输入的图的种类编号不合法，请重新输入：1代表有向图，2代表无向图" << std::endl;
		std::cin >> kind;
	}

	std::cout << "输入图的顶点个数和边的条数：" << std::endl;
	std::cin >> vexnum >> edge;
	while (!check(vexnum, edge)) {
		std::cout << "输入的数值不合法，请重新输入" << std::endl;
		std::cin >> vexnum >> edge;
	}

	Graph_DG graph(vexnum, edge);
	graph.createGraph(kind);
	graph.print();
	graph.Floyd();
	graph.print_pathTo();
	system("pause");
	return 0;
}

//检验输入边数和顶点数的值是否有效
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int vexnum, int edge)
{
	if (vexnum <= 0 || edge <= 0 || ((vexnum * (vexnum - 1)) / 2) < edge) {
		return false;
	}
	return true;
}