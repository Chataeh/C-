#ifndef SA_H
#define SA_H
#include"Student.h"


class StudentArray
{
	friend ostream& operator<<(ostream&, const StudentArray&);
public:
	StudentArray(int size);//생성자
	StudentArray(const StudentArray& obj);
	~StudentArray();//소멸자
	int size() const { return num_students; }
	Student& operator[](int index) const;//배열생성
	void sortByBirthDate();//생일순으로 정렬
	void sortByName();//이름순 정렬
	void sortBy_ST_ID();//학번순 정렬
	void sortByGPA();//학점순 정렬
private:
	Student* students;
	int num_students;
	bool isValidIndex(int index) const;
};



#endif