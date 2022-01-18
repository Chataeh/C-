#ifndef ST_H
#define ST_H
#include<iostream>
#include"Person.h"
#include"Mystring.h"

#define NUM_STUDENTS 10

class StudentArray;
class Student : public Person//Person Ŭ�������
{
	friend class StudentArray;
	friend ostream& operator << (ostream&, const Student&);
public:
	Student();//default ������
	Student(int id);//�й� ������
	Student(int id, string n, Date dob, string dept_n, double gpa);//������
	int getST_id() const { return st_id; }
	string getDept_name() const { return dept_name; }
	double getGPA() const { return gpa; }
	Date getBirthDate() const { return birthDate; }
	void setSt_id(int id) { st_id = id; }//�й�����
	void setDept_name(string dp_n) { dept_name = dp_n; }//�а�����
	void setGPA(double g) { gpa = g; }//��������
	const Student& operator = (const Student& right);//���Կ�����
	bool operator >(const Student& right);//�񱳿�����
	bool operator==(const Student& rihgt);//��ü ��ġȮ�� 

private:
	int st_id;
	string dept_name;
	double gpa;
};

Student genRandStudent(int id);//�������� �л���������
void genST_ids(int num_students, int* st_ids);//�������� �й�����

#endif // !ST_H
