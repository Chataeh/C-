/**
*�����̸�"21812160_������_Homework13-03"
*���α׷��� ���� �� �⺻ ���:
*MST��� ����
*
*���α׷� �ۼ���: 21812160 ������(2021�� 12��05��),
*���� ���� �� ����: 2021�� 12�� 05�� (������)
*/
#include"MinimumSpanningTree.h"


#define GRAPH_SIMPLE_USA_7_NODES
#define NUM_NODES 11 
#define NUM_EDGES 34

void main()
{
	ofstream fout;

	fout.open("output.txt");//���Ͽ���
	if (fout.fail())
	{
		cout << "Failed to open output.txt file !!" << endl;
		exit;
	}

	Vertex v[NUM_NODES] = // ���� ����
	{
	Vertex("GJ", 0), Vertex("DJ", 1), Vertex("DG", 2),
	Vertex("BS", 3), Vertex("PH", 4), Vertex("SW", 5),
	Vertex("WJ", 6),Vertex("GR",7),Vertex("SL",8),Vertex("CC",9),Vertex("SC",10)
	};

	Graph::Edge edges[NUM_EDGES] = // 34���� ����
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
	Graph simpleGraph("GRAPH_SIMPLE_USA_7_NODES", NUM_NODES);//�׷��� ����

	fout << "Inserting vertices .." << endl;
	for (int i = 0; i < NUM_NODES; i++) {
		simpleGraph.insertVertex(v[i]);//���� ����
	}

	VrtxList vtxLst;
	simpleGraph.vertices(vtxLst);//������ ����Ʈ�� �����
	int count = 0;

	fout << "Inserted vertices: ";
	for (VrtxItor vItor = vtxLst.begin(); vItor != vtxLst.end(); ++vItor)
	{
		fout << *vItor << ", ";//���� ��� (���������� �ԷµǾ����� Ȯ�ΰ���)
	}
	fout << endl;

	fout << "Inserting edges .." << endl;
	for (int i = 0; i < NUM_EDGES; i++)
	{
		simpleGraph.insertEdge(edges[i]);//���� ����
	}

	fout << "Inserted edges: " << endl;
	count = 0;
	EdgeList egLst;

	simpleGraph.edges(egLst);//���� ����Ʈ�� �����
	for (EdgeItor p = egLst.begin(); p != egLst.end(); ++p)//ó������ ������ ����
	{
		count++;
		fout << *p << ", ";//���� ���
		if (count % 5 == 0)//�ٹٲ�
			fout << endl;
	}
	fout << endl;

	fout << "Print out Graph based on Adjacency List .." << endl;
	simpleGraph.fprintGraph(fout);//�׷��� ���

	VrtxList path;
	MinimumSpanningTree bfsGraph(simpleGraph);//������ �׷����� ��ü ����

	bfsGraph.initDistMtrx();//2�����迭 �ʱ�ȭ

	bfsGraph.PrimJarnikMST();//MSTŽ�� �� ���
}