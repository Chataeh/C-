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
	class Vertex;//정점
	class Edge;//간선
	typedef std::list<Graph::Vertex> VrtxList;//정점 리스트
	typedef std::list<Graph::Edge> EdgeList;//간선 리스트
	typedef std::list<Vertex> ::iterator VrtxItor;//반복자
	typedef std::list<Edge>::iterator EdgeItor;//반복자

public:
	class Vertex//정점
	{
		friend ostream& operator<<(ostream& fout, Vertex v)//<<연산자
		{
			fout << v.getName();//이름 출력
			return fout;
		}
	public:
		Vertex() :name(), ID(-1) {}//default 생성자
		Vertex(string n, int id) :name(n), ID(id) {}//생성자
		Vertex(int id) :ID(id) {}//생성자
		string getName() { return name; }//이름반환
		void setName(string c_name) { name = c_name; }//이름설정
		int getID() { return ID; }//ID반환
		void setID(int id) { ID = id; }//ID 설정
		void setVrtxStatus(VrtxStatus vs) { vrtxStatus = vs; }//상태 설정
		bool operator==(Vertex v) { return ((ID == v.getID()) && (name == v.getName())); }//같은지 판별
		bool operator!=(Vertex v) { return ((ID != v.getID()) || (name != v.getName())); }//다른지 판별
	private:
		string name;//이름
		int ID;//번호
		VrtxStatus vrtxStatus;//상태
	};
public:
	class Edge//간선
	{
		friend ostream& operator<<(ostream& fout, Edge& e)//<< 연산자 정점 거리 출력
		{
			fout << "Edge(" << setw(2) << *e.getpVrtx_1() << ", " << setw(2) << *e.getpVrtx_2() << ", " << setw(4) << e.getDistance() << ")";
			return fout;
		}

	public:
		Edge() :pVrtx_1(NULL), pVrtx_2(NULL), distance(PLUS_INF) {}//default 생성자
		Edge(Vertex& v1, Vertex& v2, int d) :pVrtx_1(&v1), pVrtx_2(&v2), distance(d) {}//생성자
		void endVertices(VrtxList& vrtxLst)//리스트에 담기
		{
			vrtxLst.push_back(*pVrtx_1);//출발점 담기
			vrtxLst.push_back(*pVrtx_2);//도착점 담기
		}
		Vertex opposite(Vertex v)//두개 정점중의 하나가 정의된 경우 나머지 하나 반환
		{
			if (v == *pVrtx_1)//1인 경우
				return *pVrtx_2;//2반환
			else if (v == *pVrtx_2)//2인 경우
				return *pVrtx_1;//1반환
			else
				return Vertex(NULL);
		}
		Vertex* getpVrtx_1() { return pVrtx_1; }//정점 반환
		Vertex* getpVrtx_2() { return pVrtx_2; }//정점 반환
		int getDistance() { return distance; }//거리 반환
		void setpVrtx_1(Vertex* pV) { pVrtx_1 = pV; }//정점1 설정
		void setpVrtx_2(Vertex* pV) { pVrtx_2 = pV; }//정점2 설정
		void setDistance(int d) { distance = d; }//거리 설정
		bool operator!=(Edge e) //다른지 판별
		{
			return ((pVrtx_1 != e.getpVrtx_1()) || (pVrtx_2 != e.getpVrtx_2()));//하나라도 다를 경우
		}
		bool operator==(Edge e) //같은지 판별
		{
			return ((pVrtx_1 == e.getpVrtx_1()) && (pVrtx_2 == e.getpVrtx_2()));//둘다 같은 경우
		}
		void setEdgeStatus(EdgeStatus es) { edgeStatus = es; }//간선 상태설정
		EdgeStatus getEdgeStatus() { return edgeStatus; }//간선 상태반환
	private:
		Vertex* pVrtx_1;//시작점(포인터인 이유 정점을 나타내는 배열이 따로 있기때문에 상태가 변할때 간선에서 바로 사용가능)
		Vertex* pVrtx_2;//도착점
		int distance;//거리
		EdgeStatus edgeStatus;//상태
	};
public:
	Graph() :name(""), pVrtxArray(NULL), pAdjLstArray(NULL) {}//default 생성자
	Graph(string nm, int num_nodes) :name(nm), pVrtxArray(NULL), pAdjLstArray(NULL)//생성자
	{
		num_vertices = num_nodes;
		pVrtxArray = new Graph::Vertex[num_vertices];//동적배열 생성
		for (int i = 0; i < num_vertices; i++)
		{
			pVrtxArray[i] = NULL;	//초기화
		}
		pAdjLstArray = new EdgeList[num_vertices];//동적배열 생성
		for (int i = 0; i < num_vertices; i++)
			pAdjLstArray[i].clear();//초기화
	}
	string getName() { return name; }//이름 반환
	void vertices(VrtxList& vrtxLst);//정점들을 리스트에 담기
	void edges(EdgeList&);//간선들을 리스트에 담기
	bool isAdjacentTo(Vertex v, Vertex w);//정점들이 인접하는지 판별
	void insertVertex(Vertex& v);//정점추가
	void insertEdge(Edge& e);//간선 추가
	void eraseEdge(Edge e);//간선 삭제
	void eraseVertex(Vertex v);//정점 삭제
	int getNumVertices() { return num_vertices; }//정점 개수반환
	void incidentEdges(Vertex v, EdgeList& edges);//정점에 연결된 간선들 리스트에 담기
	Vertex* getpVrtxArray() { return pVrtxArray; }//정점배열 반환
	EdgeList* getpAdjLstArray() { return pAdjLstArray; }//간선배열 반환
	void fprintGraph(ofstream& fout);//그래프 출력
	bool isValidVrtxID(int vid);//ID가 정상적인 범위인지
private:
	string name;//이름
	Vertex* pVrtxArray;//정점배열
	EdgeList* pAdjLstArray;//간선리스트 배열 
	int num_vertices;//정점 수
};

#endif 