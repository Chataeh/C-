#ifndef S_H
#define S_H

#include"Time.h"
#include"Date.h"
#include"Person.h"

class Student :public Person//Person 클래스 상속
{
	friend ostream& operator<<(ostream&, Student&);//<< 연산자
public:
	Student();//default 생성자
	Student(int s_id, string n, Date dob, Time avt, double gpa);//생성자
	void getKey(string keyName, void* pKey);//키 설정
	bool operator<(const Student&) const;//대소비교
	bool operator<=(const Student&) const;//대소비교
	bool operator>(const Student&) const;//대소비교
	bool operator>=(const Student&) const;//대소비교
	bool operator==(const Student&) const;//같은지 비교

private:
	int st_id;//학번 
	double gpa;//학점
};

#endif // !S_H
