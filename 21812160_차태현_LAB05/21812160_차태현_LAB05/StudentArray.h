#ifndef SA_H
#define SA_H
#include"Student.h"


class StudentArray
{
	friend ostream& operator<<(ostream&, const StudentArray&);
public:
	StudentArray(int size);//������
	StudentArray(const StudentArray& obj);
	~StudentArray();//�Ҹ���
	int size() const { return num_students; }
	Student& operator[](int index) const;//�迭����
	void sortByBirthDate();//���ϼ����� ����
	void sortByName();//�̸��� ����
	void sortBy_ST_ID();//�й��� ����
	void sortByGPA();//������ ����
private:
	Student* students;
	int num_students;
	bool isValidIndex(int index) const;
};



#endif