#include<Windows.h>
#include"Multi_thread.h"
#include"HeapPrioQueue.h"
#include"Event.h"
#include"SimParams.h"

using std::this_thread::sleep_for;

void EventGen(ThreadParam_Event* pParm)
{
	HeapPrioQueue<int, Event>* pPriQ_Event = pParm->pPriQ_Event;//우선순위 큐 생성후 파라메타로부터 받아옴
	//pParm으로 부터 값받아와 초기화해줌
	int myRole = pParm->role;
	int myAddr = pParm->myAddr;
	int maxRound = pParm->maxRound;
	int targetEventGen = pParm->targeEventGen;
	LARGE_INTEGER QP_freq = pParm->QP_freq;
	ThreadStatusMonitor* pThrdMon = pParm->pThrdMon;

	T_Entry<int, Event> entry_event;
	Event event;
	int event_no = 0;//이벤트 번호
	int event_priority = 0;//이벤트 우선순위
	int event_gen_count = 0;
	int event_handler_addr;//핸들러주소
	LARGE_INTEGER t_gen;//시간측정을 위함
	
	for (int round = 0; round < maxRound; round++)
	{
		if (event_gen_count >= targetEventGen)//생성된 수 가 생성할 수 보다 많은경우
		{
			if (*pThrdMon->pFlagThreadTerminate == TERMINATE)//flag가 TERMINATE일시 종료
				break;
			else//아닐 경우
			{
				Sleep(500);
				//sleep_for(std::chrono::milliseconds(500));//대기 후 
				continue;//다시 반복문으로 돌아감
			}
		}
		event_no = event_gen_count + NUM_EVENTS_PER_GEN * myAddr;//이벤트 번호
		event_priority = targetEventGen - event_gen_count - 1;//우선순위 설정
		event.setEventNo(event_no);//이벤트 번호생성
		event.setEventPri(event_priority);//우선순위 설정
		event.setEventGenAddr(myAddr);//생성자 주소 설정
		event.setEventHandlerAddr(-1);//처리자는 아직 실행안됐으므로 -1
		QueryPerformanceCounter(&t_gen);//주파수측정
		event.setEventGenTime(t_gen);//시간 설정
		event.setEventStatus(GENERATED);//이벤트 상태
		entry_event.setKey(event.gentEventPri());//Key값 우선순위
		entry_event.setValue(event);//Value값 event
		
		while (pPriQ_Event->insert(entry_event) == NULL)//삽입 가득찰 경우 NULL반환하기 때문에 가득찰경우
		{
			pParm->pCS_main->lock();//메인 임계구역설정
			cout << "PriQ_Event is Full, waiting ..." << endl;
			pParm->pCS_main->unlock();//메인 임계구역해제
			Sleep(100);
			//sleep_for(std::chrono::milliseconds(100));
		}
		pParm->pCS_main->lock();//메인 임계구역설정
		cout << "Successfully inserted into PriQ_Event" << endl;
		pParm->pCS_main->unlock();//메인 임계구역해제

		pParm->pCS_thrd_mon->lock();//모니터링 임계구역
		pThrdMon->eventGenerated[pThrdMon->totalEventGenerated] = event;//배열에 이벤트 저장
		pThrdMon->numEventGenerated++;//생성된 이벤트 증가
		pThrdMon->totalEventGenerated++;//총이벤트 증가
		pParm->pCS_thrd_mon->unlock();//모니터링 임계해제
		event_gen_count++;

		Sleep(10);
		//sleep_for(std::chrono::milliseconds(10));
	}
	
}