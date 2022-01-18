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
	Person() { name = "nobody"; }//default 생성자
	Person(string n) { name = n; }//이름설정 생성자
protected:
	string name;//이름 
	Date dateOfBirth;
};


#endif