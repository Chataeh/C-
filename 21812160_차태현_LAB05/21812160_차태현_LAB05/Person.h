#ifndef P_H
#define P_H
#include"Date.h"

class Person
{
	friend ostream& operator<<(ostream&, const Person&);//<<������
public:
	Person() { birthDate = Date(1, 1, 1); name = ""; };//������ 0���� �ʱ�ȭ
	Person(string nm, Date bd) { birthDate = bd; name = nm; };//������
	void setName(string n) { name = n; }//�̸� ����
	void setBirthDate(Date bd) { birthDate = bd; }//���� ����
	string getName()const { return name; }//�̸� ��ȯ
	Date getBirthDate() const { return birthDate; }//���� ��ȯ
	const Person& operator =(const Person& right);
protected://�ڽ�Ŭ�������� ��밡��
	Date birthDate;//����
	string name;//�̸�
};

#endif 
