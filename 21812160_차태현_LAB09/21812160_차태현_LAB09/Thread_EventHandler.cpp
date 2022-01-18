#include<Windows.h>
#include"Multi_thread.h"
#include"HeapPrioQueue.h"
#include"Event.h"
#include"SimParams.h"

using std::this_thread::sleep_for;

void EventProc(ThreadParam_Event* pParm)
{
	HeapPrioQueue<int, Event>* pPriQ_Event=pParm->pPriQ_Event;//�켱���� ť ������ �Ķ��Ÿ�κ��� �޾ƿ�
	//pParm���� ���� ���޾ƿ� �ʱ�ȭ����
	int myRole =pParm->role;
	int myAddr=pParm->myAddr;
	int maxRound=pParm->maxRound;
	int targetEventGen = pParm->targeEventGen;
	LARGE_INTEGER QP_freq = pParm->QP_freq;
	ThreadStatusMonitor* pThrdMon=pParm->pThrdMon;

	T_Entry<int, Event>* pEntry;
	Event event, * pEvent, * pEventProc;
	int event_no = 0;//�̺�Ʈ ��ȣ
	int evnet_Priority = 0;//�̺�Ʈ �켱����
	int event_gen_count = 0;
	int num_pkt_proceesed = 0;
	
	//ó���ð��� ǥ���ϱ����� ����
	LARGE_INTEGER  t_gen, t_proc;
	LONGLONG t_diff;
	double elapsed_time;

	for (int round = 0; round < maxRound; round++)
	{
		if (*pThrdMon->pFlagThreadTerminate == TERMINATE)//TERMINATE�Ͻ� ����
			break;
		if (!pPriQ_Event->isEmpty())//���� �� ���� �������
		{
			pEntry = pPriQ_Event->removeHeapMin();//�̺�Ʈ ������ ���� ���޹���
			event = pEntry->getValue();//Value�� event ����
			pParm->pCS_thrd_mon->lock();//�Ӱ豸�� ����
			event.setEventHandlerAddr(myAddr);//ó���� �ּҼ���
			QueryPerformanceCounter(&t_proc);//�ð����
			event.setEventProcTime(t_proc);//�ð�����
			t_gen = event.getEventGenTime();//�����ð� �޾ƿ�
			t_diff = t_proc.QuadPart - t_gen.QuadPart;//�ð� �� 
			elapsed_time = ((double)t_diff / QP_freq.QuadPart);// �ð� ���
			event.setEventElaspsedTime(elapsed_time * 1000);//�и���
			pThrdMon->eventProcessed[pThrdMon->totalEventProcessed] = event;//ó���� �̺�Ʈ ����
			pThrdMon->numEventProcessed++;//ó���� �̺�Ʈ �� ����
			pThrdMon->totalEventProcessed++;//ó���� �� �̺�Ʈ �� ����
			pParm->pCS_thrd_mon->unlock();//�Ӱ豸�� ����
		}
		//sleep_for(std::chrono::milliseconds(100 + rand() % 100));
		Sleep(100 + rand() % 100);
	}
	
}