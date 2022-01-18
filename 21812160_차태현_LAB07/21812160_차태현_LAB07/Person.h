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
	Person() { name = "nobody"; }//default 생성자
	Person(string n) { name = n; }//이름설정 생성자
	void setName(string n) { name = n; }//이름설정
	string getName() { return name; }//이름반환
	void setDoB(Date dob) { dateOfBirth = dob; }//생일설정
	const Date getDoB() const { return dateOfBirth; }//생일반환
	void setArrivalTime(Time t) { arrivalTime = t; }//시간설정
	const Time getArrivalTime() const { return arrivalTime; }//시간반환
protected:
	string name;//이름 
	Date dateOfBirth;//생일
	Time arrivalTime;// 도착시간
};


#endif