#pragma once

#include"Graph.h"

class TSP
{
private:
	int _startNode;   //起始顶点
	int _allRoomVisited;  //结束state
	double _minPathCost = DBL_MAX;  //最短路径cost
	std::vector<std::vector<double>> _adjMatrix;  //邻接矩阵
	std::vector<int> _path;  //最短路径

public:
	//构造函数
	TSP(int startNode, const std::vector<std::vector<double>>& adjMatrix);
	//析构函数
	~TSP();
	//solver
	void solver(const std::vector<std::vector<double>>& adjMatrix);
	// travelling_salesman_problem algorithm (tsp)
	double tspRecursive(int i, int& state, std::vector<std::vector<double>>& memo,
		std::vector<std::vector<int>>& prev, 
		const std::vector<std::vector<double>>& adjMatrix);
	//print path and cost
	void print();
};


