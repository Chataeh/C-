/**
*파일이름" 21812160_차태현_LAB04"
*프로그램의 목적 및 기본 기능:
*  연산자 오버로딩을통한 행렬연산
*
*프로그램 작성자: 21812160 차태현(2021년 09월23일),
*최종 수정 및 보완: 2021년 9월 23일 (차태현)
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

	fin.open("Matrix_data.txt");//파일열기
	fout.open("Result.txt");

	MtrxArray mtrx(NUM_MTRX);//행렬배열 생성

	fin >> mtrx[0] >> mtrx[1] >> mtrx[2];
	mtrx[0].set_name("mtrx[0] =");
	mtrx[1].set_name("mtrx[1] =");
	mtrx[2].set_name("mtrx[2] =");

	fout << mtrx[0] << endl;
	fout << mtrx[1] << endl;
	fout << mtrx[2] << endl;

	mtrx[3] = mtrx[0] + mtrx[1];//행렬3=행렬0+행렬1
	mtrx[3].set_name("mtrx[3] = mtrx[0] + mtrx[1] =");
	fout << mtrx[3] << endl;
	
	mtrx[4] = mtrx[0] - mtrx[1];//행렬4 =행렬0-행렬1
	mtrx[4].set_name("mtrx[4] = mtrx[0] - mtrx[1] =");
	fout << mtrx[4] << endl;
	
	mtrx[5] = mtrx[0] * mtrx[2];//행렬5=행렬0*행렬2
	mtrx[5].set_name("mtrx[5] = mtrx[0] * mtrx[2] =");
	fout << mtrx[5] << endl;
	
	mtrx[6] = ~mtrx[5];//행렬6은 행렬5의 전치행렬
	mtrx[6].set_name("mtrx[6] = ~mtrx[5] (transposed matrix) =");
	fout << mtrx[6] << endl;
	
	if (mtrx[5] == mtrx[6])//두행렬이 같을경우
		fout << "mtrx[5] and mtrx[6] are equal.\n";
	if (mtrx[5] != mtrx[6])//두 행렬이 다를경우
		fout << "mtrx[5] and mtrx[6] are not equal.\n";
	
	fout << endl;
	mtrx[0].mtrxstatics(fout, mtrx[0]);


	fin.close();//파일닫기
	fout.close();
	return 0;


}