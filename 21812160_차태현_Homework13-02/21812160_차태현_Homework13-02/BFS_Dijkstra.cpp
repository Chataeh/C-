#include"BFS_Dijkstra.h"
#include"Graph.h"


void BreadthFirstSearch::initialize()//초기화
{
	Vertex* pVrtx = getGraph().getpVrtxArray();//그래프에서 정점 배열받아옴

	VrtxList vrtxLst;
	graph.vertices(vrtxLst);//리스트에 정점 담기
	int num_vertices = graph.getNumVertices();//정점수 설정
	for (int vID = 0; vID < num_vertices; vID++)
		pVrtx[vID].setVrtxStatus(UN_VISITED);//정점상태 초기화

	EdgeList edges;
	graph.edges(edges);//리스트에 간선 담기
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
		pe->setEdgeStatus(EDGE_UN_VISITED);//간선리스트 상태 초기화
}

void BreadthFirstSearch::initDistMtrx()//거리표 초기화
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

void BreadthFirstSearch::fprintDistMtrx(ofstream& fout)//거리표 출력
{
	int** ppDistMtrx;
	Vertex* pVrtxArray;
	int num_nodes;
	int dist;
	int vID;
	string vName;

	pVrtxArray = graph.getpVrtxArray();//정점 배열설정
	num_nodes = getNumVertices();//정점 수 설정
	ppDistMtrx = getppDistMtrx();//2차원 배열 설정

	fout << "\nDistance Matrix of Graph (" << graph.getName() << ") :" << endl;
	fout << "       |";

	for (int i = 0; i < num_nodes; i++)//정점 수 만큼 반복
	{
		vName = pVrtxArray[i].getName();//정점의 이름 받아옴
		fout << setw(5) << vName;
	}
	fout << endl;

	fout << "-------+";
	for (int i = 0; i < num_nodes; i++) {
		fout << "-----";
	}
	fout << endl;

	for (int i = 0; i < num_nodes; i++)
	{
		vName = pVrtxArray[i].getName();//이름 설정
		fout << setw(5) << vName << "  |";
		for (int j = 0; j < num_nodes; j++)
		{
			dist = ppDistMtrx[i][j];//2차원배열에서 i번째에서 j로가는 거리 받아옴
			if (dist == PLUS_INF)
				fout << setw(5) << "+oo";
			else
				fout << setw(5) << dist;//거리 출력
		}
		fout << endl;
	}
	fout << endl;
}

enum BFS_PROCESS_STATUS { NOT_SELECTED, SELECTED };
void BreadthFirstSearch::DijkstraShortestPath(ofstream& fout, Vertex& start, Vertex& target, VrtxList& path)//최단거리 
{
	int** ppDistMtrx;
	int* pLeastCost;
	int num_nodes, num_selected, minID, minCost;
	BFS_PROCESS_STATUS* pBFS_Process_Stat;
	int* pPrev;

	Vertex* pVrtxArray;
	Vertex vrtx, * pPrevVrtx, v;
	Edge e;
	int start_vID, target_vID, curVID, vID;
	EdgeList* pAdjLstArray;

	pVrtxArray = graph.getpVrtxArray();//그래프의 정점배열 받아옴
	pAdjLstArray = graph.getpAdjLstArray();//그래프의 간선리스트배열 받아옴
	start_vID = start.getID();//시작 정점ID
	target_vID = target.getID();//도착 정점ID

	num_nodes = getNumVertices();//정점 수
	ppDistMtrx = getppDistMtrx();// 2차원 배열

	pLeastCost = new int[num_nodes];
	pPrev = new int[num_nodes];//경로상 자신의 앞에 있는 정점
	pBFS_Process_Stat = new BFS_PROCESS_STATUS[num_nodes];

	for (int i = 0; i < num_nodes; i++)
	{
		pLeastCost[i] = ppDistMtrx[start_vID][i];//시작점부터 i번째까지 거리
		pPrev[i] = start_vID;//pPrev[i]의 이전은 시작정점
		pBFS_Process_Stat[i] = NOT_SELECTED;//i번째 정점은 선택되지 않음 상태
	}
	pBFS_Process_Stat[start_vID] = SELECTED;//시작정점은 선택된 상태로 설정
	num_selected = 1;//선택된 정점==시작점
	path.clear();

	int round = 0;
	int cost;
	string vName;

	fout << "Dijkstra::Least Cost from Vertex (" << start.getName() << ") at each round : " << endl;
	fout << "           |";

	for (int i = 0; i < num_nodes; i++)
	{
		vName = pVrtxArray[i].getName();
		fout << setw(5) << vName;
	}

	fout << endl;
	fout << "-----------+";
	for (int i = 0; i < num_nodes; i++)
	{
		fout << setw(5) << "-----";
	}
	fout << endl;

	while (num_selected < num_nodes)//선택된 노드가 정점수보다 작을때 까지 즉 모든 노드를 다 탐색할때까지 반복
	{
		round++;//라운드 증가
		fout << "round [" << setw(2) << round << "] |";
		minID = -1;
		minCost = PLUS_INF;
		for (int i = 0; i < num_nodes; i++)
		{
			if ((pLeastCost[i] < minCost) && (pBFS_Process_Stat[i] != SELECTED))//기존의 minCost보다 작고 선택되지 않은경우
			{
				//최소ID와 최소거리 변경 
				minID = i;
				minCost = pLeastCost[i];
			}
		}
		if (minID == -1)//연결이 되지않은 정점
		{
			fout << "Error in Dijkstra() -- found not connected vertex !!" << endl;
			break;
		}
		else
		{
			pBFS_Process_Stat[minID] = SELECTED;//선택됨으로 변경
			num_selected++;//선택된 노드 증가

			if (minID == target_vID)//ID가 타겟ID와 같으면 도착점까지 다 도달한 상태

			{
				fout << endl << "reached to the target node (" << pVrtxArray[minID].getName() << ") at Least Cost =" << minCost << endl;
				vID = minID;
				do {
					vrtx = pVrtxArray[vID];//도착정점 설정
					path.push_front(vrtx);//리스트에 맨앞에 넣어줌
					vID = pPrev[vID];//이전 정점으로 설정
				} while (vID != start_vID);//시작 정점까지 반복
				vrtx = pVrtxArray[vID];//시작 정점
				path.push_front(vrtx);//리스트 맨앞에 시작정점 추가
				break;
			}
		}
		int pLS, ppDistMtrx_i;
		for (int i = 0; i < num_nodes; i++)
		{
			pLS = pLeastCost[i];
			ppDistMtrx_i = ppDistMtrx[minID][i];

			if ((pBFS_Process_Stat[i] != SELECTED) && (pLeastCost[i] > (pLeastCost[minID] + ppDistMtrx[minID][i])))//선택되지 않고 minID까지 거리와 minID부터 i까지의 거리가 더 작다면
			{
				pPrev[i] = minID;//최단거리 정점이 minID이므로 이전노드를 minID로 설정
				pLeastCost[i] = pLeastCost[minID] + ppDistMtrx[minID][i];//최소 거리 설정
			}
		}
		for (int i = 0; i < num_nodes; i++)
		{
			cost = pLeastCost[i];//최단거리 설정
			if (cost == PLUS_INF)
				fout << "  +oo";
			else
				fout << setw(5) << pLeastCost[i];//출력
		}
		fout << " ==> selected vertex :" << pVrtxArray[minID] << endl;
	}
}

