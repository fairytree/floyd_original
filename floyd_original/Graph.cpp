#include "Graph.h"

//���캯��
Graph::Graph()
{
	std::cout << "����ͼ�����ࣺ1��������ͼ��2��������ͼ" << std::endl;
	std::cin >> _kind;
	//�ж������kind�Ƿ�Ϸ�
	while (_kind != 1 && _kind != 2) {
		std::cout << "�����ͼ�������Ų��Ϸ������������룺1��������ͼ��2��������ͼ" << std::endl;
		std::cin >> _kind;
	}

	std::cout << "����ͼ�Ķ�������ͱߵ�������" << std::endl;
	std::cin >> _vexnum >> _edge;
	while (!checkVexnum(_vexnum, _edge)) {
		std::cout << "�������ֵ���Ϸ�������������" << std::endl;
		std::cin >> _vexnum >> _edge;
	}


		std::cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << std::endl;
		int start;
		int end;
		int weight;
		int count = 0;
		while (count != this->_edge) {
			std::cin >> start >> end >> weight;
			//�����жϱߵ���Ϣ�Ƿ�Ϸ�
			while (!this->checkEdgeValue(start, end, weight)) {
				std::cout << "����ıߵ���Ϣ���Ϸ�������������" << std::endl;
				std::cin >> start >> end >> weight;
			}

			_adjMatrix.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  //Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ

			//���ڽӾ����Ӧ�ϵĵ㸳ֵ
			_adjMatrix[start - 1][end - 1] = weight;
			//����ͼ��������д���
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


//��������
Graph::~Graph()
{
}

//������������Ͷ�������ֵ�Ƿ���Ч
bool checkVexnum(size_t vexnum, size_t edge)
{
	if (vexnum <= 0 || edge <= 0 || edge > (vexnum * (vexnum - 1)) || edge < (vexnum - 1)) {
		return false;
	}
	return true;
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
bool Graph::checkEdgeValue(size_t start, size_t end, int weight) {
	if (start < 1 || end < 1 || start > _vexnum || end > _vexnum ) {
		return false;
	}
	return true;
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


