#include "Mtrx.h"
#include <iomanip>

Mtrx::Mtrx(int num_row, int num_col)//������
{
	int i, j;

	n_row = num_row;
	n_col = num_col;

	//2���� �����迭 ����
	dM = new double* [n_row];

	for (i = 0; i < n_row; i++)
	{
		dM[i] = new double[n_col];
	}

	for (i = 0; i < n_row; i++)
	{
		for (j = 0; j < n_col; j++)
		{
			dM[i][j] = 0.0;
		}
	}

}

Mtrx::~Mtrx()
{
	/*for (int i = 0; i < n_row; i++)
		delete[] dM[i];
	delete[] dM;
	*/
}

Mtrx::Mtrx(istream& fin)
{
	int i, j, size_row, size_col;
	double data;

	fin >> size_row >> size_col;//���Ϸκ��� ��� ũ�� �޾ƿ���

	n_row = size_row;
	n_col = size_col;

	//2���� �����迭 ����
	dM = new double* [n_row];

	for (i = 0; i < n_row; i++)
	{
		dM[i] = new double[n_col];
	}

	for (i = 0; i < n_row; i++)
	{
		for (j = 0; j < n_col; j++)
		{
			if (fin.eof())//������ ���ϰ��
				dM[i][j] = 0.0;//������ �ڸ��� 0.0
			else
			{
				fin >> data;//���Ͽ��� ������ �޾ƿ���
				dM[i][j] = data;
			}
		}
	}
}

#define SETW 8
void Mtrx::fprintMtrx(ostream& fout)//���ĵ� ������·� ���
{
	unsigned char a6 = 0XA6, a1 = 0xA1, a2 = 0xA2;
	unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5;

	fout << name << "=" << endl;
	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			fout.setf(ios::fixed);
			fout.precision(2);
			//���ĵ� ��ĸ�������� Ȯ�������
			if ((i == 0) && (j == 0))
				fout << a6 << a3 << setw(SETW) << dM[i][j];
			else if ((i == 0) && (j == n_col - 1))
				fout << setw(SETW) << dM[i][j] << a6 << a4;
			else if ((i > 0) && (i < n_row - 1) && (j == 0))
				fout << a6 << a2 << setw(SETW) << dM[i][j];
			else if ((i > 0) && (i < n_row - 1) && (j == n_col - 1))
				fout << setw(SETW) << dM[i][j] << a6 << a2;
			else if ((i == n_row - 1) && (j == 0))
				fout << a6 << a6 << setw(SETW) << dM[i][j];
			else if ((i == n_row - 1) && (j == n_col - 1))
				fout << setw(SETW) << dM[i][j] << a6 << a5;
			else
				fout << setw(SETW) << dM[i][j];
		}
		fout << endl;
	}
	fout << endl;
}

Mtrx Mtrx::add(const Mtrx& mA)//����� ����
{
	int i, j;
	Mtrx mR(n_row, n_col);//��� ����


	mR.setName("R");

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = dM[i][j] + mA.dM[i][j];//����� ������ �����ڸ��� ����
		}
	}
	return mR;

}

Mtrx Mtrx::sub(const Mtrx& mA)//����� ����
{
	int i, j;
	Mtrx mR(n_row, n_col);//��� ����


	mR.setName("R");

	for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
		{
			mR.dM[i][j] = dM[i][j] - mA.dM[i][j];//����� ������ �����ڸ��� ����
		}
	}
	return mR;

}

Mtrx Mtrx::multiply(const Mtrx& mA)//��� ����
{
	int i, j, k;
	Mtrx mR(n_row, mA.n_col);//��� ����


	mR.setName("R");
	for (i = 0; i < n_row; i++)
	{
		for (j = 0; j < mA.n_col; j++)
		{
			mR.dM[i][j] = 0.0;
			for (k = 0; k < n_col; k++)
			{
				mR.dM[i][j] += dM[i][k] * mA.dM[k][j];
			}
		}
	}
	return mR;
}