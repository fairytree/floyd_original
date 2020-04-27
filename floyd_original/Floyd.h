#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Graph.h"

class Floyd {
private:
    int _vexNum;    // 图的顶点个数 number of vertices  
    int _edgeNum;  // 图的边数 number of edges
    std::vector<std::vector<int>> _adjMatrix;  //  邻接矩阵, 记录图中顶点和边的关系, adjacency matrix
    std::vector<std::vector<int>> _distTo;   // 记录到各个顶点的最短距离(weight) 
    std::vector<std::vector<int>> _pathTo;  //  记录到各个顶点的最短路径的信息

public:
    //构造函数
    Floyd(Graph graph);
    //析构函数
    ~Floyd();
    //打印最短路径
    void printPathto();
};

