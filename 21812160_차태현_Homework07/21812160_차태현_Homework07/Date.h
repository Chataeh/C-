#ifndef D_H
#define D_H

#include<iostream>
using namespace std;

#define WEEKDAY_AD01Jan01 MON
#define DAYS_PER_WEEK 7

class Date
{
	friend ostream& operator<<(ostream&, const Date&);
public:
	Date();//default 생성자
	Date(int y, int m, int d);//생성자
	~Date();//소멸자
	int getWeekDay();//요일계산
	int getElapsedDaysFromAD010101()const;//010101부터 날짜계산
	int getElapsedDaysFromAD010101(Date) const;//010101부터 Date까지 날짜계산
	bool operator<(const Date&)const;//날짜 대소비교
	bool operator<=(const Date&)const;//날짜 대소비교
	bool operator>(const Date&)const;//날짜 대소비교
	bool operator>=(const Date&)const;//날짜 대소비교
	bool operator==(const Date&)const;//같은 날 인지 판별

private:
	bool isValidDate(int y, int m, int d);//날짜가 정상범위인지
	int year;//년
	int month;//월
	int day;//일
};
bool isLeapYear(int y);//윤년 판단
int getYearDay(int year, int month, int day);//올해의 현재까지의 날짜계산


#endif