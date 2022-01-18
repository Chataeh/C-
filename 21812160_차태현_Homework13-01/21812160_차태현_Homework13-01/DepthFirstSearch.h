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
	Graph& graph;//�׷���
	Vertex start;//���� ����
	bool done; //���� ���� 
protected:
	void initialize();//�ʱ�ȭ
	void dfsTraversal(Vertex& v, Vertex& target, VrtxList& path);//���� �켱Ž�� v���� Ÿ�ٱ���
	virtual void traverseDiscovery(const Edge& e, const Vertex& from) { }
	virtual void traverseBack(const Edge& e, const Vertex& from) { }
	virtual void finishVisit(const Vertex& v) {}
	virtual bool isDone() const { return done; }
	void visit(Vertex& v);//�湮���·� ����
	void visit(Edge& e);//�湮���·� ����
	void unvisit(Vertex& v);//�湮���� ���� ���·� ����
	void unvisit(Edge& e);//�湮���� ���� ���·� ����
	bool isVisited(Vertex& v);//�湮�ߴ��� �Ǻ�
	bool isVisited(Edge& e);//�湮�ߴ��� �Ǻ�
	void setEdgeStatus(Edge& e, EdgeStatus es);//���� ���¼���
	EdgeStatus getEdgeStatus(Edge& e);//���� ���� 
public:
	DepthFirstSearch(Graph& g);//������
	void findPath(Vertex& s, Vertex& t, VrtxList& path);//s���� t������ ��� path�� �����
	Graph& getGraph() { return graph; }//�׷��� ��ȯ
	void showConnectivity(ofstream& fout);//������� ������
private:
	VrtxStatus* pVrtxStatus;//���� ����
	EdgeStatus** ppEdgeStatus;//���� ���� 2���� �迭
	int** ppConnectivity; //���Ἲ 2���� �迭
}; 

#endif