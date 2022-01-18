#include"BFS_Dijkstra.h"
#include"Graph.h"


void BreadthFirstSearch::initialize()//�ʱ�ȭ
{
	Vertex* pVrtx = getGraph().getpVrtxArray();//�׷������� ���� �迭�޾ƿ�

	VrtxList vrtxLst;
	graph.vertices(vrtxLst);//����Ʈ�� ���� ���
	int num_vertices = graph.getNumVertices();//������ ����
	for (int vID = 0; vID < num_vertices; vID++)
		pVrtx[vID].setVrtxStatus(UN_VISITED);//�������� �ʱ�ȭ

	EdgeList edges;
	graph.edges(edges);//����Ʈ�� ���� ���
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
		pe->setEdgeStatus(EDGE_UN_VISITED);//��������Ʈ ���� �ʱ�ȭ
}

void BreadthFirstSearch::initDistMtrx()//�Ÿ�ǥ �ʱ�ȭ
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

void BreadthFirstSearch::fprintDistMtrx(ofstream& fout)//�Ÿ�ǥ ���
{
	int** ppDistMtrx;
	Vertex* pVrtxArray;
	int num_nodes;
	int dist;
	int vID;
	string vName;

	pVrtxArray = graph.getpVrtxArray();//���� �迭����
	num_nodes = getNumVertices();//���� �� ����
	ppDistMtrx = getppDistMtrx();//2���� �迭 ����

	fout << "\nDistance Matrix of Graph (" << graph.getName() << ") :" << endl;
	fout << "       |";

	for (int i = 0; i < num_nodes; i++)//���� �� ��ŭ �ݺ�
	{
		vName = pVrtxArray[i].getName();//������ �̸� �޾ƿ�
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
		vName = pVrtxArray[i].getName();//�̸� ����
		fout << setw(5) << vName << "  |";
		for (int j = 0; j < num_nodes; j++)
		{
			dist = ppDistMtrx[i][j];//2�����迭���� i��°���� j�ΰ��� �Ÿ� �޾ƿ�
			if (dist == PLUS_INF)
				fout << setw(5) << "+oo";
			else
				fout << setw(5) << dist;//�Ÿ� ���
		}
		fout << endl;
	}
	fout << endl;
}

enum BFS_PROCESS_STATUS { NOT_SELECTED, SELECTED };
void BreadthFirstSearch::DijkstraShortestPath(ofstream& fout, Vertex& start, Vertex& target, VrtxList& path)//�ִܰŸ� 
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

	pVrtxArray = graph.getpVrtxArray();//�׷����� �����迭 �޾ƿ�
	pAdjLstArray = graph.getpAdjLstArray();//�׷����� ��������Ʈ�迭 �޾ƿ�
	start_vID = start.getID();//���� ����ID
	target_vID = target.getID();//���� ����ID

	num_nodes = getNumVertices();//���� ��
	ppDistMtrx = getppDistMtrx();// 2���� �迭

	pLeastCost = new int[num_nodes];
	pPrev = new int[num_nodes];//��λ� �ڽ��� �տ� �ִ� ����
	pBFS_Process_Stat = new BFS_PROCESS_STATUS[num_nodes];

	for (int i = 0; i < num_nodes; i++)
	{
		pLeastCost[i] = ppDistMtrx[start_vID][i];//���������� i��°���� �Ÿ�
		pPrev[i] = start_vID;//pPrev[i]�� ������ ��������
		pBFS_Process_Stat[i] = NOT_SELECTED;//i��° ������ ���õ��� ���� ����
	}
	pBFS_Process_Stat[start_vID] = SELECTED;//���������� ���õ� ���·� ����
	num_selected = 1;//���õ� ����==������
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

	while (num_selected < num_nodes)//���õ� ��尡 ���������� ������ ���� �� ��� ��带 �� Ž���Ҷ����� �ݺ�
	{
		round++;//���� ����
		fout << "round [" << setw(2) << round << "] |";
		minID = -1;
		minCost = PLUS_INF;
		for (int i = 0; i < num_nodes; i++)
		{
			if ((pLeastCost[i] < minCost) && (pBFS_Process_Stat[i] != SELECTED))//������ minCost���� �۰� ���õ��� �������
			{
				//�ּ�ID�� �ּҰŸ� ���� 
				minID = i;
				minCost = pLeastCost[i];
			}
		}
		if (minID == -1)//������ �������� ����
		{
			fout << "Error in Dijkstra() -- found not connected vertex !!" << endl;
			break;
		}
		else
		{
			pBFS_Process_Stat[minID] = SELECTED;//���õ����� ����
			num_selected++;//���õ� ��� ����

			if (minID == target_vID)//ID�� Ÿ��ID�� ������ ���������� �� ������ ����

			{
				fout << endl << "reached to the target node (" << pVrtxArray[minID].getName() << ") at Least Cost =" << minCost << endl;
				vID = minID;
				do {
					vrtx = pVrtxArray[vID];//�������� ����
					path.push_front(vrtx);//����Ʈ�� �Ǿտ� �־���
					vID = pPrev[vID];//���� �������� ����
				} while (vID != start_vID);//���� �������� �ݺ�
				vrtx = pVrtxArray[vID];//���� ����
				path.push_front(vrtx);//����Ʈ �Ǿտ� �������� �߰�
				break;
			}
		}
		int pLS, ppDistMtrx_i;
		for (int i = 0; i < num_nodes; i++)
		{
			pLS = pLeastCost[i];
			ppDistMtrx_i = ppDistMtrx[minID][i];

			if ((pBFS_Process_Stat[i] != SELECTED) && (pLeastCost[i] > (pLeastCost[minID] + ppDistMtrx[minID][i])))//���õ��� �ʰ� minID���� �Ÿ��� minID���� i������ �Ÿ��� �� �۴ٸ�
			{
				pPrev[i] = minID;//�ִܰŸ� ������ minID�̹Ƿ� ������带 minID�� ����
				pLeastCost[i] = pLeastCost[minID] + ppDistMtrx[minID][i];//�ּ� �Ÿ� ����
			}
		}
		for (int i = 0; i < num_nodes; i++)
		{
			cost = pLeastCost[i];//�ִܰŸ� ����
			if (cost == PLUS_INF)
				fout << "  +oo";
			else
				fout << setw(5) << pLeastCost[i];//���
		}
		fout << " ==> selected vertex :" << pVrtxArray[minID] << endl;
	}
}

