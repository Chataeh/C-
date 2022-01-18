#include"Date.h"
#include<iomanip>
ostream& operator<<(ostream& cout, const Date& d)
{
	cout << "(" << setw(2) << d.year << ":" << setw(2) << d.month << ":" << setw(2) << d.day << ")";

	return cout;
}

Date::Date()//default ������
	:year(1), month(1), day(1)
{

}

Date::Date(int y, int m, int d)//������
	: year(y), month(m), day(d)
{

}

Date::~Date()//�Ҹ���
{

}

int Date::getWeekDay()
{
	int weekday;
	int result;

	result = getElapsedDaysFromAD010101();//��ü ��¥ �޾ƿ���
	weekday = result % 7;//���� �� �����Ǵ�

	return weekday;

}

int Date::getElapsedDaysFromAD010101() const
{
	int result = 0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < year; i++)
	{
		if (isLeapYear(i))//�����Ǵ�
			result += 366;// �����ϰ�� 366�� ������
		else
			result += 365;// ����� ��� 365�� ������
	}
	result += getYearDay(year, month, day);//�� ���� ���ݱ����� �� ������


	return result;
}

int Date::getElapsedDaysFromAD010101(Date d) const
{
	int result = 0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < d.year; i++)
	{
		if (isLeapYear(i))//�����Ǵ�
			result += 366;// �����ϰ�� 366�� ������
		else
			result += 365;// ����� ��� 365�� ������
	}
	result += getYearDay(d.year, d.month, d.day);//�� ���� ���ݱ����� �� ������


	return result;
}

bool Date::operator<(const Date& d)const//��Һ�
{
	if (getElapsedDaysFromAD010101() < d.getElapsedDaysFromAD010101())//010101�� ������ ��¥�� ��
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d)const
{
	if (getElapsedDaysFromAD010101() <= d.getElapsedDaysFromAD010101())//010101�� ������ ��¥�� ��
		return true;
	else
		return false;
}

bool Date::operator>(const Date& d)const
{
	if (getElapsedDaysFromAD010101() > d.getElapsedDaysFromAD010101())//010101�� ������ ��¥�� ��
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& d)const
{
	if (getElapsedDaysFromAD010101() >= d.getElapsedDaysFromAD010101())//010101�� ������ ��¥�� ��
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d)const//���� ������ ��
{
	if (getElapsedDaysFromAD010101() == d.getElapsedDaysFromAD010101())//010101�� ������ ��¥�� ��
		return true;
	else
		return false;
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

void Date::setDate(int newYear, int newMonth, int newDay)
{

	if (isValidDate(newYear, newMonth, newDay))//�� �� �� �� �������� ���Եɰ��
	{
		year = newYear;
		month = newMonth;
		day = newDay;
	}
}


bool isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//���� �Ǵ�
		return true;
	else
		return false;
}

int getYearDay(int year, int month, int day)
{
	int result = 0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(year))
		months[2] = 29;
	for (int i = 0; i < month; i++)
	{
		result += months[i];//���� �� �������� �����ϱ�
	}
	result += day;//�� ���ϱ�

	return result;
}