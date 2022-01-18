#include"Person.h"

ostream& operator<<(ostream& fout, const Person& rightSide)//<<연산자 
{
	fout << "name : " << rightSide.name;//이름출력

	return fout;//fout 반환
}

const Person& Person::operator=(const Person& right)//대입연산자
{
	name = right.name;
	birthDate = right.birthDate;
	

	return *this;
}