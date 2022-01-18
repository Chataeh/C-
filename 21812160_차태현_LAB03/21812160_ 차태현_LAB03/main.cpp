/**
*파일이름"21812160_차태현_LAB03"
*프로그램의 목적 및 기본 기능:
*  파일로부터 행렬값을 받아와 사칙연산 실행
*
*프로그램 작성자: 21812160 차태현(2021년 09월14일),
*최종 수정 및 보완: 2021년 9월 14일 (차태현)
*/
#include<iostream>
#include<fstream>
#include"Class_Mtrx.h"

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;

	fin.open("Matrix_data.txt");//행렬 데이터파일
	fout.open("output.txt");//결과출력

	Mtrx mtrxA(fin);//A 행렬 
	mtrxA.setName("MtrxA");
	mtrxA.fprintMtrx(fout);//행렬 출력

	Mtrx mtrxB(fin);//B 행렬
	mtrxB.setName("MtrxB");
	mtrxB.fprintMtrx(fout);
	
	Mtrx mtrxC(fin);//C 행렬
	mtrxC.setName("MtrxC");
	mtrxC.fprintMtrx(fout);
	
	Mtrx mtrxD(mtrxA.getN_row(), mtrxB.getN_col());//D 행렬
	mtrxD = mtrxA.add(mtrxB);//행렬의 덧셈 A+B
	mtrxD.setName("MtrxD = mtrxA.add(mtrxB)");
	mtrxD.fprintMtrx(fout);
	
	Mtrx mtrxE(mtrxA.getN_row(), mtrxB.getN_col());//E 행렬
	mtrxE = mtrxA.sub(mtrxB);//행렬의 뺄셈
	mtrxE.setName("MtrxE = mtrxA.sub(mtrxB)");
	mtrxE.fprintMtrx(fout);
	
	Mtrx mtrxF(mtrxA.getN_row(), mtrxC.getN_col());//F행렬
	mtrxF = mtrxA.multiply(mtrxC);//행렬의 곱셈
	mtrxF.setName("MtrxF = mtrxA.multiply(mtrxC)");
	mtrxF.fprintMtrx(fout);

	Mtrx mtrxG = mtrxF.transform();
	mtrxG.setName("MtrxG= mtrxF.transform");
	mtrxG.fprintMtrx(fout);

	fout.close();
}