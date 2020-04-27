#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Graph.h"

class Floyd {
private:
    int _vexnum;    // ͼ�Ķ������ number of vertices, differentiate member variable from parameter by beginning with underscore "_".  
    int _edge;  // ͼ�ı��� number of edges
    std::vector<std::vector<int>> _adjMatrix;  //  �ڽӾ���, ��¼ͼ�ж���ͱߵĹ�ϵ, adjacency matrix
    std::vector<std::vector<int>> _distTo;   // ��¼�������������̾��� 
    std::vector<std::vector<int>> _pathTo;  // ��¼�������·������Ϣ

public:
    //���캯��
    Graph_DG(int vexnum, int edge);
    //��������
    ~Graph_DG();
    // �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
    //�����1��ʼ���
    bool check_edge_value(int start, int end, int weight);
    //����ͼ
    void createGraph(int);
    //��ӡ�ڽӾ���
    void print();
    //�����·��
    void Floyd();
    //��ӡ���·��
    void print_pathTo();
};

