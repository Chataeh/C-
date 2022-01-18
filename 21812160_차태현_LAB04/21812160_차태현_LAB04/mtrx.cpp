#include<iostream>
#include<iomanip>
#include<fstream>
#include"Mtrx.h"

#define SETW 8

using namespace std;

Mtrx::Mtrx()
{

}

ostream& operator<<(ostream& fout, const Mtrx& m) //<< 연산자
{
	
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	
	fout << m.name << endl;

	//행렬형태로 출력
	for (int i = 0; i < m.n_row; i++)
	{
		for (int j = 0; j < m.n_col; j++)
		{
			fout.setf(ios::fixed);
			fout.precision(2);
			
			if ((i == 0) && (j == 0))
				fout << a6 << a3 << setw(SETW) << m.dM[i][j];
			else if ((i == 0) && (j == (m.n_col - 1)))
				fout << setw(SETW) << m.dM[i][j] << a6 << a4;
			else if ((i > 0) && (i < (m.n_row - 1)) && (j == 0))
				fout << a6 << a2 << setw(SETW) << m.dM[i][j];
			else if ((i > 0) && (i < (m.n_row - 1)) && (j == (m.n_col - 1)))
				fout << setw(SETW) << m.dM[i][j] << a6 << a2;
			else if ((i == (m.n_row - 1)) && (j == 0))
				fout << a6 << a6 << setw(SETW) << m.dM[i][j];
			else if ((i == (m.n_row - 1)) && (j == (m.n_col - 1)))
				fout << setw(SETW) << m.dM[i][j] << a6 << a5;
			else
				fout << setw(SETW) << m.dM[i][j];
		}
		fout << endl;
	}
	fout << endl;
	
	return fout;
}

istream& operator>>(istream& fin, Mtrx& m)//>>연산자
{
	
	int size_r, size_c;
	double data;
	//파일로 부터 행열 크기 받아오기
	fin >>size_r >> size_c;

	m.n_row = size_r;
	m.n_col = size_c;
	//2차원 동적배열생성
	m.dM = new double* [m.n_row];
	for (int i = 0; i <m.n_row; i++)
	{
		m.dM[i] = new double[m.n_col];
	}
	for (int i = 0; i < m.n_row; i++)
	{
		for (int j = 0; j < m.n_col; j++)
		{
			if (fin.eof())//파일의 끝일시 나머지0.0으로설정
				m.dM[i][j] = 0.0;
			else {//파일의 끝이아니면 데이터 받아오기
				fin >> data;
				m.dM[i][j] = data;
			}

		}
	}
	return fin;
}

Mtrx::Mtrx(string nm, int num_row, int num_col)//생성자

{
	name = nm;
	n_row = num_row;
	n_col = num_col;
	//2차원 배열 생성
	dM = new double* [n_row];
	for (int i = 0; i < n_row; i++)
	{
		dM[i] = new double[n_col];
	}
	//행렬 초기화
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
			dM[i][j] = 0.0;
	}

}

Mtrx::~Mtrx()//소멸자
{
	/*for (int i = 0; i < n_row; i++)
		delete[]dM[i];
	delete[] dM;*/
}

void Mtrx::init(int n_row, int n_col)//2차원 동적배열 생성 후 초기화
{
	Mtrx m;
	//2차원 동적배열 생성
	m.dM = new double* [n_row];
	for (int i = 0; i < n_row; i++)
	{
		m.dM[i] = new double[n_col];
	}
	//초기화
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			m.dM[i][j] = 0.0;
		}
	}
}

const Mtrx Mtrx ::operator+(const Mtrx& m)//행렬의 덧셈
{
	int i, j;

	Mtrx mR("mR", n_row, n_col);//클래스 생성

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = dM[i][j] + m.dM[i][j];//행렬의 덧셈
		}
	}
	return mR;
}

const Mtrx Mtrx ::operator-(const Mtrx& m)//행렬의 뺄셈
{
	int i, j;

	Mtrx mR("mR", n_row, n_col);//클래스 생성

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = dM[i][j] - m.dM[i][j];//행렬의 뺄셈
		}
	}
	return mR;
}
const Mtrx Mtrx ::operator~()//치환행렬
{
	int i, j;
	
	Mtrx mR("mR", n_row,n_col);//클래스생성

	for (int i = 0; i < n_col; i++)
	{
		for (j = 0; j < mR.n_row; j++)
			mR.dM[j][i] = dM[i][j];//행렬 위치교환해서 저장
	}
	return mR;
}


const Mtrx Mtrx ::operator*(const Mtrx& m)//행렬의 곱셈
{
	int i, j;

	Mtrx mR("mR", n_row,m.n_col);

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j <m.n_col; j++)
		{
			mR.dM[i][j] = 0.0;
			for (int k = 0; k < n_col; k++)
			{
				mR.dM[i][j] += dM[i][k] * m.dM[k][j];
			}
		}
	}
	return mR;
}

const Mtrx Mtrx::operator=(const Mtrx&m)
{
	this->name = m.name;
	this->n_row = m.n_row;
	this->n_col = m.n_col;
	this->dM = m.dM;


	return *this;
}


bool Mtrx::operator ==(const Mtrx&m)
{
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			if (dM[i][j] != m.dM[i][j])//행렬이 다를경우 false
				return false;
			
		}
	}
	return true;
}

bool Mtrx::operator !=(const Mtrx& m)
{
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			if (dM[i][j] != m.dM[i][j])//행렬이 다른경우 ture
				return true;
			
		}
	}
	return false;
}

void Mtrx::mtrxstatics(ostream& fout,const Mtrx& m)
{
	Mtrx mR("mR", m.n_row+1, m.n_col+1);//행렬크기 확장 생성

	int n_row = m.n_row;
	int n_col = m.n_col;

	double sum = 0.0, avg = 0.0, sq_sum_avg = 0.0, diff_sq_sum = 0.0, std_dev = 0.0, var = 0.0;
	int size = n_row * n_col;

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = m.dM[i][j];
			mR.dM[n_row][j] += m.dM[i][j];//새로 추가한 마지막 행에 덧셈값추가
			mR.dM[i][n_col] += m.dM[i][j];//추가한 열에 덧셈추가
			sum += m.dM[i][j];//행렬 전체의 합
		}
	}
	mR.dM[n_row][n_col] = sum;//모든 행렬의 합
	avg = sum / size;

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			sq_sum_avg += (m.dM[i][j] - avg) * (m.dM[i][j] - avg);
		}
	}
	var = sq_sum_avg / size;
	std_dev = sqrt(var);

	fout << mR;

	fout << "avg :" << avg << "var : " << var << "std_dev : " << std_dev;
}