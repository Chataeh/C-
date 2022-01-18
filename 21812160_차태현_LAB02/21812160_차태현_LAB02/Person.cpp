#include"Person.h"
#define NUM_PERSON 10
void Person::setRandPersonAttributes()
{
	
	char str[MAX_NAME_LEN + 1];
	int len, i;
	birthDate.setRandDateAttributes();//������� ��������
	len = rand() % (MAX_NAME_LEN - MIN_NAME_LEN) + MIN_NAME_LEN;//�̸����̼���
	str[0] = rand() % 26 + 'A';//�̸�ù���� �빮�� ����
	for (i = 1; i < len; i++)
	{
		str[i] = rand() % 26 + 'a';//�ι�°���ں��� �ҹ���
	}
	str[len] = '\0';
	name = string(str);//�̸�����

}

void Person::fprintPerson(ostream& fout)
{
	fout << "Person [name:";
	fout.setf(ios::left);//��������
	fout << setw(16) << name;
	fout << ",birth date:";
	fout.unsetf(ios::left);//������������
	birthDate.fprintDate(fout);//��¥���
	fout << "]";
}

void Person::sortname(Person* persons)//�̸������� ��������
{
	int i, j;
	int min_index;
	
	for (int i = 0; i < NUM_PERSON - 1; i++)
	{
		min_index = i;//�ʱ��ּ���ġ ����
		
		for (j = i + 1; j < NUM_PERSON; j++)
		{
			if (persons[min_index].name.compare(persons[j].name)>0)
			{
				min_index =j;//���ο�� �������� �ּ���ġ ��ȯ
			}
		}
		if (min_index != i)
		{
			swap(persons[i],persons[min_index]);//�ڸ���ȯ
		}
	}
}

void Person::sortbirthday(Person* persons)//���ϼ����� ��������
{
	int i, j;
	int min_index;
	
	for (int i = 0; i < NUM_PERSON - 1; i++)
	{
		min_index = i;//�ʱ��ּ���ġ ����
		for (j = i + 1; j < NUM_PERSON; j++)
		{
			if (persons[j].birthDate.getElapsedDaysFromAD010101() < persons[min_index].birthDate.getElapsedDaysFromAD010101())//���ϱ����� �ѳ�¥ ���̸� ���� �ּҰ�����
			{
				min_index = j;//���ο�� �������� �ּ���ġ ��ȯ
			}

		}
		if (min_index != i)
		{
			swap(persons[i], persons[min_index]);//�ڸ���ȯ
		}
	}

}