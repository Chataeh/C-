#ifndef S_H
#define S_H

#include"Time.h"
#include"Person.h"
#include"Date.h"

class Student :public Person//Person Ŭ���� ���
{
	friend ostream& operator<<(ostream&, Student&);//<< ������
public:
	Student();//default ������
	Student(int s_id, string n, Date dob, Time avt, double gpa);//������//������
	bool operator<(const Student&) const;//��Һ�
	bool operator<=(const Student&) const;//��Һ�
	bool operator>(const Student&) const;//��Һ�
	bool operator>=(const Student&) const;//��Һ�
	bool operator==(const Student&) const;//������ ��

private:
	int st_id;//�й� 
	double gpa;//����
	Time arrivalTime;//�����ð�
};

#endif // !S_H
