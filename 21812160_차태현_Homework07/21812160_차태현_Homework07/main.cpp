/**
*�����̸�"21812160_������_Homework07"
*���α׷��� ���� �� �⺻ ���:
*  ���ø��� ����� �л�Ŭ���� ���� ���
*
*���α׷� �ۼ���: 21812160 ������(2021�� 10��15��),
*���� ���� �� ����: 2021�� 10�� 15�� (������)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "T_Array.h"
#include "Student.h"
using namespace std;
#define ELEMENTS_PER_LINE 10
#define SAMPLE_LINES 5
#define NUM_ELEMENTS 500
#define MIN_NUM_ELEMENTS 10
#define NUM_STUDENTS 10
Student students[10] =
{
Student(21811000, string("Kim, G-M"),Date(1990, 10, 5), Time(3, 0, 30), 3.57),
Student(21611075, string("Yoon, S-M"),Date(1990, 4, 5),  Time(7, 30, 0), 4.37),
Student(21411015, string("Hwang, S-S"),Date(1989, 1, 10),  Time(2, 0, 50), 2.72),
Student(21611054, string("Lee, K-M"),Date(1991, 5, 15), Time(5, 30, 0), 3.35),
Student(21311340, string("Hong, G-M"),Date(1990, 2, 5), Time(1, 10, 0), 3.89),
Student(22116543, string("Jang, S-M"),Date(1978, 1, 4), Time(9, 20, 10), 4.42),
Student(22037080, string("Park, S-T"),Date(1998, 11, 9),  Time(1, 20, 15), 4.12),
Student(21559564, string("Choi, Y-H"), Date(1999, 12, 6), Time(10, 0, 0), 3.85),
Student(21614000, string("Shin, D-J"),Date(1993, 10, 26),  Time(11, 15, 10), 3.21),
Student(21787812, string("Ahn, S-B"), Date(1994, 6, 21), Time(2, 0, 5), 4.45)
}; 


int main()
{
	ofstream fout;
	T_Array<Student> studentArray(NUM_STUDENTS, "Array of Students");//���ø� �л�Ŭ������ �迭����
	Student* pStudent;

	fout.open("output.txt");

	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		pStudent = &students[i];//�л����� ����
		studentArray.insert(i, *pStudent);//�迭�� ����
	}
	
	fout << "Elements in studentArray after initialization :" << endl;
	studentArray.fprint(fout, 1);//�迭���
	
	fout << "Elements in studentArray after sorting :" << endl;
	studentArray.selection_sort(INCREASING);//�������� ��������
	studentArray.fprint(fout, 1);
	
	fout << "Elements in studentArray after sorting :" << endl;
	studentArray.quick_sort(DECREASING);//�������� ������
	studentArray.fprint(fout, 1);

	fout.close();
}
