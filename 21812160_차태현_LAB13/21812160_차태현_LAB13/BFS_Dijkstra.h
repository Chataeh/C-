#ifndef BFS_H
#define BFS_H

#include"Graph.h"

typedef Graph::Vertex Vertex;//정점
typedef Graph::Edge Edge;//간선
typedef std::list<Graph::Vertex> VrtxList;//정점 리스트
typedef std::list<Graph::Edge> EdgeList;//간선 리스트
typedef std::list<Vertex> ::iterator VrtxItor;//반복자
typedef std::list<Edge>::iterator EdgeItor;//반복자

class BreadthFirstSearch
{
protected:
	Graph& graph;//그래프
	bool done;//탐색이 끝났는지 판별
	int** ppDistMtrx;//거리 표 2차원 배열
protected:
	void initialize();//초기화
	bool isValidvID(int vid) { return graph.isValidVrtxID(vid); }//정상적인 범위인지 판별
	int getNumVertices() { return graph.getNumVertices(); }//그래프의 정점 수 반환
public:
	BreadthFirstSearch(Graph& g) :graph(g)//생성자
	{
		int num_nodes;

		num_nodes = g.getNumVertices();//정점 수 받아옴
	
		ppDistMtrx = new int* [num_nodes];//포인터 배열 생성
		for (int i = 0; i < num_nodes; i++)
			ppDistMtrx[i] = new int [num_nodes];//2차원 생성
		for (int i = 0; i < num_nodes; i++)
			for (int j = 0; j < num_nodes; j++)
				ppDistMtrx[i][j] = PLUS_INF;//2차원 배열 초기화
	}
	void initDistMtrx();//거리표 초기화
	void fprintDistMtrx(ofstream& fout);//거리표 출력
	void DijkstraShortestPathTree(ofstream& fout, Vertex& s, int* pPrev);
	void DijkstraShortestPath(ofstream& fout, Vertex& s, Vertex& t, VrtxList& path);//최단거리 찾기
	Graph& getGraph() { return graph; }//그래프 반환
	int** getppDistMtrx() { return ppDistMtrx; }//2차원배열 반환
};

#endif 
