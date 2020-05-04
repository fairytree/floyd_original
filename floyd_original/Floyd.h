#pragma once

#include"Graph.h"

class Floyd 
{
private:
    size_t _vexNum;    // ͼ�Ķ������ number of vertices  
    size_t _edgeNum;  // ͼ�ı��� number of edges
    std::vector<std::vector<double>> _distTo;   // ��¼������Ե���̾���(weight) 
    std::vector<std::vector<size_t>> _pathTo;  //  ��¼������Ե����·����Ϣ�����ɶ�����Ϣ��

public:
    //���캯��
    Floyd(const Graph& graph);

    //��������
    ~Floyd();

    // Generate Path
    void generatePath(const Graph& graph);

    // ���ص������������̾���(weight)
    std::vector<std::vector<double>> distTo() const { return _distTo; };

    //  ���ص�������������·������Ϣ
    std::vector<std::vector<size_t>> pathTo() const { return _pathTo; };

    //��ӡ���·��
    void printPath();
};

