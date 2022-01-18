#include"StudentArray.h"

ostream& operator<<(ostream& fout, const StudentArray& right)//<<������
{
	fout << "StudentArray (size: " << right.num_students <<")" <<endl;
	
	for (int i = 0; i < right.num_students; i++)
	{
		fout << right.students[i];//�л���ü ���� ���
	}
	return fout;//fout��ȯ
}

StudentArray::StudentArray(int size)//������
{
	num_students = size;//�л��� ����
	students = new Student[size];
	for (int i = 0; i < size; i++)//��ü�� ���� �ʱ�ȭ
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

StudentArray::~StudentArray()//�Ҹ���
{
	if (students != NULL)//NULL���� �ƴҽ� �����޸𸮹�ȯ
		delete[]students;
}

Student& StudentArray::operator[](int index) const//��ü �迭����
{
	if (isValidIndex(index))//index���� �����ȿ� �� ���
		return students[index];
	else
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	
}

bool StudentArray::isValidIndex(int index) const
{
	if ((index < 0) || (index >= num_students))//index�� ���� ����
		return false;
	else
		return true;
}

void StudentArray:: sortByBirthDate()//���ϼ����� ����
{
	int min_index;
	//��������

	for (int i = 0; i < NUM_STUDENTS-1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[min_index].birthDate.getElapsedDays() > students[j].birthDate.getElapsedDays())//010101������ ��¥�� ��Һ�
				min_index = j;
		}
		if (min_index != i)//�ʱ��� �ּҰ��� �ε����� �ƴҽ� ��ġ��ȯ
			swap(students[i], students[min_index]);
	}
}

void StudentArray::sortByName()//�̸� ������ ����
{

	int min_index;
	//��������
	for (int i = 0; i < NUM_STUDENTS - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[min_index].name.compare(students[j].name )> 0)//���ڿ���
				min_index = j;
		}
		if (min_index != i)//�ʱ��� �ּҰ��� �ε����� �ƴҽ� ��ġ��ȯ
			swap(students[i], students[min_index]);
	}

}

void StudentArray::sortBy_ST_ID()
{
	int min_index;

	//��������
	for (int i = 0; i < NUM_STUDENTS - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[min_index].st_id > students[j].st_id)//�й���Һ�
				min_index = j;
		}
		if (min_index != i)//�ʱ��� �ּҰ��� �ε����� �ƴҽ� ��ġ��ȯ
			swap(students[i], students[min_index]);
	}
}

void StudentArray::sortByGPA()
{
	int max_index;

	//��������
	for (int i = 0; i < NUM_STUDENTS - 1; i++)
	{
		max_index = i;
		for (int j = i + 1; j < NUM_STUDENTS; j++)
		{
			if (students[max_index].gpa < students[j].gpa)//������Һ�
				max_index = j;
		}
		if (max_index != i)//�ʱ��� �ִ밪�� �ε����� �ƴҽ� ��ġ��ȯ
			swap(students[i], students[max_index]);
	}
}