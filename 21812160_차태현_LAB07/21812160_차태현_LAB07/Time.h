#ifndef T_H
#define T_H

#include<iostream>

using namespace std;

class Time
{
	friend ostream& operator<<(ostream&, const Time&);
public:
	Time() { hour = 0; min = 0; sec = 0; }//default ������
	Time(int h, int m, int s);//������
	int elasedSec() const;
	Time getTime() const { return Time(hour, min, sec); }//�ð� ��ȯ
	bool operator<(const Time&)const;//�ð� ��Һ�
	bool operator<=(const Time&)const;//�ð� ��Һ�
	bool operator>(const Time&)const;//�ð� ��Һ�
	bool operator>=(const Time&)const;//�ð� ��Һ�
	bool operator==(const Time&)const;//�ð��� ������ �Ǻ�
	

private:
	bool isValidTime(int, int, int);//�������νð� �������� �Ǻ�
	int hour;//�ð�
	int min;//��
	int sec;//��
};



#endif