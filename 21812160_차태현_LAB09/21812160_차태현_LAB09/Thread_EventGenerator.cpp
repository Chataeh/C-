#include<Windows.h>
#include"Multi_thread.h"
#include"HeapPrioQueue.h"
#include"Event.h"
#include"SimParams.h"

using std::this_thread::sleep_for;

void EventGen(ThreadParam_Event* pParm)
{
	HeapPrioQueue<int, Event>* pPriQ_Event = pParm->pPriQ_Event;//�켱���� ť ������ �Ķ��Ÿ�κ��� �޾ƿ�
	//pParm���� ���� ���޾ƿ� �ʱ�ȭ����
	int myRole = pParm->role;
	int myAddr = pParm->myAddr;
	int maxRound = pParm->maxRound;
	int targetEventGen = pParm->targeEventGen;
	LARGE_INTEGER QP_freq = pParm->QP_freq;
	ThreadStatusMonitor* pThrdMon = pParm->pThrdMon;

	T_Entry<int, Event> entry_event;
	Event event;
	int event_no = 0;//�̺�Ʈ ��ȣ
	int event_priority = 0;//�̺�Ʈ �켱����
	int event_gen_count = 0;
	int event_handler_addr;//�ڵ鷯�ּ�
	LARGE_INTEGER t_gen;//�ð������� ����
	
	for (int round = 0; round < maxRound; round++)
	{
		if (event_gen_count >= targetEventGen)//������ �� �� ������ �� ���� �������
		{
			if (*pThrdMon->pFlagThreadTerminate == TERMINATE)//flag�� TERMINATE�Ͻ� ����
				break;
			else//�ƴ� ���
			{
				Sleep(500);
				//sleep_for(std::chrono::milliseconds(500));//��� �� 
				continue;//�ٽ� �ݺ������� ���ư�
			}
		}
		event_no = event_gen_count + NUM_EVENTS_PER_GEN * myAddr;//�̺�Ʈ ��ȣ
		event_priority = targetEventGen - event_gen_count - 1;//�켱���� ����
		event.setEventNo(event_no);//�̺�Ʈ ��ȣ����
		event.setEventPri(event_priority);//�켱���� ����
		event.setEventGenAddr(myAddr);//������ �ּ� ����
		event.setEventHandlerAddr(-1);//ó���ڴ� ���� ����ȵ����Ƿ� -1
		QueryPerformanceCounter(&t_gen);//���ļ�����
		event.setEventGenTime(t_gen);//�ð� ����
		event.setEventStatus(GENERATED);//�̺�Ʈ ����
		entry_event.setKey(event.gentEventPri());//Key�� �켱����
		entry_event.setValue(event);//Value�� event
		
		while (pPriQ_Event->insert(entry_event) == NULL)//���� ������ ��� NULL��ȯ�ϱ� ������ ���������
		{
			pParm->pCS_main->lock();//���� �Ӱ豸������
			cout << "PriQ_Event is Full, waiting ..." << endl;
			pParm->pCS_main->unlock();//���� �Ӱ豸������
			Sleep(100);
			//sleep_for(std::chrono::milliseconds(100));
		}
		pParm->pCS_main->lock();//���� �Ӱ豸������
		cout << "Successfully inserted into PriQ_Event" << endl;
		pParm->pCS_main->unlock();//���� �Ӱ豸������

		pParm->pCS_thrd_mon->lock();//����͸� �Ӱ豸��
		pThrdMon->eventGenerated[pThrdMon->totalEventGenerated] = event;//�迭�� �̺�Ʈ ����
		pThrdMon->numEventGenerated++;//������ �̺�Ʈ ����
		pThrdMon->totalEventGenerated++;//���̺�Ʈ ����
		pParm->pCS_thrd_mon->unlock();//����͸� �Ӱ�����
		event_gen_count++;

		Sleep(10);
		//sleep_for(std::chrono::milliseconds(10));
	}
	
}