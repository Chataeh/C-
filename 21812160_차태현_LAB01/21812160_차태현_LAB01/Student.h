#include <iostream>

using namespace std;

typedef struct s_Student
{
	int st_id; //�й�
	char name[16];//�̸�
	char dept[16];//�а�
	int grade;//�г�
	double gpa;//���ռ���

}Student;

void initStudents(Student students[], int st_ids[], int num_students);//�л����� �ʱ�ȭ
void fprintStudent(ostream& fout, Student* pSt);//�л����� ���Ͽ� ���
//void fprintStundetIDs(ostream& fout, Student[], int num_students, int num_first_last);
void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last);//ó���� ���� �й� ���
void sortStudentsByID(Student students[], int num_students);// �й����� ��������
void sortStudentsByGPA_ID(Student students[], int num_students);//gpa������ �������� gpa������ �й����� �Ǵ�
void fprintBigArrayOfstudent_GPA_IDs(ostream& fout, Student students[], int num_students, int num_first_last);
Student* searchStudentByID(Student students[], int num_students, int st_ID);//Ư�� �л� ����ü ã��