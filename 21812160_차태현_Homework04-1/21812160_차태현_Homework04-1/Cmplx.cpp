#include<iostream>
#include<iomanip>
#include"Cmplx.h"


using namespace std;

ostream& operator<<(ostream& fout, const Cmplx& c)
{
	fout.setf(ios::fixed);
	fout.precision(2);//�Ҽ��� ��°�ڸ����� ǥ��

	string sign="+";//��ȣǥ�ø� ����

	if (c.imag < 0)
		sign = "-";


	fout << setw(6) << c.real <<setw(6)<<sign<< setw(8) << c.imag << "j" << endl;

	return fout;
}

istream& operator>>(istream& fin, Cmplx& c)
{
	fin >> c.real >> c.imag;//���Ϸκ��� ���Ҽ� �� �޾ƿ���

	return fin;
}


Cmplx::Cmplx(double real, double imag)//������
{
	real = real;
	imag = imag;
}
Cmplx ::~Cmplx()//�Ҹ���
{

}
double Cmplx::mag() const//���Ҽ� ũ�ⱸ�ϱ�
{
	double result=0.0;
	result = (sqrt(real * real + imag * imag));//�Ǽ��� ����� ������ ������ ��Ʈ

	return result;		

}

const Cmplx Cmplx::operator+(const Cmplx& c)//���Ҽ� ����
{
	Cmplx result;
	
	result.real = real + c.real;//�Ǽ� �� ����
	result.imag = imag + c.imag;//��� �� ����

	return result;
}

const Cmplx Cmplx::operator-(const Cmplx& c)//���Ҽ� ����
{
	Cmplx result;

	result.real = real - c.real;//�Ǽ��� ����
	result.imag = imag - c.imag;//����� ����

	return result;
}

const Cmplx Cmplx::operator*(const Cmplx& c)//���Ҽ� ����
{
	Cmplx result;
	
	result.real = real * c.real - imag * c.imag;
	result.imag = real * c.imag + imag * c.real;

	return result;
}

const Cmplx Cmplx::operator/(const Cmplx& c)//���Ҽ� ������
{
	Cmplx result;

	result.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
	result.imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);

	return result;
}

const Cmplx Cmplx::operator~()//�ӷ����Ҽ� ��ȯ
{
	Cmplx result;

	result.real = real;
	result.imag = -imag;

	return result;
}

const Cmplx Cmplx ::operator=(const Cmplx&c)//���Կ�����
{
	
	this->real = c.real;
	this->imag = c.imag;

	return *this;
}

bool Cmplx ::operator==(const Cmplx& c)//������ ��
{
	if ((real == c.real) && (imag == c.imag))//������� ture
		return true;

	return false;//�ٸ���� false
}


bool Cmplx ::operator!=(const Cmplx& c)
{
	if ((real != c.real) || (imag != c.imag))//�ٸ���� true
		return true;

	return false;//������� false
}

bool Cmplx::operator>(const Cmplx& c)
{
	if (mag() > c.mag())//���Ҽ� ũ�⸦ ���� ��Һ�
		return true;
	return false;

}

bool Cmplx::operator<(const Cmplx& c)
{
	if (mag() < c.mag())//���Ҽ� ũ�⸦ ���� ��Һ�
		return true;
	return false;

}
