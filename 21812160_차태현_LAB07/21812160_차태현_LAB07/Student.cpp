#include"Student.h"
#include<iomanip>

ostream& operator <<(ostream& cout, Student& s)//<<������ ��±��
{
	cout << "Studnet [ st_id:" << setw(6) << s.st_id << ", name: " << setw(9) <<s.name<< ", gpa: " << setw(4) << s.gpa << " , date_of_birth: " << s.dateOfBirth
		<< ", arrival: " << s.arrivalTime << "]" ;

	return cout;//cout��ȯ
}

Student::Student()//default ������
	:Person(),st_id(0),gpa(0.0)
{

}

Student::Student(int s_id, string n, Date dob, Time avt, double gpa)//������
	:Person(n),st_id(s_id),gpa(gpa)
{
	dateOfBirth = dob;
	arrivalTime = avt;
}

void Student::getKey(string keyName, void* pKey)//Ű����
{
	//pKey�� keyName �� ������
	if (keyName == "ST_ID")
		*(int*)pKey = this->st_id;//int*�� Ű
	else if (keyName == "ST_NAME")
		*(string*)pKey = this->name;//string* �� Ű
	else if (keyName == "GPA")
		*(double*)pKey = this->gpa;//double * �� Ű
	else if (keyName == "ARRIVAL_TIME")
		*(Time*)pKey = this->arrivalTime;//Time * �� Ű
	else if (keyName == "BIRTH_DATE")
		*(Date*)pKey = this->dateOfBirth;//Date * �� Ű
	else
		pKey = NULL;//�ƹ��͵� �ƴҽ� key�� NULL
}

bool Student::operator<(const Student& s) const//�й������� ��Һ�
{
	if (st_id < s.st_id)
		return true;
	else
		return false;
}

bool Student::operator<=(const Student& s) const//�й������� ��Һ�
{
	if (st_id <= s.st_id)
		return true;
	else
		return false;
}

bool Student::operator>(const Student& s) const//�й������� ��Һ�
{
	if (st_id > s.st_id)
		return true;
	else
		return false;
}

bool Student::operator>=(const Student& s) const//�й������� ��Һ�
{
	if (st_id >= s.st_id)
		return true;
	else
		return false;
}

bool Student::operator==(const Student& s) const//�й������� �Ǻ�
{
	if (st_id == s.st_id)
		return true;
	else
		return false;
}