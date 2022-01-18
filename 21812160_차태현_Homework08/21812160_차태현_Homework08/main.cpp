/**
*파일이름"21812160_차태현_Homework08"
*프로그램의 목적 및 기본 기능:
*  템플릿을 사용한 heap우선순이 큐 동작확인
*
*프로그램 작성자: 21812160 차태현(2021년 10월31일),
*최종 수정 및 보완: 2021년 10월 31일 (차태현)
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

	HeapPrioQueue<int> HeapPriQ_int(INITIAL_CBT_CAPA, string("Heap_Priority_Queue_Int"));//int형 heap우선순위 큐생성
	for (int i = 0; i < NUM_DATA; i++)
	{
		HeapPriQ_int.insert(inputArray[i]);//삽입
		fout << "Insert " << setw(3) << inputArray[i];
		fout << " ==> Size of Heap Priority Queue : " << setw(3) << HeapPriQ_int.size() << endl;
	}
	fout << "Final status of insertions : " << endl;
	HeapPriQ_int.fprintCBT_byLevel(fout);//레벨별 출력
	for (int i = 0; i < NUM_DATA; i++)
	{
		fout << "\nCurrent top priority in Heap Priority Queue : ";
		pD = HeapPriQ_int.getHeapMin();//추출
		fout << setw(3) << *pD << endl;
		pD = HeapPriQ_int.removeHeapMin();//제거
		fout << "RemoveMin (" << *pD << ") from HeapPriQ_int";
		fout << " ==> " << HeapPriQ_int.size() << " elements remains." << endl;
		HeapPriQ_int.fprintCBT_byLevel(fout);//출력
		fout << endl;
	}
	fout.close();//파일닫기
}