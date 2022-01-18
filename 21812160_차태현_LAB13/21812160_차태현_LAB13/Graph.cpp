#include"Graph.h"


void Graph::insertVertex(Vertex& v)//정점 추가
{
	int vID;
	vID = v.getID();//번호 반환
	if (pVrtxArray[vID] == NULL)//배열이 비어있다면
		pVrtxArray[vID] = v;//삽입
}

void Graph::vertices(VrtxList& vrtxLst)//정점 리스트에 담기
{
	vrtxLst.clear();
	for (int i = 0; i < getNumVertices(); i++)//정점수 만큼
		vrtxLst.push_back(pVrtxArray[i]);//push_back을 통해 배열의 값을 넣어줌
}

void Graph::insertEdge(Edge& e)//간선 추가
{
	Vertex vrtx_1, vrtx_2;//정점생성
	
	int vID_1, vID_2;

	vrtx_1 = *e.getpVrtx_1();//정점 설정
	vID_1 = vrtx_1.getID();//번호 설정

	vrtx_2 = *e.getpVrtx_2();//정점 설정
	vID_2 = vrtx_2.getID();//번호 설정

	if (pVrtxArray[vID_1] == NULL)//비어있는경우
		pVrtxArray[vID_1] = vrtx_1;//설정

	if (pVrtxArray[vID_2] == NULL)//비어있는경우 
		pVrtxArray[vID_2] = vrtx_2;//설정

	e.setpVrtx_1(&pVrtxArray[vID_1]);//간선의 정점1 설정
	e.setpVrtx_2(&pVrtxArray[vID_2]);//간선의 정점2 설정

	pAdjLstArray[vID_1].push_back(e);//간선 추가
}


void Graph::edges(EdgeList& edges)//리스트에 간선담기
{
	EdgeItor eItor;
	Graph::Edge e;

	edges.clear();
	for (int i = 0; i < getNumVertices(); i++)//정점 수 만큼
	{
		eItor = pAdjLstArray[i].begin();//반복자 시작부터
		while (eItor != pAdjLstArray[i].end())//끝까지
		{
			e = *eItor;//반복자가 가르키는 값
			edges.push_back(e);//값을 리스트에 담기
			eItor++;//다음으로 이동
		}
	}
}

void Graph::incidentEdges(Vertex v, EdgeList& edgeLst)//V정점의 간선 찾기
{
	Graph::Edge e;
	EdgeItor eItor;
	int vID = v.getID();//번호 설정

	eItor = pAdjLstArray[vID].begin();//반복자 시작부터
	while (eItor != pAdjLstArray[vID].end())//끝까지 반복
	{
		e = *eItor;//반복자가 가르키는 값
		edgeLst.push_back(e);//값을 리스트에 담기
		eItor++;//반복자 증가
	}
}

bool Graph::isValidVrtxID(int vid)//범위 판별
{
	if ((vid >= 0) && (vid < num_vertices))//정상범위
		return true;
	else
	{
		cout << "Vertex ID (" << vid << ") is invalid for Graph (" << getName()<< ") with num_vertices (" << num_vertices << ")" << endl;
	}
}

void Graph::fprintGraph(ofstream& fout)//출력
{
	int i, j;
	EdgeItor eItor;
	Graph::Edge e;
	int numOutgoingEdges;

	fout << this->getName() << " with " << this->getNumVertices() << " vertices has following connectivity :" << endl;

	for (i = 0; i < num_vertices; i++)//정점만큼 반복
	{
		fout << " vertex (" << setw(3) << pVrtxArray[i].getName() << ") : ";
		numOutgoingEdges = pAdjLstArray[i].size();//간선의 개수

		eItor = pAdjLstArray[i].begin();//시작부터
		while (eItor != pAdjLstArray[i].end())//끝까지 반복
		{
			e = *eItor;//값 받아옴
			fout << e << " ";//출력
			eItor++;//반복자 증가
		}
		fout << endl;
	}
}