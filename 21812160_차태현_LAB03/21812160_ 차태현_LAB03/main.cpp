/**
*�����̸�"21812160_������_LAB03"
*���α׷��� ���� �� �⺻ ���:
*  ���Ϸκ��� ��İ��� �޾ƿ� ��Ģ���� ����
*
*���α׷� �ۼ���: 21812160 ������(2021�� 09��14��),
*���� ���� �� ����: 2021�� 9�� 14�� (������)
*/
#include<iostream>
#include<fstream>
#include"Class_Mtrx.h"

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("Matrix_data.txt");//��� ����������
	fout.open("output.txt");//������

	Mtrx mtrxA(fin);//A ��� 
	mtrxA.setName("MtrxA");
	mtrxA.fprintMtrx(fout);//��� ���

	Mtrx mtrxB(fin);//B ���
	mtrxB.setName("MtrxB");
	mtrxB.fprintMtrx(fout);
	
	Mtrx mtrxC(fin);//C ���
	mtrxC.setName("MtrxC");
	mtrxC.fprintMtrx(fout);
	
	Mtrx mtrxD(mtrxA.getN_row(), mtrxB.getN_col());//D ���
	mtrxD = mtrxA.add(mtrxB);//����� ���� A+B
	mtrxD.setName("MtrxD = mtrxA.add(mtrxB)");
	mtrxD.fprintMtrx(fout);
	
	Mtrx mtrxE(mtrxA.getN_row(), mtrxB.getN_col());//E ���
	mtrxE = mtrxA.sub(mtrxB);//����� ����
	mtrxE.setName("MtrxE = mtrxA.sub(mtrxB)");
	mtrxE.fprintMtrx(fout);
	
	Mtrx mtrxF(mtrxA.getN_row(), mtrxC.getN_col());//F���
	mtrxF = mtrxA.multiply(mtrxC);//����� ����
	mtrxF.setName("MtrxF = mtrxA.multiply(mtrxC)");
	mtrxF.fprintMtrx(fout);

	Mtrx mtrxG = mtrxF.transform();
	mtrxG.setName("MtrxG= mtrxF.transform");
	mtrxG.fprintMtrx(fout);

	fout.close();
}