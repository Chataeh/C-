#include<iostream>
#include<stdlib.h>
#include "Student.h"
#include <iomanip>

void initStudents(Student students[], int st_ids[], int num_students)// 학생 구조체 값 초기화
{
	int name_len;//이름길이
	int j, grade;
	

	srand(time(0));

	for (int i = 0; i < num_students; i++)
	{
		students[i].st_id = st_ids[i];//학번 설정

		name_len = rand() % 11 + 5;//이름길이 5~15자
		students[i].name[0] = rand() % 26 + 'A'; //이름의 첫글자는 대문자
		for (j = 1; j < name_len; j++)
		{
			students[i].name[j] = rand() % 26 + 'a';	//첫글자 제외 글자 소문자
		}
		students[i].name[j] = '\0';

		name_len = rand() % 4 + 2;//학과 명 길이 설정 3~5
		for (j = 0; j < name_len; j++)
			students[i].dept[j] = rand() % 26 + 'A';// 대문자로표현
		
		students[i].dept[j] = '\0';
		students[i].grade = rand() % 8 + 1;//학년 설정
		students[i].gpa = (rand() % 10000) / 100.00;// 종합성적 설정
	}
}

void fprintStudent(ostream& fout, Student* pSt)//학생 구조체 정보 파일에 출력
{
	
	fout.setf(ios::fixed);//고정 소수점 설정
	fout.setf(ios::showpoint);//소수점 표현
	fout.precision(2);//소수점아래 두자리출력

	fout << "Studnet(ID:" << setw(4) << pSt->st_id;//출력길이 4
	fout << ",Name::" << setw(16) << pSt->name;//출력길이 16
	fout << ",Dept:" << setw(6) << pSt->dept;//출력길이 6
	fout << ",Grade:" << pSt->gpa<<")";
}

//void fprintStundetIDs(ostream& fout, Student[], int num_students, int num_first_last);



void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last)//구조체 배열의 첫부분과 마지막부분 출력
{
	Student* pSt;
	int count = 0;//줄바꿈을 위한 반복 수 체크

	
	for (int i = 0; i < num_first_last; i++)//처음 20개 출력
	{
		pSt = &students[i];

		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << "....." << endl;

	for (int i = num_students - num_first_last; i < num_students; i++)//마지막 20개 출력
	{
		pSt = &students[i];

		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}

void sortStudentsByID(Student students[], int num_students) //학생 학번을 기준으로 선택정렬
{
	int i, j;
	Student temp;
	int min_st, min_ID;
	//선택정렬
	for (i = 0; i < num_students - 1; i++)
	{
		min_st = i;// 처음 위치를 최소값을 가진 위치로설정	
		for (j = i + 1; j < num_students; j++)
		{
			if (students[j].st_id < students[min_st].st_id)
			{
				min_st = j;//최소값으로 설정된 값보다 작은값이 나올시 그 값을 최소값으로 설정
			}
		}

		if(min_st!=i)//초기의 최소값이 현재의 최소값과 다를경우에 위치변환
		{
			temp = students[i];
			students[i] = students[min_st];
			students[min_st] = temp;
		}
	}
}

void sortStudentsByGPA_ID(Student students[], int num_students)
{
	int i, j;
	Student temp;
	int max_st, max_gpa;
	//선택정렬
	for (i = 0; i < num_students - 1; i++)
	{
		max_st = i;// 처음 값을 최대값으로설정
		for (j = i + 1; j < num_students; j++)
		{
			if (students[j].gpa > students[max_st].gpa)//오름차순 출력을 위해
			{
				max_st = j;
			}
			else if (students[j].gpa == students[max_st].gpa)
			{
				if (students[j].st_id < students[max_st].st_id)
					max_st = j;
			}
		}

		if (max_st != i)//초기의 최대값이 현재의 최대값과 다를경우에 위치변환
		{
			temp = students[i];
			students[i] = students[max_st];
			students[max_st] = temp;
		}
	}
}

void fprintBigArrayOfstudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last)
{
	Student* pSt;
	int count = 0;

	
	for (int i = 0; i < num_first_last; i++)//앞부분 출력
	{
		pSt = &students[i];

		fout << "(" << setw(5) << pSt->gpa << "," << setw(5) << pSt->st_id << ")";
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << "....." << endl;//경계 표시

	for (int i = num_students - num_first_last; i < num_students; i++)//뒷부분 출력
	{
		pSt = &students[i];

		fout << "(" << setw(5) << pSt->gpa << "," << setw(5) << pSt->st_id << ")";
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}

Student* searchStudentByID(Student students[], int num_students, int st_ID)//이진 탐색
{
	int low=0, high, mid;
	int round = 0;

	high = num_students - 1;
	round++; //반복 횟수
	
	while (low<=high)
	{
		//cout << round << "d-th round: Search range: [" << low << "," << high << "]"<<endl;
		mid = (low + high) / 2;//중간값 설정
		if (st_ID == students[mid].st_id)//중간값이 찾는값일시
			return &students[mid];//mid 의 학생구조체 반환
		else if (st_ID <= students[mid].st_id)
			high = mid - 1;
		else
			low = mid + 1;
		round++;
	}
	return NULL;
}