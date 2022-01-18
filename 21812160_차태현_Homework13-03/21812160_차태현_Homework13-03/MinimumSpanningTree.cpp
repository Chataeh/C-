#include"Graph.h"
#include"MinimumSpanningTree.h"
void MinimumSpanningTree::initDistMtrx()//거리표 초기화
{
	int** ppDistMtrx;
	int* pLeaseCostMtrx;
	int num_nodes;
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int curVID, vID;

	num_nodes = getNumVertices();//정점수 설정
	pVrtxArray = graph.getpVrtxArray();//정점 배열
	pAdjLstArray = graph.getpAdjLstArray();//리스트 배열

	ppDistMtrx = getppDistMtrx();//2차원 배열

	for (int i = 0; i < num_nodes; i++)
	{
		curVID = pVrtxArray[i].getID();//ID 받아옴
		EdgeItor pe = pAdjLstArray[curVID].begin();//간선 리스트의 처음부터
		while (pe != pAdjLstArray[curVID].end())//마지막까지
		{
			vID = (*(*pe).getpVrtx_2()).getID();//정점 2 설정
			ppDistMtrx[curVID][vID] = (*pe).getDistance();//거리 값 저장
			pe++;//반복자 증가
		}
		ppDistMtrx[curVID][curVID] = 0;//자기자신의 거리는 0
	}

}

enum VertexStatus { NOT_SELECTED, SELECTED };
void MinimumSpanningTree::PrimJarnikMST()
{
	int num_nodes, num_edges;
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int curVrtx_ID, vrtxID;
	int** ppDistMtrx;
	int* pDist;
	int start, min_id, dist, min_dist, min_dist_org, min_dist_end, end_ID;
	VertexStatus* pVrtxStatus;
	Graph::Edge* pParentEdge, edge, min_edge; 
	std::list<Graph::Edge> selectedEdgeLst;
	std::list<Graph::Edge>::iterator edgeItor;
	
	//그래프에서 값과 배열받아옴
	num_nodes = graph.getNumVertices();
	pVrtxArray = graph.getpVrtxArray();
	pAdjLstArray = graph.getpAdjLstArray();
	initDistMtrx();
	ppDistMtrx = getppDistMtrx();
	
	//동적할당
	pDist = new int[num_nodes];
	pVrtxStatus = new VertexStatus[num_nodes];
	pParentEdge = new Graph::Edge[num_nodes];
	
	//초기값 설정
	for (int i = 0; i < num_nodes; i++) {
		pDist[i] = PLUS_INF;
		pVrtxStatus[i] = NOT_SELECTED;
		pParentEdge[i] = Graph::Edge();
	}

	srand(time(0));
	start = rand() % num_nodes; // 시작노드 랜덤으로 설정
	cout << "Start node : " << start << endl;
	pDist[start] = 0;
	selectedEdgeLst.clear();
	for (int round = 0; round < num_nodes; round++)//노드 수 만큼 동작
	{
		min_dist = PLUS_INF;
		min_id = -1;
		for (int n = 0; n < num_nodes; n++)
		{
			if ((pVrtxStatus[n] == NOT_SELECTED) && (pDist[n] < min_dist))//선택되지 않고 짧은거리 탐색
			{
				//값 변경
				min_dist = pDist[n];
				min_id = n;
			} 
		} 
		if (min_id == -1)
		{
			cout << "Error in finding Prim-Jarnik's algorithm !!";
			break;
		}
		pVrtxStatus[min_id] = SELECTED;//min_id노드 상태변경
		
		// edge relaxtion
		EdgeItor pe = pAdjLstArray[min_id].begin();//간선반복자 처음부터
		while (pe != pAdjLstArray[min_id].end())//끝까지
		{
			end_ID = (*(*pe).getpVrtx_2()).getID();//ID받아옴
			dist = (*pe).getDistance();//거리 받아옴
			if ((pVrtxStatus[end_ID] == NOT_SELECTED) && (dist <= pDist[end_ID]))//거리가 더 작고 선택되지 않은 것일 경우
			{
				pDist[end_ID] = dist;//거리 값 담기
				pParentEdge[end_ID] = *pe;//간선 담기
			}
			pe++;//다음으로 이동
		} 

		if (min_id != start) //시작 점이 아닐경우
		{
			min_edge = pParentEdge[min_id];
			selectedEdgeLst.push_back(min_edge);
		}
		cout << "Dist after round [" << setw(2) << round << "] : ";
		// edge relaxtion 이후 상태확인
		for (int i = 0; i < num_nodes; i++)
		{
			if (pDist[i] == PLUS_INF)
				cout << " +oo ";
			else
				cout << setw(4) << pDist[i] << " ";
		}
		cout << endl;
	}
	cout << "\nEnd of finding Minimum Spanning Tree by Prim-Jarnik's Algorithm";
		cout << "selectedEdgeLst.size ="  << selectedEdgeLst.size() << endl;
		cout << "Selected edges: " << endl;

	edgeItor = selectedEdgeLst.begin(); 
	int cnt = 0;
	//최종 간선출력
	while (edgeItor != selectedEdgeLst.end())
	{
		cout << *edgeItor << ", ";
		edgeItor++;
		if ((++cnt % 5) == 0)
			cout << endl;
	}
	cout << endl;
}