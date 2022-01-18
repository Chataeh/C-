/**
*파일이름"21812160_차태현_LAB09 "
*프로그램의 목적 및 기본 기능:
*  멀티스레드 동작실행 모니터링
*
*프로그램 작성자: 21812160 차태현(2021년 11월05일),
*최종 수정 및 보완: 2021년 11월 05일 (차태현)
*/
#include<stdio.h>
#include<stdlib.h>
#include"Multi_thread.h"
#include"HeapPrioQueue.h"
#include"Event.h"
#include"ConsoleDisplay.h"
#include"SimParams.h"
#include<time.h>
#include<conio.h>
#include <thread>
#include <mutex>
#include <Windows.h>

using namespace std;
void main()
{
	ofstream fout;
	fout.open("output.txt");//파일 열기
	LARGE_INTEGER QP_freq;//시간 계산을 위함
	double elapsed_time, min_elapsed_time, max_elapsed_time;
	double avg_elapsed_time, total_elapsed_time;
	HeapPrioQueue<int, Event> heapPriQ_Event(30, string("HeapPriorityQueue_Event"));//우선순위 큐 생성
	Event* pEvent, * pEv_min_elasped_time, * pEv_max_elapsed_time;//이벤트 ,최대시간 걸린 이벤트 ,최소시간걸린이벤트
	int myAddr = 0;
	int eventPriority;

	ThreadParam_Event thrdParam_EventGen, thrdParam_EventHndlr;//스레드 파라메타
	HANDLE hThrd_EventGenerator, hThrd_EventHandler;
	mutex cs_main;//메인 임계구역
	mutex cs_thrd_mon;//스레드 모니터링 임계구역
	ThreadStatusMonitor thrdMon;//스레드 모니터링
	HANDLE consHndlr;
	THREAD_FLAG eventThreadFlag = RUN;//스레드 실행
	int count, numEventGenerated, numEventProcessed;//생성처리된 이벤트 수
	int num_events_in_PrioQ;
	Event eventProcessed[TOTAL_NUM_EVENTS];//처리된 이벤트

	

	consHndlr = initConsoleHandler();
	QueryPerformanceFrequency(&QP_freq);//주파수 측정
	srand(time(NULL));

	thrdMon.pFlagThreadTerminate = &eventThreadFlag; //RUN상태
	thrdMon.totalEventGenerated = 0;//초기 생성된 이벤트 0
	thrdMon.totalEventProcessed = 0;//초기 처리된 이벤트 0

	for (int ev = 0; ev < TOTAL_NUM_EVENTS; ev++)
	{
		thrdMon.eventProcessed[ev].setEventNo(-1);
		thrdMon.eventProcessed[ev].setEventPri(-1);
	}
	//처리 스레드 인수 초기화
	thrdMon.numEventProcessed = 0;
	thrdParam_EventHndlr.role = EVENT_HANDLER;
	thrdParam_EventHndlr.myAddr = 1;
	thrdParam_EventHndlr.pCS_main = &cs_main;
	thrdParam_EventHndlr.pCS_thrd_mon = &cs_thrd_mon;
	thrdParam_EventHndlr.pPriQ_Event = &heapPriQ_Event;
	thrdParam_EventHndlr.maxRound = MAX_ROUND;
	thrdParam_EventHndlr.QP_freq = QP_freq;
	thrdParam_EventHndlr.pThrdMon = &thrdMon;

	thread thrd_EvProc(EventProc, &thrdParam_EventHndlr);//스레드 생성및 실행
	cs_main.lock();
	printf("Thread_EventProc is created and activated...\n");
	cs_main.unlock();
	
	// 생성 스레드 인수 초기화
	thrdMon.numEventGenerated = 0;
	thrdParam_EventGen.role = EVENT_GENERATOR;
	thrdParam_EventGen.myAddr = 0;
	thrdParam_EventGen.pCS_main = &cs_main;
	thrdParam_EventGen.pCS_thrd_mon = &cs_thrd_mon;
	thrdParam_EventGen.pPriQ_Event = &heapPriQ_Event;
	thrdParam_EventGen.targeEventGen = NUM_EVENTS_PER_GEN;
	thrdParam_EventGen.maxRound = MAX_ROUND;
	thrdParam_EventGen.QP_freq = QP_freq;
	thrdParam_EventGen.pThrdMon = &thrdMon;

	thread thrd_EvGen(EventGen, &thrdParam_EventGen);
	cs_main.lock();
	printf( "Thread_EventGen is created and activated ...\n" );
	cs_main.unlock();


	for (int round = 0; round < MAX_ROUND; round++)
	{
		cs_main.lock();//임계구역 생성
		cls(consHndlr);
		gotoxy(consHndlr, 0, 0);

		printf( "Thread monitoring by main()::\n" );
		printf(" round(%2d): current total_event_gen (%2d), total_event_proc(%2d)\n",round, thrdMon.totalEventGenerated, thrdMon.totalEventProcessed);
		printf("\n*****************************\n");
		numEventGenerated = thrdMon.numEventGenerated;//생성이벤트 수 = 모니터링 생성이벤트 수
		printf("Events generated (current total = %2d)\n", numEventGenerated);

		count = 0;

		for (int ev = 0; ev < numEventGenerated; ev++)
		{
			pEvent = &thrdMon.eventGenerated[ev];//이벤트 저장
			if (pEvent != NULL)
			{
				cout << *pEvent << "";//이벤트 출력
				if (((ev + 1) % EVENT_PER_LINE) == 0)
					printf("\n");
			}
		}
		printf("\n");

		printf("\n*****************************\n");
		num_events_in_PrioQ = heapPriQ_Event.size();//큐 크기
		printf("Events currently in Priority_Queue (%d) : \n", num_events_in_PrioQ);
		heapPriQ_Event.fprint(cout);

		printf("\n*****************************\n");
		numEventProcessed = thrdMon.totalEventProcessed;
		printf("Events processed (current total = %d): \n", numEventProcessed);
		count = 0;
		total_elapsed_time = 0.0;

		for (int ev = 0; ev < numEventProcessed; ev++)
		{
			pEvent = &thrdMon.eventProcessed[ev];
			if (pEvent != NULL)
			{
				pEvent->printEvent_proc();
				if (((ev + 1) % EVENT_PER_LINE) == 0)
					printf("\n");
			}
			if (ev == 0)
			{
				min_elapsed_time = max_elapsed_time = total_elapsed_time = pEvent->getEventElapsedTime();//초기값 설정
				pEv_min_elasped_time = pEv_max_elapsed_time = pEvent;//초기값 설정
			}
			else
			{
				if (min_elapsed_time > pEvent->getEventElapsedTime())//최소 시간보다 작을경우
				{
					min_elapsed_time = pEvent->getEventElapsedTime();//최소시간 설정
					pEv_min_elasped_time = pEvent;//최소시간 이벤트 설정
				}
				if (max_elapsed_time < pEvent->getEventElapsedTime())//최대시간 보다 클경우
				{
					max_elapsed_time = pEvent->getEventElapsedTime();//최대시간 설정
					pEv_max_elapsed_time = pEvent;//최대시간 이벤트 설정
				}
				total_elapsed_time += pEvent->getEventElapsedTime();//총 걸린시간
			}
		}
		printf("\n");
	
		if (numEventProcessed > 0)
		{
			printf("numEventProcessed = %d\n", numEventProcessed);
			printf("min_elapsed_time = %8.2lf[ms]; ", min_elapsed_time);
			cout << *pEv_min_elasped_time << endl;//최소시간 이벤트 출력
			printf("max_elapsed_time = %8.2lf[ms]; ", max_elapsed_time);
			cout << *pEv_max_elapsed_time << endl;//최대시간 이벤트 출력
			avg_elapsed_time = total_elapsed_time / numEventProcessed;//이벤트 생성처리 평균시간
			printf("avg_elapsed_time = %8.2lf[ms]; \n", avg_elapsed_time);

		}
		if (numEventProcessed >= TOTAL_NUM_EVENTS)
		{
			eventThreadFlag = TERMINATE;
			cs_main.unlock();
			break;
		}
	cs_main.unlock();
	Sleep(100);
	}

	
	thrd_EvProc.join();
	thrd_EvGen.join();

	fout.close();

	printf("Hit any key to terminate : ");
	_getch();

}