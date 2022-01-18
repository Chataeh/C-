#ifndef G_H
#define G_H

#include<list>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<limits>
#include<string>

using namespace std;

#define PLUS_INF INT_MAX/2

enum VrtxStatus { UN_VISITED, VISITED, VRTX_NOT_FOUND };
enum EdgeStatus { DISCOVERY, BACK, CROSS, EDGE_UN_VISITED, EDGE_VISITED, EDGE_NOT_FOUND };

class Graph
{
	class Vertex;//����
	class Edge;//����
	typedef std::list<Graph::Vertex> VrtxList;//���� ����Ʈ
	typedef std::list<Graph::Edge> EdgeList;//���� ����Ʈ
	typedef std::list<Vertex> ::iterator VrtxItor;//�ݺ���
	typedef std::list<Edge>::iterator EdgeItor;//�ݺ���

public:
	class Vertex//����
	{
		friend ostream& operator<<(ostream& fout, Vertex v)//<<������
		{
			fout << v.getName();//�̸� ���
			return fout;
		}
	public:
		Vertex() :name(), ID(-1) {}//default ������
		Vertex(string n, int id) :name(n), ID(id) {}//������
		Vertex(int id) :ID(id) {}//������
		string getName() { return name; }//�̸���ȯ
		void setName(string c_name) { name = c_name; }//�̸�����
		int getID() { return ID; }//ID��ȯ
		void setID(int id) { ID = id; }//ID ����
		void setVrtxStatus(VrtxStatus vs) { vrtxStatus = vs; }//���� ����
		bool operator==(Vertex v) { return ((ID == v.getID()) && (name == v.getName())); }//������ �Ǻ�
		bool operator!=(Vertex v) { return ((ID != v.getID()) || (name != v.getName())); }//�ٸ��� �Ǻ�
	private:
		string name;//�̸�
		int ID;//��ȣ
		VrtxStatus vrtxStatus;//����
	};
public:
	class Edge//����
	{
		friend ostream& operator<<(ostream& fout, Edge& e)//<< ������ ���� �Ÿ� ���
		{
			fout << "Edge(" << setw(2) << *e.getpVrtx_1() << ", " << setw(2) << *e.getpVrtx_2() << ", " << setw(4) << e.getDistance() << ")";
			return fout;
		}

	public:
		Edge() :pVrtx_1(NULL), pVrtx_2(NULL), distance(PLUS_INF) {}//default ������
		Edge(Vertex& v1, Vertex& v2, int d) :pVrtx_1(&v1), pVrtx_2(&v2), distance(d) {}//������
		void endVertices(VrtxList& vrtxLst)//����Ʈ�� ���
		{
			vrtxLst.push_back(*pVrtx_1);//����� ���
			vrtxLst.push_back(*pVrtx_2);//������ ���
		}
		Vertex opposite(Vertex v)//�ΰ� �������� �ϳ��� ���ǵ� ��� ������ �ϳ� ��ȯ
		{
			if (v == *pVrtx_1)//1�� ���
				return *pVrtx_2;//2��ȯ
			else if (v == *pVrtx_2)//2�� ���
				return *pVrtx_1;//1��ȯ
			else
				return Vertex(NULL);
		}
		Vertex* getpVrtx_1() { return pVrtx_1; }//���� ��ȯ
		Vertex* getpVrtx_2() { return pVrtx_2; }//���� ��ȯ
		int getDistance() { return distance; }//�Ÿ� ��ȯ
		void setpVrtx_1(Vertex* pV) { pVrtx_1 = pV; }//����1 ����
		void setpVrtx_2(Vertex* pV) { pVrtx_2 = pV; }//����2 ����
		void setDistance(int d) { distance = d; }//�Ÿ� ����
		bool operator!=(Edge e) //�ٸ��� �Ǻ�
		{
			return ((pVrtx_1 != e.getpVrtx_1()) || (pVrtx_2 != e.getpVrtx_2()));//�ϳ��� �ٸ� ���
		}
		bool operator==(Edge e) //������ �Ǻ�
		{
			return ((pVrtx_1 == e.getpVrtx_1()) && (pVrtx_2 == e.getpVrtx_2()));//�Ѵ� ���� ���
		}
		void setEdgeStatus(EdgeStatus es) { edgeStatus = es; }//���� ���¼���
		EdgeStatus getEdgeStatus() { return edgeStatus; }//���� ���¹�ȯ
	private:
		Vertex* pVrtx_1;//������(�������� ���� ������ ��Ÿ���� �迭�� ���� �ֱ⶧���� ���°� ���Ҷ� �������� �ٷ� ��밡��)
		Vertex* pVrtx_2;//������
		int distance;//�Ÿ�
		EdgeStatus edgeStatus;//����
	};
public:
	Graph() :name(""), pVrtxArray(NULL), pAdjLstArray(NULL) {}//default ������
	Graph(string nm, int num_nodes) :name(nm), pVrtxArray(NULL), pAdjLstArray(NULL)//������
	{
		num_vertices = num_nodes;
		pVrtxArray = new Graph::Vertex[num_vertices];//�����迭 ����
		for (int i = 0; i < num_vertices; i++)
		{
			pVrtxArray[i] = NULL;	//�ʱ�ȭ
		}
		pAdjLstArray = new EdgeList[num_vertices];//�����迭 ����
		for (int i = 0; i < num_vertices; i++)
			pAdjLstArray[i].clear();//�ʱ�ȭ
	}
	string getName() { return name; }//�̸� ��ȯ
	void vertices(VrtxList& vrtxLst);//�������� ����Ʈ�� ���
	void edges(EdgeList&);//�������� ����Ʈ�� ���
	bool isAdjacentTo(Vertex v, Vertex w);//�������� �����ϴ��� �Ǻ�
	void insertVertex(Vertex& v);//�����߰�
	void insertEdge(Edge& e);//���� �߰�
	void eraseEdge(Edge e);//���� ����
	void eraseVertex(Vertex v);//���� ����
	int getNumVertices() { return num_vertices; }//���� ������ȯ
	void incidentEdges(Vertex v, EdgeList& edges);//������ ����� ������ ����Ʈ�� ���
	Vertex* getpVrtxArray() { return pVrtxArray; }//�����迭 ��ȯ
	EdgeList* getpAdjLstArray() { return pAdjLstArray; }//�����迭 ��ȯ
	void fprintGraph(ofstream& fout);//�׷��� ���
	bool isValidVrtxID(int vid);//ID�� �������� ��������
private:
	string name;//�̸�
	Vertex* pVrtxArray;//�����迭
	EdgeList* pAdjLstArray;//��������Ʈ �迭 
	int num_vertices;//���� ��
};

#endif 