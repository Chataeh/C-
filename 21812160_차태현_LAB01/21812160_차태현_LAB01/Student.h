#include <iostream>

using namespace std;

typedef struct s_Student
{
	int st_id; //학번
	char name[16];//이름
	char dept[16];//학과
	int grade;//학년
	double gpa;//종합성적

}Student;

void initStudents(Student students[], int st_ids[], int num_students);//학생정보 초기화
void fprintStudent(ostream& fout, Student* pSt);//학생정보 파일에 출력
//void fprintStundetIDs(ostream& fout, Student[], int num_students, int num_first_last);
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last);//처음과 끝의 학번 출력
void sortStudentsByID(Student students[], int num_students);// 학번으로 선택정렬
void sortStudentsByGPA_ID(Student students[], int num_students);//gpa순으로 선택정렬 gpa같을시 학번으로 판단
void fprintBigArrayOfstudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
Student* searchStudentByID(Student students[], int num_students, int st_ID);//특정 학생 구조체 찾기