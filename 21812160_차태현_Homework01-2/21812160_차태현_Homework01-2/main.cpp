/**
*�����̸�"21812160_������_Homework-01-2"
*���α׷��� ���� �� �⺻ ���:
*  1~32������ ���� 10���� 8���� 16���� 2������ ���
*
*���α׷� �ۼ���: 21812160 ������(2021�� 9��2��),
*���� ���� �� ����: 2021�� 9�� 2�� (������)
*/
#include<iostream>
#include<iomanip>
#include<bitset>
#define NUM 33

using namespace std;

int main()
{

	for (int i = 0; i < NUM; i++)//32�� �ݺ�
	{
		cout.setf(ios::showbase);//������ ������� ǥ��
		cout.setf(ios::right);//������ �� ����
		cout.setf(ios::uppercase);//�빮�� ���
		cout << setw(10) << dec<<i << setw(10) << oct<<i <<setw(10) << hex <<i<< setw(10) <<  bitset<8>(i) << endl;
	}

}