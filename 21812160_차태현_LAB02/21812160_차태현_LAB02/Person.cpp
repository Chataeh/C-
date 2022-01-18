#include"Person.h"
#define NUM_PERSON 10
void Person::setRandPersonAttributes()
{
	
	char str[MAX_NAME_LEN + 1];
	int len, i;
	birthDate.setRandDateAttributes();//생년월일 랜덤설정
	len = rand() % (MAX_NAME_LEN - MIN_NAME_LEN) + MIN_NAME_LEN;//이름길이설정
	str[0] = rand() % 26 + 'A';//이름첫글자 대문자 설정
	for (i = 1; i < len; i++)
	{
		str[i] = rand() % 26 + 'a';//두번째글자부턴 소문자
	}
	str[len] = '\0';
	name = string(str);//이름정의

}

void Person::fprintPerson(ostream& fout)
{
	fout << "Person [name:";
	fout.setf(ios::left);//왼쪽정렬
	fout << setw(16) << name;
	fout << ",birth date:";
	fout.unsetf(ios::left);//왼쪽정렬해제
	birthDate.fprintDate(fout);//날짜출력
	fout << "]";
}

void Person::sortname(Person* persons)//이름순으로 선택정렬
{
	int i, j;
	int min_index;
	
	for (int i = 0; i < NUM_PERSON - 1; i++)
	{
		min_index = i;//초기최소위치 설정
		
		for (j = i + 1; j < NUM_PERSON; j++)
		{
			if (persons[min_index].name.compare(persons[j].name)>0)
			{
				min_index =j;//새로운값이 더작을시 최소위치 변환
			}
		}
		if (min_index != i)
		{
			swap(persons[i],persons[min_index]);//자리교환
		}
	}
}

void Person::sortbirthday(Person* persons)//생일순으로 선택정렬
{
	int i, j;
	int min_index;
	
	for (int i = 0; i < NUM_PERSON - 1; i++)
	{
		min_index = i;//초기최소위치 설정
		for (j = i + 1; j < NUM_PERSON; j++)
		{
			if (persons[j].birthDate.getElapsedDaysFromAD010101() < persons[min_index].birthDate.getElapsedDaysFromAD010101())//생일까지의 총날짜 차이를 통해 최소값구함
			{
				min_index = j;//새로운값이 더작을시 최소위치 변환
			}

		}
		if (min_index != i)
		{
			swap(persons[i], persons[min_index]);//자리교환
		}
	}

}