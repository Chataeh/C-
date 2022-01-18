#ifndef E_H
#define E_H

#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<thread>
#include<process.h>
#include<iomanip>

using namespace std;

enum EventStatus {GENERATED,ENQUEUED,PROCESSED,UNDEFINED};
#define MAX_EVENT_PRIORITY 100
#define NUM_EVENT_GENERATOR 10

class Event
{
	friend ostream& operator<<(ostream& cout, const Event& e);//<<연산자 출력기능
public:
	Event();//default 생성자
	Event(int event_id, int event_pri, int srcAddr);//생성자
	void printEvent_proc();//이벤트 출력
	void setEventHandlerAddr(int evtHndlerAddr) { event_handler_addr = evtHndlerAddr; }//이벤트 핸들러 주소 설정
	void setEventGenAddr(int genAddr) { event_gen_addr = genAddr; }//이벤트 생성자 주소 설정
	void setEventNo(int evtNo) { event_no = evtNo; }//이벤트 번호설정
	void setEventPri(int pri) { event_pri = pri; }//우선순위 설정
	void setEventStatus(EventStatus evtStatus) {eventStatus = evtStatus; }//이벤트 상태설정
	void setEventGenTime(LARGE_INTEGER t_gen) { t_event_gen = t_gen; }//생성시간 설정
	void setEventProcTime(LARGE_INTEGER t_proc) { t_event_proc = t_proc; }//처리시간 설정
	LARGE_INTEGER getEventGenTime() { return t_event_gen; }//생성시간 반환
	LARGE_INTEGER getEventProcTime() { return t_event_proc; }//처리시간 반환
	void setEventElaspsedTime(double t_elapsed_ms) { t_elapsed_time_ms = t_elapsed_ms; }//걸린시간 설정 시간차
	double getEventElapsedTime() { return t_elapsed_time_ms; }//걸린시간 반환 시간차
	int gentEventPri() { return event_pri; }//우선순위 반환
	int gentEventNo() { return event_no; }//이벤트 번호 반환
	bool operator>(Event& e) { return (event_pri > e.event_pri); }//우선순위 대소비교
	bool operator<(Event& e) { return (event_pri < e.event_pri); }//우선순위 대소비교
private:
	int event_no;//이벤트 번호
	int event_gen_addr;//생성자 주소
	int event_handler_addr;//핸들러 주소
	int event_pri;//우선순위
	LARGE_INTEGER t_event_gen;//생성시간
	LARGE_INTEGER t_event_proc;//처리시간
	double t_elapsed_time_ms;//시간 차
	EventStatus eventStatus;//이벤트 상태
};

Event* genRandEvent(int evt_no);//랜덤 이벤트 생성
#endif