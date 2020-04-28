#include "Floyd_new.h"

std::vector<std::vector<double>> floyd(const Graph& graph) {
	// _distTo ��¼�������������̾���(weight)
	std::vector<std::vector<double>> _distTo = graph.adjMatrix();
	// _pathTo ��¼��������������·������Ϣ
	std::vector<std::vector<size_t>> _pathTo(graph.vexNum(), std::vector<size_t>(graph.vexNum(), UINT_MAX));

	//����_pathTo�ĳ�ֵΪ�����ߵ��յ㶥��
	for (size_t row = 0; row < graph.vexNum(); ++row) {
		for (size_t col = 0; col < graph.vexNum(); ++col) {
			if (_distTo[row][col] != UINT_MAX) {
				_pathTo[row][col] = col;
			}
		}
	}

	//����ѭ�������ڼ���ÿ������Ե����·��
	for (size_t bridge = 0; bridge < graph.vexNum(); ++bridge) {
		for (size_t row = 0; row < graph.vexNum(); ++row) {
			for (size_t col = 0; col < graph.vexNum(); ++col) {
				double new_distTo = (_distTo[row][bridge] == UINT_MAX || _distTo[bridge][col] == UINT_MAX) ? UINT_MAX : (_distTo[row][bridge] + _distTo[bridge][col]);
				if (_distTo[row][col] > new_distTo) {
					_distTo[row][col] = new_distTo;
					_pathTo[row][col] = _pathTo[row][bridge];
				}
			}
		}
	}


	// ��ӡ������Ե����·����Ϣ
	std::cout << "��������Ե����·����" << std::endl;
	for (size_t row = 0; row < graph.vexNum(); ++row) {
		for (size_t col = 0; col < graph.vexNum(); ++col) {
			std::cout << "v" << std::to_string(row + 1) << "---"
				<< "v" << std::to_string(col + 1) << " weight: "
				<< _distTo[row][col] << "; pathTo: "
				<< " v" << std::to_string(row + 1);
			size_t bridge = _pathTo[row][col];

			while (bridge != col) {
				std::cout << "-->" << "v" << std::to_string(bridge + 1);
				bridge = _pathTo[bridge][col];
			}
			std::cout << "-->" << "v" << std::to_string(col + 1) << std::endl;
		}
	}
	return _distTo;
}