#ifndef P_H
#define P_H

#include<string>
#include"Time.h"
#include"Date.h"

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
protected:
	string name;//�̸� 
	Date dateOfBirth;
};


#endif