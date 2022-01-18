#include"Student.h"
#include"Date.h"
#include<iomanip>
ostream& operator<<(ostream& fout, const Student& right)//<<������
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.setf(ios::right);
	fout.precision(2);
	
	
	fout << "Student[ st_id: " << setw(6) << right.st_id << ", name : " << setw(8) 
		<< right.name << ", dept : " << setw(5) << right.dept_name << ", birth date :"
		<< setw(4) << right.birthDate << ", GPA : " << setw(5) << right.gpa<<"]"<<endl;//�л����� ���

	return fout;//fout���
}

Student::Student()//������ 
	:Person()
{
	//�� �ʱ�ȭ
	
	st_id = 0;
	dept_name = "";
	gpa = 0.0;
}

Student::Student(int id)//������
{
	//�й� ���� �ʱ�ȭ
	st_id = id;
	dept_name =" ";
	gpa = 0.0;

}

Student::Student(int id, string n, Date dob, string dept_n, double gpa)//������
	:Person(n, dob)
{
	//�Է°����� �� ����
	
	st_id = id;
	dept_name = dept_n;
	gpa = gpa;
}

const Student& Student::operator=(const Student& right)//���Կ�����
{
	Person::operator=(right);
	st_id = right.st_id;
	//name = right.name;
	//birthDate = right.birthDate;
	dept_name = right.dept_name;
	gpa = right.gpa;

	return *this;
}

bool Student::operator>(const Student& right)//�� ������
{
	if (st_id > right.st_id)
		return true;
	else
		return false;
}

bool Student:: operator==(const Student& right)//��ü�� ������ ��
{
	//�й� �̸� ���� �а� ������ ��� ������ true
	if (st_id != right.st_id)
		return false;
	else if (name != right.name)
		return false;
	else if (birthDate != right.birthDate)
		return false;
	else if (dept_name != right.dept_name)
		return false;
	else if (gpa != right.gpa)
		return false;
	else
		return true;
	
}

Student genRandStudent(int id)//�������� �л����� ����
{
	Student right;
	string name;
	string dept_name;
	Date birth;
	double gpa=0.0;

	name = genRandName();//�������� �̸�����
	birth = genRandDate();//�������� ���ϻ���
	dept_name = genRandDeptName();//�������� �а� ����
	gpa = (rand() % 10000)/100.0;//�Ҽ��� ���� gpa����

	//������ ���� ��ü�� ������ ����
	right.setName(name);
	right.setBirthDate(birth);
	right.setSt_id(id);
	right.setDept_name(dept_name);
	right.setGPA(gpa);
	

	return right;	

}

void genST_ids(int num_students, int* st_id)//�й�����
{
	char *flag;
	int count = 0;
	int id;

	flag = new char[50000];//�ߺ� ���Ÿ� ���� ����

	while (count < num_students)
	{
		id = (rand() % 40000)+10001;//10000~50000������ �й�
		if (flag[id] == 1)//�ߺ�Ȯ��
		{
			continue;
		}
		flag[id] = 1;
		st_id[count] = id;//�ߺ��� �ƴ� �� �� ����
		count++;
	}
}