#ifndef D_H
#define D_H
#include<iostream>

using namespace std;


class Date {
	friend istream& operator >>(istream&, Date&);//>>연산자
	friend ostream& operator << (ostream&, const Date&);//<<연산자

public:
	Date();//생성자
	Date(int y, int m, int d);//생성자
	void setDate(int newYear, int newMonth, int newDay);//년월일 설정
	int getYear() { return year; }//년도값 반환
	int getYearDay();//그 년도의 지금까지의 일수 계산
	int getWeekDay();//요일 계산
	int getElapsedDays();//010101부터의 현재까지의 날짜 계산
	const Date operator =(const Date rightSide);//대입연산자
	bool operator>(Date rightSide);//비교연산자
	bool operator<(Date rightSide);//비교연산자
	bool operator==(Date rightSide);//일치하는지 비교연산자
	bool operator!=(Date rightSide);//일치하지 않는지 비교연산자
	bool isLeapYear(int y);//윤년판단
private:
	bool isLeapYear();//윤년판단
	bool isValidDate(int y, int m, int d );//년월일의 값이 지정된 범위안에있는가 판별
	int year;
	int month;
	int day;
};

bool isLeapYear(int y);//윤년판단
Date genRandDate();//생일 랜덤출력

#endif