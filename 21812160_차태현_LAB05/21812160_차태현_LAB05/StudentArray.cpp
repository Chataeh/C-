#include"StudentArray.h"

ostream& operator<<(ostream& fout, const StudentArray& right)//<<연산자
{
	fout << "StudentArray (size: " << right.num_students <<")" <<endl;
	
	for (int i = 0; i < right.num_students; i++)
	{
		fout << right.students[i];//학생객체 정보 출력
	}
	return fout;//fout반환
}

StudentArray::StudentArray(int size)//생성자
{
	num_students = size;//학생수 정의
	students = new Student[size];
	for (int i = 0; i < size; i++)//객체의 값들 초기화
	{
		students[i].st_id = 0;
		students[i].name = "";
		students[i].dept_name = "";
		students[i].birthDate = Date();
		students[i].gpa = 0.0;

	}
}

StudentArray::StudentArray(const StudentArray& obj)
{
	num_students = obj.num_students;
	students = new Student[num_students]; 

	for (int i = 0; i < num_students; i++)
	{
		students[i] = obj.students[i]; 
	}
}

StudentArray::~StudentArray()//소멸자
{
	if (students != NULL)//NULL값이 아닐시 동적메모리반환
		delete[]students;
}

Student& StudentArray::operator[](int index) const//객체 배열생성
{
	if (isValidIndex(index))//index값이 범위안에 들어갈 경우
		return students[index];
	else
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	
}

bool StudentArray::isValidIndex(int index) const
{
	if ((index < 0) || (index >= num_students))//index값 범위 설정
		return false;
	else
		return true;
}

void StudentArray:: sortByBirthDate()//생일순으로 정렬
{
	int min_index;
	//선택정렬

	for (int i = 0; i < NUM_STUDENTS-1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[min_index].birthDate.getElapsedDays() > students[j].birthDate.getElapsedDays())//010101부터의 날짜의 대소비교
				min_index = j;
		}
		if (min_index != i)//초기의 최소값의 인덱스가 아닐시 위치교환
			swap(students[i], students[min_index]);
	}
}

void StudentArray::sortByName()//이름 순으로 정렬
{

	int min_index;
	//선택정렬
	for (int i = 0; i < NUM_STUDENTS - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[min_index].name.compare(students[j].name )> 0)//문자열비교
				min_index = j;
		}
		if (min_index != i)//초기의 최소값의 인덱스가 아닐시 위치교환
			swap(students[i], students[min_index]);
	}

}

void StudentArray::sortBy_ST_ID()
{
	int min_index;

	//선택정렬
	for (int i = 0; i < NUM_STUDENTS - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[min_index].st_id > students[j].st_id)//학번대소비교
				min_index = j;
		}
		if (min_index != i)//초기의 최소값의 인덱스가 아닐시 위치교환
			swap(students[i], students[min_index]);
	}
}

void StudentArray::sortByGPA()
{
	int max_index;

	//선택정렬
	for (int i = 0; i < NUM_STUDENTS - 1; i++)
	{
		max_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[max_index].gpa < students[j].gpa)//학점대소비교
				max_index = j;
		}
		if (max_index != i)//초기의 최대값의 인덱스가 아닐시 위치교환
			swap(students[i], students[max_index]);
	}
}