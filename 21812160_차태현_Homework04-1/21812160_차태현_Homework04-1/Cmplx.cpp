#include<iostream>
#include<iomanip>
#include"Cmplx.h"


using namespace std;

ostream& operator<<(ostream& fout, const Cmplx& c)
{
	fout.setf(ios::fixed);
	fout.precision(2);//소수점 둘째자리까지 표현

	string sign="+";//부호표시를 위함

	if (c.imag < 0)
		sign = "-";


	fout << setw(6) << c.real <<setw(6)<<sign<< setw(8) << c.imag << "j" << endl;

	return fout;
}

istream& operator>>(istream& fin, Cmplx& c)
{
	fin >> c.real >> c.imag;//파일로부터 복소수 값 받아오기

	return fin;
}


Cmplx::Cmplx(double real, double imag)//생성자
{
	real = real;
	imag = imag;
}
Cmplx ::~Cmplx()//소멸자
{

}
double Cmplx::mag() const//복소수 크기구하기
{
	double result=0.0;
	result = (sqrt(real * real + imag * imag));//실수부 허수부 각각의 제곱의 루트

	return result;		

}

const Cmplx Cmplx::operator+(const Cmplx& c)//복소수 덧셈
{
	Cmplx result;
	
	result.real = real + c.real;//실수 부 덧셈
	result.imag = imag + c.imag;//허수 부 덧셈

	return result;
}

const Cmplx Cmplx::operator-(const Cmplx& c)//복소수 뺄셈
{
	Cmplx result;

	result.real = real - c.real;//실수부 덧셈
	result.imag = imag - c.imag;//허수부 뺄셈

	return result;
}

const Cmplx Cmplx::operator*(const Cmplx& c)//복소수 곱셈
{
	Cmplx result;
	
	result.real = real * c.real - imag * c.imag;
	result.imag = real * c.imag + imag * c.real;

	return result;
}

const Cmplx Cmplx::operator/(const Cmplx& c)//복소수 나눗셈
{
	Cmplx result;

	result.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
	result.imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);

	return result;
}

const Cmplx Cmplx::operator~()//켤레복소수 반환
{
	Cmplx result;

	result.real = real;
	result.imag = -imag;

	return result;
}

const Cmplx Cmplx ::operator=(const Cmplx&c)//대입연산자
{
	
	this->real = c.real;
	this->imag = c.imag;

	return *this;
}

bool Cmplx ::operator==(const Cmplx& c)//같은지 비교
{
	if ((real == c.real) && (imag == c.imag))//같을경우 ture
		return true;

	return false;//다를경우 false
}


bool Cmplx ::operator!=(const Cmplx& c)
{
	if ((real != c.real) || (imag != c.imag))//다를경우 true
		return true;

	return false;//같은경우 false
}

bool Cmplx::operator>(const Cmplx& c)
{
	if (mag() > c.mag())//복소수 크기를 통한 대소비교
		return true;
	return false;

}

bool Cmplx::operator<(const Cmplx& c)
{
	if (mag() < c.mag())//복소수 크기를 통한 대소비교
		return true;
	return false;

}
