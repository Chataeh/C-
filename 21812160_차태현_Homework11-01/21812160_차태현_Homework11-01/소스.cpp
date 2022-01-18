/**
*�����̸�"21812160_������_Homework11-01"
*���α׷��� ���� �� �⺻ ���:
*
*
*���α׷� �ۼ���: 21812160 ������(2021�� 11��21��),
*���� ���� �� ����: 2021�� 11�� 21�� (������)
*/
#include<iostream>
#include<string>


using namespace std;

#define BIT_SHIFTS 5
#define BITS_INT 32
#define BIT_SHIFTS 5
#define BITS_INT 32
#define NUM_MY_TOEIC_VOCA 20

int CyclicShiftHash(const string key);
int main()
{
	
	const string str[] = { "prescribe","regulate","prescribe","regulate", "plentiful","ample","lavish" ,"busy","decorated","refined" ,
	"detailed","careful" ,"burden","abstain" ,"melody","theme","force","necessitate","obilge","inevitable" };

	int h = 0;
	for (int i = 0; i < NUM_MY_TOEIC_VOCA; i++)
	{
		h=CyclicShiftHash(str[i]);
		cout <<"Key Value ["<< h <<"]"<< endl;
	}
}


int CyclicShiftHash(const string key)
{
	
	int len = key.length();//���̼���
	unsigned int h = 0;//32��Ʈ�� ����
	for (int i = 0; i < len; i++)//���ڿ� ���̸�ŭ �ݺ�
	{
		h = (h << BIT_SHIFTS) | (h >> (BITS_INT - BIT_SHIFTS));//(h �������� 5��ŭ�̵�) or���� (h ���������� 27���̵�)
		h += (unsigned int)key.at(i);//i��° ��ġ ���ڰ� ������
	}
	return h%64;
}