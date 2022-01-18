#ifndef P_H
#define P_H
#include"Date.h"

class Person
{
	friend ostream& operator<<(ostream&, const Person&);//<<연산자
public:
	Person() { birthDate = Date(1, 1, 1); name = ""; };//생성자 0으로 초기화
	Person(string nm, Date bd) { birthDate = bd; name = nm; };//생성자
	void setName(string n) { name = n; }//이름 설정
	void setBirthDate(Date bd) { birthDate = bd; }//생일 설정
	string getName()const { return name; }//이름 반환
	Date getBirthDate() const { return birthDate; }//생일 반환
	const Person& operator =(const Person& right);
protected://자식클래스에서 사용가능
	Date birthDate;//생일
	string name;//이름
};

#endif 
