#include"Date.h"
#include<iomanip>
ostream& operator<<(ostream& cout, const Date& d)
{
	cout << "(" << setw(2) << d.year << ":" << setw(2) << d.month << ":" << setw(2) << d.day << ")";

	return cout;
}

Date::Date()//default 생성자
	:year(1), month(1), day(1)
{

}

Date::Date(int y, int m, int d)//생성자
	: year(y), month(m), day(d)
{

}

Date::~Date()//소멸자
{

}

int Date::getWeekDay()
{
	int weekday;
	int result;

	result = getElapsedDaysFromAD010101();//전체 날짜 받아오기
	weekday = result % 7;//요일 수 수로판단

	return weekday;

}

int Date::getElapsedDaysFromAD010101() const
{
	int result = 0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < year; i++)
	{
		if (isLeapYear(i))//윤년판단
			result += 366;// 윤년일경우 366일 더해줌
		else
			result += 365;// 평년일 경우 365일 더해줌
	}
	result += getYearDay(year, month, day);//그 해의 지금까지의 일 더해줌


	return result;
}

int Date::getElapsedDaysFromAD010101(Date d) const
{
	int result = 0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < d.year; i++)
	{
		if (isLeapYear(i))//윤년판단
			result += 366;// 윤년일경우 366일 더해줌
		else
			result += 365;// 평년일 경우 365일 더해줌
	}
	result += getYearDay(d.year, d.month, d.day);//그 해의 지금까지의 일 더해줌


	return result;
}

bool Date::operator<(const Date& d)const//대소비교
{
	if (getElapsedDaysFromAD010101() < d.getElapsedDaysFromAD010101())//010101로 부터의 날짜로 비교
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d)const
{
	if (getElapsedDaysFromAD010101() <= d.getElapsedDaysFromAD010101())//010101로 부터의 날짜로 비교
		return true;
	else
		return false;
}

bool Date::operator>(const Date& d)const
{
	if (getElapsedDaysFromAD010101() > d.getElapsedDaysFromAD010101())//010101로 부터의 날짜로 비교
		return true;
	else
		return false;
}

bool Date::operator>=(const Date& d)const
{
	if (getElapsedDaysFromAD010101() >= d.getElapsedDaysFromAD010101())//010101로 부터의 날짜로 비교
		return true;
	else
		return false;
}

bool Date::operator==(const Date& d)const//같은 날인지 비교
{
	if (getElapsedDaysFromAD010101() == d.getElapsedDaysFromAD010101())//010101로 부터의 날짜로 비교
		return true;
	else
		return false;
}

bool Date::isValidDate(int y, int m, int d)
{
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (isLeapYear(y))//윤년판단
		months[2] = 29;
	if ((m >= 1) || (m <= 12) || (d >= 1) || (d <= months[d]))//달은 1~12  일은 배열에 맞게
		return true;

	else
		cout << "leagl date!";
	return false;
}

void Date::setDate(int newYear, int newMonth, int newDay)
{

	if (isValidDate(newYear, newMonth, newDay))//년 월 일 이 적정값에 포함될경우
	{
		year = newYear;
		month = newMonth;
		day = newDay;
	}
}


bool isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//윤년 판단
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
		result += months[i];//현재 달 전까지의 값더하기
	}
	result += day;//일 더하기

	return result;
}