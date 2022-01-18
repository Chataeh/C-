/**
*�����̸�" 21812160_������_LAB04"
*���α׷��� ���� �� �⺻ ���:
*  ������ �����ε������� ��Ŀ���
*
*���α׷� �ۼ���: 21812160 ������(2021�� 09��23��),
*���� ���� �� ����: 2021�� 9�� 23�� (������)
*/
#include<iostream>
#include<fstream>
#include<string>
#include"Mtrx.h"
#include"MtrxArray.h"

using namespace std;

#define NUM_MTRX 7

int main()
{
	ifstream fin;
	ofstream fout;

	int n_row, n_col;

	fin.open("Matrix_data.txt");//���Ͽ���
	fout.open("Result.txt");

	MtrxArray mtrx(NUM_MTRX);//��Ĺ迭 ����

	fin >> mtrx[0] >> mtrx[1] >> mtrx[2];
	mtrx[0].set_name("mtrx[0] =");
	mtrx[1].set_name("mtrx[1] =");
	mtrx[2].set_name("mtrx[2] =");

	fout << mtrx[0] << endl;
	fout << mtrx[1] << endl;
	fout << mtrx[2] << endl;

	mtrx[3] = mtrx[0] + mtrx[1];//���3=���0+���1
	mtrx[3].set_name("mtrx[3] = mtrx[0] + mtrx[1] =");
	fout << mtrx[3] << endl;
	
	mtrx[4] = mtrx[0] - mtrx[1];//���4 =���0-���1
	mtrx[4].set_name("mtrx[4] = mtrx[0] - mtrx[1] =");
	fout << mtrx[4] << endl;
	
	mtrx[5] = mtrx[0] * mtrx[2];//���5=���0*���2
	mtrx[5].set_name("mtrx[5] = mtrx[0] * mtrx[2] =");
	fout << mtrx[5] << endl;
	
	mtrx[6] = ~mtrx[5];//���6�� ���5�� ��ġ���
	mtrx[6].set_name("mtrx[6] = ~mtrx[5] (transposed matrix) =");
	fout << mtrx[6] << endl;
	
	if (mtrx[5] == mtrx[6])//������� �������
		fout << "mtrx[5] and mtrx[6] are equal.\n";
	if (mtrx[5] != mtrx[6])//�� ����� �ٸ����
		fout << "mtrx[5] and mtrx[6] are not equal.\n";
	
	fout << endl;
	mtrx[0].mtrxstatics(fout, mtrx[0]);


	fin.close();//���ϴݱ�
	fout.close();
	return 0;


}