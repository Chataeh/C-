#ifndef S_H
#define S_H

#include"Time.h"
#include"Person.h"
#include"Date.h"

class Student :public Person//Person 클래스 상속
{
	friend ostream& operator<<(ostream&, Student&);//<< 연산자
public:
	Student();//default 생성자
	Student(int s_id, string n, Date dob, Time avt, double gpa);//생성자//생성자
	bool operator<(const Student&) const;//대소비교
	bool operator<=(const Student&) const;//대소비교
	bool operator>(const Student&) const;//대소비교
	bool operator>=(const Student&) const;//대소비교
	bool operator==(const Student&) const;//같은지 비교

private:
	int st_id;//학번 
	double gpa;//학점
	Time arrivalTime;//도착시간
};

#endif // !S_H
