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
	Person():name(string("nobody")),birthDate(Date(1,1,1)){}//������
	Person(string n,Date bd):name(n),birthDate(bd){}
	void setName(string n) { name = n; }//�̸�����
	void setBirhtDAte(Date bd) { birthDate = bd; }//���ϼ���
	string getName() { return name; }
	Date getBirthDate() { return birthDate; }
	void setRandPersonAttributes();//�������� �̸�����
	void fprintPerson(ostream& fout);//�̸��� �������
	void sortname(Person* persons);
	void sortbirthday(Person* persons);
private:
	Date birthDate;
	string name;
};

#endif