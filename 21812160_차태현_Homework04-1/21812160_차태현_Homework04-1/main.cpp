/**
*�����̸�"21812160_������_Homework04-1 "
*���α׷��� ���� �� �⺻ ���:
*  ���Ϸκ��� ���Ҽ��� �޾ƿ� ��Ģ������ �ϴ� ���α׷�.
*
*���α׷� �ۼ���: 21812160 ������(2021�� 09��24��),
*���� ���� �� ����: 2021�� 9�� 24�� (������)
*/
#include<iostream>
#include<fstream>
#include"Cmplx.h"
#include"CmplxArray.h"

using namespace std;

int main()
{
	
	ifstream fin;

	CmplxArray cmplxs(7);//7���� ���Ҽ� �迭����

	fin.open("input.txt");//���Ͽ���

	fin >> cmplxs[0] >> cmplxs[1];//���Ϸ� ������ ���Ҽ� �޾ƿ���

	cmplxs[2] = cmplxs[0] + cmplxs[1];//���Ҽ��� ����
	cmplxs[3] = cmplxs[0] - cmplxs[1];//���Ҽ��� ����
	cmplxs[4] = cmplxs[0] * cmplxs[1];//���Ҽ��� ����
	cmplxs[5] = cmplxs[0] / cmplxs[1];//���Ҽ��� ������
	cmplxs[6] = ~cmplxs[0] ;//�ӷ����Ҽ�

	//���Ҽ� ���
	cout << "cmplxs[0] = " << cmplxs[0] << endl;
	cout << "cmplxs[1] = " << cmplxs[1] << endl;
	cout<< "cmplxs[2] = cmplxs[0] + cmplxs[1]= "<<cmplxs[2]<< endl;
	cout << "cmplxs[3] = cmplxs[0] - cmplxs[1]= " << cmplxs[3] << endl;
	cout << "cmplxs[4] = cmplxs[0] * cmplxs[1]= " << cmplxs[4] << endl;
	cout << "cmplxs[5] = cmplxs[0] / cmplxs[1]= " << cmplxs[5] << endl;
	cout << "cmplxs[6] = ~cmplxs[0] (coniugate)" << cmplxs[6] << endl;

	if (cmplxs[0] == cmplxs[1])//���Ϸ� �־��� �� ���Ҽ��� ������ �Ǻ�
	{
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	}
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;

	cmplxs[1] = cmplxs[0];//���Ϸ� �޾ƿ� ���Ҽ��� ���� ����
	cout << "After cmplxs[1]==cmplxs[0];==>"<<endl;

	if (cmplxs[0] == cmplxs[1])//���Ϸ� �־��� �� ���Ҽ��� ������ �Ǻ�
	{
		cout << "cmplxs[0] is equal to cmplxs[1]" << endl;
	}
	else
		cout << "cmplxs[0] is not equal to cmplxs[1]" << endl;

	fin.close();//���ϴݱ�
}