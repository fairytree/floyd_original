#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Graph.h"

class Floyd {
private:
    int _vexNum;    // ͼ�Ķ������ number of vertices  
    int _edgeNum;  // ͼ�ı��� number of edges
    std::vector<std::vector<int>> _adjMatrix;  //  �ڽӾ���, ��¼ͼ�ж���ͱߵĹ�ϵ, adjacency matrix
    std::vector<std::vector<int>> _distTo;   // ��¼�������������̾���(weight) 
    std::vector<std::vector<int>> _pathTo;  //  ��¼��������������·������Ϣ

public:
    //���캯��
    Floyd(Graph graph);
    //��������
    ~Floyd();
    //��ӡ���·��
    void printPathto();
};

