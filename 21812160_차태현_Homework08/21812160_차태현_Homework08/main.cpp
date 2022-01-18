/**
*�����̸�"21812160_������_Homework08"
*���α׷��� ���� �� �⺻ ���:
*  ���ø��� ����� heap�켱���� ť ����Ȯ��
*
*���α׷� �ۼ���: 21812160 ������(2021�� 10��31��),
*���� ���� �� ����: 2021�� 10�� 31�� (������)
*/#include"HeapPrioQueue.h"
#include<fstream>

#define INITIAL_CBT_CAPA 100
#define NUM_DATA 15

int main()
{
	ofstream fout;
	int size;
	int* pD;
	int inputArray[NUM_DATA] =
	{ 14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };

	fout.open("output.txt");

	HeapPrioQueue<int> HeapPriQ_int(INITIAL_CBT_CAPA, string("Heap_Priority_Queue_Int"));//int�� heap�켱���� ť����
	for (int i = 0; i < NUM_DATA; i++)
	{
		HeapPriQ_int.insert(inputArray[i]);//����
		fout << "Insert " << setw(3) << inputArray[i];
		fout << " ==> Size of Heap Priority Queue : " << setw(3) << HeapPriQ_int.size() << endl;
	}
	fout << "Final status of insertions : " << endl;
	HeapPriQ_int.fprintCBT_byLevel(fout);//������ ���
	for (int i = 0; i < NUM_DATA; i++)
	{
		fout << "\nCurrent top priority in Heap Priority Queue : ";
		pD = HeapPriQ_int.getHeapMin();//����
		fout << setw(3) << *pD << endl;
		pD = HeapPriQ_int.removeHeapMin();//����
		fout << "RemoveMin (" << *pD << ") from HeapPriQ_int";
		fout << " ==> " << HeapPriQ_int.size() << " elements remains." << endl;
		HeapPriQ_int.fprintCBT_byLevel(fout);//���
		fout << endl;
	}
	fout.close();//���ϴݱ�
}