#include"Person.h"

ostream& operator<<(ostream& fout, const Person& rightSide)//<<������ 
{
	fout << "name : " << rightSide.name;//�̸����

	return fout;//fout ��ȯ
}

const Person& Person::operator=(const Person& right)//���Կ�����
{
	name = right.name;
	birthDate = right.birthDate;
	

	return *this;
}