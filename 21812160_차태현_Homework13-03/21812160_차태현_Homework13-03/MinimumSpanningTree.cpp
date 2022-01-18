#include"Graph.h"
#include"MinimumSpanningTree.h"
void MinimumSpanningTree::initDistMtrx()//�Ÿ�ǥ �ʱ�ȭ
{
	int** ppDistMtrx;
	int* pLeaseCostMtrx;
	int num_nodes;
	Vertex* pVrtxArray;
	EdgeList* pAdjLstArray;
	int curVID, vID;

	num_nodes = getNumVertices();//������ ����
	pVrtxArray = graph.getpVrtxArray();//���� �迭
	pAdjLstArray = graph.getpAdjLstArray();//����Ʈ �迭

	ppDistMtrx = getppDistMtrx();//2���� �迭

	for (int i = 0; i < num_nodes; i++)
	{
		curVID = pVrtxArray[i].getID();//ID �޾ƿ�
		EdgeItor pe = pAdjLstArray[curVID].begin();//���� ����Ʈ�� ó������
		while (pe != pAdjLstArray[curVID].end())//����������
		{
			vID = (*(*pe).getpVrtx_2()).getID();//���� 2 ����
			ppDistMtrx[curVID][vID] = (*pe).getDistance();//�Ÿ� �� ����
			pe++;//�ݺ��� ����
		}
		ppDistMtrx[curVID][curVID] = 0;//�ڱ��ڽ��� �Ÿ��� 0
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
	
	//�׷������� ���� �迭�޾ƿ�
	num_nodes = graph.getNumVertices();
	pVrtxArray = graph.getpVrtxArray();
	pAdjLstArray = graph.getpAdjLstArray();
	initDistMtrx();
	ppDistMtrx = getppDistMtrx();
	
	//�����Ҵ�
	pDist = new int[num_nodes];
	pVrtxStatus = new VertexStatus[num_nodes];
	pParentEdge = new Graph::Edge[num_nodes];
	
	//�ʱⰪ ����
	for (int i = 0; i < num_nodes; i++) {
		pDist[i] = PLUS_INF;
		pVrtxStatus[i] = NOT_SELECTED;
		pParentEdge[i] = Graph::Edge();
	}

	srand(time(0));
	start = rand() % num_nodes; // ���۳�� �������� ����
	cout << "Start node : " << start << endl;
	pDist[start] = 0;
	selectedEdgeLst.clear();
	for (int round = 0; round < num_nodes; round++)//��� �� ��ŭ ����
	{
		min_dist = PLUS_INF;
		min_id = -1;
		for (int n = 0; n < num_nodes; n++)
		{
			if ((pVrtxStatus[n] == NOT_SELECTED) && (pDist[n] < min_dist))//���õ��� �ʰ� ª���Ÿ� Ž��
			{
				//�� ����
				min_dist = pDist[n];
				min_id = n;
			} 
		} 
		if (min_id == -1)
		{
			cout << "Error in finding Prim-Jarnik's algorithm !!";
			break;
		}
		pVrtxStatus[min_id] = SELECTED;//min_id��� ���º���
		
		// edge relaxtion
		EdgeItor pe = pAdjLstArray[min_id].begin();//�����ݺ��� ó������
		while (pe != pAdjLstArray[min_id].end())//������
		{
			end_ID = (*(*pe).getpVrtx_2()).getID();//ID�޾ƿ�
			dist = (*pe).getDistance();//�Ÿ� �޾ƿ�
			if ((pVrtxStatus[end_ID] == NOT_SELECTED) && (dist <= pDist[end_ID]))//�Ÿ��� �� �۰� ���õ��� ���� ���� ���
			{
				pDist[end_ID] = dist;//�Ÿ� �� ���
				pParentEdge[end_ID] = *pe;//���� ���
			}
			pe++;//�������� �̵�
		} 

		if (min_id != start) //���� ���� �ƴҰ��
		{
			min_edge = pParentEdge[min_id];
			selectedEdgeLst.push_back(min_edge);
		}
		cout << "Dist after round [" << setw(2) << round << "] : ";
		// edge relaxtion ���� ����Ȯ��
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
	//���� �������
	while (edgeItor != selectedEdgeLst.end())
	{
		cout << *edgeItor << ", ";
		edgeItor++;
		if ((++cnt % 5) == 0)
			cout << endl;
	}
	cout << endl;
}