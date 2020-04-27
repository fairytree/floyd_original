#pragma once

#include<iostream>
#include<string>
#include<vector>

class Graph 
{
private:
	int _vexnum;    // 图的顶点个数 number of vertices, differentiate member variable from parameter by beginning with underscore "_".  
	int _edge;  // 图的边数 number of edges
	std::vector<std::vector<int>> _adjMatrix;  //  邻接矩阵, 记录图中顶点和边的关系, adjacency matrix

public:
	//构造函数
	Graph();
	//析构函数
	~Graph();
	// 判断我们每次输入的的边的信息是否合法
	bool check_edge_value(int start, int end, int weight);
	//打印邻接矩阵
	void print();
};


