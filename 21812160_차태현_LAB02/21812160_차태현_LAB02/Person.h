#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"Date.h"
#include<algorithm>


using namespace std;

#define MAX_NAME_LEN 15
#define MIN_NAME_LEN 5

class Person
{
public:
	Person():name(string("nobody")),birthDate(Date(1,1,1)){}//생성자
	Person(string n,Date bd):name(n),birthDate(bd){}
	void setName(string n) { name = n; }//이름설정
	void setBirhtDAte(Date bd) { birthDate = bd; }//생일설정
	string getName() { return name; }
	Date getBirthDate() { return birthDate; }
	void setRandPersonAttributes();//랜덤으로 이름설정
	void fprintPerson(ostream& fout);//이름과 생일출력
	void sortname(Person* persons);
	void sortbirthday(Person* persons);
private:
	Date birthDate;
	string name;
};

#endif