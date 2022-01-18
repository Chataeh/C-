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
	//cout << "Date object instance is destructed" << endl; // ���� �Ҹ��ڰ� ����Ǵ��� Ȯ���� �� �ִ�
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
		fout << setw(10) << string(monthName[month]);//�� ���
	}
	fout << "" << setw(2) << day << "," << setw(4) << year;

	yearDay = getYearDay();
	weekday = getWeekDay();

	fout << "(" << setw(10) << string(weekDayName[weekday]) << ")";//�������


}

void Date::setDate(int y, int m, int d) //����� ����
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

void Date::setRandDateAttributes()//�������� ����� ����
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	year = rand() % 2000 + 1000;//1000~2999��
	month = rand() % 12 + 1;//1~12��
	if (isLeapYear(year) && month == 2)
		month_days[2] = 29;
	day = rand() % month_days[month] + 1;
}

void Date::setMonth(int m)//�� ���� ����1�ΰ���
{
	if ((m >= 1) && (m <= 12))
		month = m;
	else
		exit(1);
	day = 1;
}

void Date::setYear(int y)//�⵵����
{
	year = y;
}

bool Date::isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//�������� �Ǵ�
		return true;
	else
		return false;
}

bool Date::isLeapYear()
{
	return isLeapYear(year);
}

bool Date::isValidDate(int y, int m, int d)//�Էµ� ���� �������� ���� ���� �������� �Ǵ�
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(y))
		month_days[2] = 29;//�����ϰ��
	if ((m >= 1) && (m <= 12) && (d >= 1) && (d <= month_days[m]))//���� 1~12���ޱ����ְ� ���� �޿� �´��� �Ͻ�
		return true;
	else
	{
		cout << "Illegal date! (" << m << ", " << d << ") ==> Program aborted.\n";
		return false;
	}
}

int Date::getYearDay()//������ �ϼ����
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;

	if (isLeapYear())
		month_days[2] = 29;
	for (int i = 1; i < month; i++)
	{
		days += month_days[i];//�־��� ���ޱ����� �ϼ� ��
	}
	days = days + day;//�ϼ� ��

	return days;
}
int Date::getYearDay(int m, int d)//������ �־��� �������� �ϼ����
{
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	if (isLeapYear())//�����Ǵ�
		month_days[2] = 29;
	for (int i = 1; i < m; i++)
	{
		days += month_days[i];
	}
	days = days + d;

	return days;
}
int Date::getWeekDay()//���ϱ��ϱ�
{
	int weekDay_AD010101 = MON;//1��1��1���� ������
	int elapsedays = 0;
	int weekday;
	elapsedays = getElapsedDaysFromAD010101();//1��1��1�Ϸκ����� ��¥ ���
	weekday = elapsedays % 7;//�����Ǵ� ��ȭ���������

	return weekday;
}

int Date::getElapsedDaysFromAD010101()
{
	int days;
	int elpsday = 0;
	for (int i = 1; i < year; i++)
	{
		if (isLeapYear(i))
			elpsday += 366;//�����Ͻ� ���ش�366��
		else
			elpsday += 365;
	}
	days = getYearDay(month, day);//������ �ϼ�
	elpsday += days;

	return elpsday;
}