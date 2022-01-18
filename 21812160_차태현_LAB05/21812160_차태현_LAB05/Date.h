#ifndef D_H
#define D_H
#include<iostream>

using namespace std;


class Date {
	friend istream& operator >>(istream&, Date&);//>>������
	friend ostream& operator << (ostream&, const Date&);//<<������

public:
	Date();//������
	Date(int y, int m, int d);//������
	void setDate(int newYear, int newMonth, int newDay);//����� ����
	int getYear() { return year; }//�⵵�� ��ȯ
	int getYearDay();//�� �⵵�� ���ݱ����� �ϼ� ���
	int getWeekDay();//���� ���
	int getElapsedDays();//010101������ ��������� ��¥ ���
	const Date operator =(const Date rightSide);//���Կ�����
	bool operator>(Date rightSide);//�񱳿�����
	bool operator<(Date rightSide);//�񱳿�����
	bool operator==(Date rightSide);//��ġ�ϴ��� �񱳿�����
	bool operator!=(Date rightSide);//��ġ���� �ʴ��� �񱳿�����
	bool isLeapYear(int y);//�����Ǵ�
private:
	bool isLeapYear();//�����Ǵ�
	bool isValidDate(int y, int m, int d );//������� ���� ������ �����ȿ��ִ°� �Ǻ�
	int year;
	int month;
	int day;
};

bool isLeapYear(int y);//�����Ǵ�
Date genRandDate();//���� �������

#endif