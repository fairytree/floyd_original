#include "Graph.h"

//构造函数
Graph::Graph()
{
	std::cout << "输入图的种类：1代表有向图，2代表无向图" << std::endl;
	std::cin >> _kind;
	//判读输入的kind是否合法
	while (_kind != 1 && _kind != 2) {
		std::cout << "输入的图的种类编号不合法，请重新输入：1代表有向图，2代表无向图" << std::endl;
		std::cin >> _kind;
	}

	std::cout << "输入图的顶点个数和边的条数：" << std::endl;
	std::cin >> _vexnum >> _edge;
	while (!checkVexnum(_vexnum, _edge)) {
		std::cout << "输入的数值不合法，请重新输入" << std::endl;
		std::cin >> _vexnum >> _edge;
	}


		std::cout << "请输入每条边的起点和终点（顶点编号从1开始）以及其权重" << std::endl;
		int start;
		int end;
		int weight;
		int count = 0;
		while (count != this->_edge) {
			std::cin >> start >> end >> weight;
			//首先判断边的信息是否合法
			while (!this->checkEdgeValue(start, end, weight)) {
				std::cout << "输入的边的信息不合法，请重新输入" << std::endl;
				std::cin >> start >> end >> weight;
			}

			_adjMatrix.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  //为邻接矩阵开辟空间和赋初值

			//对邻接矩阵对应上的点赋值
			_adjMatrix[start - 1][end - 1] = weight;
			//无向图添加上这行代码
			if (kind == 2)
				_adjMatrix[end - 1][start - 1] = weight;
			++count;


		}
	}

}



public class EdgeWeightedDigraph
{
	private final int V; // number of vertices
	private int E; // number of edges
	private Bag<DirectedEdge>[] adj; // adjacency lists
	public EdgeWeightedDigraph(int V)
	{
		this.V = V;
		this.E = 0;
		adj = (Bag<DirectedEdge>[]) new Bag[V];
		for (int v = 0; v < V; v++)
			adj[v] = new Bag<DirectedEdge>();
	}
	public EdgeWeightedDigraph(In in)
		// See Exercise 4.4.2.
		public int V() { return V; }
	public int E() { return E; }
	public void addEdge(DirectedEdge e)
	{
		adj[e.from()].add(e);
		E++;
	}
	public Iterable<Edge> adj(int v)
	{
		return adj[v];
	}
	public Iterable<DirectedEdge> edges()
	{
		Bag<DirectedEdge> bag = new Bag<DirectedEdge>();
		for (int v = 0; v < V; v++)
			for (DirectedEdge e : adj[v])
				bag.add(e);
		return bag;
	}
}


//析构函数
Graph::~Graph()
{
}

//检验输入边数和顶点数的值是否有效
bool checkVexnum(size_t vexnum, size_t edge)
{
	if (vexnum <= 0 || edge <= 0 || edge > (vexnum * (vexnum - 1)) || edge < (vexnum - 1)) {
		return false;
	}
	return true;
}

// 判断我们每次输入的的边的信息是否合法
bool Graph::checkEdgeValue(size_t start, size_t end, int weight) {
	if (start < 1 || end < 1 || start > _vexnum || end > _vexnum ) {
		return false;
	}
	return true;
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


