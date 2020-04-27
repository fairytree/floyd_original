#include "Graph.h"

//���캯��
Graph::Graph(int vexnum, int edge)
	:_vexnum(vexnum), _edge(edge)  //��ʼ���������ͱ���
{
	_adjMatrix.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  //Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
	_distTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));
	_pathTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));
}

//��������
Graph::~Graph()
{
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph::check_edge_value(int start, int end, int weight) {
	if (start < 1 || end < 1 || start > _vexnum || end > _vexnum || weight < 0) {
		return false;
	}
	return true;
}

void Graph::createGraph(int kind) {
	std::cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << std::endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->_edge) {
		std::cin >> start >> end >> weight;
		//�����жϱߵ���Ϣ�Ƿ�Ϸ�
		while (!this->check_edge_value(start, end, weight)) {
			std::cout << "����ıߵ���Ϣ���Ϸ�������������" << std::endl;
			std::cin >> start >> end >> weight;
		}
		//���ڽӾ����Ӧ�ϵĵ㸳ֵ
		_adjMatrix[start - 1][end - 1] = weight;
		//����ͼ��������д���
		if (kind == 2)
			_adjMatrix[end - 1][start - 1] = weight;
		++count;
	}
}

void Graph::print() {
	std::cout << "ͼ���ڽӾ���Ϊ��" << std::endl;
	int count_row = 0; //��ӡ�еı�ǩ
	int count_col = 0; //��ӡ�еı�ǩ
					   //��ʼ��ӡ
	while (count_row != this->_vexnum) {
		count_col = 0;
		while (count_col != this->_vexnum) {
			if (_adjMatrix[count_row][count_col] == INT_MAX)
				std::cout << "��" << " ";
			else
				std::cout << _adjMatrix[count_row][count_col] << " ";
			++count_col;
		}
		std::cout << std::endl;
		++count_row;
	}
}


