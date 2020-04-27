#include"Floyd.h"

//���캯��
Graph_DG::Graph_DG(int vexnum, int edge)
    :_vexnum(vexnum), _edge(edge)  //��ʼ���������ͱ���
{    
    _adjMatrix.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  //Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
    _distTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));  
    _pathTo.assign(_vexnum, std::vector<int>(_vexnum, INT_MAX));
}

//��������
Graph_DG::~Graph_DG() 
{
}

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if (start < 1 || end < 1 || start > _vexnum || end > _vexnum || weight < 0) {
        return false;
    }
    return true;
}

void Graph_DG::createGraph(int kind) {
    std::cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << std::endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while (count != this->_edge) {
        std::cin >> start >> end >> weight;
        //�����жϱߵ���Ϣ�Ƿ�Ϸ�
        while (!this->check_edge_value(start, end, weight)) {
            std::cout << "����ıߵ���Ϣ���Ϸ�������������" << std::endl;
            std::cin >> start >> end >> weight;
        }
        //���ڽӾ����Ӧ�ϵĵ㸳ֵ
        _adjMatrix[start - 1][end - 1] = weight;
        //����ͼ��������д���
        if (kind == 2)
            _adjMatrix[end - 1][start - 1] = weight;
        ++count;
    }
}

void Graph_DG::print() {
    std::cout << "ͼ���ڽӾ���Ϊ��" << std::endl;
    int count_row = 0; //��ӡ�еı�ǩ
    int count_col = 0; //��ӡ�еı�ǩ
                       //��ʼ��ӡ
    while (count_row != this->_vexnum) {
        count_col = 0;
        while (count_col != this->_vexnum) {
            if (_adjMatrix[count_row][count_col] == INT_MAX)
                std::cout << "��" << " ";
            else
                std::cout << _adjMatrix[count_row][count_col] << " ";
            ++count_col;
        }
        std::cout << std::endl;
        ++count_row;
    }
}

void Graph_DG::Floyd() {
    int row = 0;
    int col = 0;
    for (row = 0; row < _vexnum; row++) {
        for (col = 0; col < _vexnum; col++) {
            //�Ѿ���D��ʼ��Ϊ�ڽӾ����ֵ
            _distTo[row][col] = _adjMatrix[row][col];
            //����P�ĳ�ֵ��Ϊ�����ߵ��յ㶥����±�
            _pathTo[row][col] = col;
        }
    }

    //����ѭ�������ڼ���ÿ����Ե����·��
    int temp = 0;
    int select = 0;
    for (temp = 0; temp < this->_vexnum; temp++) {
        for (row = 0; row < this->_vexnum; row++) {
            for (col = 0; col < this->_vexnum; col++) {
                //Ϊ�˷�ֹ�����������Ҫ����һ��selectֵ
                select = (_distTo[row][temp] == INT_MAX || _distTo[temp][col] == INT_MAX) ? INT_MAX : (_distTo[row][temp] + _distTo[temp][col]);
                if (_distTo[row][col] > select) {
                    //�������ǵ�D����
                    _distTo[row][col] = select;
                    //�������ǵ�P����
                    _pathTo[row][col] = _pathTo[row][temp];
                }
            }
        }
    }
}

void Graph_DG::print_pathTo() {
    std::cout << "��������Ե����·����" << std::endl;
    int row = 0;
    int col = 0;
    int temp = 0;
    for (row = 0; row < this->_vexnum; row++) {
        for (col = row + 1; col < this->_vexnum; col++) {
            std::cout << "v" << std::to_string(row + 1) << "---" << "v" << std::to_string(col + 1) << " weight: "
                << _distTo[row][col] << " pathTo: " << " v" << std::to_string(row + 1);
            temp = _pathTo[row][col];
            //ѭ�����;����ÿ��·����
            while (temp != col) {
                std::cout << "-->" << "v" << std::to_string(temp + 1);
                temp = _pathTo[temp][col];
            }
            std::cout << "-->" << "v" << std::to_string(col + 1) << std::endl;
        }

        std::cout << std::endl;
    }
}


