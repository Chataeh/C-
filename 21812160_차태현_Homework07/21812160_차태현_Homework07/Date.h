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
	Date();//default ������
	Date(int y, int m, int d);//������
	~Date();//�Ҹ���
	int getWeekDay();//���ϰ��
	int getElapsedDaysFromAD010101()const;//010101���� ��¥���
	int getElapsedDaysFromAD010101(Date) const;//010101���� Date���� ��¥���
	bool operator<(const Date&)const;//��¥ ��Һ�
	bool operator<=(const Date&)const;//��¥ ��Һ�
	bool operator>(const Date&)const;//��¥ ��Һ�
	bool operator>=(const Date&)const;//��¥ ��Һ�
	bool operator==(const Date&)const;//���� �� ���� �Ǻ�

private:
	bool isValidDate(int y, int m, int d);//��¥�� �����������
	int year;//��
	int month;//��
	int day;//��
};
bool isLeapYear(int y);//���� �Ǵ�
int getYearDay(int year, int month, int day);//������ ��������� ��¥���


#endif