#pragma once

#include"Graph.h"

class TSP
{
private:
	int _startNode;   //��ʼ����
	int _finishedState;  //����state
	double _minTourCost = DBL_MAX;  //���·��cost
	std::vector<std::vector<double>> _adjMatrix;  //�ڽӾ���
	std::vector<int> _tour;  //���·��

public:
	//���캯��
	TSP(int startNode, const std::vector<std::vector<double>>& adjMatrix);
	//��������
	~TSP();
	// travelling_salesman_problem algorithm (tsp)
	double tsp(int i, int& state, std::vector<std::vector<double>>& memo,
		std::vector<std::vector<int>>& prev, 
		const std::vector<std::vector<double>>& adjMatrix);
	//print path and cost
	void print();
};


