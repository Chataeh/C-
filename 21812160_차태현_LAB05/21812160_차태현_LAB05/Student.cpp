#include"Student.h"
#include"Date.h"
#include<iomanip>
ostream& operator<<(ostream& fout, const Student& right)//<<연산자
{
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	fout.setf(ios::right);
	fout.precision(2);
	
	
	fout << "Student[ st_id: " << setw(6) << right.st_id << ", name : " << setw(8) 
		<< right.name << ", dept : " << setw(5) << right.dept_name << ", birth date :"
		<< setw(4) << right.birthDate << ", GPA : " << setw(5) << right.gpa<<"]"<<endl;//학생정보 출력

	return fout;//fout출력
}

Student::Student()//생성자 
	:Person()
{
	//값 초기화
	
	st_id = 0;
	dept_name = "";
	gpa = 0.0;
}

Student::Student(int id)//생성자
{
	//학번 제외 초기화
	st_id = id;
	dept_name =" ";
	gpa = 0.0;

}

Student::Student(int id, string n, Date dob, string dept_n, double gpa)//생성자
	:Person(n, dob)
{
	//입력값으로 값 설정
	
	st_id = id;
	dept_name = dept_n;
	gpa = gpa;
}

const Student& Student::operator=(const Student& right)//대입연산자
{
	Person::operator=(right);
	st_id = right.st_id;
	//name = right.name;
	//birthDate = right.birthDate;
	dept_name = right.dept_name;
	gpa = right.gpa;

	return *this;
}

bool Student::operator>(const Student& right)//비교 연산자
{
	if (st_id > right.st_id)
		return true;
	else
		return false;
}

bool Student:: operator==(const Student& right)//객체가 같은지 비교
{
	//학번 이름 생일 학과 학점이 모두 같을시 true
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

Student genRandStudent(int id)//랜덤으로 학생정보 생성
{
	Student right;
	string name;
	string dept_name;
	Date birth;
	double gpa=0.0;

	name = genRandName();//랜덤으로 이름생성
	birth = genRandDate();//랜덤으로 생일생성
	dept_name = genRandDeptName();//랜덤으로 학과 생성
	gpa = (rand() % 10000)/100.0;//소수점 포함 gpa생성

	//생성한 값을 객체의 값으로 설정
	right.setName(name);
	right.setBirthDate(birth);
	right.setSt_id(id);
	right.setDept_name(dept_name);
	right.setGPA(gpa);
	

	return right;	

}

void genST_ids(int num_students, int* st_id)//학번생성
{
	char *flag;
	int count = 0;
	int id;

	flag = new char[50000];//중복 제거를 위한 생성

	while (count < num_students)
	{
		id = (rand() % 40000)+10001;//10000~50000사이의 학번
		if (flag[id] == 1)//중복확인
		{
			continue;
		}
		flag[id] = 1;
		st_id[count] = id;//중복이 아닐 시 값 저장
		count++;
	}
}