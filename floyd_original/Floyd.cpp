#include"Floyd.h"


//���캯��
Floyd::Floyd(const Graph& graph) 
	:_vexNum(graph.vexNum()), _edgeNum(graph.edgeNum()), _distTo(graph.adjMatrix())
{
	_pathTo.assign(_vexNum, std::vector<size_t>(_vexNum, UINT_MAX));

	//����_pathTo�ĳ�ֵΪ�����ߵ��յ㶥��
	for (size_t row = 0; row < _vexNum; ++row) {
		for (size_t col = 0; col < _vexNum; ++col) {
			if (graph.adjMatrix()[row][col] != UINT_MAX) {
				_pathTo[row][col] = col;
			}
		}
	}
}


//��������
Floyd::~Floyd()
{
}

void Floyd::generatePath(const Graph& graph)
{
	//����ѭ�������ڼ���ÿ������Ե����·��
	for (size_t bridge = 0; bridge < _vexNum; ++bridge) {
		for (size_t row = 0; row < _vexNum; ++row) {
			for (size_t col = 0; col < _vexNum; ++col) {
				double new_distTo = (_distTo[row][bridge] == UINT_MAX || _distTo[bridge][col] == UINT_MAX) ? UINT_MAX : (_distTo[row][bridge] + _distTo[bridge][col]);
				if (_distTo[row][col] > new_distTo) {
					_distTo[row][col] = new_distTo;
					_pathTo[row][col] = _pathTo[row][bridge];
				}
			}
		}
	}
}

//��ӡ������Ե����·����Ϣ
void Floyd::printPath() {
	std::cout << "Floyd��������Ե����·����" << std::endl;
	for (size_t row = 0; row < _vexNum; ++row) {
		for (size_t col = 0; col < _vexNum; ++col) {
			std::cout << "v" << std::to_string(row + 1) << "---"
				<< "v" << std::to_string(col + 1) << " weight: "
				<< _distTo[row][col] << "; pathTo: "
				<< " v" << std::to_string(row + 1);
			size_t bridge = _pathTo[row][col];
			//ѭ�����;����ÿ��·����
			while (bridge != col) {
				std::cout << "-->" << "v" << std::to_string(bridge + 1);
				bridge = _pathTo[bridge][col];
			}
			std::cout << "-->" << "v" << std::to_string(col + 1) << std::endl;
		}
	}
}


