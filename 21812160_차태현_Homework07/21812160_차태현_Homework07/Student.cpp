#include"Student.h"
#include<iomanip>

ostream& operator <<(ostream& cout, Student& s)//<<������ ��±��
{
	cout << "Studnet [ st_id:" << setw(6) << s.st_id << ", name: " << setw(10) << s.name<<", date_of_birth:"<<setw(2)<<s.dateOfBirth
		<< ", arrival: " << s.arrivalTime << ", gpa: " << setw(4) << s.gpa << "]";

	return cout;//cout��ȯ
}

Student::Student()//default ������
	:Person(), st_id(0), gpa(0.0)
{

}

Student::Student(int s_id, string n,Date dob,  Time avt, double gpa)//������
	: Person(n), st_id(s_id), gpa(gpa)
{
	dateOfBirth = dob;
	arrivalTime = avt;
}


bool Student::operator<(const Student& s) const//�����ð� ������ ��Һ�
{
	if (arrivalTime.elasedSec() < s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator<=(const Student& s) const//�����ð� ������ ��Һ�
{
	if(arrivalTime.elasedSec() <=s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator>(const Student& s) const//�����ð������� ��Һ�
{
	if (arrivalTime.elasedSec() > s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator>=(const Student& s) const//�����ð������� ��Һ�
{
	if (arrivalTime.elasedSec() >= s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}

bool Student::operator==(const Student& s) const//�����ð������� �Ǻ�
{
	if (arrivalTime.elasedSec() == s.arrivalTime.elasedSec())
		return true;
	else
		return false;
}