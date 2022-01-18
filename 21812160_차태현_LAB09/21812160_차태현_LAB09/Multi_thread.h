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
	int numEventGenerated;//생성된 이벤트
	int numEventProcessed;//처리된 이벤트
	int totalEventGenerated;//총 생성된 이벤트 수
	int totalEventProcessed;//총 처리된 이벤트 수
	Event eventGenerated[TOTAL_NUM_EVENTS];//생성 이벤트
	Event eventProcessed[TOTAL_NUM_EVENTS];//처리 이벤트
	THREAD_FLAG* pFlagThreadTerminate;//스레드 상태
}ThreadStatusMonitor;//스레드 모니터

typedef struct ThreadParam
{
	mutex* pCS_main;//메인문 임계구역
	mutex* pCS_thrd_mon;//모니터링 임계구역
	HeapPrioQueue<int, Event>* pPriQ_Event;//우선순위 큐 이벤트 생성
	FILE* fout;
	ROLE role;
	int myAddr;
	int maxRound;//최대 라운드
	int targeEventGen;//생성 할 수
	LARGE_INTEGER QP_freq;//주파수 측정
	ThreadStatusMonitor* pThrdMon;//모니터링
}ThreadParam_Event;


void EventGen(ThreadParam_Event* pParm);
void EventProc(ThreadParam_Event* pParm);
#endif // !MT_H
