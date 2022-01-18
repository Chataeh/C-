/**
*파일이름"21812160_차태현_LAB13"
*프로그램의 목적 및 기본 기능:
*자료구조 Graph를 이용한 최단거리 찾기
*
*프로그램 작성자: 21812160 차태현(2021년 12월01일),
*최종 수정 및 보완: 2021년 12월 01일 (차태현)
*/
#include"BFS_Dijkstra.h"

#define GRAPH_SIMPLE_USA_7_NODES
#define NUM_NODES 7 
#define NUM_EDGES 26 

void main()
{
	ofstream fout;
	
	fout.open("output.txt");//파일열기
	if (fout.fail())
	{
		cout << "Failed to open output.txt file !!" << endl;
		exit;
	}
	
	Vertex v[NUM_NODES] = // 정점7개 생성
	{
	Vertex("SF", 0), Vertex("LA", 1), Vertex("DLS", 2),
	Vertex("CHG", 3), Vertex("MIA", 4), Vertex("NY", 5),
	Vertex("BOS", 6)
	};
	
	Graph::Edge edges[NUM_EDGES] = // 26개의 간선
	{
	Edge(v[0], v[1], 337), Edge(v[1], v[0], 337), Edge(v[0], v[2], 1464), Edge(v[2], v[0], 1464),
	Edge(v[0], v[3], 1846), Edge(v[3], v[0], 1846), Edge(v[0], v[6], 2704), Edge(v[6], v[0], 2704),
	Edge(v[1], v[2], 1235), Edge(v[2], v[1], 1235), Edge(v[1], v[4], 2342), Edge(v[4], v[1], 2342),
	Edge(v[2], v[3], 802), Edge(v[3], v[2], 802), Edge(v[2], v[4], 1121), Edge(v[4], v[2], 1121),
	Edge(v[3], v[5], 740), Edge(v[5], v[3], 740), Edge(v[3], v[6], 867), Edge(v[6], v[3], 867),
	Edge(v[5], v[4], 1090), Edge(v[4], v[5], 1090), Edge(v[5], v[6], 187), Edge(v[6], v[5], 187),
	Edge(v[4], v[6], 1258), Edge(v[6], v[4], 1258),
	};
	
	int test_start = 1;
	int test_end = 6;
	Graph simpleGraph("GRAPH_SIMPLE_USA_7_NODES", NUM_NODES);//그래프 생성
	
	fout << "Inserting vertices .." << endl;
	for (int i = 0; i < NUM_NODES; i++) {
		simpleGraph.insertVertex(v[i]);//정점 삽입
	}
	
	VrtxList vtxLst;
	simpleGraph.vertices(vtxLst);//정점을 리스트에 담어줌
	int count = 0;
	
	fout << "Inserted vertices: ";
	for (VrtxItor vItor = vtxLst.begin(); vItor != vtxLst.end(); ++vItor)
	{
		fout << *vItor << ", ";//정점 출력 (정상적으로 입력되었는지 확인가능)
	}
	fout << endl;
	
	fout << "Inserting edges .." << endl;
	for (int i = 0; i < NUM_EDGES; i++)
	{
		simpleGraph.insertEdge(edges[i]);//간선 삽입
	}
	
	fout << "Inserted edges: " << endl;
	count = 0;
	EdgeList egLst;
	
	simpleGraph.edges(egLst);//간선 리스트에 담아줌
	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p)//처음부터 끝까지 실행
	{
		count++;
		fout << *p << ", ";//간선 출력
		if (count % 5 == 0)//줄바꿈
			fout << endl;
	}
	fout << endl;
	
	fout << "Print out Graph based on Adjacency List .." << endl;
	simpleGraph.fprintGraph(fout);//그래프 출력
	

	VrtxList path;
	BreadthFirstSearch bfsGraph(simpleGraph);//생성한 그래프로 객체 생성

	fout << "\nTesting Breadth First Search with Dijkstra Algorithm" << endl;
	bfsGraph.initDistMtrx();//2차원배열 초기화
	
	bfsGraph.fprintDistMtrx(fout);//거리 배열출력
	path.clear();
	
	fout << "\nDijkstra Shortest Path Finding from " << v[test_start].getName() << " to "<< v[test_end].getName() << " .... " << endl;
	bfsGraph.DijkstraShortestPath(fout, v[test_start], v[test_end], path);//최단거리 탐색
	
	fout << "Path found by DijkstraShortestPath from " << v[test_end] << " to " << v[test_start] << " : ";
	for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
	{
		fout << *vItor;
		if (*vItor != v[test_end])
			fout << " -> ";
	}
	fout << endl;
	fout.close();
}