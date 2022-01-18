/**
*�����̸�"21812160_������_LAB02 "
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
#include"Person.h"
#include<algorithm>

using namespace std;
#define NUM_PERSON 10


int main()
{
	
	cout << "Person size:" << sizeof(Person);
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
	
	Date newYearDay(year, 1, 1), today(year, month, day),christmas(year, 12, 25);
	
	fout << "AD Jan. 1,1 is";
	AD010101.fprintDate(fout);//1��1��1�� ���
	fout << endl;

	fout << "Today is";
	today.fprintDate(fout);//�Է¹��� ���� ���
	fout << endl;

	fout << "New year's day of this year was";
	newYearDay.fprintDate(fout);//�Է¹��� ���� 1��1�����
	fout << endl;

	if (today.getMonth() == christmas.getMonth() && today.getDay() == christmas.getDay())//�Է��� ���� 12�� 25�� ���
	{
		fout << "Today is Chhristams! Happy Christmas to you all!!";
	}
	else
	{
		fout << "Sorry, today is not Christmas!";
		daysToChristmas = christmas.getElapsedDaysFromAD010101() - today.getElapsedDaysFromAD010101();//(ũ������������ ���� �ϰ�� 1��1��1�Ϻ��� ũ������������ �ϼ�) -(1��1��1�Ϻ��� ���ñ��� �ϼ�)
		fout << "You must wait" << daysToChristmas << "day(s) to Christams !" << endl;
	}
	fout << endl;

	Person p1(string("Hong,Gil-Dong"), Date(2000, 1, 1)), p2;
	fout << "Person p1 :" << endl;
	p1.fprintPerson(fout);//1����� ���(ȫ�浿)
	fout << endl;

	fout << "Person p2 :" << endl;
	p2.setName(string("Lee,Soo-Jeong"));//p2 ��� �̸�����
	p2.setBirhtDAte(Date(2018, 9, 1));//p2 ���ϼ���
	p2.fprintPerson(fout);//p2 ����������
	fout << endl;

	fout << endl << "Generating array of persons..." << endl;
	Person* persons;
	persons = (Person*)new Person[NUM_PERSON];//�����޸� �Ҵ�
	
	for (int i = 0; i < NUM_PERSON; i++)
	{
		persons[i].setRandPersonAttributes();//������� ��������
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	
	persons->sortname(persons);
	fout << endl;
	fout << "sorted Person by Name" << endl;
	for (int i = 0; i < NUM_PERSON; i++)
	{
		persons[i].fprintPerson(fout);
		fout << endl;
	}
	
	fout << endl;
	
	persons->sortbirthday(persons);
	fout << endl;
	fout << "sorted Person by BD" << endl;
	for (int i = 0; i < NUM_PERSON; i++)
	{
		persons[i].fprintPerson(fout);
		fout << endl;
	}

	fout << endl;
	delete[] persons;//�����޸� ��ȯ
	fout.close();//���ϴݱ�

}

