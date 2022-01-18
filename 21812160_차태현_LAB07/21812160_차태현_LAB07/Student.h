#ifndef S_H
#define S_H

#include"Time.h"
#include"Date.h"
#include"Person.h"

class Student :public Person//Person Ŭ���� ���
{
	friend ostream& operator<<(ostream&, Student&);//<< ������
public:
	Student();//default ������
	Student(int s_id, string n, Date dob, Time avt, double gpa);//������
	void getKey(string keyName, void* pKey);//Ű ����
	bool operator<(const Student&) const;//��Һ�
	bool operator<=(const Student&) const;//��Һ�
	bool operator>(const Student&) const;//��Һ�
	bool operator>=(const Student&) const;//��Һ�
	bool operator==(const Student&) const;//������ ��

private:
	int st_id;//�й� 
	double gpa;//����
};

#endif // !S_H
