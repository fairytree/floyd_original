#include"Floyd.h"

//构造函数
Floyd::Floyd(Graph graph)
	:_vexNum(graph.vexNum()), _edgeNum(graph.edgeNum()), 
	_adjMatrix(graph.adjMatrix()), _distTo(graph.adjMatrix())
{
	_pathTo.assign(_vexNum, std::vector<size_t>(_vexNum, INT_MAX));

	//矩阵P的初值则为各个边的终点顶点的下标???
	for (size_t row = 0; row < _vexNum; ++row) {
		for (size_t col = 0; col < _vexNum; ++col) {
			while (_adjMatrix[row][col] != INT_MAX); {
				_pathTo[row][col] = col;
			}
		}
	}

	//三重循环，用于计算每个顶点对的最短路径
	for (size_t bridge = 0; bridge < _vexNum; ++bridge) {
		for (size_t row = 0; row < _vexNum; ++row) {
			for (size_t col = 0; col < _vexNum; ++col) {
				double new_distTo = (_distTo[row][bridge] == INT_MAX || _distTo[bridge][col] == INT_MAX) ? INT_MAX : (_distTo[row][bridge] + _distTo[bridge][col]);
				if (_distTo[row][col] > new_distTo) {
					_distTo[row][col] = new_distTo;
					_pathTo[row][col] = _pathTo[row][bridge];
				}
			}
		}
	}
}


//析构函数
Floyd::~Floyd()
{
}

void Floyd::printPathto() {
	std::cout << "各个顶点对的最短路径：" << std::endl;
	for (size_t row = 0; row < _vexNum; ++row) {
		for (size_t col = row + 1; col < _vexNum; ++col) {
			std::cout << "v" << std::to_string(row + 1) << "---"
				<< "v" << std::to_string(col + 1) << " weight: "
				<< _distTo[row][col] << " pathTo: "
				<< " v" << std::to_string(row + 1);
			size_t temp = _pathTo[row][col];
			//循环输出途径的每条路径。
			while (temp != col) {
				std::cout << "-->" << "v" << std::to_string(temp + 1);
				temp = _pathTo[temp][col];
			}
			std::cout << "-->" << "v" << std::to_string(col + 1) << std::endl;
		}
		std::cout << std::endl;
	}
}


