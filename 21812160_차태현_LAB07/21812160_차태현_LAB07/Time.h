#ifndef T_H
#define T_H

#include<iostream>

using namespace std;

class Time
{
	friend ostream& operator<<(ostream&, const Time&);
public:
	Time() { hour = 0; min = 0; sec = 0; }//default 생성자
	Time(int h, int m, int s);//생성자
	int elasedSec() const;
	Time getTime() const { return Time(hour, min, sec); }//시간 반환
	bool operator<(const Time&)const;//시간 대소비교
	bool operator<=(const Time&)const;//시간 대소비교
	bool operator>(const Time&)const;//시간 대소비교
	bool operator>=(const Time&)const;//시간 대소비교
	bool operator==(const Time&)const;//시간이 같은지 판별
	

private:
	bool isValidTime(int, int, int);//정상적인시간 범위인지 판별
	int hour;//시간
	int min;//분
	int sec;//초
};



#endif