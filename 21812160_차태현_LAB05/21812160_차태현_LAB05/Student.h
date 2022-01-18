#ifndef ST_H
#define ST_H
#include<iostream>
#include"Person.h"
#include"Mystring.h"

#define NUM_STUDENTS 10

class StudentArray;
class Student : public Person//Person 클래스상속
{
	friend class StudentArray;
	friend ostream& operator << (ostream&, const Student&);
public:
	Student();//default 생성자
	Student(int id);//학번 생성자
	Student(int id, string n, Date dob, string dept_n, double gpa);//생성자
	int getST_id() const { return st_id; }
	string getDept_name() const { return dept_name; }
	double getGPA() const { return gpa; }
	Date getBirthDate() const { return birthDate; }
	void setSt_id(int id) { st_id = id; }//학번설정
	void setDept_name(string dp_n) { dept_name = dp_n; }//학과설정
	void setGPA(double g) { gpa = g; }//학점설정
	const Student& operator = (const Student& right);//대입연산자
	bool operator >(const Student& right);//비교연산자
	bool operator==(const Student& rihgt);//객체 일치확인 

private:
	int st_id;
	string dept_name;
	double gpa;
};

Student genRandStudent(int id);//랜덤으로 학생정보생성
void genST_ids(int num_students, int* st_ids);//랜덤으로 학번생성

#endif // !ST_H
