#include"Floyd.h"
#include "Graph.h"

bool check(int vexnum, int edge);

int main() {
	int vexnum;
	int edge;
	int kind;

	std::cout << "����ͼ�����ࣺ1��������ͼ��2��������ͼ" << std::endl;
	std::cin >> kind;
	//�ж������kind�Ƿ�Ϸ�
	while (kind != 1 && kind != 2) {
		std::cout << "�����ͼ�������Ų��Ϸ������������룺1��������ͼ��2��������ͼ" << std::endl;
		std::cin >> kind;
	}

	std::cout << "����ͼ�Ķ�������ͱߵ�������" << std::endl;
	std::cin >> vexnum >> edge;
	while (!check(vexnum, edge)) {
		std::cout << "�������ֵ���Ϸ�������������" << std::endl;
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

//������������Ͷ�������ֵ�Ƿ���Ч
//�������ͱ����Ĺ�ϵ�ǣ�((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int vexnum, int edge)
{
	if (vexnum <= 0 || edge <= 0 || ((vexnum * (vexnum - 1)) / 2) < edge) {
		return false;
	}
	return true;
}