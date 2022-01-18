#ifndef E_H
#define E_H

#include<iostream>
using namespace std;

enum EventStatus{GENERATED, ENQUEUED, PROCESSED,UNDEFINED};

class Event
{
	friend ostream& operator<<(ostream& fout, const Event& e);//<<������ ��±��
public:
	Event();//default ������
	Event(int event_id, int event_pri, string title, int gen_addr);//������
	void printEvent(ostream& fout);//�̺�Ʈ ���
	void setEventHandlerAddr(int evtHndlerAddr) { event_handler_addr = evtHndlerAddr; }//�̺�Ʈ �ڵ鷯 �ּ� ����
	void setEventGenAddr(int genAddr) { event_gen_addr = genAddr; }//�̺�Ʈ ������ �ּ� ����
	void setEventNo(int evtNo) { event_no = evtNo; }//�̺�Ʈ ��ȣ����
	void setEventPri(int pri) { event_pri = pri; }//�켱���� ����
	void setEventStatus(EventStatus evtStatus) { eventStatus = evtStatus; }//�̺�Ʈ ���¼���
	int gentEventPri() { return event_pri; }//�켱���� ��ȯ
	int gentEventNo() { return event_no; }//�̺�Ʈ ��ȣ ��ȯ
	bool operator>(Event& e) { return (event_pri > e.event_pri); }//�켱���� ��Һ�
	bool operator<(Event& e) { return (event_pri < e.event_pri); }//�켱���� ��Һ�
private:
	int event_no;//�̺�Ʈ ��ȣ
	string event_title;//�̺�Ʈ �̸�
	int event_gen_addr;//������ �ּ�
	int event_handler_addr;//�ڵ鷯 �ּ�
	int event_pri;//�켱����
	EventStatus eventStatus;//�̺�Ʈ ����
};
#endif E_H