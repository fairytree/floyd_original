#pragma once

//#include"Graph.h"
//#include"Floyd.h"
#include<vector>
#include <iostream>

class TSP
{
private:
	int _nodeNum;
	int _startNode;
	int _finishedState;
	double _minTourCost = DBL_MAX;
	bool _ranSolver = false;

	std::vector<std::vector<double>> _distance;
	std::vector<int> _tour;



public:
	//构造函数
	TSP(int startNode, std::vector<std::vector<double>> distance);
	//析构函数
	~TSP();
	// Returns the optimal tour for the traveling salesman problem.
	std::vector<int> getTour();
	// Returns the minimal tour cost.
	double getTourCost();
	// Run the solver
	void solve();
	// tsp
	double tsp(int i, int& state, std::vector<std::vector<double>>& memo,
		std::vector<std::vector<int>>& prev);
	//print path and cost
	void print();
};


