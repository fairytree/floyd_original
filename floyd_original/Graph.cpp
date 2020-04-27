#include "Graph.h"

//构造函数
Graph::Graph(int vexnum, int edge)
	:_vexnum(vexnum), _edge(edge)  //初始化顶点数和边数
{
	_adjMatrix.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  //为邻接矩阵开辟空间和赋初值
	_distTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));
	_pathTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));
}

//析构函数
Graph::~Graph()
{
}

// 判断我们每次输入的的边的信息是否合法
//顶点从1开始编号
bool Graph::check_edge_value(int start, int end, int weight) {
	if (start < 1 || end < 1 || start > _vexnum || end > _vexnum || weight < 0) {
		return false;
	}
	return true;
}

void Graph::createGraph(int kind) {
	std::cout << "请输入每条边的起点和终点（顶点编号从1开始）以及其权重" << std::endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->_edge) {
		std::cin >> start >> end >> weight;
		//首先判断边的信息是否合法
		while (!this->check_edge_value(start, end, weight)) {
			std::cout << "输入的边的信息不合法，请重新输入" << std::endl;
			std::cin >> start >> end >> weight;
		}
		//对邻接矩阵对应上的点赋值
		_adjMatrix[start - 1][end - 1] = weight;
		//无向图添加上这行代码
		if (kind == 2)
			_adjMatrix[end - 1][start - 1] = weight;
		++count;
	}
}

void Graph::print() {
	std::cout << "图的邻接矩阵为：" << std::endl;
	int count_row = 0; //打印行的标签
	int count_col = 0; //打印列的标签
					   //开始打印
	while (count_row != this->_vexnum) {
		count_col = 0;
		while (count_col != this->_vexnum) {
			if (_adjMatrix[count_row][count_col] == INT_MAX)
				std::cout << "∞" << " ";
			else
				std::cout << _adjMatrix[count_row][count_col] << " ";
			++count_col;
		}
		std::cout << std::endl;
		++count_row;
	}
}


