#include"DepthFirstSearch.h"
#include"Graph.h"

DepthFirstSearch::DepthFirstSearch(Graph& g) :graph(g)
{
	int num_nodes = g.getNumVertices();//정점 개수반환
	
	pVrtxStatus = new VrtxStatus[num_nodes];//정점 상태
	for (int i = 0; i < num_nodes; i++)
		pVrtxStatus[i] = UN_VISITED;//UN_VISITED로 초기화
	
	//2차원 동적할당
	ppEdgeStatus = new EdgeStatus * [num_nodes];
	for (int i = 0; i < num_nodes; i++)
		ppEdgeStatus[i] = new EdgeStatus[num_nodes];
	
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppEdgeStatus[i][j] = EDGE_UN_VISITED;//2차원 동적배열 초기화
	
	//2차원 동적할당
	ppConnectivity = new int* [num_nodes];
	for (int i = 0; i < num_nodes; i++)
		ppConnectivity[i] = new int[num_nodes];
	
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppConnectivity[i][j] = PLUS_INF;//값 초기화

	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	EdgeList edges;
	
	edges.clear();
	graph.edges(edges);//간선 리스트에 담아줌
	
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
	{
		//정점과 간선 행렬 설정
		vrtx_1 = *(*pe).getpVrtx_1(); 
		vID_1 = vrtx_1.getID();
		
		vrtx_2 = *(*pe).getpVrtx_2();
		vID_2 = vrtx_2.getID();
		
		ppConnectivity[vID_1][vID_2] = (*pe).getDistance();//거리 
	}
	
	for (int i = 0; i < num_nodes; i++)
		ppConnectivity[i][i] = 0; // 같은 노드는 거리가 0
}

void DepthFirstSearch::initialize()// 초기화
{
	int num_nodes = graph.getNumVertices();
	VrtxList verts;
	graph.vertices(verts);//정점 리스트에 담아줌
	
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	done = false;
	
	for (int i = 0; i < num_nodes; i++)
		pVrtxStatus[i] = UN_VISITED;//상태 설정
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppEdgeStatus[i][j] = EDGE_UN_VISITED;//상태 설정
}

void DepthFirstSearch::showConnectivity(ofstream& fout)//출력
{
	int num_nodes = graph.getNumVertices();
	int dist;
	Graph g = getGraph();
	Vertex* pVrtxArray = g.getpVrtxArray();//정점배열 받아옴
	
	fout << "Connectivity of graph: " << endl;
	fout << "       |";
	
	for (int i = 0; i < num_nodes; i++)
		fout << setw(5) << pVrtxArray[i].getName();//정점이름 출력
	fout << endl;
	
	fout << "-------+";
	for (int i = 0; i < num_nodes; i++)
		fout << "-----";
	fout << endl;
	
	for (int i = 0; i < num_nodes; i++) {
		fout << setw(5) << pVrtxArray[i].getName() << "  |";
	
		for (int j = 0; j < num_nodes; j++)
		{
			dist = ppConnectivity[i][j];//거리행렬값 받아옴
			if (dist == PLUS_INF)
				fout << setw(5) << " +oo";
			else
				fout << setw(5) << dist;
		}
			fout << endl;
	} 
}


void DepthFirstSearch::dfsTraversal(Vertex& v, Vertex& target, VrtxList& path)//경로 탐색
{
	visit(v);//v visit상태로 설정
	if (v == target) //v가 target일경우 목적지에 도착
	{
		done = true;
		return;
	}
	EdgeList incidentEdges;//간선리스트 생성
	incidentEdges.clear();
	graph.incidentEdges(v, incidentEdges);//v의 연결된 간선 리스트에 담기
	EdgeItor pe = incidentEdges.begin();//반복자의 처음부터
	while (!isDone() && pe != incidentEdges.end())//상태가 flase이고 반복자의 마지막까지 반복 
	{
		Edge e = *pe++;//간선 설정 후 다음 간선으로 넘어감
		EdgeStatus eStat = getEdgeStatus(e);
		if (eStat == EDGE_UN_VISITED)//방문하지 않은 간선인 경우
		{
			visit(e);//상태 변경
			Vertex w = e.opposite(v);//e간선에 v 이외의 정점 설정
			if (!isVisited(w))//방문하지 않은 경우라면
			{
				path.push_back(w);//리스트에 담아줌
				setEdgeStatus(e, DISCOVERY);//간선 상태 변경
				if (!isDone()) //아직 목적지에 도착하지 않음
				{
					dfsTraversal(w, target, path);//w를 기준 정점으로 재귀함수 호출 
					if (!isDone()) //목적지에 도착 하지 않은경우
					{	
						//사이클 생성되기때문에 삭제하기위해서 실행
						Vertex last_pushed = path.back(); //path 의 마지막을 정점 설정
						path.pop_back();//삭제
					}
				}
			}
			else //w가 방문한 정점이라면
			{
				setEdgeStatus(e, BACK);//BACK로 상태 설정
			}
		} 
	}
}

void DepthFirstSearch::findPath(Vertex& start, Vertex& target, VrtxList& path)
{
	initialize();//초기화
	path.clear();
	
	path.push_back(start);//출발정점
	dfsTraversal(start, target, path);//경로 탐색 후 path에 담아줌
}

void DepthFirstSearch::visit(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	
	if (graph.isValidVrtxID(vID))//범위 확인
	{
		pVrtxStatus[vID] = VISITED;//상태변경
	}
}

void DepthFirstSearch::visit(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	
	vrtx_1 = *e.getpVrtx_1(); 
	vID_1 = vrtx_1.getID();
	
	vrtx_2 = *e.getpVrtx_2(); 
	vID_2 = vrtx_2.getID();
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//범위 확인
	{
		ppEdgeStatus[vID_1][vID_2] = EDGE_VISITED;//상태변경
	}
}

void DepthFirstSearch::unvisit(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	
	if (graph.isValidVrtxID(vID))//범위 확인
	{
		pVrtxStatus[vID] = UN_VISITED;//상태변경
	}
}
void DepthFirstSearch::unvisit(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	
	vrtx_1 = *e.getpVrtx_1();
	vID_1 = vrtx_1.getID();
	
	vrtx_2 = *e.getpVrtx_2();
	vID_2 = vrtx_2.getID();
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//범위 확인
	{
		ppEdgeStatus[vID_1][vID_2] = EDGE_UN_VISITED;//상태변경
	}
}

bool DepthFirstSearch::isVisited(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	
	if (graph.isValidVrtxID(vID))
	{
		return (pVrtxStatus[vID] == VISITED);//방문한 경우에 true
	}
}
bool DepthFirstSearch::isVisited(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	EdgeStatus eStat;
	int numNodes = getGraph().getNumVertices();
	
	vrtx_1 = *e.getpVrtx_1();
	vID_1 = vrtx_1.getID();
	vrtx_2 = *e.getpVrtx_2(); vID_2 = vrtx_2.getID();
	
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//범위 확인
	{
		eStat = ppEdgeStatus[vID_1][vID_2];
		if ((eStat == EDGE_VISITED) || (eStat == DISCOVERY) || (eStat == BACK))//방문한적이 있는상태
			return true;
		else
			return false;
	}
	return false;
}

void DepthFirstSearch::setEdgeStatus(Edge& e, EdgeStatus es)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	
	vrtx_1 = *e.getpVrtx_1(); 
	vID_1 = vrtx_1.getID();
	
	vrtx_2 = *e.getpVrtx_2();
	vID_2 = vrtx_2.getID();
	
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//범위 확인
	{
		ppEdgeStatus[vID_1][vID_2] = es;//es 상태로 설정해줌
	}
}
EdgeStatus DepthFirstSearch::getEdgeStatus(Edge& e)
{
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	int numNodes = getGraph().getNumVertices();
	EdgeStatus eStat;
	
	vrtx_1 = *e.getpVrtx_1();
	vID_1 = vrtx_1.getID();
	
	vrtx_2 = *e.getpVrtx_2(); 
	vID_2 = vrtx_2.getID();
	
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//범위 확인
	{
		eStat = ppEdgeStatus[vID_1][vID_2];//상태설정
		return eStat;
	}
	else {
		cout << "Edge (" << e << ") was not found from AdjacencyList" << endl;
		return EDGE_NOT_FOUND;
	}
}