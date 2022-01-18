/**
*파일이름"21812160_차태현_LAB08 "
*프로그램의 목적 및 기본 기능:
*  템플릿을 사용하여 힙우선순위 큐 동작실행
*
*프로그램 작성자: 21812160 차태현(2021년 10월28일),
*최종 수정 및 보완: 2021년 10월 28일 (차태현)
*/
#include<iostream>
#include<fstream>
#include"Event.h"
#include"HeapPrioQueue.h"
#include<Windows.h>

using namespace std;

#define INITAL_CBT_CAPA 100
#define TEST_HEAP_PRIO_Q_EVENT
#define NUM_EVENTS 15

int main()
{
	ofstream fout;
	string tName = "";
	//char tmp[10];
	int priority = -1;
	//int current_top_priority;
	//int duration = 0;
	//int size;
	//int* pE;
	//LARGE_INTEGER freq, t1, t2;
	//LONGLONG t_diff;
	//double elapsed_time;

	fout.open("output.txt");
	
	//QueryPerformanceFrequency(&freq);
	//srand(time(NULL));
	Event events[NUM_EVENTS] =
	{
		Event(0, 14, "evt_00", 0), Event(1, 13, "evt_01", 1), Event(2, 12, "evt_02", 2),
		Event(3, 11, "evt_03", 3), Event(4, 10, "evt_04", 4), Event(5, 9, "evt_05", 5),
		Event(6, 8, "evt_06", 6), Event(7, 7, "evt_07", 7), Event(8, 6, "evt_08", 8),
		Event(9, 5, "evt_09", 9), Event(10, 4, "evt_10", 10), Event(11, 3, "evt_11", 11),
		Event(12, 2, "evt_12", 12), Event(13, 1, "evt_13", 13), Event(14, 0, "evt_14", 14)
	};

	HeapPrioQueue<int, Event*>HeapPriQ_Event(INITAL_CBT_CAPA, string("Event_Heap_Priority_Queue"));
	//Event* pEv;
	T_Entry<int, Event*>entry_event, * pEntry_Event;

	for (int i = 0; i < NUM_EVENTS; i++)
	{
		entry_event.setKey(events[i].gentEventPri());
		entry_event.setValue(&events[i]);
		//QueryPerformanceCounter(&t1);
		HeapPriQ_Event.insert(entry_event);
		fout << "Insert" << events[i];
		fout << "==> Size of Heap Priority Queue : " << setw(3) << HeapPriQ_Event.size() << endl;
	}

	fout << "Final status of insertions : " << endl;
	HeapPriQ_Event.fprintCBT_byLevel(fout);

	for (int i = 0; i < NUM_EVENTS; i++)
	{
		fout << "\nCurrent top priority in Heap Priority Queue : ";
		pEntry_Event = HeapPriQ_Event.getHeapMin();
		fout << *pEntry_Event << endl;
		pEntry_Event = HeapPriQ_Event.removeHeapMin();
		//QueryPerformanceCounter(&t2);
		fout << "Remove" << *pEntry_Event;
		fout << "==>" << HeapPriQ_Event.size() << "elements remains." << endl;
		HeapPriQ_Event.fprintCBT_byLevel(fout);
		
		//t_diff = t2.QuadPart - t1.QuadPart;
		//elapsed_time = (double)t_diff / freq.QuadPart;
		//fout << "Elapsed_Time  " << i << "-st Event took " << setw(10) << elapsed_time * 1000000 << "[micro-seconds]" << endl;
		fout << endl;
	}
	fout.close();

}