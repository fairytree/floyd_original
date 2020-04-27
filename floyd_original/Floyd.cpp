#include"Floyd.h"

//构造函数
Graph_DG::Graph_DG(int vexnum, int edge)
    :_vexnum(vexnum), _edge(edge)  //初始化顶点数和边数
{    
    _adjMatrix.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  //为邻接矩阵开辟空间和赋初值
    _distTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  
    _pathTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));
}

//析构函数
Graph_DG::~Graph_DG() 
{
}

// 判断我们每次输入的的边的信息是否合法
//顶点从1开始编号
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if (start < 1 || end < 1 || start > _vexnum || end > _vexnum || weight < 0) {
        return false;
    }
    return true;
}

void Graph_DG::createGraph(int kind) {
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

void Graph_DG::print() {
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

void Graph_DG::Floyd() {
    int row = 0;
    int col = 0;
    for (row = 0; row < _vexnum; row++) {
        for (col = 0; col < _vexnum; col++) {
            //把矩阵D初始化为邻接矩阵的值
            _distTo[row][col] = _adjMatrix[row][col];
            //矩阵P的初值则为各个边的终点顶点的下标
            _pathTo[row][col] = col;
        }
    }

    //三重循环，用于计算每个点对的最短路径
    int temp = 0;
    int select = 0;
    for (temp = 0; temp < this->_vexnum; temp++) {
        for (row = 0; row < this->_vexnum; row++) {
            for (col = 0; col < this->_vexnum; col++) {
                //为了防止溢出，所以需要引入一个select值
                select = (_distTo[row][temp] == INT_MAX || _distTo[temp][col] == INT_MAX) ? INT_MAX : (_distTo[row][temp] + _distTo[temp][col]);
                if (_distTo[row][col] > select) {
                    //更新我们的D矩阵
                    _distTo[row][col] = select;
                    //更新我们的P矩阵
                    _pathTo[row][col] = _pathTo[row][temp];
                }
            }
        }
    }
}

void Graph_DG::print_pathTo() {
    std::cout << "各个顶点对的最短路径：" << std::endl;
    int row = 0;
    int col = 0;
    int temp = 0;
    for (row = 0; row < this->_vexnum; row++) {
        for (col = row + 1; col < this->_vexnum; col++) {
            std::cout << "v" << std::to_string(row + 1) << "---" << "v" << std::to_string(col + 1) << " weight: "
                << _distTo[row][col] << " pathTo: " << " v" << std::to_string(row + 1);
            temp = _pathTo[row][col];
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


