#ifndef MST_H
#define MST_H
#include"Graph.h"

typedef Graph::Vertex Vertex;//정점
typedef Graph::Edge Edge;//간선
typedef std::list<Graph::Vertex> VrtxList;//정점 리스트
typedef std::list<Graph::Edge> EdgeList;//간선 리스트
typedef std::list<Vertex> ::iterator VrtxItor;//반복자
typedef std::list<Edge>::iterator EdgeItor;//반복자

class MinimumSpanningTree
{
protected:
	Graph& graph;//그래프
	bool done;//탐색이 끝났는지 판별
	int** ppDistMtrx;//거리 표 2차원 배열
protected:
	bool isValidvID(int vid) { return graph.isValidVrtxID(vid); }//정상적인 범위인지 판별
	int getNumVertices() { return graph.getNumVertices(); }//그래프의 정점 수 반환

public:
	MinimumSpanningTree(Graph& g) :graph(g)//생성자
	{
		int num_nodes;

		num_nodes = g.getNumVertices();//정점 수 받아옴

		ppDistMtrx = new int* [num_nodes];//포인터 배열 생성
		for (int i = 0; i < num_nodes; i++)
			ppDistMtrx[i] = new int[num_nodes];//2차원 생성
		for (int i = 0; i < num_nodes; i++)
			for (int j = 0; j < num_nodes; j++)
				ppDistMtrx[i][j] = PLUS_INF;//2차원 배열 초기화
	};
	void PrimJarnikMST();
	void initDistMtrx();
	int** getppDistMtrx() { return ppDistMtrx; }//2차원배열 반환
};
#endif // !MST_H
