#include"Student.h"
#include<iomanip>

ostream& operator <<(ostream& cout, Student& s)//<<연산자 출력기능
{
	cout << "Studnet [ st_id:" << setw(6) << s.st_id << ", name: " << setw(10) << s.name<<", date_of_birth:"<<setw(2)<<s.dateOfBirth
		<< ", arrival: " << s.arrivalTime << ", gpa: " << setw(4) << s.gpa << "]";

	return cout;//cout반환
}

Student::Student()//default 생성자
	:Person(), st_id(0), gpa(0.0)
{

}

Student::Student(int s_id, string n,Date dob,  Time avt, double gpa)//생성자
	: Person(n), st_id(s_id), gpa(gpa)
{
	dateOfBirth = dob;
	arrivalTime = avt;
}


bool Student::operator<(const Student& s) const//도착시간 순으로 대소비교
{
	if (arrivalTime.elasedSec() < s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator<=(const Student& s) const//도착시간 순으로 대소비교
{
	if(arrivalTime.elasedSec() <=s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator>(const Student& s) const//도착시간순으로 대소비교
{
	if (arrivalTime.elasedSec() > s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator>=(const Student& s) const//도착시간순으로 대소비교
{
	if (arrivalTime.elasedSec() >= s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator==(const Student& s) const//도착시간같은지 판별
{
	if (arrivalTime.elasedSec() == s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}