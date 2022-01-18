#include"Mystring.h"

#define MAX_NAME_LEN 8
#define MIN_NAME_LEN 4
#define MAX_Dept_LEN 5
#define MIN_Dept_LEN 3

string genRandName()
{
	string name;
	char str[MAX_NAME_LEN+1]="";
	int len;

	len = rand() % (MAX_NAME_LEN - MIN_NAME_LEN) + MIN_NAME_LEN;//이름 길이설정 4~7
	str[0] = rand() % 26 + 'A';//첫글자만 대문자

	for (int i = 1; i < len; i++)
	{
		str[i] = rand() % 26 + 'a';//나머지는 소문자
	}
	str[len] = NULL;
	
	name = string(str);//string으로 저장

	return name;
}
string genRandDeptName() 
{
	string name;
	char str[MAX_Dept_LEN + 1]="";
	int len;

	len = rand() % (MAX_Dept_LEN - MIN_Dept_LEN) + MIN_Dept_LEN;//학과코드 설정 3~4개
	for (int i = 0; i < len; i++)
	{
		str[i] = rand() % 26 + 'A';//대문자로만 설정
	}
	str[len] = NULL;

	name = string(str);//string으로 저장

	return name;
}
