#ifndef E_H
#define E_H

#include<iostream>
using namespace std;

enum EventStatus{GENERATED, ENQUEUED, PROCESSED,UNDEFINED};

class Event
{
	friend ostream& operator<<(ostream& fout, const Event& e);//<<연산자 출력기능
public:
	Event();//default 생성자
	Event(int event_id, int event_pri, string title, int gen_addr);//생성자
	void printEvent(ostream& fout);//이벤트 출력
	void setEventHandlerAddr(int evtHndlerAddr) { event_handler_addr = evtHndlerAddr; }//이벤트 핸들러 주소 설정
	void setEventGenAddr(int genAddr) { event_gen_addr = genAddr; }//이벤트 생성자 주소 설정
	void setEventNo(int evtNo) { event_no = evtNo; }//이벤트 번호설정
	void setEventPri(int pri) { event_pri = pri; }//우선순위 설정
	void setEventStatus(EventStatus evtStatus) { eventStatus = evtStatus; }//이벤트 상태설정
	int gentEventPri() { return event_pri; }//우선순위 반환
	int gentEventNo() { return event_no; }//이벤트 번호 반환
	bool operator>(Event& e) { return (event_pri > e.event_pri); }//우선순위 대소비교
	bool operator<(Event& e) { return (event_pri < e.event_pri); }//우선순위 대소비교
private:
	int event_no;//이벤트 번호
	string event_title;//이벤트 이름
	int event_gen_addr;//생성자 주소
	int event_handler_addr;//핸들러 주소
	int event_pri;//우선순위
	EventStatus eventStatus;//이벤트 상태
};
#endif E_H