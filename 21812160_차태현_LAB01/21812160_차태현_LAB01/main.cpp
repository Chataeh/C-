/**
*파일이름"21812160_차태현_LAB01 "
*프로그램의 목적 및 기본 기능:
*  구조체 배열에 학생정보를 저장하여 정렬 후 출력하고 특정학생을 찾아내는 프로그램
*
*프로그램 작성자: 21812160 차태현(2021년 9월1일),
*최종 수정 및 보완: 2021년 9월 1일 (차태현)
*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include"Student.h"

using namespace std;

#define NUM_STUDENTS 5000
#define NUM_SEARCH 5
#define NUM_FIRST_LAST_BLOCK 100

void genBigRandArray(int randArray[], int num_rands);//큰 난수생성

int main(void)
{
	cout <<"studnet size:"<< sizeof(Student);
	
	ofstream fout;//파일에 출력

	int* students_ids;
	Student* students, *pSt;
	int student_search[NUM_SEARCH] = { 1,123,999,2500,4999 }; 

	fout.open("output.txt");
	
	students_ids = (int*)malloc(sizeof(int) * NUM_STUDENTS); //학생의 수만큼 동적할당
	students = (Student*)malloc(sizeof(Student) * NUM_STUDENTS); //구조체 메모리 동적할당
	genBigRandArray(students_ids, NUM_STUDENTS);//큰 난수생성
	initStudents(students, students_ids, NUM_STUDENTS);//구조체 정보 초기화

	fout << endl << endl;
	fout << "Initialized array of students :" << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);//구조체 배열 첫부분 끝부분 출력

	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID :" << endl;
	sortStudentsByID(students, NUM_STUDENTS);//학번순으로 구조체 배열 정렬
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Sorting array of students by (decreasing order of GPA, increasing order of ID) :" << endl;
	sortStudentsByGPA_ID(students, NUM_STUDENTS);//gpa 순으로 학생 정렬
	fprintBigArrayOfstudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Sorting array of students by non-decreasing order of ID :" << endl;
	sortStudentsByID(students, NUM_STUDENTS);//학번순으로 학생구조체 정렬
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);
	fout << endl << endl;
	fout << "Searching student with student_ID :" << endl;
	for (int i = 0; i < NUM_SEARCH; i++)
	{
		pSt = searchStudentByID(students, NUM_STUDENTS, student_search[i]);
		fout << "Student search by ID (" << setw(4) << student_search[i] << "):";
		if (pSt != NULL)
			fprintStudent(fout, pSt);//특정학번의 학생들 출력
		else
			fout << "NULL- student was not found!!";
		fout << endl;
	}
	fout.close();//파일닫기

}

void genBigRandArray(int randArray[], int num_rands)//학번생성
{
	char* flag;
	int count = 0;
	unsigned int u_int32 = 0;
	unsigned int bigRand;
	flag = (char*)calloc(sizeof(char), num_rands);
	
	while (count < num_rands)//학생수 만큼 반복
	{
		u_int32 = ((long)rand() << 15) | rand();//큰 난수를 생성하기위함
		bigRand = u_int32 % num_rands;//모듈러 연산을 통하여 난수값제한
		if (flag[bigRand] == 1)//중복방지를 위하여
		{
			continue;
		}
		flag[bigRand] = 1;
		randArray[count++] = bigRand;
	}
}

