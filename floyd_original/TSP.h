#pragma once

#include"Graph.h"

class TSP
{
private:
	int _startNode;   //��ʼ����
	int _allRoomVisited;  //����state
	double _minPathCost = DBL_MAX;  //���·��cost
	std::vector<std::vector<double>> _adjMatrix;  //�ڽӾ���
	std::vector<int> _path;  //���·��

public:
	//���캯��
	TSP(int startNode, const std::vector<std::vector<double>>& adjMatrix);
	//��������
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


