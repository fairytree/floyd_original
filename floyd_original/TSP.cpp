#include "TSP.h"

//Time complexity - O(2^n * n^2)
//Space complexity - O(n * 2^n)

//���캯��
TSP::TSP(unsigned int startNode, const Graph& graph)
{
	// ���䣨���㣩����Ϊͼ�Ķ�������
	_totalRoomNumber = graph.vexNum();

	// ��bits����ʾ�����ж��㱻���ʹ���״̬��
	// ����һ����6�����䣨���㣩����ʼ״̬Ϊ000001���ұߵ�һ�����ִ����1�����䣬�����˴ӵ�1�����俪ʼ����Ĭ�ϵ�1�������ѱ�����)
	// ���ж��㱻���ʹ���״̬Ϊ111000ʱ��ʾ����1��2��3��������δ���ʹ�����4��5��6�������ѱ����ʹ�
	// �����з���ȫ��������ϵ�ʱ�����յ�ֵΪ111111
	_allRoomVisited = (1 << _totalRoomNumber) - 1;

	// "startNode-1"����Ϊ�û����붥��ı���Ǵ�1��ʼ��
	_startNode = startNode - 1;

	// ��ʼ�����·���ɱ�Ϊ����ֵ
	double _minPathCost = DBL_MAX;
}

//��������
TSP::~TSP()
{
}

//���ɱ������ж�����Ҫ;���ľ���·����Ϣ
void TSP::generatePath(const Floyd& floyd)
{
	// cost ��¼�����˴ӵ�ǰ����λ�ü��������״̬"������һ���估״̬����Ҫ�ĳɱ�(cost)
	std::vector<std::vector<double>> cost(_totalRoomNumber, std::vector<double>((1 << _totalRoomNumber), NULL));

	// PathTo ��¼�������з��䣨���㣩����̷���˳��
	std::vector<std::vector<unsigned int>> pathTo(_totalRoomNumber, std::vector<unsigned int>((1 << _totalRoomNumber), NULL));

	// Ĭ�ϻ����˵���ʼλ�ã����㣩�ѱ����ʹ�
	unsigned int roomVisitedState = 1 << _startNode;

	// _minPathCost ��¼�������ж������С�ɱ�֮��
	_minPathCost = tspRecursive(_startNode, roomVisitedState, cost, pathTo, floyd);

	// ���ɱ������ж�����Ҫ;���ľ���·����Ϣ
	// currentPosition��ʾ������Ŀǰ����λ�ã�nexPosition��ʾ��������һ��λ��
	unsigned int currentPosition = _startNode;
	unsigned int nextPosition = currentPosition;
	while (true) {
		//����Floyd�ĸ���������·����ѭ����������˷�����һ��������Ҫ�����Ĺ��ɶ���
		size_t bridge = floyd.pathTo()[currentPosition][nextPosition] ;
		while (bridge != nextPosition) {
			_path.push_back(bridge);
			bridge = floyd.pathTo()[bridge][nextPosition];
		}
		_path.push_back(nextPosition);

		//����TSP���ɵķ��ʶ����˳�򣬼���������һ�����㣬ֱ��ȫ���������
		unsigned int nextRoomToVisit = pathTo[nextPosition][roomVisitedState];
		if (nextRoomToVisit == NULL) {
			break;
		}

		// nextVisitedState��ʾ����һ�����䱻���ʺ����з��䱻���ʹ���״̬
		unsigned int nextVisitedState = roomVisitedState | (1 << nextRoomToVisit);
		roomVisitedState = nextVisitedState;
		currentPosition = nextPosition;
		nextPosition = nextRoomToVisit;
	}

	// �����з��䶼������Ϻ����ɻص����ľ���·��
	size_t bridge = floyd.pathTo()[nextPosition][_startNode];
	while (bridge != _startNode) {
		_path.push_back(bridge);
		bridge = floyd.pathTo()[bridge][_startNode];
	}
	_path.push_back(_startNode);
}


// �ݹ�������·��, �����ӵ�ǰ������λ�ü��������״̬�����յ㣨���з��䱻ȫ�����ʣ�����С�ɱ���·��
double TSP::tspRecursive(unsigned int robotPosition, unsigned int& roomVisitedState, 
	std::vector<std::vector<double>>& cost,
	std::vector<std::vector<unsigned int>>& pathTo,
	const Floyd& floyd)
{
	// �����з���ȫ�������ʹ��󣬷��شӵ�ǰλ�ûص����ĳɱ���cost).
	if (roomVisitedState == _allRoomVisited) {
		return floyd.distTo()[robotPosition][_startNode];
	}

	// ����ɱ��Ѿ��������ֱ��ʹ��
	if (cost[robotPosition][roomVisitedState] != NULL) {
		return cost[robotPosition][roomVisitedState];
	}

	// minCost��ʾ�ӵ�ǰ������λ�ü��������״̬�����յ㣨���з��䱻ȫ�����ʣ�����С�ɱ�
	double minCost = DBL_MAX;
	int nextRoomToVisit = -1;
	// �����˵���һ������λ�ÿ�������һ���䣨����)
	for (int nextRoomIndex = 0; nextRoomIndex < _totalRoomNumber; nextRoomIndex++) {
		// �����ѱ����ʹ��ķ��䣨���㣩
		if ((roomVisitedState & (1 << nextRoomIndex)) != 0) {
			continue;
		}

		// nextVisitedState��ʾ����һ�����䱻���ʺ����з��䱻���ʹ�����״̬
		unsigned int nextVisitedState = roomVisitedState | (1 << nextRoomIndex);
		double newCost = floyd.distTo()[robotPosition][nextRoomIndex] + tspRecursive(nextRoomIndex, nextVisitedState, cost, pathTo, floyd);
		
		//������ĳһ������(����)���ܳɱ�С������ѡ���ʱ�򣬽��÷����趨Ϊ�����˷��ʵ���һλ��
		if (newCost < minCost) {
			minCost = newCost;
			nextRoomToVisit = nextRoomIndex;
		}
	}

	pathTo[robotPosition][roomVisitedState] = nextRoomToVisit;
	return cost[robotPosition][roomVisitedState] = minCost;
}

// ��ӡ�������ж�������·����Ϣ
void TSP::printPath()
{
	std::cout << "Travelling_Salesman_Problem Solution: " << std::endl;
	std::cout << "Path: ";
	for (auto n : _path) {
		std::cout << n + 1 << "-->";
	}

	std::cout << " Path cost: " << _minPathCost << std::endl;
}
