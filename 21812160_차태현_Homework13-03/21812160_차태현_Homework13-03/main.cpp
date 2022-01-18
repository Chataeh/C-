/**
*파일이름"21812160_차태현_Homework13-03"
*프로그램의 목적 및 기본 기능:
*MST기능 실행
*
*프로그램 작성자: 21812160 차태현(2021년 12월05일),
*최종 수정 및 보완: 2021년 12월 05일 (차태현)
*/
#include"MinimumSpanningTree.h"


#define GRAPH_SIMPLE_USA_7_NODES
#define NUM_NODES 11 
#define NUM_EDGES 34

void main()
{
	ofstream fout;

	fout.open("output.txt");//파일열기
	if (fout.fail())
	{
		cout << "Failed to open output.txt file !!" << endl;
		exit;
	}

	Vertex v[NUM_NODES] = // 정점 생성
	{
	Vertex("GJ", 0), Vertex("DJ", 1), Vertex("DG", 2),
	Vertex("BS", 3), Vertex("PH", 4), Vertex("SW", 5),
	Vertex("WJ", 6),Vertex("GR",7),Vertex("SL",8),Vertex("CC",9),Vertex("SC",10)
	};

	Graph::Edge edges[NUM_EDGES] = // 34개의 간선
	{
	Edge(v[0], v[1], 138), Edge(v[1], v[0], 138), Edge(v[0], v[2], 170), Edge(v[2], v[0], 170),
	Edge(v[0], v[3], 202), Edge(v[3], v[0], 202), Edge(v[2], v[4], 66), Edge(v[4], v[2], 66),
	Edge(v[1], v[2], 120), Edge(v[2], v[1], 120), Edge(v[3], v[4], 93), Edge(v[4], v[3], 93),
	Edge(v[2], v[3], 87), Edge(v[3], v[2], 87),Edge(v[1], v[5], 109), Edge(v[5], v[1], 109),
	Edge(v[2], v[6], 174), Edge(v[6], v[2], 174),Edge(v[4], v[7], 200), Edge(v[7], v[4], 200),
	Edge(v[5], v[6], 84), Edge(v[6], v[5], 84), Edge(v[6], v[7], 91), Edge(v[7], v[6], 91),
	Edge(v[5], v[8], 34), Edge(v[8], v[5], 34), Edge(v[6], v[9], 47), Edge(v[6], v[9], 47),
	Edge(v[7], v[10], 42), Edge(v[10], v[7], 42), Edge(v[8], v[9], 71), Edge(v[9], v[8], 71),
	Edge(v[9], v[10], 79), Edge(v[10], v[9], 79),
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
	MinimumSpanningTree bfsGraph(simpleGraph);//생성한 그래프로 객체 생성

	bfsGraph.initDistMtrx();//2차원배열 초기화

	bfsGraph.PrimJarnikMST();//MST탐색 및 출력
}