/**
*파일이름"21812160_차태현_Homework02 "
*프로그램의 목적 및 기본 기능:
*  클래스를 작성하여 학생정보 및 날짜출력
*
*프로그램 작성자: 21812160 차태현(2021년 09월09일),
*최종 수정 및 보완: 2021년 9월 09일 (차태현)
*/
#include<iostream>
#include<fstream>
#include<time.h>
#include<string>
#include"Date.h"


using namespace std;
#define NUM_PERSON 10


int main()
{
	ofstream fout;
	fout.open("output.txt");//파일열기

	//srand(time(NULL));

	Date AD010101(1, 1, 1);//1년1월1일
	int year, month, day;
	int daysToChristmas;
	time_t currentTime;
	struct tm* time_and_date;

	time(&currentTime);//현재시간 측정
	time_and_date = localtime(&currentTime);
	year = time_and_date->tm_year + 1900;
	month = time_and_date->tm_mon + 1;
	day = time_and_date->tm_mday;

	Date newYearDay(year, 1, 1), today(year, month, day), christmas(year, 12, 25);

	fout << "AD Jan. 1,1 is";
	AD010101.fprintDate(fout);//1년1월1일 출력
	fout << endl;

	fout << "Today is";
	today.fprintDate(fout);//입력받은 오늘 출력
	fout << endl;

	fout << "New year's day of this year was";
	newYearDay.fprintDate(fout);//입력받은 해의 1월1일출력
	fout << endl;
	
	fout << "Christmas of this year is  "; christmas.fprintDate(fout);
	fout << endl;
	if (today.getMonth() == christmas.getMonth() && today.getDay() == christmas.getDay())//입력한 값이 12월 25일 경우
	{
		fout << "Today is Chhristams! Happy Christmas to you all!!";
	}
	else
	{
		fout << "Sorry, today is not Christmas!";
		daysToChristmas = christmas.getElapsedDaysFromAD010101() - today.getElapsedDaysFromAD010101();//(크리스마스까지 남은 일계산 1년1월1일부터 크리스마스까지 일수) -(1년1월1일부터 오늘까지 일수)
		fout << endl;
		fout << "You must wait " << daysToChristmas << " day(s) to Christams !" << endl;
	}
	fout << endl;
}