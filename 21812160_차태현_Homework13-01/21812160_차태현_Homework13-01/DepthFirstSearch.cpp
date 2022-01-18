#include"DepthFirstSearch.h"
#include"Graph.h"

DepthFirstSearch::DepthFirstSearch(Graph& g) :graph(g)
{
	int num_nodes = g.getNumVertices();//���� ������ȯ
	
	pVrtxStatus = new VrtxStatus[num_nodes];//���� ����
	for (int i = 0; i < num_nodes; i++)
		pVrtxStatus[i] = UN_VISITED;//UN_VISITED�� �ʱ�ȭ
	
	//2���� �����Ҵ�
	ppEdgeStatus = new EdgeStatus * [num_nodes];
	for (int i = 0; i < num_nodes; i++)
		ppEdgeStatus[i] = new EdgeStatus[num_nodes];
	
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppEdgeStatus[i][j] = EDGE_UN_VISITED;//2���� �����迭 �ʱ�ȭ
	
	//2���� �����Ҵ�
	ppConnectivity = new int* [num_nodes];
	for (int i = 0; i < num_nodes; i++)
		ppConnectivity[i] = new int[num_nodes];
	
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppConnectivity[i][j] = PLUS_INF;//�� �ʱ�ȭ

	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	EdgeList edges;
	
	edges.clear();
	graph.edges(edges);//���� ����Ʈ�� �����
	
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
	{
		//������ ���� ��� ����
		vrtx_1 = *(*pe).getpVrtx_1(); 
		vID_1 = vrtx_1.getID();
		
		vrtx_2 = *(*pe).getpVrtx_2();
		vID_2 = vrtx_2.getID();
		
		ppConnectivity[vID_1][vID_2] = (*pe).getDistance();//�Ÿ� 
	}
	
	for (int i = 0; i < num_nodes; i++)
		ppConnectivity[i][i] = 0; // ���� ���� �Ÿ��� 0
}

void DepthFirstSearch::initialize()// �ʱ�ȭ
{
	int num_nodes = graph.getNumVertices();
	VrtxList verts;
	graph.vertices(verts);//���� ����Ʈ�� �����
	
	Vertex vrtx_1, vrtx_2;
	int vID_1, vID_2;
	done = false;
	
	for (int i = 0; i < num_nodes; i++)
		pVrtxStatus[i] = UN_VISITED;//���� ����
	for (int i = 0; i < num_nodes; i++)
		for (int j = 0; j < num_nodes; j++)
			ppEdgeStatus[i][j] = EDGE_UN_VISITED;//���� ����
}

void DepthFirstSearch::showConnectivity(ofstream& fout)//���
{
	int num_nodes = graph.getNumVertices();
	int dist;
	Graph g = getGraph();
	Vertex* pVrtxArray = g.getpVrtxArray();//�����迭 �޾ƿ�
	
	fout << "Connectivity of graph: " << endl;
	fout << "       |";
	
	for (int i = 0; i < num_nodes; i++)
		fout << setw(5) << pVrtxArray[i].getName();//�����̸� ���
	fout << endl;
	
	fout << "-------+";
	for (int i = 0; i < num_nodes; i++)
		fout << "-----";
	fout << endl;
	
	for (int i = 0; i < num_nodes; i++) {
		fout << setw(5) << pVrtxArray[i].getName() << "  |";
	
		for (int j = 0; j < num_nodes; j++)
		{
			dist = ppConnectivity[i][j];//�Ÿ���İ� �޾ƿ�
			if (dist == PLUS_INF)
				fout << setw(5) << " +oo";
			else
				fout << setw(5) << dist;
		}
			fout << endl;
	} 
}


void DepthFirstSearch::dfsTraversal(Vertex& v, Vertex& target, VrtxList& path)//��� Ž��
{
	visit(v);//v visit���·� ����
	if (v == target) //v�� target�ϰ�� �������� ����
	{
		done = true;
		return;
	}
	EdgeList incidentEdges;//��������Ʈ ����
	incidentEdges.clear();
	graph.incidentEdges(v, incidentEdges);//v�� ����� ���� ����Ʈ�� ���
	EdgeItor pe = incidentEdges.begin();//�ݺ����� ó������
	while (!isDone() && pe != incidentEdges.end())//���°� flase�̰� �ݺ����� ���������� �ݺ� 
	{
		Edge e = *pe++;//���� ���� �� ���� �������� �Ѿ
		EdgeStatus eStat = getEdgeStatus(e);
		if (eStat == EDGE_UN_VISITED)//�湮���� ���� ������ ���
		{
			visit(e);//���� ����
			Vertex w = e.opposite(v);//e������ v �̿��� ���� ����
			if (!isVisited(w))//�湮���� ���� �����
			{
				path.push_back(w);//����Ʈ�� �����
				setEdgeStatus(e, DISCOVERY);//���� ���� ����
				if (!isDone()) //���� �������� �������� ����
				{
					dfsTraversal(w, target, path);//w�� ���� �������� ����Լ� ȣ�� 
					if (!isDone()) //�������� ���� ���� �������
					{	
						//����Ŭ �����Ǳ⶧���� �����ϱ����ؼ� ����
						Vertex last_pushed = path.back(); //path �� �������� ���� ����
						path.pop_back();//����
					}
				}
			}
			else //w�� �湮�� �����̶��
			{
				setEdgeStatus(e, BACK);//BACK�� ���� ����
			}
		} 
	}
}

void DepthFirstSearch::findPath(Vertex& start, Vertex& target, VrtxList& path)
{
	initialize();//�ʱ�ȭ
	path.clear();
	
	path.push_back(start);//�������
	dfsTraversal(start, target, path);//��� Ž�� �� path�� �����
}

void DepthFirstSearch::visit(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	
	if (graph.isValidVrtxID(vID))//���� Ȯ��
	{
		pVrtxStatus[vID] = VISITED;//���º���
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
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//���� Ȯ��
	{
		ppEdgeStatus[vID_1][vID_2] = EDGE_VISITED;//���º���
	}
}

void DepthFirstSearch::unvisit(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	
	if (graph.isValidVrtxID(vID))//���� Ȯ��
	{
		pVrtxStatus[vID] = UN_VISITED;//���º���
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
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//���� Ȯ��
	{
		ppEdgeStatus[vID_1][vID_2] = EDGE_UN_VISITED;//���º���
	}
}

bool DepthFirstSearch::isVisited(Vertex& v)
{
	Graph::Vertex* pVtx;
	int numNodes = getGraph().getNumVertices();
	int vID = v.getID();
	
	if (graph.isValidVrtxID(vID))
	{
		return (pVrtxStatus[vID] == VISITED);//�湮�� ��쿡 true
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
	
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//���� Ȯ��
	{
		eStat = ppEdgeStatus[vID_1][vID_2];
		if ((eStat == EDGE_VISITED) || (eStat == DISCOVERY) || (eStat == BACK))//�湮������ �ִ»���
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
	
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//���� Ȯ��
	{
		ppEdgeStatus[vID_1][vID_2] = es;//es ���·� ��������
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
	
	if (graph.isValidVrtxID(vID_1) && graph.isValidVrtxID(vID_2))//���� Ȯ��
	{
		eStat = ppEdgeStatus[vID_1][vID_2];//���¼���
		return eStat;
	}
	else {
		cout << "Edge (" << e << ") was not found from AdjacencyList" << endl;
		return EDGE_NOT_FOUND;
	}
}