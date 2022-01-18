#ifndef MST_H
#define MST_H
#include"Graph.h"

typedef Graph::Vertex Vertex;//����
typedef Graph::Edge Edge;//����
typedef std::list<Graph::Vertex> VrtxList;//���� ����Ʈ
typedef std::list<Graph::Edge> EdgeList;//���� ����Ʈ
typedef std::list<Vertex> ::iterator VrtxItor;//�ݺ���
typedef std::list<Edge>::iterator EdgeItor;//�ݺ���

class MinimumSpanningTree
{
protected:
	Graph& graph;//�׷���
	bool done;//Ž���� �������� �Ǻ�
	int** ppDistMtrx;//�Ÿ� ǥ 2���� �迭
protected:
	bool isValidvID(int vid) { return graph.isValidVrtxID(vid); }//�������� �������� �Ǻ�
	int getNumVertices() { return graph.getNumVertices(); }//�׷����� ���� �� ��ȯ

public:
	MinimumSpanningTree(Graph& g) :graph(g)//������
	{
		int num_nodes;

		num_nodes = g.getNumVertices();//���� �� �޾ƿ�

		ppDistMtrx = new int* [num_nodes];//������ �迭 ����
		for (int i = 0; i < num_nodes; i++)
			ppDistMtrx[i] = new int[num_nodes];//2���� ����
		for (int i = 0; i < num_nodes; i++)
			for (int j = 0; j < num_nodes; j++)
				ppDistMtrx[i][j] = PLUS_INF;//2���� �迭 �ʱ�ȭ
	};
	void PrimJarnikMST();
	void initDistMtrx();
	int** getppDistMtrx() { return ppDistMtrx; }//2�����迭 ��ȯ
};
#endif // !MST_H
