/**
*�����̸�"21812160_������_Homework02 "
*���α׷��� ���� �� �⺻ ���:
*  Ŭ������ �ۼ��Ͽ� �л����� �� ��¥���
*
*���α׷� �ۼ���: 21812160 ������(2021�� 09��09��),
*���� ���� �� ����: 2021�� 9�� 09�� (������)
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
	fout.open("output.txt");//���Ͽ���

	//srand(time(NULL));

	Date AD010101(1, 1, 1);//1��1��1��
	int year, month, day;
	int daysToChristmas;
	time_t currentTime;
	struct tm* time_and_date;

	time(&currentTime);//����ð� ����
	time_and_date = localtime(&currentTime);
	year = time_and_date->tm_year + 1900;
	month = time_and_date->tm_mon + 1;
	day = time_and_date->tm_mday;

	Date newYearDay(year, 1, 1), today(year, month, day), christmas(year, 12, 25);

	fout << "AD Jan. 1,1 is";
	AD010101.fprintDate(fout);//1��1��1�� ���
	fout << endl;

	fout << "Today is";
	today.fprintDate(fout);//�Է¹��� ���� ���
	fout << endl;

	fout << "New year's day of this year was";
	newYearDay.fprintDate(fout);//�Է¹��� ���� 1��1�����
	fout << endl;
	
	fout << "Christmas of this year is  "; christmas.fprintDate(fout);
	fout << endl;
	if (today.getMonth() == christmas.getMonth() && today.getDay() == christmas.getDay())//�Է��� ���� 12�� 25�� ���
	{
		fout << "Today is Chhristams! Happy Christmas to you all!!";
	}
	else
	{
		fout << "Sorry, today is not Christmas!";
		daysToChristmas = christmas.getElapsedDaysFromAD010101() - today.getElapsedDaysFromAD010101();//(ũ������������ ���� �ϰ�� 1��1��1�Ϻ��� ũ������������ �ϼ�) -(1��1��1�Ϻ��� ���ñ��� �ϼ�)
		fout << endl;
		fout << "You must wait " << daysToChristmas << " day(s) to Christams !" << endl;
	}
	fout << endl;
}