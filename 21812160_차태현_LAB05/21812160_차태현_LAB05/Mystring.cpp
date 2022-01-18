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

	len = rand() % (MAX_NAME_LEN - MIN_NAME_LEN) + MIN_NAME_LEN;//�̸� ���̼��� 4~7
	str[0] = rand() % 26 + 'A';//ù���ڸ� �빮��

	for (int i = 1; i < len; i++)
	{
		str[i] = rand() % 26 + 'a';//�������� �ҹ���
	}
	str[len] = NULL;
	
	name = string(str);//string���� ����

	return name;
}
string genRandDeptName() 
{
	string name;
	char str[MAX_Dept_LEN + 1]="";
	int len;

	len = rand() % (MAX_Dept_LEN - MIN_Dept_LEN) + MIN_Dept_LEN;//�а��ڵ� ���� 3~4��
	for (int i = 0; i < len; i++)
	{
		str[i] = rand() % 26 + 'A';//�빮�ڷθ� ����
	}
	str[len] = NULL;

	name = string(str);//string���� ����

	return name;
}
