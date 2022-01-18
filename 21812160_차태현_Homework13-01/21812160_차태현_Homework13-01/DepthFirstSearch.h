#ifndef DFS_H
#define DFS_H
#include <iostream>
#include "Graph.h"
using namespace std;
typedef Graph::Vertex Vertex;
typedef Graph::Edge Edge;
typedef std::list<Graph::Vertex> VrtxList;
typedef std::list<Graph::Vertex>::iterator VertexItor;
typedef std::list<Graph::Edge> EdgeList;
typedef std::list<Graph::Edge>::iterator EdgeItor;
class DepthFirstSearch
{
protected:
	Graph& graph;//그래프
	Vertex start;//시작 정점
	bool done; //상태 설정 
protected:
	void initialize();//초기화
	void dfsTraversal(Vertex& v, Vertex& target, VrtxList& path);//깊이 우선탐색 v부터 타겟까지
	virtual void traverseDiscovery(const Edge& e, const Vertex& from) { }
	virtual void traverseBack(const Edge& e, const Vertex& from) { }
	virtual void finishVisit(const Vertex& v) {}
	virtual bool isDone() const { return done; }
	void visit(Vertex& v);//방문상태로 변경
	void visit(Edge& e);//방문상태로 변경
	void unvisit(Vertex& v);//방문하지 않은 상태로 변경
	void unvisit(Edge& e);//방문하지 않은 상태로 변경
	bool isVisited(Vertex& v);//방문했는지 판별
	bool isVisited(Edge& e);//방문했는지 판별
	void setEdgeStatus(Edge& e, EdgeStatus es);//간선 상태설정
	EdgeStatus getEdgeStatus(Edge& e);//간선 상태 
public:
	DepthFirstSearch(Graph& g);//생성자
	void findPath(Vertex& s, Vertex& t, VrtxList& path);//s부터 t까지의 경로 path에 담아줌
	Graph& getGraph() { return graph; }//그래프 반환
	void showConnectivity(ofstream& fout);//연결상태 보여줌
private:
	VrtxStatus* pVrtxStatus;//정점 상태
	EdgeStatus** ppEdgeStatus;//간선 상태 2차원 배열
	int** ppConnectivity; //연결성 2차원 배열
}; 

#endif