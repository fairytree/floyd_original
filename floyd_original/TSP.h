#pragma once

#include"Graph.h"
#include"Floyd.h"
#include <bitset>

class TSP
{
private:
	size_t _totalRoomNumber; // ���������
	unsigned int _startNode;   //��ʼ����
	unsigned int _allRoomVisited;  //����ʱ�����з��䣨���㣩�����ʹ���״̬
	double _minPathCost;  //���·��cost
	std::vector<unsigned int> _path;  //���·��

public:
	// ���캯��
	TSP(unsigned int startNode, const Graph& graph);
	
	// ��������
	~TSP();
	
	// ���ɱ������ж�����Ҫ;���ľ���·����Ϣ
	void generatePath(const Floyd& floyd);

	// �ݹ�������·��
	double tspRecursive(unsigned int robotPosition, unsigned int& roomVisitedState,
		std::vector<std::vector<double>>& cost,
		std::vector<std::vector<unsigned int>>& pathTo,
		const Floyd& floyd);

	// ��ӡ�������ж�������·����Ϣ
	void printPath();
};


