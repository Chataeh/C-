#include"Date.h"
#include<iomanip>
#include<string>
enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
enum MONTH { JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NUM_MONTHS };
const char* weekDayName[DAYS_PER_WEEK] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };
const char* weekDayNameShort[DAYS_PER_WEEK] = { "SUN", "MON", "TUE", "WED", "THR", "FRI","SAT" };
const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December" };

Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(int y, int m, int d)
{
	setDate(y, m, d);
}

Date::~Date()
{
	//cout << "Date object instance is destructed" << endl; // 언제 소멸자가 실행되는지 확인할 수 있다
}

void Date::inputDate()
{
	int y, m, d;
	cin >> y >> m >> d;
	if (isValidDate(y, m, d))
	{
		year = y;
		month = m;
		day = d;
	}
	else
		exit(1);
}

void Date::fprintDate(ostream& fout)
{
	const char* weekDayName[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday" };
	const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November", "December" };
	int yearDay = 0;
	int weekday;

	if (month >= 1 && month <= 12)
	{
		fout << setw(10) << string(monthName[month]);//달 출력
	}
	fout << "" << setw(2) << day << "," << setw(4) << year;

	yearDay = getYearDay();
	weekday = getWeekDay();

	fout << "(" << setw(10) << string(weekDayName[weekday]) << ")";//요일출력


}

void Date::setDate(int y, int m, int d) //년월일 설정
{
	if (isValidDate(y, m, d))
	{
		year = y;
		month = m;
		day = d;
	}
	else
		exit(1);
}

void Date::setRandDateAttributes()//랜덤으로 년원일 설정
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	year = rand() % 2000 + 1000;//1000~2999년
	month = rand() % 12 + 1;//1~12월
	if (isLeapYear(year) && month == 2)
		month_days[2] = 29;
	day = rand() % month_days[month] + 1;
}

void Date::setMonth(int m)//달 설정 일은1로고정
{
	if ((m >= 1) && (m <= 12))
		month = m;
	else
		exit(1);
	day = 1;
}

void Date::setYear(int y)//년도설정
{
	year = y;
}

bool Date::isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//윤년인지 판단
		return true;
	else
		return false;
}

bool Date::isLeapYear()
{
	return isLeapYear(year);
}

bool Date::isValidDate(int y, int m, int d)//입력된 값이 정상적인 월과 일의 범위인지 판단
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(y))
		month_days[2] = 29;//윤년일경우
	if ((m >= 1) && (m <= 12) && (d >= 1) && (d <= month_days[m]))//달이 1~12월달까지있고 일이 달에 맞는일 일시
		return true;
	else
	{
		cout << "Illegal date! (" << m << ", " << d << ") ==> Program aborted.\n";
		return false;
	}
}

int Date::getYearDay()//그해의 일수계산
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;

	if (isLeapYear())
		month_days[2] = 29;
	for (int i = 1; i < month; i++)
	{
		days += month_days[i];//주어진 전달까지의 일수 합
	}
	days = days + day;//일수 합

	return days;
}
int Date::getYearDay(int m, int d)//그해의 주어진 날까지의 일수계산
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	if (isLeapYear())//윤년판단
		month_days[2] = 29;
	for (int i = 1; i < m; i++)
	{
		days += month_days[i];
	}
	days = days + d;

	return days;
}
int Date::getWeekDay()//요일구하기
{
	int weekDay_AD010101 = MON;//1년1월1일이 월요일
	int elapsedays = 0;
	int weekday;
	elapsedays = getElapsedDaysFromAD010101();//1년1월1일로부터의 날짜 계산
	weekday = elapsedays % 7;//요일판단 월화수목금토일

	return weekday;
}

int Date::getElapsedDaysFromAD010101()
{
	int days;
	int elpsday = 0;
	for (int i = 1; i < year; i++)
	{
		if (isLeapYear(i))
			elpsday += 366;//윤년일시 한해는366일
		else
			elpsday += 365;
	}
	days = getYearDay(month, day);//그해의 일수
	elpsday += days;

	return elpsday;
}