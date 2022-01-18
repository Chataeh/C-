#include"Date.h"
#include<iostream>
#include<fstream>
#include<iomanip>


istream& operator>>(istream& fin, Date& date)//>> ������ ����
{
	//���Ϸκ��� ��,��,�� �޾ƿ���
	fin >> date.year;
	fin >> date.month;
	fin >> date.day;

	return fin;//fin ��ȯ
}

ostream& operator<<(ostream& fout, const Date& date)//<<������
{
	fout << "(" << date.year << "-" << setw(2) << date.month << "-" << setw(2) << date.day << ")" ;//���� ���
	
	return fout;
}

Date::Date()//������
	:year(1),month(1),day(1)
{
	/*�ʱ�ȭ ����
	year = 1;
	month = 1;
	day = 1;*/
}

Date::Date(int y, int m, int d)
{
	setDate(y, m, d);//�� �� �� ����
}

void Date::setDate(int newYear, int newMonth, int newDay)
{

	if (isValidDate(newYear, newMonth, newDay))//�� �� �� �� �������� ���Եɰ��
	{
		year = newYear;
		month = newMonth;
		day = newDay;
	}
}
int Date::getYearDay()//����⵵�� �� �� ���ϱ�
{
	int result=0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if(isLeapYear(year))
		months[2] = 29;
	for (int i = 0; i < month; i++)
	{
		result += months[i];//���� �� �������� �����ϱ�
	}
	result += day;//�� ���ϱ�

	return result;
}

int Date::getWeekDay()
{
	int weekday;
	int result;

	result = getElapsedDays();//��ü ��¥ �޾ƿ���
	weekday = result % 7;//���� �� �����Ǵ�

	return weekday;
}

int Date::getElapsedDays()
{
	int result=0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < year; i++)
	{
		if (isLeapYear(i))//�����Ǵ�
			result += 366;// �����ϰ�� 366�� ������
		else
			result += 365;// ����� ��� 365�� ������
	}
	result += getYearDay();//�� ���� ���ݱ����� �� ������
	
	
	return result;
}

const Date Date::operator=(const Date rightSide)//���Կ�����
{
	if (isValidDate(rightSide.year, rightSide.month, rightSide.day))//������� �ȿ� �� ��
	{
		year = rightSide.year;
		month = rightSide.month;
		day = rightSide.day;

		return *this;
	}
	else
	{
		return Date(1, 1, 1);
	}
		

	
}

bool Date::operator>(Date rightSide)//�񱳿�����
{
	if (getElapsedDays() > rightSide.getElapsedDays())
		return true;
	else
		false;
}
bool Date::operator<(Date rightSide)//�񱳿�����
{
	if (getElapsedDays() < rightSide.getElapsedDays())
		return true;
	else
		false;
}
bool Date::operator==(Date rightSide)//��ġ�ϴ��� �񱳿�����
{
	if (getElapsedDays() == rightSide.getElapsedDays())
		return true;
	else
		false;
}
bool Date::operator!=(Date rightSide)//��ġ���� �ʴ��� �񱳿�����
{
	if (getElapsedDays() != rightSide.getElapsedDays())
		return true;
	else
		false;
}


bool Date::isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//���� �Ǵ�
		return true;
	else
		return false;
}


bool Date::isLeapYear()
{
	return isLeapYear(year);//���� �Ǵ�
}

bool Date::isValidDate(int y, int m, int d)
{
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(y))//�����Ǵ�
		months[2] = 29;
	if ((m >= 1) || (m <= 12) || (d >= 1) || (d <= months[d]))//���� 1~12  ���� �迭�� �°�
		return true;

	else
		cout << "leagl date!";
		return false;
	
	
}


bool isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//���� �Ǵ�
		return true;
	else
		return false;
}

Date genRandDate()
{
	Date date;
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	
	year = rand() % 1000 + 2000;//2000~2999��
	month = rand() % 12 + 1;//1~12��
	if (isLeapYear(year) && month == 2)
		month_days[2] = 29;
	day = rand() % month_days[month] + 1;//�޿� �´� ������ ����

	date.setDate(year, month, day);//date ����ü�� ������ ����

	return date;
}