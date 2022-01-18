#include<iostream>
#include<stdlib.h>
#include "Student.h"
#include <iomanip>

void initStudents(Student students[], int st_ids[], int num_students)// �л� ����ü �� �ʱ�ȭ
{
	int name_len;//�̸�����
	int j, grade;
	

	srand(time(0));

	for (int i = 0; i < num_students; i++)
	{
		students[i].st_id = st_ids[i];//�й� ����

		name_len = rand() % 11 + 5;//�̸����� 5~15��
		students[i].name[0] = rand() % 26 + 'A'; //�̸��� ù���ڴ� �빮��
		for (j = 1; j < name_len; j++)
		{
			students[i].name[j] = rand() % 26 + 'a';	//ù���� ���� ���� �ҹ���
		}
		students[i].name[j] = '\0';

		name_len = rand() % 4 + 2;//�а� �� ���� ���� 3~5
		for (j = 0; j < name_len; j++)
			students[i].dept[j] = rand() % 26 + 'A';// �빮�ڷ�ǥ��
		
		students[i].dept[j] = '\0';
		students[i].grade = rand() % 8 + 1;//�г� ����
		students[i].gpa = (rand() % 10000) / 100.00;// ���ռ��� ����
	}
}

void fprintStudent(ostream& fout, Student* pSt)//�л� ����ü ���� ���Ͽ� ���
{
	
	fout.setf(ios::fixed);//���� �Ҽ��� ����
	fout.setf(ios::showpoint);//�Ҽ��� ǥ��
	fout.precision(2);//�Ҽ����Ʒ� ���ڸ����

	fout << "Studnet(ID:" << setw(4) << pSt->st_id;//��±��� 4
	fout << ",Name::" << setw(16) << pSt->name;//��±��� 16
	fout << ",Dept:" << setw(6) << pSt->dept;//��±��� 6
	fout << ",Grade:" << pSt->gpa<<")";
}

//void fprintStundetIDs(ostream& fout, Student[], int num_students, int num_first_last);



void fprintBigArrayOfStudent_IDs(ostream& fout, Student students[], int num_students, int num_first_last)//����ü �迭�� ù�κа� �������κ� ���
{
	Student* pSt;
	int count = 0;//�ٹٲ��� ���� �ݺ� �� üũ

	
	for (int i = 0; i < num_first_last; i++)//ó�� 20�� ���
	{
		pSt = &students[i];

		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << "....." << endl;

	for (int i = num_students - num_first_last; i < num_students; i++)//������ 20�� ���
	{
		pSt = &students[i];

		fout << setw(6) << pSt->st_id;
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}

void sortStudentsByID(Student students[], int num_students) //�л� �й��� �������� ��������
{
	int i, j;
	Student temp;
	int min_st, min_ID;
	//��������
	for (i = 0; i < num_students - 1; i++)
	{
		min_st = i;// ó�� ��ġ�� �ּҰ��� ���� ��ġ�μ���	
		for (j = i + 1; j < num_students; j++)
		{
			if (students[j].st_id < students[min_st].st_id)
			{
				min_st = j;//�ּҰ����� ������ ������ �������� ���ý� �� ���� �ּҰ����� ����
			}
		}

		if(min_st!=i)//�ʱ��� �ּҰ��� ������ �ּҰ��� �ٸ���쿡 ��ġ��ȯ
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
	//��������
	for (i = 0; i < num_students - 1; i++)
	{
		max_st = i;// ó�� ���� �ִ밪���μ���
		for (j = i + 1; j < num_students; j++)
		{
			if (students[j].gpa > students[max_st].gpa)//�������� ����� ����
			{
				max_st = j;
			}
			else if (students[j].gpa == students[max_st].gpa)
			{
				if (students[j].st_id < students[max_st].st_id)
					max_st = j;
			}
		}

		if (max_st != i)//�ʱ��� �ִ밪�� ������ �ִ밪�� �ٸ���쿡 ��ġ��ȯ
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

	
	for (int i = 0; i < num_first_last; i++)//�պκ� ���
	{
		pSt = &students[i];

		fout << "(" << setw(5) << pSt->gpa << "," << setw(5) << pSt->st_id << ")";
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
	fout << "....." << endl;//��� ǥ��

	for (int i = num_students - num_first_last; i < num_students; i++)//�޺κ� ���
	{
		pSt = &students[i];

		fout << "(" << setw(5) << pSt->gpa << "," << setw(5) << pSt->st_id << ")";
		count++;
		if ((count % 20) == 0)
			fout << endl;
	}
}

Student* searchStudentByID(Student students[], int num_students, int st_ID)//���� Ž��
{
	int low=0, high, mid;
	int round = 0;

	high = num_students - 1;
	round++; //�ݺ� Ƚ��
	
	while (low<=high)
	{
		//cout << round << "d-th round: Search range: [" << low << "," << high << "]"<<endl;
		mid = (low + high) / 2;//�߰��� ����
		if (st_ID == students[mid].st_id)//�߰����� ã�°��Ͻ�
			return &students[mid];//mid �� �л�����ü ��ȯ
		else if (st_ID <= students[mid].st_id)
			high = mid - 1;
		else
			low = mid + 1;
		round++;
	}
	return NULL;
}