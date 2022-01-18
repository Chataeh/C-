#ifndef P_H
#define P_H

#include<string>
#include"Date.h"
#include"Time.h"

class Person
{
	friend ostream& operator<<(ostream& fout, const Person& p)
	{
		fout << "Person [name:" << p.name << "]";

		return fout;
	}

public:
	Person() { name = "nobody"; }//default ������
	Person(string n) { name = n; }//�̸����� ������
	void setName(string n) { name = n; }//�̸�����
	string getName() { return name; }//�̸���ȯ
	void setDoB(Date dob) { dateOfBirth = dob; }//���ϼ���
	const Date getDoB() const { return dateOfBirth; }//���Ϲ�ȯ
	void setArrivalTime(Time t) { arrivalTime = t; }//�ð�����
	const Time getArrivalTime() const { return arrivalTime; }//�ð���ȯ
protected:
	string name;//�̸� 
	Date dateOfBirth;//����
	Time arrivalTime;// �����ð�
};


#endif