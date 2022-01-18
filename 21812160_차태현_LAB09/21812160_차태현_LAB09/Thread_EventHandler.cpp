#include<Windows.h>
#include"Multi_thread.h"
#include"HeapPrioQueue.h"
#include"Event.h"
#include"SimParams.h"

using std::this_thread::sleep_for;

void EventProc(ThreadParam_Event* pParm)
{
	HeapPrioQueue<int, Event>* pPriQ_Event=pParm->pPriQ_Event;//우선순위 큐 생성후 파라메타로부터 받아옴
	//pParm으로 부터 값받아와 초기화해줌
	int myRole =pParm->role;
	int myAddr=pParm->myAddr;
	int maxRound=pParm->maxRound;
	int targetEventGen = pParm->targeEventGen;
	LARGE_INTEGER QP_freq = pParm->QP_freq;
	ThreadStatusMonitor* pThrdMon=pParm->pThrdMon;

	T_Entry<int, Event>* pEntry;
	Event event, * pEvent, * pEventProc;
	int event_no = 0;//이벤트 번호
	int evnet_Priority = 0;//이벤트 우선순위
	int event_gen_count = 0;
	int num_pkt_proceesed = 0;
	
	//처리시간을 표현하기위한 정의
	LARGE_INTEGER  t_gen, t_proc;
	LONGLONG t_diff;
	double elapsed_time;

	for (int round = 0; round < maxRound; round++)
	{
		if (*pThrdMon->pFlagThreadTerminate == TERMINATE)//TERMINATE일시 종료
			break;
		if (!pPriQ_Event->isEmpty())//추출 할 것이 있을경우
		{
			pEntry = pPriQ_Event->removeHeapMin();//이벤트 추출을 위해 전달받음
			event = pEntry->getValue();//Value인 event 저장
			pParm->pCS_thrd_mon->lock();//임계구역 생성
			event.setEventHandlerAddr(myAddr);//처리자 주소설정
			QueryPerformanceCounter(&t_proc);//시간기록
			event.setEventProcTime(t_proc);//시간설정
			t_gen = event.getEventGenTime();//생성시간 받아옴
			t_diff = t_proc.QuadPart - t_gen.QuadPart;//시간 차 
			elapsed_time = ((double)t_diff / QP_freq.QuadPart);// 시간 계산
			event.setEventElaspsedTime(elapsed_time * 1000);//밀리초
			pThrdMon->eventProcessed[pThrdMon->totalEventProcessed] = event;//처리된 이벤트 저장
			pThrdMon->numEventProcessed++;//처리된 이벤트 수 증가
			pThrdMon->totalEventProcessed++;//처리된 총 이벤트 수 증가
			pParm->pCS_thrd_mon->unlock();//임계구역 해제
		}
		//sleep_for(std::chrono::milliseconds(100 + rand() % 100));
		Sleep(100 + rand() % 100);
	}
	
}