#include"Student.h"
#include<iomanip>

ostream& operator <<(ostream& cout, Student& s)//<<연산자 출력기능
{
	cout << "Studnet [ st_id:" << setw(6) << s.st_id << ", name: " << setw(9) <<s.name<< ", gpa: " << setw(4) << s.gpa << " , date_of_birth: " << s.dateOfBirth
		<< ", arrival: " << s.arrivalTime << "]" ;

	return cout;//cout반환
}

Student::Student()//default 생성자
	:Person(),st_id(0),gpa(0.0)
{

}

Student::Student(int s_id, string n, Date dob, Time avt, double gpa)//생성자
	:Person(n),st_id(s_id),gpa(gpa)
{
	dateOfBirth = dob;
	arrivalTime = avt;
}

void Student::getKey(string keyName, void* pKey)//키설정
{
	//pKey는 keyName 에 따라설정
	if (keyName == "ST_ID")
		*(int*)pKey = this->st_id;//int*형 키
	else if (keyName == "ST_NAME")
		*(string*)pKey = this->name;//string* 형 키
	else if (keyName == "GPA")
		*(double*)pKey = this->gpa;//double * 형 키
	else if (keyName == "ARRIVAL_TIME")
		*(Time*)pKey = this->arrivalTime;//Time * 형 키
	else if (keyName == "BIRTH_DATE")
		*(Date*)pKey = this->dateOfBirth;//Date * 형 키
	else
		pKey = NULL;//아무것도 아닐시 key는 NULL
}

bool Student::operator<(const Student& s) const//학번순으로 대소비교
{
	if (st_id < s.st_id)
		return true;
	else
		return false;
}

bool Student::operator<=(const Student& s) const//학번순으로 대소비교
{
	if (st_id <= s.st_id)
		return true;
	else
		return false;
}

bool Student::operator>(const Student& s) const//학번순으로 대소비교
{
	if (st_id > s.st_id)
		return true;
	else
		return false;
}

bool Student::operator>=(const Student& s) const//학번순으로 대소비교
{
	if (st_id >= s.st_id)
		return true;
	else
		return false;
}

bool Student::operator==(const Student& s) const//학번같은지 판별
{
	if (st_id == s.st_id)
		return true;
	else
		return false;
}