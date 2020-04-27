#pragma once

#include<iostream>
#include<string>
#include<vector>

class Graph 
{
private:
	int _vexnum;    // ͼ�Ķ������ number of vertices, differentiate member variable from parameter by beginning with underscore "_".  
	int _edge;  // ͼ�ı��� number of edges
	std::vector<std::vector<int>> _adjMatrix;  //  �ڽӾ���, ��¼ͼ�ж���ͱߵĹ�ϵ, adjacency matrix

public:
	//���캯��
	Graph();
	//��������
	~Graph();
	// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
	bool check_edge_value(int start, int end, int weight);
	//��ӡ�ڽӾ���
	void print();
};


