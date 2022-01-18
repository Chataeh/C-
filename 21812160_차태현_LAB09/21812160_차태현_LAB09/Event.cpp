#include"Event.h"


ostream& operator<<(ostream& cout, const Event& e)//<<연산자 
{
	cout << "Event(no:" << setw(3) << e.event_no << ", pri:" << setw(3) << e.event_pri
		<< " )";

	return cout;//fout반환
}

Event::Event()//default 생성자
	
{
	event_no = 0;//
	event_gen_addr = 0;
	event_handler_addr = -1;
	event_pri = 0;
	eventStatus = GENERATED;
}

Event::Event(int event_id, int event_pri, int srcAddr)//생성자

{
	event_no = event_id;//
	event_gen_addr = srcAddr;
	event_handler_addr = -1;
	this->event_pri = event_pri;
	eventStatus = GENERATED;
	
}

void Event::printEvent_proc()//이벤트 출력
{
	cout.precision(2);//소수점 두째자리
	cout.setf(ios::fixed);
	cout << "Event(no:" << setw(2) << event_no << ", pri:" << setw(2) << event_pri
		<< ", t_elapsed:" << setw(8) <<t_elapsed_time_ms << " )";
}

Event* genRandEvent(int evt_no)
{
	Event* pEv;
	int evt_prio;
	int evt_generator_id;

	evt_prio = rand() % MAX_EVENT_PRIORITY;//우선순위 랜덤생성
	evt_generator_id = rand() % NUM_EVENT_GENERATOR;//생성자 랜덤생성

	pEv = (Event*)new Event(evt_no, evt_prio, evt_generator_id);//생성자 동적 할당 

	return pEv;
}