#include"Event.h"
#include<iomanip>

ostream& operator<<(ostream& fout, const Event& e)//<<연산자 
{
	fout << "Event(no:" << setw(3) << e.event_no << ", pri:" << setw(3) << e.event_pri
		<< ", gen:" << setw(3) << e.event_gen_addr << ", title:" << setw(6) << e.event_title << " )";

	return fout;//fout반환
}

Event::Event()//default 생성자
	:event_no(0),event_title("no name"),event_gen_addr(-1),event_handler_addr(-1),event_pri(0),eventStatus(GENERATED)
{
	
}

Event::Event(int event_id, int event_pri, string title, int gen_addr)//생성자
		
{
	event_no = event_id;//
	event_gen_addr = gen_addr;
	event_handler_addr = -1;
	this->event_pri = event_pri;
	event_title = title;
	eventStatus = GENERATED;
}

void Event::printEvent(ostream& fout)//이벤트 출력
{
	fout << "Event(no:" << setw(3) << event_no << ", pri:" << setw(3) << event_pri
		<< ", gen:" << setw(3) << event_gen_addr << ", title:" << setw(3) << event_title << " )";
}