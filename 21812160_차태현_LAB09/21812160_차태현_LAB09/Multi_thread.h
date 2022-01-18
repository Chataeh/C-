#ifndef MT_H
#define MT_H

#include"HeapPrioQueue.h"
#include"SimParams.h"
#include"Event.h"
#include<thread>
#include<process.h>

enum ROLE {EVENT_GENERATOR,EVENT_HANDLER};
enum THREAD_FLAG {INITIALIZE,RUN,TERMINATE};

typedef struct ThreadStatusMonitor
{
	int numEventGenerated;//������ �̺�Ʈ
	int numEventProcessed;//ó���� �̺�Ʈ
	int totalEventGenerated;//�� ������ �̺�Ʈ ��
	int totalEventProcessed;//�� ó���� �̺�Ʈ ��
	Event eventGenerated[TOTAL_NUM_EVENTS];//���� �̺�Ʈ
	Event eventProcessed[TOTAL_NUM_EVENTS];//ó�� �̺�Ʈ
	THREAD_FLAG* pFlagThreadTerminate;//������ ����
}ThreadStatusMonitor;//������ �����

typedef struct ThreadParam
{
	mutex* pCS_main;//���ι� �Ӱ豸��
	mutex* pCS_thrd_mon;//����͸� �Ӱ豸��
	HeapPrioQueue<int, Event>* pPriQ_Event;//�켱���� ť �̺�Ʈ ����
	FILE* fout;
	ROLE role;
	int myAddr;
	int maxRound;//�ִ� ����
	int targeEventGen;//���� �� ��
	LARGE_INTEGER QP_freq;//���ļ� ����
	ThreadStatusMonitor* pThrdMon;//����͸�
}ThreadParam_Event;


void EventGen(ThreadParam_Event* pParm);
void EventProc(ThreadParam_Event* pParm);
#endif // !MT_H
