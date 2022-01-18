#include"Date.h"
#include<iostream>
#include<fstream>
#include<iomanip>


istream& operator>>(istream& fin, Date& date)//>> 연산자 실행
{
	//파일로부터 년,월,일 받아오기
	fin >> date.year;
	fin >> date.month;
	fin >> date.day;

	return fin;//fin 반환
}

ostream& operator<<(ostream& fout, const Date& date)//<<연산자
{
	fout << "(" << date.year << "-" << setw(2) << date.month << "-" << setw(2) << date.day << ")" ;//파일 출력
	
	return fout;
}

Date::Date()//생성자
	:year(1),month(1),day(1)
{
	/*초기화 실행
	year = 1;
	month = 1;
	day = 1;*/
}

Date::Date(int y, int m, int d)
{
	setDate(y, m, d);//년 월 일 설정
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
int Date::getYearDay()//현재년도의 일 수 구하기
{
	int result=0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if(isLeapYear(year))
		months[2] = 29;
	for (int i = 0; i < month; i++)
	{
		result += months[i];//현재 달 전까지의 값더하기
	}
	result += day;//일 더하기

	return result;
}

int Date::getWeekDay()
{
	int weekday;
	int result;

	result = getElapsedDays();//전체 날짜 받아오기
	weekday = result % 7;//요일 수 수로판단

	return weekday;
}

int Date::getElapsedDays()
{
	int result=0;
	int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < year; i++)
	{
		if (isLeapYear(i))//윤년판단
			result += 366;// 윤년일경우 366일 더해줌
		else
			result += 365;// 평년일 경우 365일 더해줌
	}
	result += getYearDay();//그 해의 지금까지의 일 더해줌
	
	
	return result;
}

const Date Date::operator=(const Date rightSide)//대입연산자
{
	if (isValidDate(rightSide.year, rightSide.month, rightSide.day))//정상범위 안에 들어갈 시
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

bool Date::operator>(Date rightSide)//비교연산자
{
	if (getElapsedDays() > rightSide.getElapsedDays())
		return true;
	else
		false;
}
bool Date::operator<(Date rightSide)//비교연산자
{
	if (getElapsedDays() < rightSide.getElapsedDays())
		return true;
	else
		false;
}
bool Date::operator==(Date rightSide)//일치하는지 비교연산자
{
	if (getElapsedDays() == rightSide.getElapsedDays())
		return true;
	else
		false;
}
bool Date::operator!=(Date rightSide)//일치하지 않는지 비교연산자
{
	if (getElapsedDays() != rightSide.getElapsedDays())
		return true;
	else
		false;
}


bool Date::isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//윤년 판단
		return true;
	else
		return false;
}


bool Date::isLeapYear()
{
	return isLeapYear(year);//윤년 판단
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


bool isLeapYear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))//윤년 판단
		return true;
	else
		return false;
}

Date genRandDate()
{
	Date date;
	int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	
	year = rand() % 1000 + 2000;//2000~2999년
	month = rand() % 12 + 1;//1~12월
	if (isLeapYear(year) && month == 2)
		month_days[2] = 29;
	day = rand() % month_days[month] + 1;//달에 맞는 랜덤일 설정

	date.setDate(year, month, day);//date 구조체의 값으로 정의

	return date;
}