/**
*�����̸�"21812160_������_LAB09 "
*���α׷��� ���� �� �⺻ ���:
*  ��Ƽ������ ���۽��� ����͸�
*
*���α׷� �ۼ���: 21812160 ������(2021�� 11��05��),
*���� ���� �� ����: 2021�� 11�� 05�� (������)
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
	fout.open("output.txt");//���� ����
	LARGE_INTEGER QP_freq;//�ð� ����� ����
	double elapsed_time, min_elapsed_time, max_elapsed_time;
	double avg_elapsed_time, total_elapsed_time;
	HeapPrioQueue<int, Event> heapPriQ_Event(30, string("HeapPriorityQueue_Event"));//�켱���� ť ����
	Event* pEvent, * pEv_min_elasped_time, * pEv_max_elapsed_time;//�̺�Ʈ ,�ִ�ð� �ɸ� �̺�Ʈ ,�ּҽð��ɸ��̺�Ʈ
	int myAddr = 0;
	int eventPriority;

	ThreadParam_Event thrdParam_EventGen, thrdParam_EventHndlr;//������ �Ķ��Ÿ
	HANDLE hThrd_EventGenerator, hThrd_EventHandler;
	mutex cs_main;//���� �Ӱ豸��
	mutex cs_thrd_mon;//������ ����͸� �Ӱ豸��
	ThreadStatusMonitor thrdMon;//������ ����͸�
	HANDLE consHndlr;
	THREAD_FLAG eventThreadFlag = RUN;//������ ����
	int count, numEventGenerated, numEventProcessed;//����ó���� �̺�Ʈ ��
	int num_events_in_PrioQ;
	Event eventProcessed[TOTAL_NUM_EVENTS];//ó���� �̺�Ʈ

	

	consHndlr = initConsoleHandler();
	QueryPerformanceFrequency(&QP_freq);//���ļ� ����
	srand(time(NULL));

	thrdMon.pFlagThreadTerminate = &eventThreadFlag; //RUN����
	thrdMon.totalEventGenerated = 0;//�ʱ� ������ �̺�Ʈ 0
	thrdMon.totalEventProcessed = 0;//�ʱ� ó���� �̺�Ʈ 0

	for (int ev = 0; ev < TOTAL_NUM_EVENTS; ev++)
	{
		thrdMon.eventProcessed[ev].setEventNo(-1);
		thrdMon.eventProcessed[ev].setEventPri(-1);
	}
	//ó�� ������ �μ� �ʱ�ȭ
	thrdMon.numEventProcessed = 0;
	thrdParam_EventHndlr.role = EVENT_HANDLER;
	thrdParam_EventHndlr.myAddr = 1;
	thrdParam_EventHndlr.pCS_main = &cs_main;
	thrdParam_EventHndlr.pCS_thrd_mon = &cs_thrd_mon;
	thrdParam_EventHndlr.pPriQ_Event = &heapPriQ_Event;
	thrdParam_EventHndlr.maxRound = MAX_ROUND;
	thrdParam_EventHndlr.QP_freq = QP_freq;
	thrdParam_EventHndlr.pThrdMon = &thrdMon;

	thread thrd_EvProc(EventProc, &thrdParam_EventHndlr);//������ ������ ����
	cs_main.lock();
	printf("Thread_EventProc is created and activated...\n");
	cs_main.unlock();
	
	// ���� ������ �μ� �ʱ�ȭ
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
		cs_main.lock();//�Ӱ豸�� ����
		cls(consHndlr);
		gotoxy(consHndlr, 0, 0);

		printf( "Thread monitoring by main()::\n" );
		printf(" round(%2d): current total_event_gen (%2d), total_event_proc(%2d)\n",round, thrdMon.totalEventGenerated, thrdMon.totalEventProcessed);
		printf("\n*****************************\n");
		numEventGenerated = thrdMon.numEventGenerated;//�����̺�Ʈ �� = ����͸� �����̺�Ʈ ��
		printf("Events generated (current total = %2d)\n", numEventGenerated);

		count = 0;

		for (int ev = 0; ev < numEventGenerated; ev++)
		{
			pEvent = &thrdMon.eventGenerated[ev];//�̺�Ʈ ����
			if (pEvent != NULL)
			{
				cout << *pEvent << "";//�̺�Ʈ ���
				if (((ev + 1) % EVENT_PER_LINE) == 0)
					printf("\n");
			}
		}
		printf("\n");

		printf("\n*****************************\n");
		num_events_in_PrioQ = heapPriQ_Event.size();//ť ũ��
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
				min_elapsed_time = max_elapsed_time = total_elapsed_time = pEvent->getEventElapsedTime();//�ʱⰪ ����
				pEv_min_elasped_time = pEv_max_elapsed_time = pEvent;//�ʱⰪ ����
			}
			else
			{
				if (min_elapsed_time > pEvent->getEventElapsedTime())//�ּ� �ð����� �������
				{
					min_elapsed_time = pEvent->getEventElapsedTime();//�ּҽð� ����
					pEv_min_elasped_time = pEvent;//�ּҽð� �̺�Ʈ ����
				}
				if (max_elapsed_time < pEvent->getEventElapsedTime())//�ִ�ð� ���� Ŭ���
				{
					max_elapsed_time = pEvent->getEventElapsedTime();//�ִ�ð� ����
					pEv_max_elapsed_time = pEvent;//�ִ�ð� �̺�Ʈ ����
				}
				total_elapsed_time += pEvent->getEventElapsedTime();//�� �ɸ��ð�
			}
		}
		printf("\n");
	
		if (numEventProcessed > 0)
		{
			printf("numEventProcessed = %d\n", numEventProcessed);
			printf("min_elapsed_time = %8.2lf[ms]; ", min_elapsed_time);
			cout << *pEv_min_elasped_time << endl;//�ּҽð� �̺�Ʈ ���
			printf("max_elapsed_time = %8.2lf[ms]; ", max_elapsed_time);
			cout << *pEv_max_elapsed_time << endl;//�ִ�ð� �̺�Ʈ ���
			avg_elapsed_time = total_elapsed_time / numEventProcessed;//�̺�Ʈ ����ó�� ��սð�
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