#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>


using namespace std;

#define WEEKDAY_AD01Jan01 MON
#define DAYS_PER_WEEK 7
#define Secs_in_Minute 60
#define Secs_in_Hour (Secs_in_Minute*60)
#define Secs_in_DAY (Secs_in_Hour*24)
#define LOCAL_GMT_OFFSET_HOUR 9

class Date {
public:
	Date();//기본 생성자
	Date(int y, int m, int d);//생성자
	~Date();//소멸자
	void inputDate();
	void fprintDate(ostream& fout);
	void setDate(int y, int m, int d);//날짜 정의
	void setRandDateAttributes();//랜덤 날짜 설정
	void setMonth(int m);//달 설정
	void setYear(int y);//년도 설정
	int getYear() {return year;}
	int getMonth() { return month;}
	int getDay() { return day; }
	int getYearDay();
	int getYearDay(int m, int d);
	int getWeekDay();
	int getElapsedDaysFromAD010101();//1년1월1일부터의 날짜
	
private:
	bool isLeapYear();//윤년판단
	bool isLeapYear(int y);
	bool isValidDate(int y, int m, int d);//정상적인 값인지 판단
	int year;
	int month;
	int day;
};

#endif