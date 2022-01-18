#include"Graph.h"


void Graph::insertVertex(Vertex& v)//���� �߰�
{
	int vID;
	vID = v.getID();//��ȣ ��ȯ
	if (pVrtxArray[vID] == NULL)//�迭�� ����ִٸ�
		pVrtxArray[vID] = v;//����
}

void Graph::vertices(VrtxList& vrtxLst)//���� ����Ʈ�� ���
{
	vrtxLst.clear();
	for (int i = 0; i < getNumVertices(); i++)//������ ��ŭ
		vrtxLst.push_back(pVrtxArray[i]);//push_back�� ���� �迭�� ���� �־���
}

void Graph::insertEdge(Edge& e)//���� �߰�
{
	Vertex vrtx_1, vrtx_2;//��������
	
	int vID_1, vID_2;

	vrtx_1 = *e.getpVrtx_1();//���� ����
	vID_1 = vrtx_1.getID();//��ȣ ����

	vrtx_2 = *e.getpVrtx_2();//���� ����
	vID_2 = vrtx_2.getID();//��ȣ ����

	if (pVrtxArray[vID_1] == NULL)//����ִ°��
		pVrtxArray[vID_1] = vrtx_1;//����

	if (pVrtxArray[vID_2] == NULL)//����ִ°�� 
		pVrtxArray[vID_2] = vrtx_2;//����

	e.setpVrtx_1(&pVrtxArray[vID_1]);//������ ����1 ����
	e.setpVrtx_2(&pVrtxArray[vID_2]);//������ ����2 ����

	pAdjLstArray[vID_1].push_back(e);//���� �߰�
}


void Graph::edges(EdgeList& edges)//����Ʈ�� �������
{
	EdgeItor eItor;
	Graph::Edge e;

	edges.clear();
	for (int i = 0; i < getNumVertices(); i++)//���� �� ��ŭ
	{
		eItor = pAdjLstArray[i].begin();//�ݺ��� ���ۺ���
		while (eItor != pAdjLstArray[i].end())//������
		{
			e = *eItor;//�ݺ��ڰ� ����Ű�� ��
			edges.push_back(e);//���� ����Ʈ�� ���
			eItor++;//�������� �̵�
		}
	}
}

void Graph::incidentEdges(Vertex v, EdgeList& edgeLst)//V������ ���� ã��
{
	Graph::Edge e;
	EdgeItor eItor;
	int vID = v.getID();//��ȣ ����

	eItor = pAdjLstArray[vID].begin();//�ݺ��� ���ۺ���
	while (eItor != pAdjLstArray[vID].end())//������ �ݺ�
	{
		e = *eItor;//�ݺ��ڰ� ����Ű�� ��
		edgeLst.push_back(e);//���� ����Ʈ�� ���
		eItor++;//�ݺ��� ����
	}
}

bool Graph::isValidVrtxID(int vid)//���� �Ǻ�
{
	if ((vid >= 0) && (vid < num_vertices))//�������
		return true;
	else
	{
		cout << "Vertex ID (" << vid << ") is invalid for Graph (" << getName()<< ") with num_vertices (" << num_vertices << ")" << endl;
	}
}

void Graph::fprintGraph(ofstream& fout)//���
{
	int i, j;
	EdgeItor eItor;
	Graph::Edge e;
	int numOutgoingEdges;

	fout << this->getName() << " with " << this->getNumVertices() << " vertices has following connectivity :" << endl;

	for (i = 0; i < num_vertices; i++)//������ŭ �ݺ�
	{
		fout << " vertex (" << setw(3) << pVrtxArray[i].getName() << ") : ";
		numOutgoingEdges = pAdjLstArray[i].size();//������ ����

		eItor = pAdjLstArray[i].begin();//���ۺ���
		while (eItor != pAdjLstArray[i].end())//������ �ݺ�
		{
			e = *eItor;//�� �޾ƿ�
			fout << e << " ";//���
			eItor++;//�ݺ��� ����
		}
		fout << endl;
	}
}