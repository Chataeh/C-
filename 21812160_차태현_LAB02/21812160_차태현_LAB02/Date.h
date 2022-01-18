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
	Date();//�⺻ ������
	Date(int y, int m, int d);//������
	~Date();//�Ҹ���
	void inputDate();
	void fprintDate(ostream& fout);
	void setDate(int y, int m, int d);//��¥ ����
	void setRandDateAttributes();//���� ��¥ ����
	void setMonth(int m);//�� ����
	void setYear(int y);//�⵵ ����
	int getYear() {return year;}
	int getMonth() { return month;}
	int getDay() { return day; }
	int getYearDay();
	int getYearDay(int m, int d);
	int getWeekDay();
	int getElapsedDaysFromAD010101();//1��1��1�Ϻ����� ��¥
	
private:
	bool isLeapYear();//�����Ǵ�
	bool isLeapYear(int y);
	bool isValidDate(int y, int m, int d);//�������� ������ �Ǵ�
	int year;
	int month;
	int day;
};

#endif