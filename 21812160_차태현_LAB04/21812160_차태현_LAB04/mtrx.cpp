#include<iostream>
#include<iomanip>
#include<fstream>
#include"Mtrx.h"

#define SETW 8

using namespace std;

Mtrx::Mtrx()
{

}

ostream& operator<<(ostream& fout, const Mtrx& m) //<< ������
{
	
	unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;
	
	fout << m.name << endl;

	//������·� ���
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

istream& operator>>(istream& fin, Mtrx& m)//>>������
{
	
	int size_r, size_c;
	double data;
	//���Ϸ� ���� �࿭ ũ�� �޾ƿ���
	fin >>size_r >> size_c;

	m.n_row = size_r;
	m.n_col = size_c;
	//2���� �����迭����
	m.dM = new double* [m.n_row];
	for (int i = 0; i <m.n_row; i++)
	{
		m.dM[i] = new double[m.n_col];
	}
	for (int i = 0; i < m.n_row; i++)
	{
		for (int j = 0; j < m.n_col; j++)
		{
			if (fin.eof())//������ ���Ͻ� ������0.0���μ���
				m.dM[i][j] = 0.0;
			else {//������ ���̾ƴϸ� ������ �޾ƿ���
				fin >> data;
				m.dM[i][j] = data;
			}

		}
	}
	return fin;
}

Mtrx::Mtrx(string nm, int num_row, int num_col)//������

{
	name = nm;
	n_row = num_row;
	n_col = num_col;
	//2���� �迭 ����
	dM = new double* [n_row];
	for (int i = 0; i < n_row; i++)
	{
		dM[i] = new double[n_col];
	}
	//��� �ʱ�ȭ
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
			dM[i][j] = 0.0;
	}

}

Mtrx::~Mtrx()//�Ҹ���
{
	/*for (int i = 0; i < n_row; i++)
		delete[]dM[i];
	delete[] dM;*/
}

void Mtrx::init(int n_row, int n_col)//2���� �����迭 ���� �� �ʱ�ȭ
{
	Mtrx m;
	//2���� �����迭 ����
	m.dM = new double* [n_row];
	for (int i = 0; i < n_row; i++)
	{
		m.dM[i] = new double[n_col];
	}
	//�ʱ�ȭ
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			m.dM[i][j] = 0.0;
		}
	}
}

const Mtrx Mtrx ::operator+(const Mtrx& m)//����� ����
{
	int i, j;

	Mtrx mR("mR", n_row, n_col);//Ŭ���� ����

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = dM[i][j] + m.dM[i][j];//����� ����
		}
	}
	return mR;
}

const Mtrx Mtrx ::operator-(const Mtrx& m)//����� ����
{
	int i, j;

	Mtrx mR("mR", n_row, n_col);//Ŭ���� ����

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = dM[i][j] - m.dM[i][j];//����� ����
		}
	}
	return mR;
}
const Mtrx Mtrx ::operator~()//ġȯ���
{
	int i, j;
	
	Mtrx mR("mR", n_row,n_col);//Ŭ��������

	for (int i = 0; i < n_col; i++)
	{
		for (j = 0; j < mR.n_row; j++)
			mR.dM[j][i] = dM[i][j];//��� ��ġ��ȯ�ؼ� ����
	}
	return mR;
}


const Mtrx Mtrx ::operator*(const Mtrx& m)//����� ����
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
			if (dM[i][j] != m.dM[i][j])//����� �ٸ���� false
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
			if (dM[i][j] != m.dM[i][j])//����� �ٸ���� ture
				return true;
			
		}
	}
	return false;
}

void Mtrx::mtrxstatics(ostream& fout,const Mtrx& m)
{
	Mtrx mR("mR", m.n_row+1, m.n_col+1);//���ũ�� Ȯ�� ����

	int n_row = m.n_row;
	int n_col = m.n_col;

	double sum = 0.0, avg = 0.0, sq_sum_avg = 0.0, diff_sq_sum = 0.0, std_dev = 0.0, var = 0.0;
	int size = n_row * n_col;

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = m.dM[i][j];
			mR.dM[n_row][j] += m.dM[i][j];//���� �߰��� ������ �࿡ �������߰�
			mR.dM[i][n_col] += m.dM[i][j];//�߰��� ���� �����߰�
			sum += m.dM[i][j];//��� ��ü�� ��
		}
	}
	mR.dM[n_row][n_col] = sum;//��� ����� ��
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