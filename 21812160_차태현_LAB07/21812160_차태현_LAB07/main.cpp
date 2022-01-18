/**
*파일이름"21812160_차태현_LAB07"
*프로그램의 목적 및 기본 기능:
*  템플릿을 사용하여 함수를사용 
*
*프로그램 작성자: 21812160 차태현(2021년 10월13일),
*최종 수정 및 보완: 2021년 10월 13일 (차태현)
*/
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include"VectorHandler.h"
#include"Date.h"
#include"Time.h"
#include"Person.h"
#include"Student.h"
#include"Template class T_Array.h"

using namespace std;

#define STEP_1 
//#define STEP_2 
#define STEP_3 
#define STEP_4 
#define NUM_TIMES 10 
#define NUM_DATES 10 
#define NUM_STUDENTS 10 

int main()
{
#ifdef STEP_1
	
	cout << " STEP_1 " << endl;
	Time times[NUM_TIMES] =
	{
	Time(3, 0, 30), Time(7, 30, 0), Time(2, 0, 50), Time(5, 30, 0), Time(1, 10, 0),
	Time(9, 20, 10), Time(1, 20, 15), Time(10, 0, 0), Time(11, 15, 10), Time(2, 0, 5)
	};// 시간설정

	vector<Time> v_times(times, times + NUM_TIMES);//vector 생성
	cout << "Initial v_times : " << endl;
	printVector(v_times);//템플릿을 사용해 time 에대한 출력
	sort(v_times.begin(), v_times.end());//정의된 정렬함수 사용
	cout << "After sort() : " << endl;
	printVector(v_times);

	Date dates[10] =
	{
	Date(2003, 4, 5), Date(2002, 7, 15), Date(2001, 5, 1), Date(2001, 3, 10), Date(2000, 5, 21),
	Date(2000, 3, 1), Date(1999, 12, 25), Date(1998, 10, 9), Date(1997, 6, 10), Date(1996, 1, 1)
	};//Date설정

	vector<Date> v_dates(dates, dates + NUM_DATES);//vector 생성
	cout << "Initial v_dates :" << endl;
	printVector(v_dates);//템플릿을 사용해 date출력
	sort(v_dates.begin(), v_dates.end());
	cout << "After sort() : " << endl;
	printVector(v_dates);

	cout << "Hit any key to continue .... ";
	_getch();

	cout << endl;
	cout << endl;
#endif

#ifdef STEP_2
	
	cout << " STEP_2 " << endl;
	
	Student students[NUM_STUDENTS] =
	{
	Student(5234, string("Kim, G-M"), Date(2002, 7, 15), Time(3, 0, 30), 3.57),
	Student(1999, string("Yoon, S-M"), Date(1999, 12, 25), Time(7, 30, 0), 4.37),
	Student(4141, string("Byun, S-S"), Date(2001, 3, 10), Time(2, 0, 50), 2.72),
	Student(2167, string("Lee, K-M"), Date(1998, 10, 9), Time(5, 30, 0), 3.35),
	Student(3890, string("Hong, G-M"), Date(2000, 3, 1), Time(1, 10, 0), 3.89),
	Student(6543, string("Jang, S-M"), Date(2000, 5, 21), Time(9, 20, 10), 4.42),
	Student(7080, string("Park, S-T"), Date(2001, 5, 1), Time(1, 20, 15), 4.12),
	Student(9564, string("Choi, Y-H"), Date(1997, 6, 10), Time(10, 0, 0), 3.85),
	Student(1000, string("Shin, D-J"), Date(2003, 4, 5), Time(11, 15, 10), 3.21),
	Student(8812, string("Ahn, S-B"), Date(1997, 1, 1), Time(2, 0, 5), 4.45),
	};//학생정보 설정

	vector<Student> v_students(students, students + NUM_DATES);//vector 클래스 Student로 생성

	cout << "Initial v_students :" << endl;
	printVector(v_students);//템플릿함수를 통한 Student 출력
	sort(v_students.begin(), v_students.end());
	cout << "₩nstudents after sorting by st_id :" << endl;
	printVector(v_students);
	cout << "Hit any key to continue .... ";

	_getch();

	cout << endl;

#endif

#ifdef STEP_3
	cout << " STEP_3 " << endl;
	Student students[NUM_STUDENTS] =
	{
	Student(5234, string("Kim, G-M"), Date(2002, 7, 15), Time(3, 0, 30), 3.57),
	Student(1999, string("Yoon, S-M"), Date(1999, 12, 25), Time(7, 30, 0), 4.37),
	Student(4141, string("Byun, S-S"), Date(2001, 3, 10), Time(2, 0, 50), 2.72),
	Student(2167, string("Lee, K-M"), Date(1998, 10, 9), Time(5, 30, 0), 3.35),
	Student(3890, string("Hong, G-M"), Date(2000, 3, 1), Time(1, 10, 0), 3.89),
	Student(6543, string("Jang, S-M"), Date(2000, 5, 21), Time(9, 20, 10), 4.42),
	Student(7080, string("Park, S-T"), Date(2001, 5, 1), Time(1, 20, 15), 4.12),
	Student(9564, string("Choi, Y-H"), Date(1997, 6, 10), Time(10, 0, 0), 3.85),
	Student(1000, string("Shin, D-J"), Date(2003, 4, 5), Time(11, 15, 10), 3.21),
	Student(8812, string("Ahn, S-B"), Date(1997, 1, 1), Time(2, 0, 5), 4.45),
	};//학생정보 생성

	Student* pSt;
	T_Array<Student, int> stArray_keyID(NUM_STUDENTS, "T_Array<Student, keyST_ID>");//학생에서 학번사용	
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyID.insert(i, students[i]);//i번째에 학생i번째 정보 삽입
	}

	cout << "T_Array<Student_keyID> at initialization : " << endl;
	stArray_keyID.print(1);
	stArray_keyID.selection_sort(string("ST_ID"), INCREASING);//오름차순정렬
	cout << "\nT_Array<Student_keyID> after sorting (increasing order) by ST_ID : " << endl;
	stArray_keyID.print(1);//한줄씩출력


	T_Array<Student, double> stArray_keyGPA(NUM_STUDENTS, "T_Array<Student, keyGPA>");//학생에서 학점사용
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyGPA.insert(i, students[i]);//i번째에 학생i번째 정보 삽입
	}

	stArray_keyGPA.quick_sort(string("GPA"), DECREASING);//내림차순 정렬
	cout << "\nT_Array<Student, keyGPA> after sorting (decreasing order) by GPA : " << endl;
	stArray_keyGPA.print(1);//한줄씩출력

	cout << "Hit any key to continue .... ";
	_getch();
	cout << endl;

#endif // !STEP3

#ifdef STEP_4
	
	cout <<" STEP_4 "<< endl;

	T_Array<Student, string> stArray_keyName(NUM_STUDENTS, "T_Array<Student, keyName > "); //학생에서 이름사용
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyName.insert(i, students[i]);//i번째에 학생i번째 정보 삽입
	}
	stArray_keyName.selection_sort(string("ST_NAME"), INCREASING);//오름차순정렬
	cout << "\nT_Array<Student_keyName> after sorting (increasing order) by name : " << endl;
	stArray_keyName.print(1);//한줄씩출력

	T_Array<Student, Date> stArray_keyDoB(NUM_STUDENTS, "Array of Students, date of birth as key");//학생에서 생일사용
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyDoB.insert(i, students[i]);//i번째에 학생i번째 정보 삽입
	}
	stArray_keyDoB.selection_sort(string("BIRTH_DATE"), INCREASING);//오름차순정렬
	cout << "\nstArray_keyDoB after sorting (increasing order) by date of birth : " << endl;
	stArray_keyDoB.print(1);//한줄씩출력


	T_Array<Student, Time> stArray_keyTime(NUM_STUDENTS, "Array of Students, arrival time as key");//학생정보에 시간사용
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		stArray_keyTime.insert(i, students[i]);//i번째에 학생i번째 정보 삽입
	}
	stArray_keyTime.selection_sort(string("ARRIVAL_TIME"), INCREASING);//오름차순정렬
	cout << "\nstArray_keyArrTm after sorting (increasing order) by arrival time : " << endl;
	stArray_keyTime.print(1);//한줄씩출력

}
#endif




