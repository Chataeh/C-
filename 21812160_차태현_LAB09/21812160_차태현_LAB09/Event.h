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
	friend ostream& operator<<(ostream& cout, const Event& e);//<<������ ��±��
public:
	Event();//default ������
	Event(int event_id, int event_pri, int srcAddr);//������
	void printEvent_proc();//�̺�Ʈ ���
	void setEventHandlerAddr(int evtHndlerAddr) { event_handler_addr = evtHndlerAddr; }//�̺�Ʈ �ڵ鷯 �ּ� ����
	void setEventGenAddr(int genAddr) { event_gen_addr = genAddr; }//�̺�Ʈ ������ �ּ� ����
	void setEventNo(int evtNo) { event_no = evtNo; }//�̺�Ʈ ��ȣ����
	void setEventPri(int pri) { event_pri = pri; }//�켱���� ����
	void setEventStatus(EventStatus evtStatus) {eventStatus = evtStatus; }//�̺�Ʈ ���¼���
	void setEventGenTime(LARGE_INTEGER t_gen) { t_event_gen = t_gen; }//�����ð� ����
	void setEventProcTime(LARGE_INTEGER t_proc) { t_event_proc = t_proc; }//ó���ð� ����
	LARGE_INTEGER getEventGenTime() { return t_event_gen; }//�����ð� ��ȯ
	LARGE_INTEGER getEventProcTime() { return t_event_proc; }//ó���ð� ��ȯ
	void setEventElaspsedTime(double t_elapsed_ms) { t_elapsed_time_ms = t_elapsed_ms; }//�ɸ��ð� ���� �ð���
	double getEventElapsedTime() { return t_elapsed_time_ms; }//�ɸ��ð� ��ȯ �ð���
	int gentEventPri() { return event_pri; }//�켱���� ��ȯ
	int gentEventNo() { return event_no; }//�̺�Ʈ ��ȣ ��ȯ
	bool operator>(Event& e) { return (event_pri > e.event_pri); }//�켱���� ��Һ�
	bool operator<(Event& e) { return (event_pri < e.event_pri); }//�켱���� ��Һ�
private:
	int event_no;//�̺�Ʈ ��ȣ
	int event_gen_addr;//������ �ּ�
	int event_handler_addr;//�ڵ鷯 �ּ�
	int event_pri;//�켱����
	LARGE_INTEGER t_event_gen;//�����ð�
	LARGE_INTEGER t_event_proc;//ó���ð�
	double t_elapsed_time_ms;//�ð� ��
	EventStatus eventStatus;//�̺�Ʈ ����
};

Event* genRandEvent(int evt_no);//���� �̺�Ʈ ����
#endif