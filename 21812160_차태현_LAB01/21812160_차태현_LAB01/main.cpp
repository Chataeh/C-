/**
*�����̸�"21812160_������_LAB01 "
*���α׷��� ���� �� �⺻ ���:
*  ����ü �迭�� �л������� �����Ͽ� ���� �� ����ϰ� Ư���л��� ã�Ƴ��� ���α׷�
*
*���α׷� �ۼ���: 21812160 ������(2021�� 9��1��),
*���� ���� �� ����: 2021�� 9�� 1�� (������)
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include"Student.h"

using namespace std;

#define NUM_STUDENTS 5000
#define NUM_SEARCH 5
#define NUM_FIRST_LAST_BLOCK 100

void genBigRandArray(int randArray[], int num_rands);//ū ��������

int main(void)
{
	cout <<"studnet size:"<< sizeof(Student);
	
	ofstream fout;//���Ͽ� ���

	int* students_ids;
	Student* students, *pSt;
	int student_search[NUM_SEARCH] = { 1,123,999,2500,4999 }; 

	fout.open("output.txt");
	
	students_ids = (int*)malloc(sizeof(int) * NUM_STUDENTS); //�л��� ����ŭ �����Ҵ�
	students = (Student*)malloc(sizeof(Student) * NUM_STUDENTS); //����ü �޸� �����Ҵ�
	genBigRandArray(students_ids, NUM_STUDENTS);//ū ��������
	initStudents(students, students_ids, NUM_STUDENTS);//����ü ���� �ʱ�ȭ

	fout << endl << endl;
	fout << "Initialized array of students :" << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);//����ü �迭 ù�κ� ���κ� ���

	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID :" << endl;
	sortStudentsByID(students, NUM_STUDENTS);//�й������� ����ü �迭 ����
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) :" << endl;
	sortStudentsByGPA_ID(students, NUM_STUDENTS);//gpa ������ �л� ����
	fprintBigArrayOfstudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID :" << endl;
	sortStudentsByID(students, NUM_STUDENTS);//�й������� �л�����ü ����
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	fout << endl << endl;
	fout << "Searching student with student_ID :" << endl;
	for (int i = 0; i < NUM_SEARCH; i++)
	{
		pSt = searchStudentByID(students, NUM_STUDENTS, student_search[i]);
		fout << "Student search by ID (" << setw(4) << student_search[i] << "):";
		if (pSt != NULL)
			fprintStudent(fout, pSt);//Ư���й��� �л��� ���
		else
			fout << "NULL- student was not found!!";
		fout << endl;
	}
	fout.close();//���ϴݱ�

}

void genBigRandArray(int randArray[], int num_rands)//�й�����
{
	char* flag;
	int count = 0;
	unsigned int u_int32 = 0;
	unsigned int bigRand;
	flag = (char*)calloc(sizeof(char), num_rands);
	
	while (count < num_rands)//�л��� ��ŭ �ݺ�
	{
		u_int32 = ((long)rand() << 15) | rand();//ū ������ �����ϱ�����
		bigRand = u_int32 % num_rands;//��ⷯ ������ ���Ͽ� ����������
		if (flag[bigRand] == 1)//�ߺ������� ���Ͽ�
		{
			continue;
		}
		flag[bigRand] = 1;
		randArray[count++] = bigRand;
	}
}

